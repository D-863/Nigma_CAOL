#ifndef NIGMA_CAOL_STDLIBRASPECS_H
#define NIGMA_CAOL_STDLIBRASPECS_H

#include "compilics.h"

/*Standard Library-Specific identifications:
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
//The order of these shall not change, as 'enables.h' cannot access them despite being possibly required too.
#define CAOL_STDLIBRASPECS_DEF_LIBID_Bionic  0
#define CAOL_STDLIBRASPECS_DEF_LIBID_glibc   1
#define CAOL_STDLIBRASPECS_DEF_LIBID_klibc   2
#define CAOL_STDLIBRASPECS_DEF_LIBID_uClibc  3
#define CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib  4
#define CAOL_STDLIBRASPECS_DEF_LIBID_WINDOWS 5

#define CAOL_STDLIBRASPECS_DEF_LIBNAME_Bionic  "Bionic"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_glibc   "glibc"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_klibc   "klibc"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_uClibc  "uClibc"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_zOSlib  "zOSlib"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_WINDOWS "WINDOWS"

#if (defined(CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE) == 0)
    #if defined(__BIONIC__)
        #define CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE CAOL_STDLIBRASPECS_DEF_LIBID_Bionic
    #elif (defined(__GNU_LIBRARY__) || defined(__GLIBC__))
        #define CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE CAOL_STDLIBRASPECS_DEF_LIBID_glibc
    #elif defined(__KLIBC__)
        #define CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE CAOL_STDLIBRASPECS_DEF_LIBID_klibc
    #elif defined(__UCLIBC__)
        #define CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE CAOL_STDLIBRASPECS_DEF_LIBID_uClibc
    #elif (defined(__LIBREL__) || defined(__TARGET_LIB__))
        #define CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib
    #elif ((caolCompilifics(CURRENT, COMPILER, ID) == caolCompilifics(COMPILER, ID, MicrosoftVisualCPP)) || \
           (caolCompilifics(CURRENT, COMPILER, DOMAIN) == caolCompilifics(COMPILER, DOMAIN, MinGW))         \
        )
        #define CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE CAOL_STDLIBRASPECS_DEF_LIBID_WINDOWS
    #else
        #error "nCAOL: Apologizes, but it seems like the utilized C standard library was not detectable! Due to various reasons, it's possible and even recommended too manually specify such by defining 'CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE' within 'enables.h'; If your utilized C standard library is not one of the possible 'CAOL_STDLIBRASPECS_DEF_LIBID_' values, please do feel free to send a request if you have the spare time."
    #endif
#endif

#if (CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE == CAOL_STDLIBRASPECS_DEF_LIBID_Bionic)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_Bionic
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_Bionic
    #include <sys/types.h>
#elif (CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE == CAOL_STDLIBRASPECS_DEF_LIBID_glibc)
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_glibc
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_glibc

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
#elif (CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE == CAOL_STDLIBRASPECS_DEF_LIBID_klibc)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_klibc
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_klibc
    #include <sys/types.h>
#elif (CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE == CAOL_STDLIBRASPECS_DEF_LIBID_uClibc)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_uClibc
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_uClibc
    #include <sys/types.h>
#elif (CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE == CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_zOSlib
    #include <sys/types.h>
#elif (CAOL_ENABLES_EXPLICITLY_UTILIZE_THIS_C_STANDARD_LIBRARY_TYPE == CAOL_STDLIBRASPECS_DEF_LIBID_WINDOWS)
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_WINDOWS
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_WINDOWS
    #include <sys/types.h>
#else
    #error "nCAOL: Apologizes, but it seems like the utilized C standard library is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

#define caolSTDLibraspecs(t, ...) CAOL_STDLIBRASPECS_INTER_##t(__VA_ARGS__)
#define CAOL_STDLIBRASPECS_INTER_LIB(t, ...) CAOL_STDLIBRASPECS_INTER_LIB_##t(__VA_ARGS__)
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME(t) CAOL_STDLIBRASPECS_INTER_LIB_NAME_##t
#define CAOL_STDLIBRASPECS_INTER_LIB_ID(t) CAOL_STDLIBRASPECS_INTER_LIB_ID_##t

#define CAOL_STDLIBRASPECS_INTER_LIB_NAME_Bionic  CAOL_STDLIBRASPECS_DEF_LIBNAME_Bionic
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME_glibc   CAOL_STDLIBRASPECS_DEF_LIBNAME_glibc
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME_klibc   CAOL_STDLIBRASPECS_DEF_LIBNAME_klibc
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME_uClibc  CAOL_STDLIBRASPECS_DEF_LIBNAME_uClibc
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME_zOSlib  CAOL_STDLIBRASPECS_DEF_LIBNAME_zOSlib
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME_WINDOWS CAOL_STDLIBRASPECS_DEF_LIBNAME_WINDOWS

#define CAOL_STDLIBRASPECS_INTER_LIB_ID_Bionic  CAOL_STDLIBRASPECS_DEF_LIBID_Bionic
#define CAOL_STDLIBRASPECS_INTER_LIB_ID_glibc   CAOL_STDLIBRASPECS_DEF_LIBID_glibc
#define CAOL_STDLIBRASPECS_INTER_LIB_ID_klibc   CAOL_STDLIBRASPECS_DEF_LIBID_klibc
#define CAOL_STDLIBRASPECS_INTER_LIB_ID_uClibc  CAOL_STDLIBRASPECS_DEF_LIBID_uClibc
#define CAOL_STDLIBRASPECS_INTER_LIB_ID_zOSlib  CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib
#define CAOL_STDLIBRASPECS_INTER_LIB_ID_WINDOWS CAOL_STDLIBRASPECS_DEF_LIBID_WINDOWS


#define CAOL_STDLIBRASPECS_INTER_CURRENT(t, ...) CAOL_STDLIBRASPECS_INTER_CURRENT_##t(__VA_ARGS__)
#define CAOL_STDLIBRASPECS_INTER_CURRENT_LIB(t) CAOL_STDLIBRASPECS_INTER_CURRENT_LIB_##t
#define CAOL_STDLIBRASPECS_INTER_CURRENT_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIB_NAME
#define CAOL_STDLIBRASPECS_INTER_CURRENT_LIB_ID   CAOL_STDLIBRASPECS_DEF_LIB_ID

#endif