INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_CPPTUTORIAL cpptutorial)

FIND_PATH(
    CPPTUTORIAL_INCLUDE_DIRS
    NAMES cpptutorial/api.h
    HINTS $ENV{CPPTUTORIAL_DIR}/include
        ${PC_CPPTUTORIAL_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    CPPTUTORIAL_LIBRARIES
    NAMES gnuradio-cpptutorial
    HINTS $ENV{CPPTUTORIAL_DIR}/lib
        ${PC_CPPTUTORIAL_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CPPTUTORIAL DEFAULT_MSG CPPTUTORIAL_LIBRARIES CPPTUTORIAL_INCLUDE_DIRS)
MARK_AS_ADVANCED(CPPTUTORIAL_LIBRARIES CPPTUTORIAL_INCLUDE_DIRS)
