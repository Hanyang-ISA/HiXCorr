/*
   Copyright 2012 University of Washington

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "Common.h"
#include "CometDataInternal.h"
#include "CometPreprocess.h"
#include "CometStatus.h"

Mutex CometPreprocess::_maxChargeMutex;
bool CometPreprocess::_bDoneProcessingAllSpectra;
bool CometPreprocess::_bFirstScan;
bool *CometPreprocess::pbMemoryPool;
double **CometPreprocess::ppdTmpRawDataArr;
double **CometPreprocess::ppdTmpFastXcorrDataArr;
double **CometPreprocess::ppdTmpCorrelationDataArr;
double **CometPreprocess::ppdTmpSmoothedSpectrumArr;
double **CometPreprocess::ppdTmpPeakExtractedArr;

// Generate data for both sp scoring (pfSpScoreData) and xcorr analysis (FastXcorr).
CometPreprocess::CometPreprocess()
{
}


CometPreprocess::~CometPreprocess()
{
}

void CometPreprocess::Reset()
{
    _bFirstScan = true;
    _bDoneProcessingAllSpectra = false;
}

bool CometPreprocess::LoadAndPreprocessSpectra(MSReader &mstReader,
                                               int iFirstScan, 
                                               int iLastScan, 
                                               int iAnalysisType,
                                               int minNumThreads,
                                               int maxNumThreads)
{
   int iFileLastScan = -1;         // The actual last scan in the file.
   int iScanNumber = 0;
   int iTotalScans = 0;
   int iNumSpectraLoaded = 0;
   int iFirstScanInRange = 0;
   int iTmpCount = 0;
   Spectrum mstSpectrum;           // For holding spectrum.

   g_massRange.iMaxFragmentCharge = 0;
   g_staticParams.precalcMasses.iMinus17 = BIN(g_staticParams.massUtility.dH2O);
   g_staticParams.precalcMasses.iMinus18 = BIN(g_staticParams.massUtility.dNH3);

   // Create the mutex we will use to protect g_massRange.iMaxFragmentCharge.
   Threading::CreateMutex(&_maxChargeMutex);

   // Get the thread pool of threads that will preprocess the data.
   ThreadPool<PreprocessThreadData *> *pPreprocessThreadPool = new ThreadPool<PreprocessThreadData *>(PreprocessThreadProc,
         minNumThreads, maxNumThreads);

   // Load all input spectra.
   while(true)
   {
      // Loads in MSMS spectrum data.
      if (_bFirstScan)
      {
         PreloadIons(mstReader, mstSpectrum, false, iFirstScan);
         _bFirstScan = false;

         iFirstScanInRange = mstSpectrum.getScanNumber();
      }
      else
      {
         PreloadIons(mstReader, mstSpectrum, true);
      }

      if (iFileLastScan == -1)
         iFileLastScan = mstReader.getLastScan();

      if ((iFileLastScan != -1) && (iFileLastScan < iFirstScan))
      {
         _bDoneProcessingAllSpectra = true;
         break;
      }

      iScanNumber = mstSpectrum.getScanNumber();

      if (iScanNumber != 0)
      {
         int iNumClearedPeaks = 0;

         iTmpCount = iScanNumber;

         if (iFirstScanInRange == 0)
            iFirstScanInRange = iScanNumber;

         // Clear out m/z range if clear_mz_range parameter is specified
         // Accomplish this by setting corresponding intensity to 0
         if (g_staticParams.options.clearMzRange.dEnd > 0.0
               && g_staticParams.options.clearMzRange.dStart <= g_staticParams.options.clearMzRange.dEnd)
         {
            int i=0;

            while (true)
            {
                if (i >= mstSpectrum.size() || mstSpectrum.at(i).mz > g_staticParams.options.clearMzRange.dEnd)
                   break;

                if (mstSpectrum.at(i).mz >= g_staticParams.options.clearMzRange.dStart
                      && mstSpectrum.at(i).mz <= g_staticParams.options.clearMzRange.dEnd)
                {
                   mstSpectrum.at(i).intensity = 0.0;
                   iNumClearedPeaks++;
                }

               i++;
            }
         }

         if (mstSpectrum.size()-iNumClearedPeaks >= g_staticParams.options.iMinPeaks)
         {
            if (iAnalysisType == AnalysisType_SpecificScanRange && iLastScan > 0 && iScanNumber > iLastScan)
            {
               _bDoneProcessingAllSpectra = true;
               break;
            }

            if (CheckActivationMethodFilter(mstSpectrum.getActivationMethod()))
            {
               Threading::LockMutex(g_pvQueryMutex);
               // this needed because processing can add multiple spectra at a time
               iNumSpectraLoaded = (int)g_pvQuery.size();
               iNumSpectraLoaded++;
               Threading::UnlockMutex(g_pvQueryMutex);

               // Queue at most 1 additional parameter for threads to process.
               pPreprocessThreadPool->WaitForQueuedParams(1, 1);
              
               //-->MH
               //If there are no Z-lines, filter the spectrum for charge state
               //run filter here.

               PreprocessThreadData *pPreprocessThreadData =
                  new PreprocessThreadData(mstSpectrum, iAnalysisType, iFileLastScan);

               pPreprocessThreadPool->Launch(pPreprocessThreadData);
            }
         }

         iTotalScans++;
      }
      else if (g_staticParams.inputFile.iInputType != InputType_MZXML)
      {
         _bDoneProcessingAllSpectra = true;
         break;
      }
      else
      {
         // What happens here when iScanNumber == 0 and it is an mzXML file?
         // Best way to deal with this is to keep trying to read but track each
         // attempt and break when the count goes past the mzXML's last scan.
         iTmpCount++;

         if (iTmpCount > iFileLastScan)
         {
            _bDoneProcessingAllSpectra = true;
            break;
         }
      }

      if (CheckExit(iAnalysisType, 
                    iScanNumber,
                    iTotalScans, 
                    iLastScan,
                    mstReader.getLastScan(),
                    iNumSpectraLoaded))
      {
         break;
      }
   }

   // Wait for active preprocess threads to complete processing.
   pPreprocessThreadPool->WaitForThreads();

   Threading::DestroyMutex(_maxChargeMutex);

   delete pPreprocessThreadPool;
   pPreprocessThreadPool = NULL;

   bool bSucceeded = !g_cometStatus.IsError() && !g_cometStatus.IsCancel();

   return bSucceeded;
}


void CometPreprocess::PreprocessThreadProc(PreprocessThreadData *pPreprocessThreadData)
{
   // This returns false if it fails, but the errors are already logged
   // so no need to check the return value here.

   //MH: Grab available array from shared memory pool.
   int i;
   Threading::LockMutex(g_preprocessMemoryPoolMutex);
   for (i=0; i<g_staticParams.options.iNumThreads; i++) 
   {
      if (pbMemoryPool[i]==false)
      {
         pbMemoryPool[i]=true;
         break;
      }
   }
   Threading::UnlockMutex(g_preprocessMemoryPoolMutex);

   //MH: Fail-safe to stop if memory isn't available for the next thread.
   //Needs better capture and return?
   if (i==g_staticParams.options.iNumThreads)
   {
      printf("Error with memory pool.\n");
      exit(1);
   }

   //MH: Give memory manager access to the thread.
   pPreprocessThreadData->SetMemory(&pbMemoryPool[i]);

   PreprocessSpectrum(pPreprocessThreadData->mstSpectrum,
         ppdTmpRawDataArr[i],
         ppdTmpFastXcorrDataArr[i],
         ppdTmpCorrelationDataArr[i],
         ppdTmpSmoothedSpectrumArr[i],
         ppdTmpPeakExtractedArr[i]);

   delete pPreprocessThreadData;
   pPreprocessThreadData = NULL;
}


bool CometPreprocess::DoneProcessingAllSpectra()
{
   return _bDoneProcessingAllSpectra;
}

bool CometPreprocess::Preprocess(struct Query *pScoring,
								 Spectrum mstSpectrum,
								 double *pdTmpRawData,
							  	 double *pdTmpFastXcorrData,
							 	 double *pdTmpCorrelationData,
								 double *pdTmpSmoothedSpectrum,
								 double *pdTmpPeakExtracted)
{
	int i;
	int j;
	struct msdata pTmpSpData[NUM_SP_IONS];
	struct PreprocessStruct pPre;

	pPre.iHighestIon = 0;
	pPre.dHighestIntensity = 0;

	// initialize these temporary arrays before re-using
	size_t iTmp = (size_t)((g_staticParams.options.dHighPeptideMass + 100.0) * g_staticParams.dInverseBinWidth)*sizeof(double);
	// pdTmpRawData is a binned array holding raw data
	map<int, double> tmpXcorrData;
	map<int, double> tmpSpecData;
	if (!LoadIons(pScoring, &tmpXcorrData, &tmpSpecData, mstSpectrum, &pPre))
	{
		return false;
	}

	// get mzML nativeID
	char szNativeID[128];
	if (mstSpectrum.getNativeID(szNativeID, 128))
		strcpy(pScoring->_spectrumInfoInternal.szNativeID, szNativeID);
	else
		pScoring->_spectrumInfoInternal.szNativeID[0] = '\0';

	// Make fast xcorr spectrum.
	vector< pair<int, double> > Compact;
	///*
	pScoring->iFastXcorrData = 1;
	pScoring->iFastXcorrDataNL = 1;

	double total = 0.0;
	map< int, double >::iterator start = tmpXcorrData.begin();
	map< int, double >::iterator end = tmpXcorrData.begin();
	map< int, double >::iterator Iter_Double;
	map<int, double> first;
	first[0] = 0;
	map<int, double>::iterator prev_ = first.begin();
	i = 0;

	for (Iter_Double = tmpXcorrData.begin(); Iter_Double != tmpXcorrData.end(); ++Iter_Double) {
		if (end != tmpXcorrData.end()) {
			while (end->first - Iter_Double->first <= 75) {
				total += end->second;
				//printf("%d\t%f\n", end->first, end->second);
				end++;
				if (end == tmpXcorrData.end()) break;
			}
		}
		if (start != tmpXcorrData.end()) {
			while (Iter_Double->first - start->first > 75) {
				total -= start->second;
				start++;
				if (start == tmpXcorrData.end()) break;
			}
		}
		Compact.push_back(make_pair(Iter_Double->first, tmpXcorrData[Iter_Double->first] - (0.0066666667 * (total - tmpXcorrData[Iter_Double->first]))));
		if (i > 0) {
			if (!isEqual(Compact[i].second, Compact[i - 1].second)) pScoring->iFastXcorrData++;
		}
		i++;
		prev_ = Iter_Double;
	}

	// Using sparse matrix which means we free pScoring->pfFastXcorrData, ->pfFastXcorrDataNL here
	if (g_staticParams.options.bSparseMatrix)
	{
		//MH: Add one more slot for the last bin
		pScoring->iFastXcorrData += 2;
		pScoring->iFastXcorrDataNL++;

		//MH: Fill sparse matrix
		try
		{
			pScoring->pSparseFastXcorrData = new SparseMatrix[pScoring->iFastXcorrData]();
		}
		catch (std::bad_alloc& ba)
		{
			char szErrorMsg[256];
			sprintf(szErrorMsg, " Error - new(pScoring->pSparseFastXcorrData[%d]). bad_alloc: %s.", pScoring->iFastXcorrData, ba.what());
			string strErrorMsg(szErrorMsg);
			logerr("%s\n\n", szErrorMsg);
			return false;
		}

		pScoring->pSparseFastXcorrData[0].bin = 0;
		pScoring->pSparseFastXcorrData[0].fIntensity = 0.0;
		if (Compact[0].second != 0.0) {
			pScoring->pSparseFastXcorrData[1].bin = Compact[0].first;
			pScoring->pSparseFastXcorrData[1].fIntensity = Compact[0].second;
		}
		j = 2;
		for (size_t xxx = 1; xxx < Compact.size(); xxx++) {
			if (!isEqual(Compact[xxx].second, Compact[xxx - 1].second)) {
				pScoring->pSparseFastXcorrData[j].bin = Compact[xxx].first;
				pScoring->pSparseFastXcorrData[j++].fIntensity = Compact[xxx].second;
			}
		}
		pScoring->pSparseFastXcorrData[j].bin = pScoring->_spectrumInfoInternal.iArraySize;
		pScoring->pSparseFastXcorrData[j].fIntensity = 0;

		//pScoring->iFastXcorrData = j+1;	  
	}

	/*
	// Create data for sp scoring.
	// Arbitrary bin size cutoff to do smoothing, peak extraction.
	if (g_staticParams.tolerances.dFragmentBinSize >= 0.10)
	{
	if (!Smooth(pdTmpRawData, pScoring->_spectrumInfoInternal.iArraySize, pdTmpSmoothedSpectrum))
	{
	return false;
	}

	if (!PeakExtract(pdTmpRawData, pScoring->_spectrumInfoInternal.iArraySize, pdTmpPeakExtracted))
	{
	return false;
	}
	}
	*/
	for (i = 0; i<NUM_SP_IONS; i++)
	{
		pTmpSpData[i].dIon = 0.0;
		pTmpSpData[i].dIntensity = 0.0;
	}

	GetTopIons(&tmpSpecData, &(pTmpSpData[0]), pScoring->_spectrumInfoInternal.iArraySize);

	qsort(pTmpSpData, NUM_SP_IONS, sizeof(struct msdata), QsortByIon);

	// Modify for Sp data.
	StairStep(pTmpSpData);

	if (g_staticParams.options.bSparseMatrix)
	{
		// MH: Fill sparse matrix for SpScore - Note that we allocate max number of sp ions,
		// but will use less than this amount.

		try
		{
			pScoring->pSparseSpScoreData = new SparseMatrix[NUM_SP_IONS]();
		}
		catch (std::bad_alloc& ba)
		{
			char szErrorMsg[256];
			sprintf(szErrorMsg, " Error - new(pScoring->pSparseSpScoreData[%d]). bad_alloc: %s.", pScoring->iSpScoreData, ba.what());
			string strErrorMsg(szErrorMsg);
			g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);
			logerr("%s\n\n", szErrorMsg);
			return false;
		}

		pScoring->iSpScoreData = 0;
		for (i = 0; i<NUM_SP_IONS; i++)
		{
			if ((float)pTmpSpData[i].dIntensity > FLOAT_ZERO)
			{
				pScoring->pSparseSpScoreData[pScoring->iSpScoreData].bin = (int)(pTmpSpData[i].dIon);
				pScoring->pSparseSpScoreData[pScoring->iSpScoreData].fIntensity = (float)pTmpSpData[i].dIntensity;
				pScoring->iSpScoreData++;
			}
		}
	}
	/*
	else
	{
	try
	{
	pScoring->pfSpScoreData = new float[pScoring->_spectrumInfoInternal.iArraySize]();
	}
	catch (std::bad_alloc& ba)
	{
	char szErrorMsg[256];
	sprintf(szErrorMsg,  " Error - new(pfSpScoreData[%d]). bad_alloc: %s.", pScoring->_spectrumInfoInternal.iArraySize, ba.what());
	string strErrorMsg(szErrorMsg);
	g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);
	logerr("%s\n\n", szErrorMsg);
	return false;
	}

	// note that pTmpSpData[].dIon values are already BIN'd
	for (i=0; i<NUM_SP_IONS; i++)
	pScoring->pfSpScoreData[(int)(pTmpSpData[i].dIon)] = (float) pTmpSpData[i].dIntensity;
	}
	*/
	return true;
}




bool CometPreprocess::PreprocessHiXCorr(struct Query *pScoring,
                                 Spectrum mstSpectrum,
                                 double *pdTmpRawData,
                                 double *pdTmpFastXcorrData,
                                 double *pdTmpCorrelationData,
                                 double *pdTmpSmoothedSpectrum,
                                 double *pdTmpPeakExtracted)
{
   int i;
   int j;
   struct msdata pTmpSpData[NUM_SP_IONS];
   struct PreprocessStruct pPre;

   pPre.iHighestIon = 0;
   pPre.dHighestIntensity = 0;

   // initialize these temporary arrays before re-using
   size_t iTmp= (size_t)((g_staticParams.options.dHighPeptideMass + 100.0) * g_staticParams.dInverseBinWidth)*sizeof(double);
   // pdTmpRawData is a binned array holding raw data
   map<int, double> tmpXcorrData;
   map<int, double> tmpSpecData;
   if (!LoadIons(pScoring, &tmpXcorrData, &tmpSpecData, mstSpectrum, &pPre))
   {
      return false;
   }

   // get mzML nativeID
   char szNativeID[128];
   if (mstSpectrum.getNativeID(szNativeID, 128))
      strcpy(pScoring->_spectrumInfoInternal.szNativeID, szNativeID);
   else
      pScoring->_spectrumInfoInternal.szNativeID[0]='\0';
   
   // Make fast xcorr spectrum.
   vector< pair<int, double> > Compact;
   ///*
   pScoring->iFastXcorrData=1;
   pScoring->iFastXcorrDataNL=1;
   
   double total = 0.0;
   map< int, double >::iterator start = tmpXcorrData.begin();
   map< int, double >::iterator end = tmpXcorrData.begin();
   map< int, double >::iterator Iter_Double;
   map<int, double> first;
   first[0] = 0;
   map<int, double>::iterator prev_ = first.begin();

   /*
   map<int, double> pfFastXcorrData;

   for (Iter_Double =  tmpXcorrData.begin(); Iter_Double != tmpXcorrData.end(); ++Iter_Double) {
	   if(start != tmpXcorrData.end() && end != tmpXcorrData.end()) {
		   while (end->first - Iter_Double->first <= 75 || Iter_Double->first - start->first > 75) {
			   if( (end->first - Iter_Double->first) < (Iter_Double->first - start->first) ) {
				   total += end->second;
				   pfFastXcorrData[end->first - 75] += 0.0;
				   end++;
				   if(end == tmpXcorrData.end()) break;
			   }
			   else if( (end->first - Iter_Double->first) > (Iter_Double->first - start->first) ) {
				   total -= start->second;
				   pfFastXcorrData[start->first + 76] += 0.0;
				   start++;
				   if(start == tmpXcorrData.end()) break;
			   }
			   else {
				   total += end->second;
				   total -= start->second;
				   pfFastXcorrData[end->first - 75] += 0.0;
				   start++;
				   end++;
				   if(start == tmpXcorrData.end() || end == tmpXcorrData.end()) break;
			   }
		   }
	   }
	   else if(start != tmpXcorrData.end()) {
		    while (Iter_Double->first - start->first > 75) {
				 total -= start->second;
				 pfFastXcorrData[start->first + 76] += 0.0;
				 start++;
				 if(start == tmpXcorrData.end()) break;
			}
	   }
	   else if(end != tmpXcorrData.end()) {
		   while (end->first - Iter_Double->first <= 75) {
			   total += end->second;
			   pfFastXcorrData[end->first - 75] += 0.0;
			   end++;
			   if(end == tmpXcorrData.end()) break;
		   }
	   }
	   pfFastXcorrData[Iter_Double->first] = Iter_Double->second;
   }

   total = 0.0;
   start = pfFastXcorrData.begin();
   end = pfFastXcorrData.begin();
   */
   i = 0;
   for (Iter_Double =  tmpXcorrData.begin(); Iter_Double != tmpXcorrData.end(); ++Iter_Double) {
	   if (end !=  tmpXcorrData.end() ) {
		   while (end->first - Iter_Double->first <= 75 ) {
			   total += end->second;
			   //printf("%d\t%f\n", end->first, end->second);
			   end++;
			   if(end == tmpXcorrData.end()) break;
		   }
	   }
	   if(start !=  tmpXcorrData.end() ) {
		   while(Iter_Double->first - start->first > 75) {
			   total -= start->second;
			   start++;
			   if(start ==  tmpXcorrData.end()) break;
		   }
	   }
	   Compact.push_back( make_pair(Iter_Double->first, tmpXcorrData[Iter_Double->first] - (0.0066666667 * (total - tmpXcorrData[Iter_Double->first])) ) );
	   if(i > 0) {
		   if (!isEqual(Compact[i].second, Compact[i-1].second)) pScoring->iFastXcorrData++;
	   }
	   i++;
	   prev_ = Iter_Double;	   
   }  

   

   // Using sparse matrix which means we free pScoring->pfFastXcorrData, ->pfFastXcorrDataNL here
   if (g_staticParams.options.bSparseMatrix)
   {
      //MH: Add one more slot for the last bin
      pScoring->iFastXcorrData += 2;
      pScoring->iFastXcorrDataNL++;
	  
      //MH: Fill sparse matrix
      try
      {
		  pScoring->pSparseFastXcorrData = new SparseMatrix[pScoring->iFastXcorrData]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pScoring->pSparseFastXcorrData[%d]). bad_alloc: %s.", pScoring->iFastXcorrData, ba.what());
         string strErrorMsg(szErrorMsg);
         logerr("%s\n\n", szErrorMsg);
         return false;
      }

	  pScoring->pSparseFastXcorrData[0].bin=0;
	  pScoring->pSparseFastXcorrData[0].fIntensity=0.0;
	  if( Compact[0].second != 0.0) {
		  pScoring->pSparseFastXcorrData[1].bin=Compact[0].first;
		  pScoring->pSparseFastXcorrData[1].fIntensity=Compact[0].second;
	  }
	  j=2;
	  for(size_t xxx=1; xxx < Compact.size(); xxx++) {
		  if (!isEqual(Compact[xxx].second, Compact[xxx-1].second)) {
			  pScoring->pSparseFastXcorrData[j].bin = Compact[xxx].first;
			  pScoring->pSparseFastXcorrData[j++].fIntensity = Compact[xxx].second;
		  }
	  }
      pScoring->pSparseFastXcorrData[j].bin=pScoring->_spectrumInfoInternal.iArraySize;
      pScoring->pSparseFastXcorrData[j].fIntensity=0;

	  //pScoring->iFastXcorrData = j+1;	  
   }

   /*
   // Create data for sp scoring.
   // Arbitrary bin size cutoff to do smoothing, peak extraction.
   if (g_staticParams.tolerances.dFragmentBinSize >= 0.10)
   {
      if (!Smooth(pdTmpRawData, pScoring->_spectrumInfoInternal.iArraySize, pdTmpSmoothedSpectrum))
      {
         return false;
      }

      if (!PeakExtract(pdTmpRawData, pScoring->_spectrumInfoInternal.iArraySize, pdTmpPeakExtracted))
      {
         return false;
      }
   }
   */
   for (i=0; i<NUM_SP_IONS; i++)
   {
      pTmpSpData[i].dIon = 0.0;
      pTmpSpData[i].dIntensity = 0.0;
   }

   GetTopIons(&tmpSpecData, &(pTmpSpData[0]), pScoring->_spectrumInfoInternal.iArraySize);

   qsort(pTmpSpData, NUM_SP_IONS, sizeof(struct msdata), QsortByIon);

   // Modify for Sp data.
   StairStep(pTmpSpData);

   if (g_staticParams.options.bSparseMatrix)
   {
      // MH: Fill sparse matrix for SpScore - Note that we allocate max number of sp ions,
      // but will use less than this amount.

      try
      {
         pScoring->pSparseSpScoreData = new SparseMatrix[NUM_SP_IONS]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pScoring->pSparseSpScoreData[%d]). bad_alloc: %s.", pScoring->iSpScoreData, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }

      pScoring->iSpScoreData=0;
      for (i=0; i<NUM_SP_IONS; i++)
      {
         if ((float)pTmpSpData[i].dIntensity > FLOAT_ZERO)
         {
            pScoring->pSparseSpScoreData[pScoring->iSpScoreData].bin = (int)(pTmpSpData[i].dIon);
            pScoring->pSparseSpScoreData[pScoring->iSpScoreData].fIntensity = (float) pTmpSpData[i].dIntensity;
            pScoring->iSpScoreData++;
         }
      }
   }
   /*
   else
   {
      try
      {
         pScoring->pfSpScoreData = new float[pScoring->_spectrumInfoInternal.iArraySize]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pfSpScoreData[%d]). bad_alloc: %s.", pScoring->_spectrumInfoInternal.iArraySize, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }

      // note that pTmpSpData[].dIon values are already BIN'd
      for (i=0; i<NUM_SP_IONS; i++)
         pScoring->pfSpScoreData[(int)(pTmpSpData[i].dIon)] = (float) pTmpSpData[i].dIntensity;
   }
   */
   return true;
}



//-->MH
// Loads spectrum into spectrum object.
void CometPreprocess::PreloadIons(MSReader &mstReader,
                                  Spectrum &spec,
                                  bool bNext,
                                  int scNum)
{
   if (!bNext)
   {
      mstReader.readFile(g_staticParams.inputFile.szFileName, spec, scNum);
   }
   else
   {
      mstReader.readFile(NULL, spec);
   }
}


bool CometPreprocess::CheckActivationMethodFilter(MSActivation act)
{
   bool bSearchSpectrum = true;

   // Check possible activation method filter.
   if (strcmp(g_staticParams.options.szActivationMethod, "ALL")!=0 && (act != mstNA))
   {
      if (!strcmp(g_staticParams.options.szActivationMethod, "CID") && (act != mstCID))
      {
         bSearchSpectrum = 0;
      }
      else if (!strcmp(g_staticParams.options.szActivationMethod, "HCD") && (act != mstHCD))
      {
         bSearchSpectrum = 0;
      }
      else if (!strcmp(g_staticParams.options.szActivationMethod, "ETD") && (act != mstETD))
      {
         bSearchSpectrum = 0;
      }
      else if (!strcmp(g_staticParams.options.szActivationMethod, "ECD") && (act != mstECD))
      {
         bSearchSpectrum = 0;
      }
      else if (!strcmp(g_staticParams.options.szActivationMethod, "PQD") && (act != mstPQD))
      {
         bSearchSpectrum = 0;
      }
      else if (!strcmp(g_staticParams.options.szActivationMethod, "IRMPD") && (act != mstIRMPD))
      {
         bSearchSpectrum = 0;
      }
   }

   return bSearchSpectrum;
}


bool CometPreprocess::CheckExit(int iAnalysisType,
                                int iScanNum, 
                                int iTotalScans, 
                                int iLastScan,
                                int iReaderLastScan,
                                int iNumSpectraLoaded)
{
   if (g_cometStatus.IsError())
   {
      return true;
   }

   if (g_cometStatus.IsCancel())
   {
       return true;
   }

   if (iAnalysisType == AnalysisType_SpecificScan)
   {
      _bDoneProcessingAllSpectra = true;
      return true;
   }

   if (iAnalysisType == AnalysisType_SpecificScanRange)
   {
      if (iLastScan > 0)
      {
         if (iScanNum >= iLastScan)
         {
            _bDoneProcessingAllSpectra = true;
            return true;
         }
      }
   }

   if (iAnalysisType == AnalysisType_EntireFile
         && g_staticParams.inputFile.iInputType == InputType_MZXML
         && iScanNum == 0)
   {
      _bDoneProcessingAllSpectra = true;
      return true;
   }

   // Horrible way to exit as this typically requires a quick cycle through
   // while loop but not sure what else to do when getScanNumber() returns 0
   // for non MS/MS scans.
   if (g_staticParams.inputFile.iInputType == InputType_MZXML && iTotalScans > iReaderLastScan)
   {
      _bDoneProcessingAllSpectra = true;
      return true;
   }

   if ((g_staticParams.options.iSpectrumBatchSize != 0)
         && (iNumSpectraLoaded >= g_staticParams.options.iSpectrumBatchSize))
   {
      return true;
   }

   return false;
}


bool CometPreprocess::PreprocessSpectrum(Spectrum &spec,
                                         double *pdTmpRawData,
                                         double *pdTmpFastXcorrData,
                                         double *pdTmpCorrelationData,
                                         double *pdTmpSmoothedSpectrum,
                                         double *pdTmpPeakExtracted)
{
   int z;
   int zStart;
   int zStop;

   int iScanNumber = spec.getScanNumber();

   // Since we have no filter, just add zlines.
   // WARNING: only good up to charge state 3
   if (spec.sizeZ() == 0 || g_staticParams.options.bOverrideCharge)
   {
      if (g_staticParams.options.bOverrideCharge)
      {
         for (z=g_staticParams.options.iStartCharge; z<=g_staticParams.options.iEndCharge; z++)
         {
            spec.addZState(z,spec.getMZ()*z-(z-1)*PROTON_MASS);
         }
      }
      else // Use +1 or +2/+3 rule.
      {
         int i=0;
         double dSumBelow = 0.0;
         double dSumTotal = 0.0;

         while (true)
         {
            if (i >= spec.size())
               break;

            dSumTotal += spec.at(i).intensity;

            if (spec.at(i).mz < spec.getMZ())
               dSumBelow += spec.at(i).intensity;

            i++;
         }

         if (isEqual(dSumTotal, 0.0) || ((dSumBelow/dSumTotal) > 0.95))
         {
            z = 1;
            spec.addZState(z, spec.getMZ() * z - (z-1) * PROTON_MASS);
         }
         else
         {
            z = 2;
            spec.addZState(z,spec.getMZ()*z-(z-1)*PROTON_MASS);
            z = 3;
            spec.addZState(z,spec.getMZ()*z-(z-1)*PROTON_MASS);
         }
      }
   }

   // Set our boundaries for multiple z lines.
   zStart = 0;
   zStop = spec.sizeZ();

   for (z=zStart; z<zStop; z++)
   {
      int iPrecursorCharge = spec.atZ(z).z;  // I need this before iChargeState gets assigned.
      double dMass = spec.atZ(z).mz;

      if (!g_staticParams.options.bOverrideCharge
            || (iPrecursorCharge>=g_staticParams.options.iStartCharge
               && iPrecursorCharge<=g_staticParams.options.iEndCharge ) )
      {
         if (CheckExistOutFile(iPrecursorCharge, iScanNumber)
               && (isEqual(g_staticParams.options.dLowPeptideMass, 0.0)
                  || ((dMass >= g_staticParams.options.dLowPeptideMass)
                     && (dMass <= g_staticParams.options.dHighPeptideMass)))
               && iPrecursorCharge <= g_staticParams.options.iMaxPrecursorCharge)
         {
            Query *pScoring = new Query();

            pScoring->_pepMassInfo.dExpPepMass = dMass;
            pScoring->_spectrumInfoInternal.iArraySize = (int)((dMass + 100.0) * g_staticParams.dInverseBinWidth);
            pScoring->_spectrumInfoInternal.iChargeState = iPrecursorCharge;
            pScoring->_spectrumInfoInternal.dTotalIntensity = 0.0;
            pScoring->_spectrumInfoInternal.dRTime = 60.0*spec.getRTime();;
            pScoring->_spectrumInfoInternal.iScanNumber = iScanNumber;

            if (iPrecursorCharge == 1)
               pScoring->_spectrumInfoInternal.iMaxFragCharge = 1;
            else
            {
               pScoring->_spectrumInfoInternal.iMaxFragCharge = iPrecursorCharge - 1;

               if (pScoring->_spectrumInfoInternal.iMaxFragCharge > g_staticParams.options.iMaxFragmentCharge)
                  pScoring->_spectrumInfoInternal.iMaxFragCharge = g_staticParams.options.iMaxFragmentCharge;
            }

            Threading::LockMutex(_maxChargeMutex);

            // g_massRange.iMaxFragmentCharge is global maximum fragment ion charge across all spectra.
            if (pScoring->_spectrumInfoInternal.iMaxFragCharge > g_massRange.iMaxFragmentCharge)
            {
               g_massRange.iMaxFragmentCharge = pScoring->_spectrumInfoInternal.iMaxFragCharge;
            }

            Threading::UnlockMutex(_maxChargeMutex);

            if (!AdjustMassTol(pScoring))
            {
               return false;
            }

            // Populate pdCorrelation data.
            // NOTE: there must be a good way of doing this just once per spectrum instead
            //       of repeating for each charge state.
            if (!Preprocess(pScoring, spec, pdTmpRawData, pdTmpFastXcorrData,
                     pdTmpCorrelationData, pdTmpSmoothedSpectrum, pdTmpPeakExtracted))
            {
               return false;
            }

            Threading::LockMutex(g_pvQueryMutex);
            g_pvQuery.push_back(pScoring);
            Threading::UnlockMutex(g_pvQueryMutex);
         }
      }
   }

   return true;
}


// Skip repeating a search if output exists only works for .out files
bool CometPreprocess::CheckExistOutFile(int iCharge,
                                        int iScanNum)
{
   bool bSearchSpectrum = 1;

   if (g_staticParams.options.bOutputOutFiles
         && g_staticParams.options.bSkipAlreadyDone
         && !g_staticParams.options.bOutputSqtStream
         && !g_staticParams.options.bOutputSqtFile
         && !g_staticParams.options.bOutputPepXMLFile
         && !g_staticParams.options.bOutputPercolatorFile)
   {
      char szOutputFileName[SIZE_FILE];
      char *pStr;
      FILE *fpcheck;

      if ( (pStr = strrchr(g_staticParams.inputFile.szBaseName, '\\')) == NULL
            && (pStr = strrchr(g_staticParams.inputFile.szBaseName, '/')) == NULL)
      {
         pStr = g_staticParams.inputFile.szBaseName;
      }
      else
         *pStr++;

      sprintf(szOutputFileName, "%s/%s.%.5d.%.5d.%d.out",
            g_staticParams.inputFile.szBaseName,
            pStr,
            iScanNum,
            iScanNum,
            iCharge);

      // Check existence of .out file.
      if ((fpcheck = fopen(szOutputFileName, "r")) != NULL)
      {
         bSearchSpectrum = 0;
         fclose(fpcheck);
      }
   }

   return bSearchSpectrum;
}


bool CometPreprocess::AdjustMassTol(struct Query *pScoring)
{
   if (g_staticParams.tolerances.iMassToleranceUnits == 0) // amu
   {
      pScoring->_pepMassInfo.dPeptideMassTolerance = g_staticParams.tolerances.dInputTolerance;
   }
   else if (g_staticParams.tolerances.iMassToleranceUnits == 1) // mmu
   {
      pScoring->_pepMassInfo.dPeptideMassTolerance = g_staticParams.tolerances.dInputTolerance * 0.001;
   }
   else // ppm
   {
      pScoring->_pepMassInfo.dPeptideMassTolerance = g_staticParams.tolerances.dInputTolerance
         * pScoring->_pepMassInfo.dExpPepMass / 1000000.0;
   }

   if (g_staticParams.tolerances.iIsotopeError == 0)
   {
      pScoring->_pepMassInfo.dPeptideMassToleranceMinus = pScoring->_pepMassInfo.dExpPepMass
         - pScoring->_pepMassInfo.dPeptideMassTolerance;

      pScoring->_pepMassInfo.dPeptideMassTolerancePlus = pScoring->_pepMassInfo.dExpPepMass
         + pScoring->_pepMassInfo.dPeptideMassTolerance;
   }
   else if (g_staticParams.tolerances.iIsotopeError == 1) // search -1 to +1, +2, +3 isotope windows
   {
      pScoring->_pepMassInfo.dPeptideMassToleranceMinus = pScoring->_pepMassInfo.dExpPepMass
         - pScoring->_pepMassInfo.dPeptideMassTolerance - 3.0 * C13_DIFF * PROTON_MASS;

      pScoring->_pepMassInfo.dPeptideMassTolerancePlus = pScoring->_pepMassInfo.dExpPepMass
         + pScoring->_pepMassInfo.dPeptideMassTolerance + 1.0 * C13_DIFF * PROTON_MASS;
   }
   else if (g_staticParams.tolerances.iIsotopeError == 2) // search -8, -4, 0, 4, 8 windows
   {
      pScoring->_pepMassInfo.dPeptideMassToleranceMinus = pScoring->_pepMassInfo.dExpPepMass
         - pScoring->_pepMassInfo.dPeptideMassTolerance - 8.1;

      pScoring->_pepMassInfo.dPeptideMassTolerancePlus = pScoring->_pepMassInfo.dExpPepMass
         + pScoring->_pepMassInfo.dPeptideMassTolerance + 8.1;
   }
   else  // Should not get here.
   {
      char szErrorMsg[256];
      sprintf(szErrorMsg,  " Error - iIsotopeError=%d",  g_staticParams.tolerances.iIsotopeError);
      string strErrorMsg(szErrorMsg);
      g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);
      logerr("%s\n\n", szErrorMsg);
      return false;
   }

   return true;
}


//  Reads MSMS data file as ASCII mass/intensity pairs.
bool CometPreprocess::LoadIons(struct Query *pScoring,
                               map<int,double> *pdTmpRawData, map<int, double> *tmpSepcData,
                               Spectrum mstSpectrum,
                               struct PreprocessStruct *pPre)
{
	int  i;
	double _dIon,
		dIntensity;


	vector<int> mz;
	vector<double> intensity;

	i = 0;
	while(true)
	{
		if (i >= mstSpectrum.size())
			break;

		_dIon = mstSpectrum.at(i).mz;
		dIntensity = mstSpectrum.at(i).intensity;
		i++;

		pScoring->_spectrumInfoInternal.dTotalIntensity += dIntensity;

		if ((dIntensity >= g_staticParams.options.dMinIntensity) && (dIntensity > 0.0))
		{
			if (_dIon < (pScoring->_pepMassInfo.dExpPepMass + 50.0))
			{
				int iBinIon = BIN(_dIon);

				dIntensity = sqrt(dIntensity);

				if (iBinIon > pPre->iHighestIon)
					pPre->iHighestIon = iBinIon;

				mz.push_back(iBinIon);
				intensity.push_back(dIntensity);

				if (iBinIon < pScoring->_spectrumInfoInternal.iArraySize) {
					if (dIntensity > pPre->dHighestIntensity)
						pPre->dHighestIntensity = dIntensity;
				}

			}
		}
	}

	int  iBin,
		iWindowSize,
		iNumWindows=10;
	double dMaxWindowInten,
		dMaxOverallInten,
		dTmp2, dTmp1;

	map<int, int> intensRegion;
	int regionSelector = (int)((pPre->iHighestIon)/(double)iNumWindows)+1;

	vector<int>::iterator vecInt;
	vector<double>::iterator vecDouble = intensity.begin();

	dTmp1 = 1.0;
   if (pPre->dHighestIntensity > FLOAT_ZERO) dTmp1 = 100.0 / pPre->dHighestIntensity;

	for(vecInt = mz.begin(); vecInt != mz.end(); vecInt++) {
		int dIon = *vecInt;
		dIntensity = *vecDouble;
		//printf("%d\t%f\n", dIon, dIntensity);

		int region = ((double)dIon/(double)regionSelector);
		if (region >= iNumWindows) {
			region = iNumWindows - 1;
		}
		intensRegion[dIon] = region;

		double ttmp = dIntensity*dTmp1;
		if ((dIon < pScoring->_spectrumInfoInternal.iArraySize)
			&& (ttmp > (*tmpSepcData)[dIon]))
		{
			if (g_staticParams.options.iRemovePrecursor == 1)
			{
				double dMZ = (pScoring->_pepMassInfo.dExpPepMass
					+ (pScoring->_spectrumInfoInternal.iChargeState - 1) * PROTON_MASS)
					/ (double)(pScoring->_spectrumInfoInternal.iChargeState);

				if (fabs(dIon - dMZ) > g_staticParams.options.dRemovePrecursorTol)
				{
					if (dIntensity > (*pdTmpRawData)[dIon])
						(*pdTmpRawData)[dIon] = dIntensity;

					if ((*pdTmpRawData)[dIon] > pPre->dHighestIntensity)
						pPre->dHighestIntensity = (*pdTmpRawData)[dIon];
				}
			}
			else if (g_staticParams.options.iRemovePrecursor == 2)
			{
				int j;
				int bNotPrec = 1;

				for (j=1; j <= pScoring->_spectrumInfoInternal.iChargeState; j++)
				{
					double dMZ;

					dMZ = (pScoring->_pepMassInfo.dExpPepMass + (j - 1)*PROTON_MASS) / (double)(j);
					if (fabs(dIon - dMZ) < g_staticParams.options.dRemovePrecursorTol)
					{
						bNotPrec = 0;
						break;
					}
				}
				if (bNotPrec)
				{
					if (dIntensity > (*pdTmpRawData)[dIon])
						(*pdTmpRawData)[dIon] = dIntensity;

					if ((*pdTmpRawData)[dIon] > pPre->dHighestIntensity)
						pPre->dHighestIntensity = (*pdTmpRawData)[dIon];
				}
			}
			else // iRemovePrecursor==0
			{
				(*tmpSepcData)[dIon] = ttmp;

				dTmp2 = 0.05*(pPre->dHighestIntensity*dTmp1);
				if(ttmp > dTmp2) {
					(*pdTmpRawData)[dIon] = ttmp;
					(*pdTmpRawData)[dIon-75] += 0.;
					(*pdTmpRawData)[dIon+76] += 0.;
					(*pdTmpRawData)[dIon+1] += 0.;
				}
			}
		}
		vecDouble++;
	}
	map< int, int >::iterator Iter_Int;

	double* maxRegion = new double[iNumWindows];
	for (int re = 0; re < iNumWindows; re++) {
		maxRegion[re] = 0.0;
	}
	for (Iter_Int = intensRegion.begin(); Iter_Int != intensRegion.end(); ++Iter_Int) {
		int reg = Iter_Int->second;
		if (reg >= 0 && maxRegion[reg] < (*pdTmpRawData)[Iter_Int->first]) {
			maxRegion[reg] = (*pdTmpRawData)[Iter_Int->first];
		}
	}

	for (Iter_Int = intensRegion.begin(); Iter_Int != intensRegion.end(); ++Iter_Int) {
		int reg = Iter_Int->second;
		if (reg >= 0 && maxRegion[reg] > 0.0) {
			(*pdTmpRawData)[Iter_Int->first] *= (50.0 / maxRegion[reg]);
			//printf("%d\t%d\t%f\n", reg, Iter_Int->first, (*pdTmpRawData)[Iter_Int->first]);
		}
	}
	delete [] maxRegion;
	return true;
}


// pdTmpRawData now holds raw data, pdTmpCorrelationData is windowed data after this function
void CometPreprocess::MakeCorrData(double *pdTmpRawData,
                                   double *pdTmpCorrelationData,
                                   struct Query *pScoring,
                                   struct PreprocessStruct *pPre)
{
   int  i,
        ii,
        iBin,
        iWindowSize,
        iNumWindows=10;
   double dMaxWindowInten,
          dMaxOverallInten,
          dTmp1,
          dTmp2;

   dMaxOverallInten = 0.0;

   // Normalize maximum intensity to 100.
   dTmp1 = 1.0;
   if (pPre->dHighestIntensity > FLOAT_ZERO)
      dTmp1 = 100.0 / pPre->dHighestIntensity;

   for (i=0; i < pScoring->_spectrumInfoInternal.iArraySize; i++)
   {
      pdTmpRawData[i] = pdTmpRawData[i]*dTmp1;

      if (dMaxOverallInten < pdTmpRawData[i])
         dMaxOverallInten = pdTmpRawData[i];
   }

   iWindowSize = (int)((pPre->iHighestIon)/iNumWindows) + 1;

   for (i=0; i<iNumWindows; i++)
   {
      dMaxWindowInten = 0.0;

      for (ii=0; ii<iWindowSize; ii++)    // Find max inten. in window.
      {
         iBin = i*iWindowSize+ii;
         if (iBin < pScoring->_spectrumInfoInternal.iArraySize)
         {
            if (pdTmpRawData[iBin] > dMaxWindowInten)
               dMaxWindowInten = pdTmpRawData[iBin];
         }
      }

      if (dMaxWindowInten > 0.0)
      {
         dTmp1 = 50.0 / dMaxWindowInten;
         dTmp2 = 0.05 * dMaxOverallInten;

         for (ii=0; ii<iWindowSize; ii++)    // Normalize to max inten. in window.
         {
            iBin = i*iWindowSize+ii;
            if (iBin < pScoring->_spectrumInfoInternal.iArraySize)
            {
               if (pdTmpRawData[iBin] > dTmp2)
                  pdTmpCorrelationData[iBin] = pdTmpRawData[iBin]*dTmp1;
            }
         }
      }
   }
}


// Smooth input data over 5 points.
bool CometPreprocess::Smooth(double *data,
                             int iArraySize,
                             double *pdTmpSmoothedSpectrum)
{
   int  i;

   data[0] = 0.0;
   data[1] = 0.0;
   data[iArraySize-1] = 0.0;
   data[iArraySize-2] = 0.0;

   for (i=2; i<iArraySize-2; i++)
   {
      // *0.0625 is same as divide by 16.
      pdTmpSmoothedSpectrum[i] = (data[i-2]+4.0*data[i-1]+6.0*data[i]+4.0*data[i+1]+data[i+2]) * 0.0625;
   }

   memcpy(data, pdTmpSmoothedSpectrum, iArraySize*sizeof(double));

   return true;
}


// Run 2 passes through to pull out peaks.
bool CometPreprocess::PeakExtract(double *data,
                                  int iArraySize,
                                  double *pdTmpPeakExtracted)
{
   int  i,
        ii,
        iStartIndex,
        iEndIndex;
   double dStdDev,
          dAvgInten;

   // 1st pass, choose only peak greater than avg + dStdDev.
   for (i=0; i<iArraySize; i++)
   {
      pdTmpPeakExtracted[i] = 0.0;
      dAvgInten = 0.0;

      iStartIndex = i-50;
      if (i-50 < 0)
         iStartIndex = 0;

      iEndIndex = i+50;
      if (i+50 > iArraySize-1)
         iEndIndex = iArraySize-1;

      for (ii=iStartIndex; ii<=iEndIndex; ii++)
         dAvgInten += (double)data[ii];
      dAvgInten /= iEndIndex-iStartIndex;

      dStdDev = 0.0;
      for (ii=iStartIndex; ii<=iEndIndex; ii++)
         dStdDev += (data[ii]-dAvgInten)*(data[ii]-dAvgInten);
      dStdDev = sqrt(dStdDev/(iEndIndex-iStartIndex+1));

      if ((i > 0) && (i < iArraySize-1))
      {
         if (data[i] > (dAvgInten+dStdDev))
         {
            pdTmpPeakExtracted[i] = data[i] - dAvgInten + dStdDev;
            data[i] = 0;     // Remove the peak before 2nd pass.
         }
      }
   }

   // 2nd pass, choose only peak greater than avg + 2*dStdDev.
   for (i=0; i<iArraySize; i++)
   {
      dAvgInten = 0.0;

      iStartIndex = i-50;
      if (i-50 < 0)
         iStartIndex = 0;

      iEndIndex = i+50;
      if (i+50 > iArraySize-1)
         iEndIndex = iArraySize-1;

      for (ii=iStartIndex; ii<=iEndIndex; ii++)
         dAvgInten += (double)data[ii];
      dAvgInten /= iEndIndex-iStartIndex;

      dStdDev = 0.0;
      for (ii=iStartIndex; ii<=iEndIndex; ii++)
         dStdDev += (data[ii]-dAvgInten)*(data[ii]-dAvgInten);
      dStdDev = sqrt(dStdDev/(iEndIndex-iStartIndex+1));

      if ((i > 0) && (i < iArraySize-1))
      {
         if (data[i] > (dAvgInten + 2*dStdDev))
            pdTmpPeakExtracted[i] = data[i] - dAvgInten + dStdDev;
      }
   }

   memcpy(data, pdTmpPeakExtracted, (size_t)iArraySize*sizeof(double));

   return true;
}


// Pull out top # ions for intensity matching in search.
void CometPreprocess::GetTopIons(map< int, double > *pdTmpRawData,
                                 struct msdata *pTmpSpData,
                                 int iArraySize)
{
   int  i,
        ii,
        iLowestIntenIndex=0;
   double dLowestInten=0.0,
          dMaxInten=0.0;

   map< int, double >::iterator it = pdTmpRawData->begin();

   for(it = pdTmpRawData->begin(); it != pdTmpRawData->end(); it++) {
	   if ((*pdTmpRawData)[it->first] > dLowestInten) {
		   (pTmpSpData+iLowestIntenIndex)->dIntensity = (double)(*pdTmpRawData)[it->first];
		   (pTmpSpData+iLowestIntenIndex)->dIon = (double)it->first;

         if ((pTmpSpData+iLowestIntenIndex)->dIntensity > dMaxInten)
            dMaxInten = (pTmpSpData+iLowestIntenIndex)->dIntensity;

         dLowestInten = (pTmpSpData+0)->dIntensity;
         iLowestIntenIndex = 0;

         for (ii=1; ii<NUM_SP_IONS; ii++)
         {
            if ((pTmpSpData+ii)->dIntensity < dLowestInten)
            {
               dLowestInten = (pTmpSpData+ii)->dIntensity;
               iLowestIntenIndex=ii;
            }
         }
	   }
   }
   /*
   for (i=0; i<iArraySize; i++)
   {
      if (pdTmpRawData[i] > dLowestInten)
      {
         (pTmpSpData+iLowestIntenIndex)->dIntensity = (double)pdTmpRawData[i];
         (pTmpSpData+iLowestIntenIndex)->dIon = (double)i;

         if ((pTmpSpData+iLowestIntenIndex)->dIntensity > dMaxInten)
            dMaxInten = (pTmpSpData+iLowestIntenIndex)->dIntensity;

         dLowestInten = (pTmpSpData+0)->dIntensity;
         iLowestIntenIndex = 0;

         for (ii=1; ii<NUM_SP_IONS; ii++)
         {
            if ((pTmpSpData+ii)->dIntensity < dLowestInten)
            {
               dLowestInten = (pTmpSpData+ii)->dIntensity;
               iLowestIntenIndex=ii;
            }
         }
      }
   }
   */
   if (dMaxInten > FLOAT_ZERO)
   {
      for (i=0; i<NUM_SP_IONS; i++)
         (pTmpSpData+i)->dIntensity = (((pTmpSpData+i)->dIntensity)/dMaxInten)*100.0;
   }
}


int CometPreprocess::QsortByIon(const void *p0, const void *p1)
{
   if ( ((struct msdata *) p1)->dIon < ((struct msdata *) p0)->dIon )
      return (1);
   else if ( ((struct msdata *) p1)->dIon > ((struct msdata *) p0)->dIon )
      return (-1);
   else
      return (0);
}


// Works on Sp data.
void CometPreprocess::StairStep(struct msdata *pTmpSpData)
{
   int  i,
        ii,
        iii;
   double dMaxInten,
          dGap;

   i=0;
   while (i < NUM_SP_IONS-1)
   {
      ii = i;
      dMaxInten = (pTmpSpData+i)->dIntensity;
      dGap = 0.0;

      while (dGap<=g_staticParams.tolerances.dFragmentBinSize && ii<NUM_SP_IONS-1)
      {
         ii++;
         dGap = (pTmpSpData+ii)->dIon - (pTmpSpData+ii-1)->dIon;

         // Finds the max intensity for adjacent points.
         if (dGap<=g_staticParams.tolerances.dFragmentBinSize)
         {
            if ((pTmpSpData+ii)->dIntensity > dMaxInten)
               dMaxInten = (pTmpSpData+ii)->dIntensity;
         }
      }

      // Sets the adjacent points to the dMaxInten.
      for (iii=i; iii<ii; iii++)
         (pTmpSpData+iii)->dIntensity = dMaxInten; 

      i = ii;
   }
}


//MH: This function allocates memory to be shared by threads for spectral processing
bool CometPreprocess::AllocateMemory(int maxNumThreads)
{
   int i;

   //MH: Must be equal to largest possible array
   int iArraySize = (int)((g_staticParams.options.dHighPeptideMass + 100.0) * g_staticParams.dInverseBinWidth);

   //MH: Initally mark all arrays as available (i.e. false=not inuse).
   pbMemoryPool = new bool[maxNumThreads];
   for (i=0; i<maxNumThreads; i++)
   {
      pbMemoryPool[i] = false;
   }

   //MH: Allocate arrays
   ppdTmpRawDataArr = new double*[maxNumThreads]();
   for (i=0; i<maxNumThreads; i++)
   {
      try
      {
         ppdTmpRawDataArr[i] = new double[iArraySize]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pdTmpRawData[%d]). bad_alloc: %s.", iArraySize, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }
   }

   //MH: Allocate arrays
   ppdTmpFastXcorrDataArr = new double*[maxNumThreads]();
   for (i=0; i<maxNumThreads; i++)
   {
      try
      {
         ppdTmpFastXcorrDataArr[i] = new double[iArraySize]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pdTmpFastXcorrData[%d]). bad_alloc: %s.", iArraySize, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }
   }

   //MH: Allocate arrays
   ppdTmpCorrelationDataArr = new double*[maxNumThreads]();
   for (i=0; i<maxNumThreads; i++)
   {
      try
      {
         ppdTmpCorrelationDataArr[i] = new double[iArraySize]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pdTmpCorrelationData[%d]). bad_alloc: %s.", iArraySize, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }
   }

   //MH: Allocate arrays
   ppdTmpSmoothedSpectrumArr = new double*[maxNumThreads]();
   for (i=0; i<maxNumThreads; i++)
   {
      try
      {
         ppdTmpSmoothedSpectrumArr[i] = new double[iArraySize]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pdTmpSmoothedSpectrum[%d]). bad_alloc: %s.", iArraySize, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }
   }

   //MH: Allocate arrays
   ppdTmpPeakExtractedArr = new double*[maxNumThreads]();
   for (i=0; i<maxNumThreads; i++)
   {
      try
      {
         ppdTmpPeakExtractedArr[i] = new double[iArraySize]();
      }
      catch (std::bad_alloc& ba)
      {
         char szErrorMsg[256];
         sprintf(szErrorMsg,  " Error - new(pdTmpSmoothedSpectrum[%d]). bad_alloc: %s.", iArraySize, ba.what());
         string strErrorMsg(szErrorMsg);
         g_cometStatus.SetStatus(CometResult_Failed, strErrorMsg);      
         logerr("%s\n\n", szErrorMsg);
         return false;
      }
   }

   return true;
}


//MH: Deallocates memory shared by threads during spectral processing.
bool CometPreprocess::DeallocateMemory(int maxNumThreads)
{
   int i;

   delete [] pbMemoryPool;

   for (i=0; i<maxNumThreads; i++)
   {
      delete [] ppdTmpRawDataArr[i];
      delete [] ppdTmpFastXcorrDataArr[i];
      delete [] ppdTmpCorrelationDataArr[i];
      delete [] ppdTmpSmoothedSpectrumArr[i];
      delete [] ppdTmpPeakExtractedArr[i];
   }

   delete [] ppdTmpRawDataArr;
   delete [] ppdTmpFastXcorrDataArr;
   delete [] ppdTmpCorrelationDataArr;
   delete [] ppdTmpSmoothedSpectrumArr;
   delete [] ppdTmpPeakExtractedArr;

   return true;
}
