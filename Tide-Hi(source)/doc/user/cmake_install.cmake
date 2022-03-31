# Install script for directory: /Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc" TYPE FILE FILES
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/barista-xml-format.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/barista.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/broken-link.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/bullseye.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/bullseye_standalone_to_crux.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/calibrate-scores.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet.params"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/compute-q-values.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/contributors.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-analyze-matches.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-create-index.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-faq.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-get-ms2-spectrum.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-predict-peptide-ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-print-processed-spectra.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-search-for-matches.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-search-for-xlinks.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux-sequest-search.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux.css"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/crux.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/customize-tutorial.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/d.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/data/demo.ms2"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/data/search.target.txt"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/data/small-yeast.fasta"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/data/target.sqt"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/default.params"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/demos/demo1.sh"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/extract-columns.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/extract-rows.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/fasta-format.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/features.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/generate-peptides.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/hardklor.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/hardklor_standalone_to_crux.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/install-tutorial.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/make-pin.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/ms2-format.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/ncrr.gif"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nibib.gif"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nigms_logo-vertical.jpg"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nigms_logo.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nsaf_pep_equation_a.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nsaf_pep_equation_b.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nsaf_prot_equation_a.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/nsaf_prot_equation_b.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/parameter-file.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/percolator.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/percolator_legacy.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/q-ranker.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/quant_empai_1.gif"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/release-notes.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/sample.fasta"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/schematic.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/schematic.pptx"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/search-tutorial.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/sin_pep_equation.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/sin_prot_equation.png"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/sort-by-column.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/spectacle-eg-input.txt"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/spectacle.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/spectral-counts-tutorial.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/spectral-counts.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/sqt-format.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/start-tutorial.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/stat-column.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/tide-index.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/tide-search.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/txt-format.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/UWlogo150p.gif"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/doc/comet-options" TYPE FILE FILES
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/activation_method.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_A_alanine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_B_user_amino_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_C_cysteine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Cterm_peptide.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Cterm_protein.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_D_aspartic_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_E_glutamic_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_F_phenylalanine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_G_glycine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_H_histidine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_I_isoleucine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_J_user_amino_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_K_lysine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_L_leucine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_M_methionine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_N_asparagine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Nterm_peptide.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Nterm_protein.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_O_ornithine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_P_proline.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Q_glutamine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_R_arginine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_S_serine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_T_threonine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_U_user_amino_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_V_valine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_W_tryptophan.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_X_user_amino_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Y_tyrosine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/add_Z_user_amino_acid.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/allowed_missed_cleavage.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/clear_mz_range.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/clip_nterm_methionine.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/combined.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/comet.params"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/content.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/convertCometPHPs.py"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/database_name.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/decoy_prefix.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/decoy_search.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/digest_mass_range.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/footer.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/fragment_bin_offset.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/fragment_bin_tol.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/head.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/index.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/isotope_error.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/mass_type_fragment.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/mass_type_parent.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/max_fragment_charge.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/max_precursor_charge.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/max_variable_mods_in_peptide.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/minimum_intensity.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/minimum_peaks.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/ms_level.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/nucleotide_reading_frame.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/num_enzyme_termini.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/num_output_lines.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/num_results.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/num_threads.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_outfiles.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_pepxmlfile.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_pinxmlfile.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_sqtfile.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_sqtstream.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_suffix.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/output_txtfile.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/peptide_mass_tolerance.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/peptide_mass_units.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/precursor_charge.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/precursor_tolerance_type.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/print_expect_score.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/remove_precursor_peak.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/remove_precursor_tolerance.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/runall"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/sample_enzyme_number.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/scan_range.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/search_enzyme_number.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/show_fragment_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/skip_researching.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/spectrum_batch_size.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/theoretical_fragment_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/topmenu.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_A_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_B_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_C_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_NL_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_X_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_Y_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_Z_ions.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/use_sparse_matrix.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_C_terminus.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_C_terminus_distance.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_N_terminus.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_N_terminus_distance.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_mod1.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_mod2.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_mod3.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_mod4.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_mod5.html"
    "/Users/cegrant/buildAgent/work/c70208095d909cbb/doc/user/comet-options/variable_mod6.html"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

