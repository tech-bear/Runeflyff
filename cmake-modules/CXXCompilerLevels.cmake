INCLUDE(CheckCXXCompilerFlag)

IF (MSVC)
    INCLUDE(MSVCCXXLevels)
ELSE()
    INCLUDE(GNUCXXLevels)
ENDIF()