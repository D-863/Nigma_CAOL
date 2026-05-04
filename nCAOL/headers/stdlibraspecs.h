#ifndef NIGMA_CAOL_STDLIBRASPECS_H
#define NIGMA_CAOL_STDLIBRASPECS_H

#include "osspecifics.h"

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
*/
#define CAOL_STDLIBRASPECS_DEF_LIBID_Bionic 0
#define CAOL_STDLIBRASPECS_DEF_LIBID_glibc  1
#define CAOL_STDLIBRASPECS_DEF_LIBID_klibc  3
#define CAOL_STDLIBRASPECS_DEF_LIBID_uClibc 2
#define CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib 3

#define CAOL_STDLIBRASPECS_DEF_LIBNAME_Bionic "Bionic"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_glibc  "glibc"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_klibc  "klibc"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_uClibc "uClibc"
#define CAOL_STDLIBRASPECS_DEF_LIBNAME_zOSlib "zOSlib"

#if defined(__BIONIC__)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_Bionic
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_Bionic
#elif ((defined(__GNU_LIBRARY__) || defined(__GNU_LIBRARY_MINOR__)) || \
       (defined(__GLIBC__)       || defined(__GLIBC_MINOR__)) \
    )
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_glibc
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_glibc
#elif defined(__KLIBC__)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_klibc
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_klibc
#elif defined(__UCLIBC__)
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_uClibc
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_uClibc
#elif (defined(__LIBREL__) || defined(__TARGET_LIB__))
    #error "nCAOL: Apologizes, but while this C standard library is supported, it has yet to be fully implemented."
    #define CAOL_STDLIBRASPECS_DEF_LIB_ID CAOL_STDLIBRASPECS_DEF_LIBID_zOSlib
    #define CAOL_STDLIBRASPECS_DEF_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIBNAME_zOSlib
#else
    #error "nCAOL: Apologizes, but it seems like the utilized C standard library is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

#define caolSTDLibraspecs(t, ...) CAOL_STDLIBRASPECS_INTER_##t(__VA_ARGS__)
#define CAOL_STDLIBRASPECS_INTER_LIB(t) CAOL_STDLIBRASPECS_INTER_LIB_##t
#define CAOL_STDLIBRASPECS_INTER_LIB_NAME CAOL_STDLIBRASPECS_DEF_LIB_NAME
#define CAOL_STDLIBRASPECS_INTER_LIB_ID   CAOL_STDLIBRASPECS_DEF_LIB_ID

#endif