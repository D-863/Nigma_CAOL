#ifndef NIGMA_CAOL_SPECIFICS_ID_CSTDLIBRARY_H
#define NIGMA_CAOL_SPECIFICS_ID_CSTDLIBRARY_H


#include "values/cstdlibrary.h"

/*C-Standard Library-Specific identifications:
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

/*Explicit C-Standard Library identifications:
Bare:
    (NOT YET IMPLEMENTED)
    Makes use of all the necessities required for a Application to properly Compile and Execute just upon the Kernel itself.

MUSLLIBC:
    A identifier for the musl libc but instead a identifier,
    because while their reasoning(https://openwall.com/lists/musl/2013/03/29/13) is understandable,
    this is the exact non-throwable case where such a simple identifier resolves what the very nature of silent binary loading causes;
        Is the bug or feature in your code or the dependency itself? No one knows beyond assembly debugging!..
        Want to make your code portable by single-pass automation? To bad, either manual inqury or bootstrapping it is!

    But of course, I have no say on such beyond technical critique - This is musl libc, not nMusl. :p

MACOSX:
    Not actual a Library for libSystem but instead a identifier,
    because MacOS X had the grand idea to make libSystem's path virtual and hence a runtime exclusive check,
    and for what my cognition is aware there is no identifier..

WINDOWS:
    Not actual a Library-Specific identifier for MSVCRT or UCRT but instead a explicit identifier,
    because Micrsoft is so terrible with Documentation,
    that I do not give a frick after 5 *HOURS*..
*/


//Generic and Explicit identifications:
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
    #endif
#endif

#if defined(NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE)
    //Generic:
    #if (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_Bionic
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_Bionic
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_glibc)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_glibc
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_glibc
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_klibc)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_klibc
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_klibc
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_uClibc
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_uClibc
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_zOSlib
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_zOSlib
    #endif

    //Explicit:
    #if (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_Bare)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_Bare
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_Bare
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_MUSLLIBC)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_MUSLLIBC
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_MUSLLIBC
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_MACOSX)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_MACOSX
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_MACOSX
    #elif (NCAOL_ENABLES_EXPLICIT_CSTDLIB_TYPE == NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS)
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_NAME NCAOL_SPECS_CSTDLIB_VAL_NAME_WINDOWS
        #define NCAOL_SPECS_CSTDLIB_DEF_LIB_ID NCAOL_SPECS_CSTDLIB_VAL_ID_WINDOWS
    #endif
#endif


#endif
