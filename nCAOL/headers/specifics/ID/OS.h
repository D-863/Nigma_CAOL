#ifndef NIGMA_CAOL_SPECIFICS_ID_OS_H
#define NIGMA_CAOL_SPECIFICS_ID_OS_H


#include "values/OS.h"

/*OS-Specific identifications:
PDP7:

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

DOS:
    MS-DOS:
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


//Generic identifications:
//UnixLike:
#if (defined(NCAOL_SPECS_OS_DEF_OS_ID) == 0)
    //Other:
    #if defined(__ANDROID__)
        //Android:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Android
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Android

    #elif defined(aegis)
        //Apollo AEGIS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Apollo_AEGIS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Apollo_AEGIS

    #elif defined(apollo)
        //Apollo Domain/OS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Apollo_DomainOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Apollo_DomainOS

    #elif (defined(__GNU__) || defined(__gnu_hurd__))
        //GNU/Hurd:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_GNU_Hurd
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_GNU_Hurd

    #elif (defined(__FreeBSD_kernel__) && defined(__GLIBC__))
        //GNU/kFreeBSD:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_GNU_kFreeBSD
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_GNU_kFreeBSD

    #elif defined(__gnu_linux__)
        //GNU/Linux:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_GNU_Linux
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_GNU_Linux

    #elif defined(__linux__)
        //Linux kernel:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Linux_kernel
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Linux_kernel

    #elif defined(__Lynx__)
        //LynxOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_LynxOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_LynxOS

    #elif defined(__minix)
        //MINIX:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_MINIX
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_MINIX

    #elif (defined(__QNX__) || defined(__QNXNTO__))
        //QNX:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_QNX
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_QNX

    #elif defined(__SYLLABLE__)
        //Syllable:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Syllable
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Syllable
    #endif
#endif

//Unix:
#if (defined(NCAOL_SPECS_OS_DEF_OS_ID) == 0)
    //BSD:
    #if defined(__bsdi__)
        //BSD/OS:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_BSD_OS
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_BSD_OS

    #elif defined(__DragonFly__)
        //DragonFly:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_DragonFly
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_DragonFly

    #elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
        //FreeBSD:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_FreeBSD
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_FreeBSD

    #elif defined(__hiuxmpp)
        //HI-UX MPP:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_HIUX_MPP
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_HIUX_MPP

    #elif (defined(macintosh) || defined(Macintosh))
        //Mac OS 9:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_MacOS_9
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_MacOS_9

    #elif (defined(__APPLE__) && defined(__MACH__))
        //Mac OS X:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_MacOS_X
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_MacOS_X

    #elif defined(__NetBSD__)
        //NetBSD:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_NetBSD
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_NetBSD

    #elif defined(__OpenBSD__)
        //OpenBSD:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_OpenBSD
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_OpenBSD

    #elif (defined(ultrix) || defined(__ultrix) || defined(__ultrix__))
        //Ultrix:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_BSD
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_Ultrix
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_Ultrix

    //SystemV:
    #elif defined(_AIX)
        //AIX:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_AIX
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_AIX

    #elif (defined(DGUX) || defined(__DGUX__) || defined(__dgux__))
        //DG/UX:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_DG_UX
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_DG_UX

    #elif (defined(_SEQUENT_) || defined(sequent))
        //DYNIX/ptx:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_DYNIX_ptx
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_DYNIX_ptx

    #elif (defined(_hpux) || defined(hpux) || defined(__hpux))
        //HP-UX:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_HPUX
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_HPUX

    #elif defined(sinux)
        //Reliant UNIX:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_Reliant_UNIX
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_Reliant_UNIX

    //SystemV_R2:
    #elif defined(_UNICOS)
        //UNICOS:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV_R2
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_UNICOS
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_UNICOS

    #elif (defined(_CRAY) || defined(__crayx1))
        //UNICOS/mp:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV_R2
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_UNICOS_mp
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_UNICOS_mp

    //SystemV_R3:
    #elif (defined(sgi) || defined(__sgi))
        //IRIX:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV_R3
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_IRIX
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_IRIX

    //SystemV_R4:
    #elif (defined(__sysv__) || defined(__SVR4) || defined(__svr4__))
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV_R4

        #if defined(UTS)
            //Amdahl UTS:
            #if (defined(__unix__) || defined(__unix))
                #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
            #else
                #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
            #endif
            #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_Amdahl_UTS
            #define NCAOL_SPECS_OS_DEF_OS_ID NCAOL_SPECS_OS_VAL_ID_Amdahl_UTS

        #elif defined(pyr)
            //Pyramid DC/OSx:
            #if (defined(__unix__) || defined(__unix))
                #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
            #else
                #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
            #endif
            #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_Pyramid_DCOSx
            #define NCAOL_SPECS_OS_DEF_OS_ID NCAOL_SPECS_OS_VAL_ID_Pyramid_DCOSx

        #elif (defined(sun) || defined(__sun))
            //Solaris:
            #if (defined(__unix__) || defined(__unix))
                #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
            #else
                #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
            #endif
            #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_Solaris
            #define NCAOL_SPECS_OS_DEF_OS_ID NCAOL_SPECS_OS_VAL_ID_Solaris
        #endif

    //SystemV_R5:
    #elif defined(_SCO_DS)
        //SCO OpenServer:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV_R5
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_SCO_OpenServer
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_SCO_OpenServer

    #elif (defined(sco) || defined(_UNIXWARE7))
        //UnixWare:
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_SystemV_R5
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_UnixWare
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_UnixWare

    //OSF1:
    #elif (defined(__osf__) || defined(__osf))
        //Tru64 (OSF/1):
        #if (defined(__unix__) || defined(__unix))
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Unix
        #else
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_UnixLike
        #endif
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN NCAOL_SPECS_OS_VAL_DOMAIN_OSF1
        #define NCAOL_SPECS_OS_DEF_OS_NAME   NCAOL_SPECS_OS_VAL_NAME_Tru64_OSF1
        #define NCAOL_SPECS_OS_DEF_OS_ID     NCAOL_SPECS_OS_VAL_ID_Tru64_OSF1
    #endif
#endif

//DOS:
#if (defined(NCAOL_SPECS_OS_DEF_OS_ID) == 0)
    #if (defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__))
        #if defined(__EMX__)
            //EMX Environment:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_MSDOS
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_EMX_Environment
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_EMX_Environment
        #else
            //MSDOS:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_MSDOS
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_MSDOS
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_MSDOS
        #endif

    #elif (defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__))
        #if defined(__EMX__)
            //EMX Environment:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_OS2
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_EMX_Environment
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_EMX_Environment
        #else
            //OS/2:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_OS2
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_OS2
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_OS2
        #endif

    #elif (defined(_WIN16) || defined(_WIN32) || defined(_WIN64))
        #if defined(__CYGWIN__)
            //Cygwin Environment:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Windows
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Cygwin_Environment
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Cygwin_Environment

        #elif defined(_UWIN)
            //U/Win Environment:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Windows
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_UWin_Environment
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_UWin_Environment
        #else
            //Windows:
            #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_DOS
            #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Windows
            #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Windows
            #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Windows
        #endif
    #endif
#endif

//Other:
#if (defined(NCAOL_SPECS_OS_DEF_OS_ID) == 0)
    //Other:
    #if defined(AMIGA)
        //AmigaOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_AmigaOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_AmigaOS

    #elif defined(__BEOS__)
        //BeOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_BeOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_BeOS

    #elif (defined(__bg__) || defined(__THW_BLUEGENE__))
        //Blue Gene:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_BlueGene
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_BlueGene

    #elif defined(__convex__)
        //ConvexOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_ConvexOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_ConvexOS

    #elif defined(__ECOS)
        //eCos:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_eCos
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_eCos

    #elif defined(__OS400__)
        //IBM OS/400:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_IBM_OS400
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_IBM_OS400

    #elif defined(__INTEGRITY)
        //INTEGRITY:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_INTEGRITY
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_INTEGRITY

    #elif defined(__MORPHOS__)
        //MorphOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_MorphOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_MorphOS

    #elif (defined(mpeix) || defined(__mpexl))
        //MPE/iX:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_MPE_iX
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_MPE_iX

    #elif defined(__TANDEM)
        //NonStop:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_NonStop
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_NonStop

    #elif defined(__nucleus__)
        //Nucleus RTOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_NucleusRTOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_NucleusRTOS

    #elif defined(EPLAN9)
        //Plan 9:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Plan9
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Plan9

    #elif defined(__VOS__)
        //Stratus VOS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_Stratus_VOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_Stratus_VOS

    #elif defined(__SYMBIAN32__)
        //Symbian OS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_SymbianOS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_SymbianOS

    #elif (defined(VMS) || defined(__VMS))
        //OpenVMS:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_OpenVMS
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_OpenVMS

    #elif defined(_WINDU_SOURCE)
        //Wind/U Environment:
        #define NCAOL_SPECS_OS_DEF_OS_SUBJECT NCAOL_SPECS_OS_VAL_SUBJECT_Other
        #define NCAOL_SPECS_OS_DEF_OS_DOMAIN  NCAOL_SPECS_OS_VAL_DOMAIN_Other
        #define NCAOL_SPECS_OS_DEF_OS_NAME    NCAOL_SPECS_OS_VAL_NAME_WindU_Environment
        #define NCAOL_SPECS_OS_DEF_OS_ID      NCAOL_SPECS_OS_VAL_ID_WindU_Environment
    #endif
#endif


#endif