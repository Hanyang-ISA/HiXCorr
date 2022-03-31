#include <limits>
#include "../carp.h"
#include "mass_constants.h"
#include "header.pb.h"
#include "stdio.h"

using namespace std;

#ifdef _MSC_VER
// The windows compiler only allows intialization
// of static constant integer types within a class
double const MassConstants::proton = 1.00727646688;
//  double const MassConstants::bin_width = 1.0005079;
double const MassConstants::kFixedPointScalar = 1e5;
#endif

const double MassConstants::elts_mono[] = {
	1.007825035, // H
	12.0,        // C
	14.003074,   // N
	15.99491463, // O
	30.973762,   // P
	31.9720707   // S
};

const double MassConstants::elts_avg[] = {
	1.00794,    // H
	12.0107,    // C
	14.0067,    // N
	15.9994,    // O
	30.973761,  // P
	32.065      // S
};

double MassConstants::mono_table[256];
double MassConstants::avg_table[256];
//double* MassConstants::aa_mass_table = NULL;
//double MassConstants::aa_bin_1[256];
//double MassConstants::aa_bin_2[256];

const double MassConstants::mono_h2o = 2*MassConstants::elts_mono[0] + MassConstants::elts_mono[3];
const double MassConstants::avg_h2o = 2*MassConstants::elts_avg[0] + MassConstants::elts_avg[3];
const double MassConstants::mono_nh3 = 3*MassConstants::elts_mono[0] + MassConstants::elts_mono[2];
const double MassConstants::mono_co = MassConstants::elts_mono[1] + MassConstants::elts_mono[3];
const double MassConstants::A = 0 - 28.0;
//const double MassConstants::B_H2O = 0 - MassConstants::mono_h2o;
//const double MassConstants::B_NH3 = 0 - MassConstants::mono_nh3;
const double MassConstants::B = 0.0;
//const double MassConstants::Y_H2O = MassConstants::mono_h2o - 18.0;
//const double MassConstants::Y_NH3 = MassConstants::mono_h2o - 17.0;
const double MassConstants::Y = MassConstants::mono_h2o;
/*const double MassConstants::BIN_SHIFT_A_ION_CHG_1 = 28;
const double MassConstants::BIN_SHIFT_A_ION_CHG_2 = 14;
const double MassConstants::BIN_SHIFT_H2O_CHG_1 = 18;
const double MassConstants::BIN_SHIFT_H2O_CHG_2 = 9;
const double MassConstants::BIN_SHIFT_NH3_CHG_1 = 17;
const double MassConstants::BIN_SHIFT_NH3_CHG_2_CASE_A = 9;
const double MassConstants::BIN_SHIFT_NH3_CHG_2_CASE_B = 8;
*/
double MassConstants::BIN_H2O = 18;
double MassConstants::BIN_NH3 = 17;


//default parameter settings, will be changed during parameter parsing
double MassConstants::bin_width_ = BIN_WIDTH; // 1.0005079;
double MassConstants::bin_offset_ = BIN_OFFSET; //0.40;

FixPt MassConstants::fixp_mono_table[256];
FixPt MassConstants::fixp_avg_table[256];

const FixPt MassConstants::fixp_mono_h2o = ToFixPt(MassConstants::mono_h2o);
const FixPt MassConstants::fixp_avg_h2o  = ToFixPt(MassConstants::avg_h2o);
const FixPt MassConstants::fixp_mono_nh3 = ToFixPt(MassConstants::mono_nh3);
const FixPt MassConstants::fixp_mono_co  = ToFixPt(MassConstants::mono_co);
const FixPt MassConstants::fixp_proton   = ToFixPt(MassConstants::proton);

ModCoder MassConstants::mod_coder_;
double* MassConstants::unique_deltas_;
//double* MassConstants::unique_deltas_bin_;

static bool CheckModTable(const pb::ModTable& mod_table);

void MassConstants::FillMassTable(const double* elements, double* table) {
	const double* e = elements;
	double H = e[0], C = e[1], N = e[2], O = e[3], P = e[4], S = e[5];

	for (int i = 0; i < 256; ++i)
		table[i] = numeric_limits<double>::signaling_NaN();

	table['A'] = C*3  + H*5  + N   + O       ;
	table['C'] = C*3  + H*5  + N   + O   + S ;
	table['D'] = C*4  + H*5  + N   + O*3     ;
	table['E'] = C*5  + H*7  + N   + O*3     ;
	table['F'] = C*9  + H*9  + N   + O       ;
	table['G'] = C*2  + H*3  + N   + O       ;
	table['H'] = C*6  + H*7  + N*3 + O       ;
	table['I'] = C*6  + H*11 + N   + O       ;
	table['K'] = C*6  + H*12 + N*2 + O       ;
	table['L'] = C*6  + H*11 + N   + O       ;
	table['M'] = C*5  + H*9  + N   + O   + S ;
	table['N'] = C*4  + H*6  + N*2 + O*2     ;
	table['P'] = C*5  + H*7  + N   + O       ;
	table['Q'] = C*5  + H*8  + N*2 + O*2     ;
	table['R'] = C*6  + H*12 + N*4 + O       ;
	table['S'] = C*3  + H*5  + N   + O*2     ;
	table['T'] = C*4  + H*7  + N   + O*2     ;
	table['V'] = C*5  + H*9  + N   + O       ;
	table['W'] = C*11 + H*10 + N*2 + O       ;
	table['Y'] = C*9  + H*9  + N   + O*2     ;

	table['w'] =        H*2        + O       ; // water
	table['a'] =        H*3  + N             ; // ammonia
	table['c'] = C                 + O       ; // carbon monoxide
}


bool MassConstants::Init(const pb::ModTable* mod_table, const double bin_width, const double bin_offset) {
	if (mod_table && !CheckModTable(*mod_table))
		return false;

	for (int i = 0; i < 256; ++i)
		mono_table[i] = avg_table[i] = 0;

	FillMassTable(elts_mono, mono_table);
	FillMassTable(elts_avg, avg_table);

	if (mod_table) {
		// TODO: consider handling average and monoisotopic masses
		// differently (e.g. with different mod tables). We're deferring
		// this for now, since we haven't sorted out how to handle average
		// vs. monoisotopic masses generally.
		for (int i = 0; i < mod_table->static_mod_size(); ++i) {
			char aa = mod_table->static_mod(i).amino_acids()[0];
			double delta = mod_table->static_mod(i).delta();
			mono_table[aa] += delta;
			avg_table[aa] += delta;
		}
		carp(CARP_DEBUG, "Number of unique modification masses: %d\n", mod_table->unique_deltas_size());

		mod_coder_.Init(mod_table->unique_deltas_size());
		unique_deltas_ = new double[mod_table->unique_deltas_size()];
		for (int i = 0; i < mod_table->unique_deltas_size(); ++i) {
			unique_deltas_[i] = mod_table->unique_deltas(i);
		}
	}

	for (int i = 0; i < 256; ++i) {
		if (mono_table[i] == 0) {
			mono_table[i] = avg_table[i]/* = aa_bin_1[i] = aa_bin_2[i]*/
			= numeric_limits<double>::signaling_NaN();
			fixp_mono_table[i] = fixp_avg_table[i] = 0;
		} else {
			fixp_mono_table[i] = ToFixPt(mono_table[i]);
			fixp_avg_table[i] = ToFixPt(avg_table[i]);
		}
	}
	bin_width_ = bin_width;
	bin_offset_ = bin_offset;
	BIN_H2O = mass2bin(mono_h2o,1);
	BIN_NH3 = mass2bin(mono_nh3,1);

	return true;
}

static bool CheckModification(const pb::Modification& mod,
	bool* repeats = NULL) {
		string aa_str = mod.amino_acids();
		if (aa_str.length() != 1)
			return false;
		char aa = aa_str[0];
		const char* AA = "ACDEFGHIKLMNPQRSTVWY";
		for (; (*AA != '\0') && (*AA != aa); ++AA); // find aa in AA
		if (*AA == '\0')
			return false;
		if (repeats != NULL) {
			if (repeats[aa])
				return false;
			repeats[aa] = true;
		}
		return true;
}

static bool CheckModTable(const pb::ModTable& mod_table) {
	// static mods table should not have repeated amino acids
	bool repeats[256];
	for (int i = 0; i < 256; ++i)
		repeats[i] = false;
	for (int i = 0; i < mod_table.static_mod_size(); ++i)
		if (!CheckModification(mod_table.static_mod(i), repeats))
			return false;

	return true;
}
