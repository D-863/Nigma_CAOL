#ifndef NIGMA_CAOL_SPECIFICS_ID_ARCHITECTURE_H
#define NIGMA_CAOL_SPECIFICS_ID_ARCHITECTURE_H


#include "values/architecture.h"

/*Architecture-Specific identifications:
RISC:
    Alpha:
        GNU C:
            __alpha__
        DEC C:
            __alpha
        Visual Studio:
            _M_ALPHA

    ARM:
        GNU C:
            __arm__
        RealView:
            __arm__
            __TARGET_ARCH_ARM
            __TARGET_ARCH_THUMB
        ImageCraft C:
            _ARM
        Visual Studio
            _M_ARM
        Diab:
        __arm

    ARM-Thumb:
        GNU C:
            __thumb__
        RealView:
            __thumb__
            __TARGET_ARCH_ARM
            __TARGET_ARCH_THUMB
        Visual Studio
            _M_ARMT

    ARM64:
        GNU C:
            __aarch64__
        Visual Studio:
            _M_ARM64

    Blackfin:
        GNU C:
            __bfin
            __BFIN__

    MIPS:
        GNU C:
            __mips__
            mips
            __mips
        MIPSpro:
            __mips
        Metrowerks:
            __MIPS__

    PowerPC:
        GNU C:
            __powerpc
            __powerpc__
            __powerpc64__
            __POWERPC__
            __ppc__
            __ppc64__
            __PPC__
            __PPC64__
            _ARCH_PPC
            _ARCH_PPC64
        Visual Studio:
            _M_PPC
        XL C/C++:
            _ARCH_PPC
            _ARCH_PPC64
        Diab:
            __ppc

    RS/6000:
        XL C/C++:
            __THW_RS6000
            _IBMR2
            _POWER
            _ARCH_PWR
            _ARCH_PWR2
            _ARCH_PWR3
            _ARCH_PWR4

    SPARC:
        GNU C:
            __sparc__
        Sun Studio:
            __sparc

    SuperH:
        GNU C:
            __sh__

EPIC:
    Intel Itanium (IA-64):
        GNU C:
            __ia64__
            _IA64
            __IA64__
        HP aCC:
            __ia64
        Visual Studio:
            _M_IA64
        Intel C/C++
            _M_IA64
            __itanium__

CISC:
    x86-64:
        AMD64:
            GNU C:
                __amd64__
                __amd64
                __x86_64__
                __x86_64
            Sun Studio:
                __amd64__
                __amd64
                __x86_64__
                __x86_64
            Visual Studio:
                _M_X64
                _M_AMD64

    Intel x86:
        GNU C:
            i386
            __i386
            __i386__
        Sun Studio:
            __i386
        Stratus VOS C:
            __i386
            __IA32__
        Visual Studio:
            _M_IX86
        Digital Mars:
            _M_IX86
            __I86__
        Intel C/C++:
            _M_IX86
        MinGW32:
            _X86_
        XL C/C++:
            __THW_INTEL__
        CodeWarrior:
            __INTEL__
        Diab:
            __386

    Intel x86-16Bit:
        Visual Studio:
            _M_I86
        Digital Mars:
            _M_I86

    Motorola 68k:
        GNU C:
            __m68k__
        SAS/C:
            M68000
        Stratus VOS C:
            __MC68K__

    SystemZ:
        XL C/C++:
            __370__
            __THW_370__
        GNU C:
            __s390__
            __s390x__
        clang:
            __zarch__
        Systems/C:
            __SYSC_ZARCH__
*/
#if (defined(__alpha)   || \
     defined(__alpha__) || \
     defined(_M_ALPHA)     \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_Alpha
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_Alpha
#elif (defined(_ARM)    || \
       defined(__arm)   || \
       defined(__arm__) || \
       (defined(_M_ARM) && (defined(_M_ARMT) == 0)) \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_ARM
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_ARM
    #if defined(__arm__)
        //GNU C and RealView
        #if (defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB))
            //RealView
            //__TARGET_ARCH_ARM = Version
            //__TARGET_ARCH_THUMB = Version
            //__TARGET_ARCH_'VR' = Version and Revision
        #else
            //GNU C
            //__ARM_ARCH_'V'__ = Version

            /*
                #elif defined(__ARM_ARCH_2__)
                    //ARM2
                #elif (defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__))
                    //ARM3
                #elif (defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T))
                    //ARM4T
                #elif (defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_))
                    //ARM5"
                #elif (defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_))
                    //ARM6T2
                #elif (defined(__ARM_ARCH_6__) ||
                    defined(__ARM_ARCH_6J__) ||
                    defined(__ARM_ARCH_6K__) ||
                    defined(__ARM_ARCH_6Z__) ||
                    defined(__ARM_ARCH_6ZK__)
                    )
                    //ARM6
                #elif (defined(__ARM_ARCH_7__) ||
                    defined(__ARM_ARCH_7A__) ||
                    defined(__ARM_ARCH_7R__) ||
                    defined(__ARM_ARCH_7M__) ||
                    defined(__ARM_ARCH_7S__)
                    )
                    //ARM7
                #elif (defined(__ARM_ARCH_7A__) ||
                    defined(__ARM_ARCH_7R__) ||
                    defined(__ARM_ARCH_7M__) ||
                    defined(__ARM_ARCH_7S__)
                    )
                    //ARM7A
                #elif (defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__))
                    //ARM7R
                #elif (defined(__ARM_ARCH_7M__))
                    //ARM7M
                #elif (defined(__ARM_ARCH_7S__))
                    //ARM7S
            */
        #endif
    #elif (_M_ARM)
        //Visual Studio
        //_M_ARM = Version
    #elif (_ARM)
        //ImageCraft C
    #else
        //Diab
    #endif
#elif (defined(__thumb__) || \
       (defined(_M_ARM) && (defined(_M_ARMT) == 1)) \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_ARM_Thumb
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_ARM_Thumb
    #if defined(__thumb__)
        //GNU C and RealView
        #if (defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB))
            //RealView
            //__TARGET_ARCH_ARM = Version
            //__TARGET_ARCH_THUMB = Version
            //__TARGET_ARCH_'VR' = Version and Revision
        #else
            //GNU C
            //__ARM_ARCH_'V'__ = Version
        #endif
    #else
        //Visual Studio
        //_M_ARM = Version
    #endif
#elif defined(__aarch64__)
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_ARM64
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_ARM64
#elif (defined(__bfin)   || \
       defined(__BFIN__)    \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_Blackfin
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_Blackfin
#elif (defined(mips)     || \
       defined(__mips)   || \
       defined(__mips__) || \
       defined(__MIPS__)    \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_MIPS
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_MIPS
#elif (defined(__ppc)         || \
       defined(__ppc__)       || \
       defined(__PPC__)       || \
       defined(__ppc64__)     || \
       defined(__PPC64__)     || \
       defined(__powerpc)     || \
       defined(__powerpc__)   || \
       defined(__POWERPC__)   || \
       defined(__powerpc64__) || \
       defined(_ARCH_PPC)     || \
       defined(_ARCH_PPC64)   || \
       defined(_M_PPC)           \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC

    #if (defined(__ppc64__)     || \
         defined(__PPC64__)     || \
         defined(__powerpc64__) || \
         defined(_ARCH_PPC64)      \
        )
        #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME PowerPC64
        #define NCAOL_SPECS_ARCH_DEF_ARCH_ID   NCAOL_SPECS_ARCH_VAL_ID_PowerPC64
    #else
        #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME PowerPC
        #define NCAOL_SPECS_ARCH_DEF_ARCH_ID   NCAOL_SPECS_ARCH_VAL_ID_PowerPC
    #endif
#elif (defined(_IBMR2)       || \
       defined(_POWER)       || \
       defined(_ARCH_PWR)    || \
       defined(_ARCH_PWR2)   || \
       defined(_ARCH_PWR3)   || \
       defined(_ARCH_PWR4)   || \
       defined(__THW_RS6000)    \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_RS6000
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_RS6000
#elif (defined(__sparc)   || \
       defined(__sparc__)    \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_SPARC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_SPARC
#elif defined(__sh__)
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_RISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_SuperH
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_SuperH
#elif (defined(_IA64)       || \
       defined(__ia64)      || \
       defined(__ia64__)    || \
       defined(__IA64__)    || \
       defined(__itanium__) || \
       defined(_M_IA64)        \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_EPIC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_IntelItanium_IA64
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_IntelItanium_IA64
#elif (defined(__amd64)    || \
       defined(__amd64__)  || \
       defined(__x86_64)   || \
       defined(__x86_64__) || \
       defined(_M_X64)     || \
       defined(_M_AMD64)      \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_CISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_x86_64
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_x86_64
#elif (defined(i386)          || \
       defined(_X86_)         || \
       defined(__386)         || \
       defined(__i386)        || \
       defined(__I86__)       || \
       defined(__i386__)      || \
       defined(__IA32__)      || \
       defined(__INTEL__)     || \
       defined(__THW_INTEL__) || \
       defined(_M_IX86)          \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_CISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_Intel_x86
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_Intel_x86
#elif defined(_M_I86)
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_CISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_Intel_x86_16Bit
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_Intel_x86_16Bit
#elif (defined(M68000)    || \
       defined(__m68k__)  || \
       defined(__MC68K__)    \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_CISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_Motorola68k
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_Motorola68k
#elif (defined(__370__)        || \
       defined(__s390__)       || \
       defined(__s390x__)      || \
       defined(__zarch__)      || \
       defined(__THW_370__)    || \
       defined(__SYSC_ZARCH__)    \
    )
    #define NCAOL_SPECS_ARCH_DEF_ARCH_CLASS NCAOL_SPECS_ARCH_VAL_CLASS_CISC
    #define NCAOL_SPECS_ARCH_DEF_ARCH_NAME  NCAOL_SPECS_ARCH_VAL_NAME_SystemZ
    #define NCAOL_SPECS_ARCH_DEF_ARCH_ID    NCAOL_SPECS_ARCH_VAL_ID_SystemZ
#endif


#endif