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
*/

#if (defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA))
#elif defined(__amd64__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#elif defined(__alpha__)
#endif

#endif