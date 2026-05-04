#ifndef NIGMA_CAOL_OSSPECIFICS_H
#define NIGMA_CAOL_OSSPECIFICS_H

#include "compilics.h"

/*OS-Specific identifications:
AIX:
    Generic:
        _AIX
    xlC:
        __TOS_AIX__

Android:
    Generic:
        __ANDROID__

Amdahl UTS:
    Generic:
        UTS

AmigaOS:
    Generic:
        AMIGA
    GNU C:
        __amigaos__

Apollo AEGIS:
    Generic:
        aegis

Apollo Domain/OS:
    Generic:
        apollo

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

BSD Environment:
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

ConvexOS:
    Generic:
        __convex__

Cygwin Environment:
    Generic:
        __CYGWIN__

DG/UX:
    Generic:
        DGUX
        __DGUX__
        __dgux__

DragonFly:
    Generic:
        __DragonFly__

DYNIX/ptx:
    Generic:
        _SEQUENT_
        sequent

eCos:
    Generic:
        __ECOS

EMX Environment:
    Generic:
        __EMX__

FreeBSD:
    Generic:
        __FreeBSD__
        __FreeBSD_kernel__

GNU aka GNU/Hurd:
    Generic:
        __GNU__
        __gnu_hurd__

GNU/kFreeBSD:
    Generic:
        __FreeBSD_kernel__

GNU/Linux:
    Generic:
        __gnu_linux__

HI-UX MPP:
    Generic:
        __hiuxmpp

HP-UX:
    Generic:
        _hpux
        hpux
        __hpux
    HP UPC:
        _hpux

IBM OS/400:
    Generic:
        __OS400__

INTEGRITY:
    Generic:
        __INTEGRITY

Interix Environment:
    GNU C:
        __INTERIX
    Visual Studio:
        __INTERIX

IRIX:
    Generic:
        sgi
        __sgi

Linux kernel:
    Generic:
        __linux__

LynxOS:
    Generic:
        __Lynx__

MacOS:
    Mac OS 9:
        macintosh
        Macintosh
    Mac OS X:
        __APPLE__ && __MACH__
    GNU C:
        __APPLE__ && __MACH__
    Intel C++:
        __APPLE__ && __MACH__

Microware OS-9:
    Ultimate C/C++:
        __OS9000
        _OSK

MINIX:
    Generic:
        __minix

MorphOS:
    Generic:
        __MORPHOS__

MPE/iX:
    Generic:
        mpeix
        __mpexl

MSDOS:
    Generic:
        MSDOS
        __MSDOS__
        _MSDOS
        __DOS__

NetBSD:
    Generic:
        __NetBSD__

NonStop:
    Generic:
        __TANDEM

Nucleus RTOS:
    Generic:
        __nucleus__

OpenBSD:
    Generic:
        __OpenBSD__

OS/2:
    Generic:
        OS2
        _OS2
        __OS2__
        __TOS_OS2__

Palm OS:
    GNU C:
        __palmos__

Plan 9:
    Generic:
        EPLAN9

Pyramid DC/OSx:
    Generic:
        pyr

QNX:
    Generic:
        __QNX__
        __QNXNTO__

Reliant UNIX:
    Generic:
        sinux

SCO OpenServer:
    Generic:
        _SCO_DS
    GNU C:
        M_I386
        M_XENIX

Solaris:
    Generic:
        sun
        __sun

Stratus VOS:
    Generic:
        __VOS__

SVR4 Environment:
    Generic:
        __sysv__
        __SVR4
        __svr4__
    IRIX:
        _SYSTYPE_SVR4

Syllable:
    Generic:
        __SYLLABLE__

Symbian OS:
    Generic:
        __SYMBIAN32__

Tru64 (OSF/1):
    Generic:
        __osf__
        __osf

Ultrix:
    Generic:
        ultrix
        __ultrix
        __ultrix__

UNICOS:
    Generic:
        _UNICOS

UNICOS/mp:
    Generic:
        _CRAY
        __crayx1

UNIX Environment:
    Generic:
        __unix__
        __unix

UnixWare:
    Generic:
        sco
        _UNIXWARE7

U/Win Environment:
    Generic:
        _UWIN

VMS:
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

Windows CE:
    Embedded Visual Studio C++:
        _WIN32_WCE

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
#define CAOL_OSSPECIFICS_DEF_OSID_AIX                                   0
#define CAOL_OSSPECIFICS_DEF_OSID_Android                               1
#define CAOL_OSSPECIFICS_DEF_OSID_Amdahl_UTS                            2
#define CAOL_OSSPECIFICS_DEF_OSID_AmigaOS                               3
#define CAOL_OSSPECIFICS_DEF_OSID_Apollo_AEGIS                          4
#define CAOL_OSSPECIFICS_DEF_OSID_Apollo_DomainOS                       5
#define CAOL_OSSPECIFICS_DEF_OSID_BeOS                                  6
#define CAOL_OSSPECIFICS_DEF_OSID_Blue_Gene                             7
#define CAOL_OSSPECIFICS_DEF_OSID_BSD_Environment                       8
#define CAOL_OSSPECIFICS_DEF_OSID_BSDOS                                 9
#define CAOL_OSSPECIFICS_DEF_OSID_ConvexOS                              10
#define CAOL_OSSPECIFICS_DEF_OSID_Cygwin_Environment                    11
#define CAOL_OSSPECIFICS_DEF_OSID_DG_UX                                 12
#define CAOL_OSSPECIFICS_DEF_OSID_DragonFly                             13
#define CAOL_OSSPECIFICS_DEF_OSID_DYNIX_ptx                             14
#define CAOL_OSSPECIFICS_DEF_OSID_eCos                                  15
#define CAOL_OSSPECIFICS_DEF_OSID_EMX_Environment                       16
#define CAOL_OSSPECIFICS_DEF_OSID_FreeBSD                               17
#define CAOL_OSSPECIFICS_DEF_OSID_GNU_Hurd                              18
#define CAOL_OSSPECIFICS_DEF_OSID_GNU_kFreeBSD                          19
#define CAOL_OSSPECIFICS_DEF_OSID_GNU_Linux                             20
#define CAOL_OSSPECIFICS_DEF_OSID_HIUX_MPP                              21
#define CAOL_OSSPECIFICS_DEF_OSID_HPUX                                  22
#define CAOL_OSSPECIFICS_DEF_OSID_IBM_OS400                             23
#define CAOL_OSSPECIFICS_DEF_OSID_INTEGRITY                             24
#define CAOL_OSSPECIFICS_DEF_OSID_Interix_Environment                   25
#define CAOL_OSSPECIFICS_DEF_OSID_IRIX                                  26
#define CAOL_OSSPECIFICS_DEF_OSID_Linux_kernel                          27
#define CAOL_OSSPECIFICS_DEF_OSID_LynxOS                                28
#define CAOL_OSSPECIFICS_DEF_OSID_MacOS                                 29
#define CAOL_OSSPECIFICS_DEF_OSID_Microware_OS9                         30
#define CAOL_OSSPECIFICS_DEF_OSID_MINIX                                 31
#define CAOL_OSSPECIFICS_DEF_OSID_MorphOS                               32
#define CAOL_OSSPECIFICS_DEF_OSID_MPE_iX                                33
#define CAOL_OSSPECIFICS_DEF_OSID_MSDOS                                 34
#define CAOL_OSSPECIFICS_DEF_OSID_NetBSD                                35
#define CAOL_OSSPECIFICS_DEF_OSID_NonStop                               36
#define CAOL_OSSPECIFICS_DEF_OSID_NucleusRTOS                           37
#define CAOL_OSSPECIFICS_DEF_OSID_OpenBSD                               38
#define CAOL_OSSPECIFICS_DEF_OSID_OS2                                   39
#define CAOL_OSSPECIFICS_DEF_OSID_PalmOS                                40
#define CAOL_OSSPECIFICS_DEF_OSID_Plan9                                 41
#define CAOL_OSSPECIFICS_DEF_OSID_Pyramid_DCOSx                         42
#define CAOL_OSSPECIFICS_DEF_OSID_QNX                                   43
#define CAOL_OSSPECIFICS_DEF_OSID_Reliant_UNIX                          44
#define CAOL_OSSPECIFICS_DEF_OSID_SCO_OpenServer                        45
#define CAOL_OSSPECIFICS_DEF_OSID_Solaris                               46
#define CAOL_OSSPECIFICS_DEF_OSID_Stratus_VOS                           47
#define CAOL_OSSPECIFICS_DEF_OSID_SVR4_Environment                      48
#define CAOL_OSSPECIFICS_DEF_OSID_Syllable                              49
#define CAOL_OSSPECIFICS_DEF_OSID_SymbianOS                             50
#define CAOL_OSSPECIFICS_DEF_OSID_Tru64_OSF1                            51
#define CAOL_OSSPECIFICS_DEF_OSID_Ultrix                                52
#define CAOL_OSSPECIFICS_DEF_OSID_UNICOS                                53
#define CAOL_OSSPECIFICS_DEF_OSID_UNICOS_mp                             54
#define CAOL_OSSPECIFICS_DEF_OSID_UNIX_Environment                      55
#define CAOL_OSSPECIFICS_DEF_OSID_UnixWare                              56
#define CAOL_OSSPECIFICS_DEF_OSID_UWin_Environment                      57
#define CAOL_OSSPECIFICS_DEF_OSID_VMS                                   58
#define CAOL_OSSPECIFICS_DEF_OSID_VxWorks                               59
#define CAOL_OSSPECIFICS_DEF_OSID_Windows                               60
#define CAOL_OSSPECIFICS_DEF_OSID_Windows_CE                            61
#define CAOL_OSSPECIFICS_DEF_OSID_WindU_Environment                     62
#define CAOL_OSSPECIFICS_DEF_OSID_zOS                                   63

#if (defined(_AIX) || defined(__TOS_AIX__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_AIX
#elif defined(__ANDROID__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Android
#elif defined(UTS)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Amdahl_UTS
#elif (defined(AMIGA) || defined(__amigaos__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_AmigaOS
#elif defined(aegis)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Apollo_AEGIS
#elif defined(apollo)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Apollo_DomainOS
#elif defined(__BEOS__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BeOS
#elif (defined(__bg__) || defined(__THW_BLUEGENE__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Blue_Gene
#elif (defined(__FreeBSD__)   || \
       defined(__NetBSD__)    || \
       defined(__OpenBSD__)   || \
       defined(__bsdi__)      || \
       defined(__DragonFly__) || \
       defined(_SYSTYPE_BSD)     \
    )
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BSD_Environment
#elif defined(__bsdi__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_BSDOS
#elif defined(__convex__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_ConvexOS
#elif defined(__CYGWIN__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Cygwin_Environment
#elif (defined(DGUX) || defined(__DGUX__) || defined(__dgux__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_DG_UX
#elif defined(__DragonFly__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_DragonFly
#elif (defined(_SEQUENT_) || defined(sequent))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_DYNIX_ptx
#elif defined(__ECOS)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_eCos
#elif defined(__EMX__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_EMX_Environment
#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_FreeBSD
#elif (defined(__GNU__) || defined(__gnu_hurd__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_GNU_Hurd
#elif defined(__FreeBSD_kernel__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_GNU_kFreeBSD
#elif defined(__gnu_linux__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_GNU_Linux
#elif defined(__hiuxmpp)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_HIUX_MPP
#elif (defined(_hpux) || defined(hpux) || defined(__hpux))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_HPUX
#elif defined(__OS400__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_IBM_OS400
#elif defined(__INTEGRITY)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_INTEGRITY
#elif defined(__INTERIX)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Interix_Environment
#elif (defined(sgiv) || defined(__sgi))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_IRIX
#elif defined(__linux__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Linux_kernel
#elif defined(__Lynx__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_LynxOS
#elif (defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__)))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MacOS
#elif (defined(__OS9000) || defined(_OSK))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Microware_OS9
#elif defined(__minix)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MINIX
#elif defined(__MORPHOS__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MorphOS
#elif (defined(mpeix) || defined(__mpexl))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MPE_iX
#elif (defined(MSDOS)     || \
       defined(__MSDOS__) || \
       defined(_MSDOS)    || \
       defined(__DOS__)      \
    )
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_MSDOS
#elif defined(__NetBSD__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_NetBSD
#elif defined(__TANDEM)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_NonStop
#elif defined(__nucleus__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_NucleusRTOS
#elif defined(__OpenBSD__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_OpenBSD
#elif (defined(OS2)      || \
       defined(_OS2)     || \
       defined(__OS2__)  || \
       defined(__TOS_OS2__) \
    )
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_OS2
#elif defined(__palmos__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_PalmOS
#elif defined(EPLAN9)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Plan9
#elif defined(pyr)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Pyramid_DCOSx
#elif (defined(__QNX__) || defined(__QNXNTO__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_QNX
#elif defined(sinux)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Reliant_UNIX
#elif (defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_SCO_OpenServer
#elif (defined(sun) || defined(__sun))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Solaris
#elif defined(__VOS__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Stratus_VOS
#elif (defined(__sysv__)   || \
       defined(__SVR4)     || \
       defined(__svr4__)   || \
       defined(_SYSTYPE_SVR4) \
    )
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_SVR4_Environment
#elif defined(__SYLLABLE__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Syllable
#elif defined(__SYMBIAN32__)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_SymbianOS
#elif (defined(__osf__) || defined(__osf))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Tru64_OSF1
#elif (defined(ultrix) || defined(__ultrix) || defined(__ultrix__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Ultrix
#elif defined(_UNICOS)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UNICOS
#elif (defined(_CRAY) || defined(__crayx1))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UNICOS_mp
#elif (defined(__unix__) || defined(__unix))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UNIX_Environment
#elif (defined(sco) || defined(_UNIXWARE7))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UnixWare
#elif defined(_UWIN)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_UWin_Environment
#elif (defined(VMS) || defined(__VMS))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_VMS
#elif (defined(__VXWORKS__) || defined(__vxworks))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_VxWorks
#elif (defined(_WIN16)      || \
       defined(_WIN32)      || \
       defined(_WIN64)      || \
       defined(__WIN32__)   || \
       defined(__TOS_WIN__) || \
       defined(__WINDOWS__)    \
    )
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Windows
#elif defined(_WIN32_WCE)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_Windows_CE
#elif defined(_WINDU_SOURCE)
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_WindU_Environment
#elif (defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__))
    #define CAOL_OSSPECIFICS_DEF_OS_ID CAOL_OSSPECIFICS_DEF_OSID_zOS
#endif

#endif