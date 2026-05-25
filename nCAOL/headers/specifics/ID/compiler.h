#ifndef NIGMA_CAOL_SPECIFICS_ID_COMPILER_H
#define NIGMA_CAOL_SPECIFICS_ID_COMPILER_H


#include "values/compiler.h"

/*Compiler-Specific identifications:
FPGA_Specfic:
    Altium:
        MicroBlaze C:
            __CMB__

        C-to-Hardware:
            __CHC__

ARM_Specfic:
    KEIL:
        CARM:
            (__CA__ || __KEIL__)

        C166:
            __C166__

        C51:
            (__C51__ || __CX51__)

    ARM-Compiler:
        __CC_ARM

    IAR:
        //To be found.

RISC-V_Specific:
        For what I know, the compiler used is very Architecture specific,
        which makes by RISC-V's nature.

        So I will add this in the future when I got a working RP2350.
    - Sincerly, Nigma -

Generic:
    //MinGW needs to be checked first, because it's more of a port than a actual standalone compiler.
    MinGW:
        MinGW32:
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            )
        )

        MinGW-w64_32B:
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            ) || (
                __MINGW64_VERSION_MAJOR ||
                __MINGW64_VERSION_MINOR
            )
        )

        MinGW-w64_64B:
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            ) || (
                __MINGW64__ ||
                __MINGW64_VERSION_MAJOR ||
                __MINGW64_VERSION_MINOR
            )
        )

    Clang:
        __clang__

    GCC:
        __GNUC__

    Microsoft Visual C++:
        _MSC_VER

*/
#if defined(__CMB__)
    //Altium MicroBlaze C
    /*
        __VERSION__ = VRRR
            V: Version
            RRR: Revision
        __REVISION__ = P
            P: Patch
        __BUILD__ = VRRRPPP
            VRRRPPP: Build number
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_FPGA
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_Altium
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_MicroBlazeC
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_MicroBlazeC
#elif defined(__CHC__)
    //Altium C-to-Hardware
    /*
        __VERSION__ = VRRR
            V: Version
            RRR: Revision
        __REVISION__ = P
            P: Patch
        __BUILD__ = VRRRPPP
            VRRRPPP: Build number
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_FPGA
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_Altium
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_CtoHardware
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_CtoHardware
#elif (defined(__CA__) || defined(__KEIL__))
    //KEIL CARM
    /*
        __CA__ = VRR
        V: Version
        RR: Revision
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_CARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_CARM
#elif defined(__C166__)
    //KEIL C166
    /*
        __C166__ = VRR
        V: Version
        RR: Revision
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_C166
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_C166
#elif (defined(__C51__) || defined(__CX51__))
    //KEIL C51
    /*
        __C51__ = VRR
        V: Version
        RR: Revision
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_C51
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_C51
#elif defined(__CC_ARM)
    //ARM Compiler
    /*
        __ARMCC_VERSION = VRPBBB
            V: Version
            R: Revision
            P: Patch
            BBB: Build
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_ARMCompiler
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_ARMCompiler
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_ARMCompiler
#elif (defined(__MINGW32__) || defined(__MINGW32_MAJOR_VERSION) || defined(__MINGW32_MINOR_VERSION))
    //MinGW
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_MinGW

    #if (defined(__MINGW64_VERSION_MAJOR) || defined(__MINGW64_VERSION_MINOR))
        //MinGW-w64
        /*
            __MINGW32_MAJOR_VERSION = V
                V: Version for MinGW32.
            __MINGW32_MINOR_VERSION = R
                R: Revision for MinGW32.

            __MINGW64_VERSION_MAJOR = V
                V: Version for MinGW-w64.
            __MINGW64_VERSION_MINOR = R
                R: Revision for MinGW-w64.
        */
        #if defined(__MINGW64__)
            //MinGW-w64_64B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME NCAOL_SPECS_COMP_VAL_NAME_MinGWw64_64B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_ID   NCAOL_SPECS_COMP_VAL_ID_MinGWw64_64B
        #else
            //MinGW-w64_32B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME NCAOL_SPECS_COMP_VAL_NAME_MinGWw64_32B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_ID   NCAOL_SPECS_COMP_VAL_ID_MinGWw64_32B
        #endif
    #else
        //MinGW32
        /*
            __MINGW32_MAJOR_VERSION = V
                V: Version for MinGW32.
            __MINGW32_MINOR_VERSION = R
                R: Revision for MinGW32.
        */
        #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME NCAOL_SPECS_COMP_VAL_NAME_MinGW32
        #define NCAOL_SPECS_COMP_DEF_COMPILER_ID   NCAOL_SPECS_COMP_VAL_ID_MinGW32
    #endif
#elif defined(__clang__)
    //Clang
    /*
        __clang_major__ = V
            V: Major version
        __clang_minor__ = R
            R: Minor version
        __clang_patchlevel__ = P
            P: Patch level
        __clang_version__ = V.R.P (tags/RELEASE_VRP/final)
            V: Major version
            R: Minor version
            P: Patch level
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_Clang
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_Clang
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_Clang
#elif defined(__GNUC__)
    //GCC
    /*
        __GNUC__ = V
            V: Version
        __GNUC_MINOR__ = R
            R: Revision

        (Version 3.0)
        __GNUC_PATCHLEVEL__ = P
            P: Patch
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_GCC
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_GCC
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_GCC
#elif defined(_MSC_VER)
    //Microsoft Visual C++
    /*
        _MSC_VER = VVRR
            VV: Version
            RR: Revision

        (Version 6.0)
        _MSC_FULL_VER = VVRRPPPP
            VV: Version
            RR: Revision
            PPPP: Patch

        (Version 8.0)
        _MSC_FULL_VER = VVRRPPPPP
            VV: Version
            RR: Revision
            PPPPP: Patch

        (Version 9.0)
        _MSC_BUILD = B
            B: Build number
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUBJECT_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_MicrosoftVisualCPP
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_MicrosoftVisualCPP
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_MicrosoftVisualCPP
#endif


#endif