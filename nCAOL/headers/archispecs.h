#ifndef NIGMA_CAOL_ARCHISPECS_H
#define NIGMA_CAOL_ARCHISPECS_H

#include "compilics.h"

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

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC 0
#define CAOL_ARCHISPECS_DEF_ARCHCLASS_EPIC 1
#define CAOL_ARCHISPECS_DEF_ARCHCLASS_CISC 2

#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Alpha     0
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_ARM       1
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_ARM_Thumb 2
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_ARM64     3
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Blackfin  4
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_MIPS      5
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_PowerPC   6
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_RS6000    7
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_SPARC     8
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_SuperH    9

#define CAOL_ARCHISPECS_DEF_ARCHTYPE_IntelItanium_IA64 10

#define CAOL_ARCHISPECS_DEF_ARCHTYPE_x86_64
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Intel_x86
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Intel_x86_16Bit
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Motorola68k
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_SystemZ

RISC:
#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Alpha
        GNU C:
            __alpha__
        DEC C:
            __alpha
        Visual Studio:
            _M_ALPHA

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_ARM
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

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_ARM_Thumb
        GNU C:
            __thumb__
        RealView:
            __thumb__
            __TARGET_ARCH_ARM
            __TARGET_ARCH_THUMB
        Visual Studio
            _M_ARMT

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_ARM64
        GNU C:
            __aarch64__

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Blackfin
        GNU C:
            __bfin
            __BFIN__

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_MIPS
        GNU C:
            __mips__
            mips
            __mips
        MIPSpro:
            __mips
        Metrowerks:
            __MIPS__

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_PowerPC
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

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_RS6000
        XL C/C++:
            __THW_RS6000
            _IBMR2
            _POWER
            _ARCH_PWR
            _ARCH_PWR2
            _ARCH_PWR3
            _ARCH_PWR4

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_SPARC
        GNU C:
            __sparc__
        Sun Studio:
            __sparc

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_RISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_SuperH
        GNU C:
            __sh__

EPIC:
#define CAOL_ARCHISPECS_DEF_ARCHCLASS_EPIC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_IntelItanium_IA64
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
#define CAOL_ARCHISPECS_DEF_ARCHCLASS_CISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_x86_64:
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

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_CISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Intel_x86
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

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_CISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Intel_x86_16Bit
        Visual Studio:
            _M_I86
        Digital Mars:
            _M_I86

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_CISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_Motorola68k
        GNU C:
            __m68k__
        SAS/C:
            M68000
        Stratus VOS C:
            __MC68K__

#define CAOL_ARCHISPECS_DEF_ARCHCLASS_CISC
#define CAOL_ARCHISPECS_DEF_ARCHTYPE_SystemZ
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







#if (defined(__x86_64__) || defined(_M_X64))
    //x86_64
#elif (
        defined(i386) ||
        defined(__i386__) ||
        defined(__i386) ||
        defined(_M_IX86)
    )
    //x86_32
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
#elif (
        defined(__ARM_ARCH_6__) ||
        defined(__ARM_ARCH_6J__) ||
        defined(__ARM_ARCH_6K__) ||
        defined(__ARM_ARCH_6Z__) ||
        defined(__ARM_ARCH_6ZK__)
    )
    //ARM6
#elif (
        defined(__ARM_ARCH_7__) ||
        defined(__ARM_ARCH_7A__) ||
        defined(__ARM_ARCH_7R__) ||
        defined(__ARM_ARCH_7M__) ||
        defined(__ARM_ARCH_7S__)
    )
    //ARM7
#elif (
        defined(__ARM_ARCH_7A__) ||
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
#elif (defined(__aarch64__) || defined(_M_ARM64))
    //ARM64
#elif (defined(mips) || defined(__mips__) || defined(__mips))
    //MIPS
#elif defined(__sh__)
    //SUPERH
#elif (
        defined(__powerpc) ||
        defined(__powerpc__) ||
        defined(__powerpc64__) ||
        defined(__POWERPC__) ||
        defined(__ppc__) ||
        defined(__PPC__) ||
        defined(_ARCH_PPC))
    //POWERPC
#elif (defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64))
    //POWERPC64
#elif (defined(__sparc__) || defined(__sparc))
    //SPARC
#elif defined(__m68k__)
    //M68K
#else
    //UNKNOWN
#endif

#endif