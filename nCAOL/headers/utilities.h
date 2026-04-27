#ifndef NIGMA_CAOL_UTILITIES_H
#define NIGMA_CAOL_UTILITIES_H

/*STD Libaries*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#if defined(NIGMA_CAOL_ENABLES_PATH)
    #include NIGMA_CAOL_ENABLES_PATH
#else
    #include "enables.h"
#endif

#if defined(NIGMA_CAOL_DEFINES_PATH)
    #include NIGMA_CAOL_DEFINES_PATH
#else
    #include "defines.h"
#endif

#endif