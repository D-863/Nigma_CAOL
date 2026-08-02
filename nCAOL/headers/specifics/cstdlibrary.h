#ifndef NIGMA_CAOL_SPECIFICS_CSTDLIBRARY_H
#define NIGMA_CAOL_SPECIFICS_CSTDLIBRARY_H


#include "compiler.h"
#include "ID/cstdlibrary.h"

//COMPILER specific identifications:
#if (defined(NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE) == 0)
    #if ((NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MicrosoftVisualCPP) || \
         (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MinGW32)            || \
         (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MinGWw64_32B)       || \
         (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MinGWw64_64B)          \
        )
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_WINDOWS
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS
    #endif
#endif

#if defined(NCAOL_SPECS_CSTDLIB_DEF_LIB_ID)
    #if (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_Bare)
        #error "nCAOL: Apologizes, but both Nigma and D_863 have yet too implemented all the necessities required for a Application to properly Compile and Execute just upon the Kernel itself, may you be patient!"
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic)
        #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_glibc)
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_klibc)
        #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc)
        #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib)
        #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_MUSLLIBC)
        #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_MACOSX)
    #elif (NCAOL_SPECS_CSTDLIB_DEF_LIB_ID == NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS)
    #endif
#else
    #error "nCAOL: Apologizes, but it seems like the utilized C-Standard Library was not detectable! Due to various reasons, it's possible and even recommended too manually specify such by defining 'NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE' with 'NCAOL_SPECS_CSTDLIB_VAL_ID_' within 'enables.h'; If your utilized C standard library is not one of the possible 'NCAOL_SPECS_CSTDLIB_VAL_ID_' values, please do feel free to send a request if you have the spare time."
#endif


#endif
