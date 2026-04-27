#ifndef NIGMA_CAOL_STANDILICS_H
#define NIGMA_CAOL_STANDILICS_H

/*Architecture-Specific identifications:
C89(K&R)/C90(ANSI-C):
C94/C95:
C99:
C11:
C17/C18:
C23:
*/
#define CAOL_STANDILICS_DEF_COMPSUB_C89C90 0
#define CAOL_STANDILICS_DEF_COMPSUB_C94C95 1
#define CAOL_STANDILICS_DEF_COMPSUB_C99    2
#define CAOL_STANDILICS_DEF_COMPSUB_C11    3
#define CAOL_STANDILICS_DEF_COMPSUB_C17C18 4
#define CAOL_STANDILICS_DEF_COMPSUB_C23    5

#if defined(__STDC_VERSION__)
    #if (__STDC_VERSION__ == 199409L)
        puts("C94/C95");
    #elif (__STDC_VERSION__ == 199901L)
        puts("C99");
    #elif (__STDC_VERSION__ == 201112L)
        puts("C11");
    #elif (__STDC_VERSION__ == 201710L)
        puts("C17/C18");
    #elif (__STDC_VERSION__ == 202311L)
        puts("C23");
    #else
        #error "nCAOL: Apologizes, but it seems like the utilized standard is unsupported!.."
    #endif
#else
    #if defined(__STDC__)
        puts("C89(Brian Kernighan & Dennis Ritchie) / C90(ANSI-C)");
    #else
        #error "nCAOL: Apologizes, but it seems like the utilized standard is unsupported! - Somehow one before C94/C95 that isn't C89(K&R)/C90(ANSI-C)?.."
    #endif
#endif

#endif