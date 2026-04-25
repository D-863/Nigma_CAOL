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

#if !defined(NIGMA_CAOL_ENABLES_PATH)
    #define NIGMA_CAOL_ENABLES_PATH "enables.h"
#endif

#include NIGMA_CAOL_ENABLES_PATH
#include "defines.h"

#endif