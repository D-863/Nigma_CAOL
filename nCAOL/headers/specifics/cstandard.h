#ifndef NIGMA_CAOL_SPECIFICS_CSTANDARD_H
#define NIGMA_CAOL_SPECIFICS_CSTANDARD_H


#include "ID/cstandard.h"

#if defined(NCAOL_SPECS_CSTD_DEF_STD_ID)
    #if (NCAOL_SPECS_CSTD_DEF_STD_ID == NCAOL_SPECS_CSTD_VAL_ID_C89C90)
    #elif (NCAOL_SPECS_CSTD_DEF_STD_ID == NCAOL_SPECS_CSTD_VAL_ID_C94C95)
    #elif (NCAOL_SPECS_CSTD_DEF_STD_ID == NCAOL_SPECS_CSTD_VAL_ID_C99)
    #elif (NCAOL_SPECS_CSTD_DEF_STD_ID == NCAOL_SPECS_CSTD_VAL_ID_C11)
    #elif (NCAOL_SPECS_CSTD_DEF_STD_ID == NCAOL_SPECS_CSTD_VAL_ID_C17C18)
    #elif (NCAOL_SPECS_CSTD_DEF_STD_ID == NCAOL_SPECS_CSTD_VAL_ID_C23)
    #endif
#else
    #error "nCAOL: Apologizes, but it seems like the utilized C-Standard is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif


#endif