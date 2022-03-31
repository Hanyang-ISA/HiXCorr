# HiXCorr
We compared Tide-Hi and Comet-Hi, where our HiXCorr implementation is implanted, with the previous implementations of Tide-C, Tide-x86 and Comet-Sparse. (Since the original Comet-Sparse modifies the mass resolution into 0.01 if the input mass resolution is higher than 0.01 such as 0.005, we disabled the modification to run it with higher resolutions than 0.01.) These comparison data were achieved on a machine with an Intel Core i7-3770K CPU (3.50 GHz) and 32GB RAM under the CentOS 6.6 operating system. The MS/MS Data were downloaded from the Clinical Proteomic Tumor Analysis Consortium (NCI/NIH) data portal.

Tide-Hi and Comet-Hi binaries can be downloaded and executed as described below. They require Linux OS (64-bit) or Windows (64-bit) on x86 CPU and at least 2 GB memory. If you can access both Linux and Windows machines, the binaries for Linux are recommended. 

# Usage
### Tide-Hi (Linux)
1. Download Tide-Hi.zip and SampleData.zip (173MB) in the same folder and unzip them.
2. "chmod 755 Tide-Hi"
3. Usage: "./Tide-Hi tide-index --decoy-format none SampleDB.fasta SampleDB-index"
4. Usage: "./Tide-Hi tide-search --precursor-window 10 --precursor-window-type ppm --mz-bin-width 0.01 Sample.mzML SampleDB-index"
### Comet-Hi (Linux)
1. Download Comet-Hi.zip and SampleData.zip (173MB) in the same folder and unzip them.
2. "chmod 755 Comet-Hi.exe"
3. Usage: "./Comet-Hi.exe Sample.mzML"
### Tide-Hi (Windows)
1. Download Tide-Hi(win).zip and SampleData.zip (173MB) in the same folder and unzip them.
2. Usage: "Tide-Hi.exe tide-index --decoy-format none SampleDB.fasta SampleDB-index"
3. Usage: "Tide-Hi.exe tide-search --precursor-window 10 --precursor-window-type ppm --mz-bin-width 0.01 Sample.mzML SampleDB-index"
### Comet-Hi (Windows)
1. Download Comet-Hi(Cygwin, Visual).zip and SampleData.zip (173MB) in the same folder and unzip them.<br>
※ Cygwin is compiled by gcc with Cygwin64 and Visual by Visual Studio 2013. According to our tests, Cygwin performs better on Windows 7 and Visual performs better on Windows 8.x. However, we recommend you should test both on your system to find a better one.
2. Usage: "Comet-Hi.exe Sample.mzML"
