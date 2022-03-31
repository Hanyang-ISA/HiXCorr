# Install script for directory: /Users/cegrant/buildAgent/work/c70208095d909cbb/src/c

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/crux")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./bullseye"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./hardklor"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./qranker-barista"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./xlink"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/build/src/percolator-build/src"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/build/src/percolator-build/src/fido"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/opt/local/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/crux")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/xlink-score-spectrum")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./bullseye"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./hardklor"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./qranker-barista"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./xlink"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/build/src/percolator-build/src"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/build/src/percolator-build/src/fido"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/opt/local/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-score-spectrum")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/xlink-assign-ions")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./bullseye"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./hardklor"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./qranker-barista"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/./xlink"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/build/src/percolator-build/src"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/cegrant/buildAgent/work/c70208095d909cbb/src/external/build/src/percolator-build/src/fido"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/opt/local/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xlink-assign-ions")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/bullseye/cmake_install.cmake")
  INCLUDE("/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/hardklor/cmake_install.cmake")
  INCLUDE("/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/qranker-barista/cmake_install.cmake")
  INCLUDE("/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/xlink/cmake_install.cmake")
  INCLUDE("/Users/cegrant/buildAgent/work/c70208095d909cbb/src/c/tide/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

