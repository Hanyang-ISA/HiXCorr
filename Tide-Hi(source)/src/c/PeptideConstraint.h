/**
 * \file peptide_constraint.h 
 * $Revision: 1.5 $
 * \brief Object for holding the peptide constraint information.
 */
#ifndef PEPTIDE_CONSTRAINT_H 
#define PEPTIDE_CONSTRAINT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "crux-utils.h"
#include "objects.h"
#include "mass.h"
#include "Peptide.h"
#include "Protein.h"
#include "carp.h"

/**
 * \class PeptideConstraint
 * \brief Object to represent constraints which a peptide may or may not
 *  satisfy.
 *
 * def TRYPTIC: a protein that ends with either K or R and 
 *              any other K and R in the sequence must be followed by a P
 */
class PeptideConstraint {
 protected:
  ENZYME_T enzyme_;
  DIGEST_T digestion_;
  FLOAT_T min_mass_; ///< The minimum mass of the peptide
  FLOAT_T max_mass_; ///< The maximum mass of the peptide
  int min_length_; ///< The minimum length of the peptide
  int max_length_; ///< The maximum length of the peptide
  int num_mis_cleavage_; ///< The maximum mis cleavage of the peptide
  MASS_TYPE_T mass_type_; ///< isotopic mass type (AVERAGE, MONO)
  int num_pointers_; ///< Number of pointers to this constraint

 public:
  
  void init();

  /**
   * Allocates a new (empty) peptide_constraint object.
   * \returns An allocated PeptideConstraint object.
   */
  PeptideConstraint();

  /**
   * Instantiates a new peptide_constraint object.
   * \returns An allocated PEPTIDE_CONSTRAINT_T object.
   */
  PeptideConstraint(
    ENZYME_T enzyme, ///< the enzyme to use for digestion
    DIGEST_T digest, ///< the degree of digestion
    FLOAT_T min_mass, ///< the minimum mass -in
    FLOAT_T max_mass, ///< the maximum mass -in
    int min_length, ///< the minimum length of peptide -in
    int max_length, ///< the maximum lenth of peptide -in
    int num_mis_cleavage, ///< The maximum mis cleavage of the peptide -in
    MASS_TYPE_T mass_type  ///< isotopic mass type (AVERAGE, MONO) -in
    );

  /**
   * \brief Create a new peptide constraint and populate its values
   * based on those in parameter.c 
   * \returns A newly allocated peptide constraint.
   */
  static PeptideConstraint* newFromParameters();

  /** 
   * Determines if a peptide satisfies a peptide_constraint.
   * \returns TRUE if the constraint is satisified. FALSE if not.
   */
  bool isSatisfied(
   Crux::Peptide* peptide ///< the query peptide -in   
   );

  /**
   * Copies an allocated peptide_constraint object.
   */
  static PeptideConstraint* copyPtr(
    PeptideConstraint* peptide_constraint ///< object to copy -in 
  );

  /**
   * Frees an allocated peptide_constraint object.
   */
  static void free(PeptideConstraint*);
  virtual ~PeptideConstraint();

  /**
   * Setters/Getters
   */
  
  void setEnzyme(
    ENZYME_T enzyme
  );

  ENZYME_T getEnzyme();


  void setDigest(
    DIGEST_T digest
  );

  DIGEST_T getDigest();

  /**
   * sets the min mass of the peptide_constraint
   */
  void setMinMass(
    FLOAT_T min_mass  ///< the min mass of the peptide constraint - in
    );

  /**
   * \returns the min mass of the peptide_constraint
   */
  FLOAT_T getMinMass();

  /**
   * sets the max mass of the peptide_constraint
   */
  void setMaxMass(
    FLOAT_T max_mass  ///< the max mass of the peptide constraint - in
    );

  /**
   * \returns the max mass of the peptide_constraint
   */
  FLOAT_T getMaxMass();

  /**
   * sets the min length of the peptide_constraint
   */
  void setMinLength(
    int min_length  ///< the min length of the peptide constraint - in
    );

  /**
   * \returns the min length of the peptide_constraint
   */
  int getMinLength();

  /**
   * sets the max length of the peptide_constraint
   */
  void setMaxLength(
    int max_length  ///< the max length of the peptide constraint - in
    );

  /**
   * \returns the max length of the peptide_constraint
   */
  int getMaxLength();

  /**
   * sets the num_mis_cleavage of the peptide_constraint
   */
  void setNumMisCleavage(
    int num_mis_cleavage ///< The maximum mis cleavage of the peptide -in
  );

  /**
   * \returns the num_mis_cleavage of the peptide_constraint
   */
  int getNumMisCleavage();

  /**
   * sets the mass type of the peptide_constraint
   */
  void setMassType(
    MASS_TYPE_T mass_type ///< the peptide_type for the constraint -in
    );

  /**
   * \returns the mass type of the mass_constraint
   */
  MASS_TYPE_T getMassType();

};

#endif

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 2
 * End:
 */
