#ifndef NIGMA_CAOL_SPECIFICS_CSTDLIBRARY_H
#define NIGMA_CAOL_SPECIFICS_CSTDLIBRARY_H

#include "compiler.h"
#include "values/cstdlibrary.h"

/*C-Standard Library-Specific identifications:
Bare:
    Upon every other identifier bellow being nonexistent; ((defined(...) || ...) == 0)

Bionic:
    __BIONIC__

GNU glibc:
    Prior Version 6:
        __GNU_LIBRARY__
        __GNU_LIBRARY_MINOR__
    Version 6:
        __GLIBC__
        __GLIBC_MINOR__

klibc:
    __KLIBC__

uClibc:
    __UCLIBC__

z/OS libc:
    Host:
        __LIBREL__
    Target:
        __TARGET_LIB__

WINDOWS:
    Not actual Library for MSVCRT or UCRT,
    but Micrsoft is so terrible with Documentation,
    that I do not give a frick after 5 *HOURS*..
*/
#if (defined(NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE) == 0)
    #if defined(__BIONIC__)
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic
    #elif (defined(__GNU_LIBRARY__) || defined(__GLIBC__))
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_glibc
    #elif defined(__KLIBC__)
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_klibc
    #elif defined(__UCLIBC__)
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc
    #elif (defined(__LIBREL__) || defined(__TARGET_LIB__))
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib
    #elif ((caolCompilifics(CURRENT, COMPILER, ID) == caolCompilifics(COMPILER, ID, MicrosoftVisualCPP)) || \
           (caolCompilifics(CURRENT, COMPILER, DOMAIN) == caolCompilifics(COMPILER, DOMAIN, MinGW))         \
        )
        #define NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS
    #else
        #error "nCAOL: Apologizes, but it seems like the utilized C standard library was not detectable! Due to various reasons, it's possible and even recommended too manually specify such by defining 'NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE' with 'NCAOL_SPECS_CSTDLIB_VAL_ID_' within 'enables.h'; If your utilized C standard library is not one of the possible 'NCAOL_SPECS_CSTDLIB_VAL_ID_' values, please do feel free to send a request if you have the spare time."
    #endif
#endif

#if (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_Bare)
    #error "nCAOL: Apologizes, but both Nigma and D_863 have yet too implemented all the necessities required for a Application to properly Compile and Execute just upon the Kernel itself, may you be patient!"
#elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_Bionic
    #include <sys/types.h>
#elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_glibc)
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_glibc
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_glibc

    //System-specific C standard headers.
    #if (caolStandilics(STD, ID, C90) <= caolStandilics(CURRENT, STD, ID))
        #include <assert.h>
        #include <signal.h>
        #include <stdlib.h>
        #include <ctype.h>
        #include <locale.h>
        #include <stdarg.h>
        #include <string.h>
        #include <errno.h>
        #include <math.h>
        #include <stddef.h>
        #include <time.h>
        #include <float.h>
        #include <setjmp.h>
        #include <stdio.h>
    #endif
    #if (caolStandilics(STD, ID, C95) <= caolStandilics(CURRENT, STD, ID))
        #include <iso646.h>
        #include <wchar.h>
        #include <wctype.h>
    #endif
    #if (caolStandilics(STD, ID, C99) <= caolStandilics(CURRENT, STD, ID))
        #include <complex.h>
        #include <inttypes.h>
        #include <stdint.h>
        #include <tgmath.h>
        #include <fenv.h>
        #include <stdbool.h>
    #endif
    #if (caolStandilics(STD, ID, C11) <= caolStandilics(CURRENT, STD, ID))
        #include <stdalign.h>
        #include <stdatomic.h>
        #include <stdnoreturn.h>
        #include <threads.h>
        #include <uchar.h>
    #endif
    #if (caolStandilics(STD, ID, C23) <= caolStandilics(CURRENT, STD, ID))
        #include <stdbit.h>
        #include <stdckdint.h>
    #endif
#elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_klibc)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_klibc
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_klibc
    #include <sys/types.h>
#elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_uClibc
    #include <sys/types.h>
#elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_zOSlib
    #include <sys/types.h>
#elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS)
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS
    #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_WINDOWS
    #include <sys/types.h>
#else
    #error "nCAOL: Apologizes, but it seems like the utilized C standard library is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

#define caolSTDLibraspecs(t, ...) NCAOL_SPECS_CSTDLIB_INTER_##t(__VA_ARGS__)
#define NCAOL_SPECS_CSTDLIB_INTER_LIB(t, ...) NCAOL_SPECS_CSTDLIB_INTER_LIB_##t(__VA_ARGS__)
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME(t) NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_##t
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID(t) NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_##t

#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_Bionic  NCAOL_SPECS_CSTDLIB_VAL_NAME_Bionic
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_glibc   NCAOL_SPECS_CSTDLIB_VAL_NAME_glibc
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_klibc   NCAOL_SPECS_CSTDLIB_VAL_NAME_klibc
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_uClibc  NCAOL_SPECS_CSTDLIB_VAL_NAME_uClibc
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_zOSlib  NCAOL_SPECS_CSTDLIB_VAL_NAME_zOSlib
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_NAME_WINDOWS NCAOL_SPECS_CSTDLIB_VAL_NAME_WINDOWS

#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_Bionic  NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_glibc   NCAOL_SPECS_CSTDLIB_VAL_ID_glibc
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_klibc   NCAOL_SPECS_CSTDLIB_VAL_ID_klibc
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_uClibc  NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_zOSlib  NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib
#define NCAOL_SPECS_CSTDLIB_INTER_LIB_ID_WINDOWS NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS


#define NCAOL_SPECS_CSTDLIB_INTER_CURRENT(t, ...) NCAOL_SPECS_CSTDLIB_INTER_CURRENT_##t(__VA_ARGS__)
#define NCAOL_SPECS_CSTDLIB_INTER_CURRENT_LIB(t) NCAOL_SPECS_CSTDLIB_INTER_CURRENT_LIB_##t
#define NCAOL_SPECS_CSTDLIB_INTER_CURRENT_LIB_NAME NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME
#define NCAOL_SPECS_CSTDLIB_INTER_CURRENT_LIB_ID   NCAOL_SPECS_CSTDLIB_DEF_LIB_ID

#endif