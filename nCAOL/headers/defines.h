#ifndef NIGMA_CAOL_DEFINES_H
#define NIGMA_CAOL_DEFINES_H


#include "specifics/interfaces.h"


//Include the utilized CSTDLIB's respective platform-specific headers, if any was identified or explicitly utilized.
#if (caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_ID) != caolSpecsCSTDLIB(NCAOL_LIB_ID_Bare))
    #if (caolSpecsOS(NCAOL_CURRENT_OS_ID) == caolSpecsOS(NCAOL_OS_ID_GNU_Linux))
        #if (caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_ID) == caolSpecsCSTDLIB(NCAOL_LIB_ID_glibc))
            #if (caolSpecsArch(NCAOL_CURRENT_ARCH_ID) == caolSpecsArch(NCAOL_ARCH_ID_x86_64))
                #include "platforms/GNU_Linux/includes/cstdlibs/glibc/x86_64.h"
            #endif
        #endif
    #elif (caolSpecsOS(NCAOL_CURRENT_OS_ID) == caolSpecsOS(NCAOL_OS_ID_Linux_kernel))
        #if (caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_ID) == caolSpecsCSTDLIB(NCAOL_LIB_ID_glibc))
            #if (caolSpecsArch(NCAOL_CURRENT_ARCH_ID) == caolSpecsArch(NCAOL_ARCH_ID_x86_64))
                #include "platforms/Linux_kernel/includes/cstdlibs/glibc/x86_64.h"
            #endif
        #endif
    #elif (caolSpecsOS(NCAOL_CURRENT_OS_ID) == caolSpecsOS(NCAOL_OS_ID_MacOS_X))
        #if (caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_ID) == caolSpecsCSTDLIB(NCAOL_LIB_ID_MACOSX))
            #if (caolSpecsArch(NCAOL_CURRENT_ARCH_ID) == caolSpecsArch(NCAOL_ARCH_ID_x86_64))
                #include "platforms/MacOS_X/includes/cstdlibs/MACOSX/x86_64.h"
            #endif
        #endif
    #elif (caolSpecsOS(NCAOL_CURRENT_OS_ID) == caolSpecsOS(NCAOL_OS_ID_Windows))
        #if (caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_ID) == caolSpecsCSTDLIB(NCAOL_LIB_ID_WINDOWS))
            #if (caolSpecsArch(NCAOL_CURRENT_ARCH_ID) == caolSpecsArch(NCAOL_ARCH_ID_x86_64))
                #include "platforms/Windows/includes/cstdlibs/WINDOWS/x86_64.h"
            #endif
        #endif
    #endif
#endif


#endif
