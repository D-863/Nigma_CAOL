#ifndef NIGMA_CAOL_OSSPECIFICS_H
#define NIGMA_CAOL_OSSPECIFICS_H

#include "stdlibraspecs.h"

/*OS-Specific identifications:
PDP7:

Unix:
    Generic:
        __unix__
        __unix

    PWBUnix:

    BSD:
        Generic:
            __FreeBSD__
            __NetBSD__
            __OpenBSD__
            __bsdi__
            __DragonFly__
        DEC C:
            _SYSTYPE_BSD

        BSD/OS:
            Generic:
                __bsdi__

        DragonFly:
            Generic:
                __DragonFly__

        FreeBSD:
            Generic:
                __FreeBSD__
                __FreeBSD_kernel__

        HI-UX MPP:
            Generic:
                __hiuxmpp

        MacOS-9:
            Generic:
                macintosh
                Macintosh

        MacOS-X:
            Generic:
                __APPLE__ && __MACH__
            GNU C:
                __APPLE__ && __MACH__
            Intel C++:
                __APPLE__ && __MACH__

        NetBSD:
            Generic:
                __NetBSD__

        OpenBSD:
            Generic:
                __OpenBSD__

        Ultrix:
            Generic:
                ultrix
                __ultrix
                __ultrix__

    Unix32V:

    SystemIII:

    SystemV:
        AIX:
            Generic:
                _AIX
            xlC:
                __TOS_AIX__

        DG/UX:
            Generic:
                DGUX
                __DGUX__
                __dgux__

        DYNIX/ptx:
            Generic:
                _SEQUENT_
                sequent

        HP-UX:
            Generic:
                _hpux
                hpux
                __hpux
            HP UPC:
                _hpux

        Reliant UNIX:
            Generic:
                sinux

    SystemV_R1:

    SystemV_R2:
        UNICOS:
            Generic:
                _UNICOS

        UNICOS/mp:
            Generic:
                _CRAY
                __crayx1

    SystemV_R3:
        IRIX:
            Generic:
                sgi
                __sgi

    SystemV_R4:
        Generic:
            __sysv__
            __SVR4
            __svr4__
        IRIX:
            _SYSTYPE_SVR4

        Amdahl UTS:
            Generic:
                UTS

        Pyramid DC/OSx:
            Generic:
                pyr

        Solaris:
            Generic:
                sun
                __sun

    SystemV_R5:
        SCO OpenServer:
            Generic:
                _SCO_DS
            GNU C:
                M_I386
                M_XENIX

        UnixWare:
            Generic:
                sco
                _UNIXWARE7

    OSF1:
        Tru64 (OSF/1):
            Generic:
                __osf__
                __osf

UnixLike:
    Other:
        Android:
            Generic:
                __ANDROID__

        Apollo AEGIS:
            Generic:
                aegis

        Apollo Domain/OS:
            Generic:
                apollo

        GNU/Hurd:
            Generic:
                __GNU__
                __gnu_hurd__

        GNU/kFreeBSD:
            Generic:
                __FreeBSD_kernel__ && __GLIBC__

        GNU/Linux:
            Generic:
                __gnu_linux__

        Linux kernel:
            Generic:
                __linux__

        LynxOS:
            Generic:
                __Lynx__

        MINIX:
            Generic:
                __minix

        QNX:
            Generic:
                __QNX__
                __QNXNTO__

        Syllable:
            Generic:
                __SYLLABLE__

DOS:
    MSDOS:
        Generic:
            MSDOS
            __MSDOS__
            _MSDOS
            __DOS__

        EMX Environment:
            Generic:
                __EMX__

    OS/2:
        Generic:
            OS2
            _OS2
            __OS2__
            __TOS_OS2__

        EMX Environment:
            Generic:
                __EMX__

    Windows:
        Generic:
            _WIN16
            _WIN32
            _WIN64
        Borland C++:
            __WIN32__
        xlC:
            __TOS_WIN__
        Watcom C/C++:
            __WINDOWS__

        Cygwin Environment:
            Generic:
                __CYGWIN__

        Interix Environment:
            GNU C:
                __INTERIX
            Visual Studio:
                __INTERIX

        U/Win Environment:
            Generic:
                _UWIN

    Windows CE:
        Embedded Visual Studio C++:
            _WIN32_WCE

Other:
    Other:
        AmigaOS:
            Generic:
                AMIGA
            GNU C:
                __amigaos__

        BeOS:
            Generic:
                __BEOS__

        Blue Gene:
            Generic:
                __bg__
                __THW_BLUEGENE__
            GNU C:
                __bg__
            XL C/C++:
                __bg__
                __THW_BLUEGENE__

        ConvexOS:
            Generic:
                __convex__

        eCos:
            Generic:
                __ECOS

        IBM OS/400:
            Generic:
                __OS400__

        INTEGRITY:
            Generic:
                __INTEGRITY

        Microware OS-9:
            Ultimate C/C++:
                __OS9000
                _OSK

        MorphOS:
            Generic:
                __MORPHOS__

        MPE/iX:
            Generic:
                mpeix
                __mpexl

        NonStop:
            Generic:
                __TANDEM

        Nucleus RTOS:
            Generic:
                __nucleus__

        Palm OS:
            GNU C:
                __palmos__

        Plan 9:
            Generic:
                EPLAN9

        Stratus VOS:
            Generic:
                __VOS__

        Symbian OS:
            Generic:
                __SYMBIAN32__

        OpenVMS:
            Generic:
                VMS
                __VMS

        VxWorks:
            GNU C:
                __VXWORKS__
                __vxworks
            Diab
                __VXWORKS__
                __vxworks

        Wind/U Environment:
            Generic:
                _WINDU_SOURCE

        z/OS:
            Host:
                __MVS__
                __HOS_MVS__
            Target:
                __TOS_MVS__
*/
#define CAOL_OSSPECIFICS_DEF_OSSUB_PDP7      0
#define CAOL_OSSPECIFICS_DEF_OSSUB_Unix      1
#define CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike  2
#define CAOL_OSSPECIFICS_DEF_OSSUB_DOS       3
#define CAOL_OSSPECIFICS_DEF_OSSUB_Other     4

#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_PWBUnix    0
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD        1
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_Unix32V    2
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemIII  3
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV    4
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R1 5
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R2 6
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R3 7
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R4 8
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R5 9
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_OSF1       10
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_MSDOS      11
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_OS2        12
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_Windows    13
#define CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other      14

#define CAOL_OSSPECIFICS_DEF_OSID_AIX                 0
#define CAOL_OSSPECIFICS_DEF_OSID_Android             1
#define CAOL_OSSPECIFICS_DEF_OSID_Amdahl_UTS          2
#define CAOL_OSSPECIFICS_DEF_OSID_AmigaOS             3
#define CAOL_OSSPECIFICS_DEF_OSID_Apollo_AEGIS        4
#define CAOL_OSSPECIFICS_DEF_OSID_Apollo_DomainOS     5
#define CAOL_OSSPECIFICS_DEF_OSID_BeOS                6
#define CAOL_OSSPECIFICS_DEF_OSID_BlueGene            7
#define CAOL_OSSPECIFICS_DEF_OSID_BSD_Environment     8
#define CAOL_OSSPECIFICS_DEF_OSID_BSDOS               9
#define CAOL_OSSPECIFICS_DEF_OSID_ConvexOS            10
#define CAOL_OSSPECIFICS_DEF_OSID_Cygwin_Environment  11
#define CAOL_OSSPECIFICS_DEF_OSID_DG_UX               12
#define CAOL_OSSPECIFICS_DEF_OSID_DragonFly           13
#define CAOL_OSSPECIFICS_DEF_OSID_DYNIX_ptx           14
#define CAOL_OSSPECIFICS_DEF_OSID_eCos                15
#define CAOL_OSSPECIFICS_DEF_OSID_EMX_Environment     16
#define CAOL_OSSPECIFICS_DEF_OSID_FreeBSD             17
#define CAOL_OSSPECIFICS_DEF_OSID_GNU_Hurd            18
#define CAOL_OSSPECIFICS_DEF_OSID_GNU_kFreeBSD        19
#define CAOL_OSSPECIFICS_DEF_OSID_GNU_Linux           20
#define CAOL_OSSPECIFICS_DEF_OSID_HIUX_MPP            21
#define CAOL_OSSPECIFICS_DEF_OSID_HPUX                22
#define CAOL_OSSPECIFICS_DEF_OSID_IBM_OS400           23
#define CAOL_OSSPECIFICS_DEF_OSID_INTEGRITY           24
#define CAOL_OSSPECIFICS_DEF_OSID_Interix_Environment 25
#define CAOL_OSSPECIFICS_DEF_OSID_IRIX                26
#define CAOL_OSSPECIFICS_DEF_OSID_Linux_kernel        27
#define CAOL_OSSPECIFICS_DEF_OSID_LynxOS              28
#define CAOL_OSSPECIFICS_DEF_OSID_MacOS_9             29
#define CAOL_OSSPECIFICS_DEF_OSID_MacOS_X             30
#define CAOL_OSSPECIFICS_DEF_OSID_Microware_OS9       31
#define CAOL_OSSPECIFICS_DEF_OSID_MINIX               32
#define CAOL_OSSPECIFICS_DEF_OSID_MorphOS             33
#define CAOL_OSSPECIFICS_DEF_OSID_MPE_iX              34
#define CAOL_OSSPECIFICS_DEF_OSID_MSDOS               35
#define CAOL_OSSPECIFICS_DEF_OSID_NetBSD              36
#define CAOL_OSSPECIFICS_DEF_OSID_NonStop             37
#define CAOL_OSSPECIFICS_DEF_OSID_NucleusRTOS         38
#define CAOL_OSSPECIFICS_DEF_OSID_OpenBSD             39
#define CAOL_OSSPECIFICS_DEF_OSID_OS2                 40
#define CAOL_OSSPECIFICS_DEF_OSID_PalmOS              41
#define CAOL_OSSPECIFICS_DEF_OSID_Plan9               42
#define CAOL_OSSPECIFICS_DEF_OSID_Pyramid_DCOSx       43
#define CAOL_OSSPECIFICS_DEF_OSID_QNX                 44
#define CAOL_OSSPECIFICS_DEF_OSID_Reliant_UNIX        45
#define CAOL_OSSPECIFICS_DEF_OSID_SCO_OpenServer      46
#define CAOL_OSSPECIFICS_DEF_OSID_Solaris             47
#define CAOL_OSSPECIFICS_DEF_OSID_Stratus_VOS         48
#define CAOL_OSSPECIFICS_DEF_OSID_SVR4_Environment    49
#define CAOL_OSSPECIFICS_DEF_OSID_Syllable            50
#define CAOL_OSSPECIFICS_DEF_OSID_SymbianOS           51
#define CAOL_OSSPECIFICS_DEF_OSID_Tru64_OSF1          52
#define CAOL_OSSPECIFICS_DEF_OSID_Ultrix              53
#define CAOL_OSSPECIFICS_DEF_OSID_UNICOS              54
#define CAOL_OSSPECIFICS_DEF_OSID_UNICOS_mp           55
#define CAOL_OSSPECIFICS_DEF_OSID_UNIX_Environment    56
#define CAOL_OSSPECIFICS_DEF_OSID_UnixWare            57
#define CAOL_OSSPECIFICS_DEF_OSID_UWin_Environment    58
#define CAOL_OSSPECIFICS_DEF_OSID_OpenVMS             59
#define CAOL_OSSPECIFICS_DEF_OSID_VxWorks             60
#define CAOL_OSSPECIFICS_DEF_OSID_Windows             61
#define CAOL_OSSPECIFICS_DEF_OSID_Windows_CE          62
#define CAOL_OSSPECIFICS_DEF_OSID_WindU_Environment   63
#define CAOL_OSSPECIFICS_DEF_OSID_zOS                 64

#if (caolSTDLibraspecs(CURRENT, LIB, ID) == caolSTDLibraspecs(LIB, ID, Bionic))
#elif (caolSTDLibraspecs(CURRENT, LIB, ID) == caolSTDLibraspecs(LIB, ID, glibc))
    //GNU C specific
    #if (defined(__APPLE__) && defined(__MACH__))
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MacOS_X
    #elif (defined(M_I386) || defined(M_XENIX))
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R5
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_SCO_OpenServer
    #elif defined(__INTERIX)
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Windows
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Interix_Environment
    #elif defined(__amigaos__)
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_AmigaOS
    #elif defined(__bg__)
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BlueGene
    #elif defined(__palmos__)
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_PalmOS
    #elif (defined(__VXWORKS__) || defined(__vxworks))
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_VxWorks
    #endif
#elif (caolSTDLibraspecs(CURRENT, LIB, ID) == caolSTDLibraspecs(LIB, ID, klibc))
#elif (caolSTDLibraspecs(CURRENT, LIB, ID) == caolSTDLibraspecs(LIB, ID, uClibc))
#elif (caolSTDLibraspecs(CURRENT, LIB, ID) == caolSTDLibraspecs(LIB, ID, zOSlib))
#elif (caolSTDLibraspecs(CURRENT, LIB, ID) == caolSTDLibraspecs(LIB, ID, WINDOWS))
#endif

/*
Unix:
    (defined(__unix__) || defined(__unix))
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix

    BSD:
        BSD/OS:
            defined(__bsdi__)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BSDOS

        DragonFly:
            defined(__DragonFly__)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_DragonFly

        FreeBSD:
            (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_FreeBSD

        HI-UX MPP:
            defined(__hiuxmpp)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_HIUX_MPP

        Mac OS 9:
            (defined(macintosh) || defined(Macintosh))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MacOS_9

        Mac OS X:
            (defined(__APPLE__) && defined(__MACH__))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MacOS_X

        NetBSD:
            defined(__NetBSD__)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_NetBSD

        OpenBSD:
            defined(__OpenBSD__)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_OpenBSD

        Ultrix:
            (defined(ultrix) || defined(__ultrix) || defined(__ultrix__))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_BSD
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Ultrix

    SystemV:
        AIX:
            defined(_AIX)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_AIX

        DG/UX:
            (defined(DGUX) || defined(__DGUX__) || defined(__dgux__))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_DG_UX

        DYNIX/ptx:
            (defined(_SEQUENT_) || defined(sequent))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_DYNIX_ptx

        HP-UX:
            (defined(_hpux) || defined(hpux) || defined(__hpux))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_HPUX

        Reliant UNIX:
            defined(sinux)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Reliant_UNIX

    SystemV_R2:
        UNICOS:
            defined(_UNICOS)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R2
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UNICOS

        UNICOS/mp:
            (defined(_CRAY) || defined(__crayx1))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R2
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UNICOS_mp

    SystemV_R3:
        IRIX:
            (defined(sgi) || defined(__sgi))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R3
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_IRIX

    SystemV_R4:
        (defined(__sysv__) || defined(__SVR4) || defined(__svr4__))
            #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
            #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R4

        Amdahl UTS:
            defined(UTS)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R4
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Amdahl_UTS

        Pyramid DC/OSx:
            defined(pyr)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R4
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Pyramid_DCOSx

        Solaris:
            (defined(sun) || defined(__sun))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R4
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Solaris

    SystemV_R5:
        SCO OpenServer:
            defined(_SCO_DS)
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R5
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_SCO_OpenServer

        UnixWare:
            (defined(sco) || defined(_UNIXWARE7))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_SystemV_R5
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UnixWare

    OSF1:
        Tru64 (OSF/1):
            (defined(__osf__) || defined(__osf))
                #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Unix
                #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_OSF1
                #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Tru64_OSF1
*/

//UnixLike:
    //Other:
    #if defined(__ANDROID__)
        //Android:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Android

    #elif defined(aegis)
        //Apollo AEGIS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Apollo_AEGIS

    #elif defined(apollo)
        //Apollo Domain/OS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Apollo_DomainOS

    #elif (defined(__GNU__) || defined(__gnu_hurd__))
        //GNU/Hurd:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_GNU_Hurd

    #elif (defined(__FreeBSD_kernel__) && defined(__GLIBC__))
        //GNU/kFreeBSD:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_GNU_kFreeBSD

    #elif defined(__gnu_linux__)
        //GNU/Linux:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_GNU_Linux

    #elif defined(__linux__)
        //Linux kernel:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Linux_kernel

    #elif defined(__Lynx__)
        //LynxOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_LynxOS

    #elif defined(__minix)
        //MINIX:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MINIX

    #elif (defined(__QNX__) || defined(__QNXNTO__))
        //QNX:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_QNX

    #elif defined(__SYLLABLE__)
        //Syllable:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_UnixLike
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Syllable
    #endif

//DOS:
#if (defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__))
    //MSDOS:
    #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
    #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_MSDOS
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MSDOS

    #if defined(__EMX__)
        //EMX Environment:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_MSDOS
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_EMX_Environment
    #endif

#elif (defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__))
    //OS/2:
    #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
    #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_OS2
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_OS2

    #if defined(__EMX__)
        //EMX Environment:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_OS2
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_EMX_Environment
    #endif

#elif (defined(_WIN16) || defined(_WIN32) || defined(_WIN64))
    //Windows:
    #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
    #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Windows
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Windows

    #if defined(__CYGWIN__)
        //Cygwin Environment:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Windows
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Cygwin_Environment

    #elif defined(_UWIN)
        //U/Win Environment:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_DOS
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Windows
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UWin_Environment
    #endif
#endif

//Other:
    //Other:
    #if defined(AMIGA)
        //AmigaOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_AmigaOS

    #elif defined(__BEOS__)
        //BeOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BeOS

    #elif (defined(__bg__) || defined(__THW_BLUEGENE__))
        //Blue Gene:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BlueGene

    #elif defined(__convex__)
        //ConvexOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_ConvexOS

    #elif defined(__ECOS)
        //eCos:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_eCos

    #elif defined(__OS400__)
        //IBM OS/400:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_IBM_OS400

    #elif defined(__INTEGRITY)
        //INTEGRITY:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_INTEGRITY

    #elif defined(__MORPHOS__)
        //MorphOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MorphOS

    #elif (defined(mpeix) || defined(__mpexl))
        //MPE/iX:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MPE_iX

    #elif defined(__TANDEM)
        //NonStop:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_NonStop

    #elif defined(__nucleus__)
        //Nucleus RTOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_NucleusRTOS

    #elif defined(EPLAN9)
        //Plan 9:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Plan9

    #elif defined(__VOS__)
        //Stratus VOS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Stratus_VOS

    #elif defined(__SYMBIAN32__)
        //Symbian OS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_SymbianOS

    #elif (defined(VMS) || defined(__VMS))
        //OpenVMS:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_OpenVMS

    #elif defined(_WINDU_SOURCE)
        //Wind/U Environment:
        #define CAOL_OSSPECIFICS_DEF_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OSSUB_Other
        #define CAOL_OSSPECIFICS_DEF_OS_DOMAIN CAOL_OSSPECIFICS_DEF_OSDOMAIN_Other
        #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_WindU_Environment
    #endif


#define caolOSSpecifics(t, ...) CAOL_OSSPECIFICS_INTER_##t(__VA_ARGS__)
#define CAOL_OSSPECIFICS_INTER_OS(t, ...) CAOL_OSSPECIFICS_INTER_OS_##t(__VA_ARGS__)
//#define CAOL_OSSPECIFICS_INTER_OS_SUBJECT(t) CAOL_OSSPECIFICS_INTER_OS_SUBJECT_##t
//#define CAOL_OSSPECIFICS_INTER_OS_DOMAIN(t)  CAOL_OSSPECIFICS_INTER_OS_DOMAIN_##t
//#define CAOL_OSSPECIFICS_INTER_OS_ID(t)      CAOL_OSSPECIFICS_INTER_OS_ID_##t

#define CAOL_OSSPECIFICS_INTER_CURRENT(t, ...) CAOL_OSSPECIFICS_INTER_CURRENT_##t(__VA_ARGS__)
#define CAOL_OSSPECIFICS_INTER_CURRENT_OS_SUBJECT CAOL_OSSPECIFICS_DEF_OS_SUBJECT
#define CAOL_OSSPECIFICS_INTER_CURRENT_OS_DOMAIN  CAOL_OSSPECIFICS_DEF_OS_DOMAIN
//#define CAOL_OSSPECIFICS_INTER_CURRENT_OS_NAME    CAOL_OSSPECIFICS_DEF_OS_NAME
#define CAOL_OSSPECIFICS_INTER_CURRENT_OS_ID      CAOL_OSSPECIFICS_DEF_OS_ID

#endif