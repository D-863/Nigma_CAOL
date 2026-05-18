#include "headers/diagnosis.h"

uint8_t caolCheckstrs(char *sA, char *sB) {
    register uint8_t a = 0;
    register uint8_t r = 0;
    while (r == 0) {
        a = sA[0];
        r = a ^ sB[0];
        r |= ((a | r) == 0);

        ++sA;
        ++sB;
    }
    return r - 1;
}
