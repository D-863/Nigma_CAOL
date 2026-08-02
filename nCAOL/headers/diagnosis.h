#ifndef NIGMA_CAOL_DIAGNOSIS_H
#define NIGMA_CAOL_DIAGNOSIS_H


#include "nCAOL.h"

extern uint8_t caolCheckstrs(char *sA, char *sB);

#define NCAOL_DIAGNOSIS_DEF_FSTR(y) #y
#define NCAOL_DIAGNOSIS_DEF_STR(x) NCAOL_DIAGNOSIS_DEF_FSTR(x)


#define caolDiagnosis() \
    (void)printf("Architecture<%s> {\n\tClass<%u>,\n\tID<%u>\n}\n",                                                     \
        caolSpecsArch(NCAOL_CURRENT_ARCH_NAME),                                                                         \
        caolSpecsArch(NCAOL_CURRENT_ARCH_CLASS),                                                                        \
        caolSpecsArch(NCAOL_CURRENT_ARCH_ID)                                                                            \
    );                                                                                                                  \
    (void)printf("C-Standard<%s> {\n\tID<%u>\n}\n",                                                                     \
        caolSpecsCSTD(NCAOL_CURRENT_STD_NAME),                                                                          \
        caolSpecsCSTD(NCAOL_CURRENT_STD_ID)                                                                             \
    );                                                                                                                  \
    (void)printf("OS<%s> {\n\tSubject<%u>,\n\tDomain<%u>,\n\tID<%u>\n}\n",                                              \
        caolSpecsOS(NCAOL_CURRENT_OS_NAME),                                                                             \
        caolSpecsOS(NCAOL_CURRENT_OS_SUBJECT),                                                                          \
        caolSpecsOS(NCAOL_CURRENT_OS_DOMAIN),                                                                           \
        caolSpecsOS(NCAOL_CURRENT_OS_ID)                                                                                \
    );                                                                                                                  \
    (void)printf("C-STDLIB<%s> {\n\tID<%u>\n}\n",                                                                       \
        caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_NAME),                                                                       \
        caolSpecsCSTDLIB(NCAOL_CURRENT_LIB_ID)                                                                          \
    );                                                                                                                  \
    (void)printf("Compiler<%s> {\n\tSubject<%u>,\n\tDomain<%u>,\n\tID<%u>,\n\tExtensions(THAT ARE NOT SUPPORTED): {\n", \
        caolSpecsComp(NCAOL_CURRENT_COMPILER_NAME),                                                                     \
        caolSpecsComp(NCAOL_CURRENT_COMPILER_SUBJECT),                                                                  \
        caolSpecsComp(NCAOL_CURRENT_COMPILER_DOMAIN),                                                                   \
        caolSpecsComp(NCAOL_CURRENT_COMPILER_ID)                                                                        \
    );                                                                                                                  \
    if (0x00 != caolCheckstrs("alias(NCAOLtarget)",                         NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalias(NCAOLtarget)                         ))))) { (void)puts("\t\talias");                          } \
    if (0x00 != caolCheckstrs("aligned(NCAOLalignment)",                    NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLaligned(NCAOLalignment)                    ))))) { (void)puts("\t\taligned");                        } \
    if (0x00 != caolCheckstrs("alloc_align(NCAOLposition)",                 NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalloc_align(NCAOLposition)                 ))))) { (void)puts("\t\talloc_align");                    } \
    if (0x00 != caolCheckstrs("alloc_size (NCAOL_VA_ARGS)",                 NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalloc_size((NCAOL_VA_ARGS))                ))))) { (void)puts("\t\talloc_size");                     } \
    if (0x00 != caolCheckstrs("always_inline static inline",                NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalways_inline                              ))))) { (void)puts("\t\talways_inline");                  } \
    if (0x00 != caolCheckstrs("artificial",                                 NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLartificial                                 ))))) { (void)puts("\t\tartificial");                     } \
    if (0x00 != caolCheckstrs("assume_aligned (NCAOL_VA_ARGS)",             NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLassume_aligned((NCAOL_VA_ARGS))            ))))) { (void)puts("\t\tassume_aligned");                 } \
    if (0x00 != caolCheckstrs("btf_decl_tag(NCAOLstr)",                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLbtf_decl_tag(NCAOLstr)                     ))))) { (void)puts("\t\tbtf_decl_tag");                   } \
    if (0x00 != caolCheckstrs("btf_type_tag(NCAOLarg)",                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLbtf_type_tag(NCAOLarg)                     ))))) { (void)puts("\t\tbtf_type_tag");                   } \
    if (0x00 != caolCheckstrs("cleanup(NCAOLfunc)",                         NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcleanup(NCAOLfunc)                         ))))) { (void)puts("\t\tcleanup");                        } \
    if (0x00 != caolCheckstrs("cold",                                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcold                                       ))))) { (void)puts("\t\tcold");                           } \
    if (0x00 != caolCheckstrs("hot",                                        NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLhot                                        ))))) { (void)puts("\t\thot");                            } \
    if (0x00 != caolCheckstrs("common",                                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcommon                                     ))))) { (void)puts("\t\tcommon");                         } \
    if (0x00 != caolCheckstrs("nocommon",                                   NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnocommon                                   ))))) { (void)puts("\t\tnocommon");                       } \
    if (0x00 != caolCheckstrs("const",                                      NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLconst                                      ))))) { (void)puts("\t\tconst");                          } \
    if (0x00 != caolCheckstrs("constructor(NCAOLpriority)",                 NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLconstructor(NCAOLpriority)                 ))))) { (void)puts("\t\tconstructor");                    } \
    if (0x00 != caolCheckstrs("destructor(NCAOLpriority)",                  NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLdestructor(NCAOLpriority)                  ))))) { (void)puts("\t\tdestructor");                     } \
    if (0x00 != caolCheckstrs("counted_by(NCAOLcount)",                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcounted_by(NCAOLcount)                     ))))) { (void)puts("\t\tcounted_by");                     } \
    if (0x00 != caolCheckstrs("deprecated(NCAOLmsg)",                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLdeprecated(NCAOLmsg)                       ))))) { (void)puts("\t\tdeprecated");                     } \
    if (0x00 != caolCheckstrs("error(NCAOLmsg)",                            NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLerror(NCAOLmsg)                            ))))) { (void)puts("\t\terror");                          } \
    if (0x00 != caolCheckstrs("warning(NCAOLmsg)",                          NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLwarning(NCAOLmsg)                          ))))) { (void)puts("\t\twarning");                        } \
    if (0x00 != caolCheckstrs("flag_enum",                                  NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLflag_enum                                  ))))) { (void)puts("\t\tflag_enum");                      } \
    if (0x00 != caolCheckstrs("flatten",                                    NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLflatten                                    ))))) { (void)puts("\t\tflatten");                        } \
    if (0x00 != caolCheckstrs("format(NCAOLarchT, NCAOLindex, NCAOLcheck)", NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLformat(NCAOLarchT, NCAOLindex, NCAOLcheck) ))))) { (void)puts("\t\tformat");                         } \
    if (0x00 != caolCheckstrs("format_arg(NCAOLstring_index)",              NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLformat_arg(NCAOLstring_index)              ))))) { (void)puts("\t\tformat_arg");                     } \
    if (0x00 != caolCheckstrs("gnu_inline",                                 NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLgnu_inline                                 ))))) { (void)puts("\t\tgnu_inline");                     } \
    if (0x00 != caolCheckstrs("ifunc(NCAOLresolver)",                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLifunc(NCAOLresolver)                       ))))) { (void)puts("\t\tifunc");                          } \
    if (0x00 != caolCheckstrs("interrupt",                                  NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLinterrupt                                  ))))) { (void)puts("\t\tinterrupt");                      } \
    if (0x00 != caolCheckstrs("leaf",                                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLleaf                                       ))))) { (void)puts("\t\tleaf");                           } \
    if (0x00 != caolCheckstrs("malloc (NCAOL_VA_ARGS)",                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmalloc((NCAOL_VA_ARGS))                    ))))) { (void)puts("\t\tmalloc");                         } \
    if (0x00 != caolCheckstrs("may_alias",                                  NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmay_alias                                  ))))) { (void)puts("\t\tmay_alias");                      } \
    if (0x00 != caolCheckstrs("mode(NCAOLmode)",                            NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmode(NCAOLmode)                            ))))) { (void)puts("\t\tmode");                           } \
    if (0x00 != caolCheckstrs("musttail",                                   NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmusttail                                   ))))) { (void)puts("\t\tmusttail");                       } \
    if (0x00 != caolCheckstrs("naked",                                      NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnaked                                      ))))) { (void)puts("\t\tnaked");                          } \
    if (0x00 != caolCheckstrs("no_profile_instrument_function",             NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_profile_instrument_function             ))))) { (void)puts("\t\tno_profile_instrument_function"); } \
    if (0x00 != caolCheckstrs("no_sanitize(NCAOLoption)",                   NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_sanitize(NCAOLoption)                   ))))) { (void)puts("\t\tno_sanitize");                    } \
    if (0x00 != caolCheckstrs("no_sanitize_address",                        NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_sanitize_address                        ))))) { (void)puts("\t\tno_sanitize_address");            } \
    if (0x00 != caolCheckstrs("no_sanitize_thread",                         NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_sanitize_thread                         ))))) { (void)puts("\t\tno_sanitize_thread");             } \
    if (0x00 != caolCheckstrs("no_split_stack",                             NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_split_stack                             ))))) { (void)puts("\t\tno_split_stack");                 } \
    if (0x00 != caolCheckstrs("no_stack_protector",                         NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_stack_protector                         ))))) { (void)puts("\t\tno_stack_protector");             } \
    if (0x00 != caolCheckstrs("noinline",                                   NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnoinline                                   ))))) { (void)puts("\t\tnoinline");                       } \
    if (0x00 != caolCheckstrs("nonnull (NCAOL_VA_ARGS)",                    NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnonnull((NCAOL_VA_ARGS))                   ))))) { (void)puts("\t\tnonnull");                        } \
    if (0x00 != caolCheckstrs("nonstring",                                  NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnonstring                                  ))))) { (void)puts("\t\tnonstring");                      } \
    if (0x00 != caolCheckstrs(NCAOL_DIAGNOSIS_DEF_STR(noreturn),            NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnoreturn                                   ))))) { (void)puts("\t\tnoreturn");                       } \
    if (0x00 != caolCheckstrs("nothrow",                                    NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnothrow                                    ))))) { (void)puts("\t\tnothrow");                        } \
    if (0x00 != caolCheckstrs("optimize",                                   NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLoptimize                                   ))))) { (void)puts("\t\toptimize");                       } \
    if (0x00 != caolCheckstrs("packed",                                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLpacked                                     ))))) { (void)puts("\t\tpacked");                         } \
    if (0x00 != caolCheckstrs("patchable_function_entry",                   NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLpatchable_function_entry                   ))))) { (void)puts("\t\tpatchable_function_entry");       } \
    if (0x00 != caolCheckstrs("pure",                                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLpure                                       ))))) { (void)puts("\t\tpure");                           } \
    if (0x00 != caolCheckstrs("reproducible",                               NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLreproducible                               ))))) { (void)puts("\t\treproducible");                   } \
    if (0x00 != caolCheckstrs("retain",                                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLretain                                     ))))) { (void)puts("\t\tretain");                         } \
    if (0x00 != caolCheckstrs("returns_nonnull",                            NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLreturns_nonnull                            ))))) { (void)puts("\t\treturns_nonnull");                } \
    if (0x00 != caolCheckstrs("returns_twice",                              NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLreturns_twice                              ))))) { (void)puts("\t\treturns_twice");                  } \
    if (0x00 != caolCheckstrs("section(NCAOLsection)",                      NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLsection(NCAOLsection)                      ))))) { (void)puts("\t\tsection");                        } \
    if (0x00 != caolCheckstrs("sentinel(NCAOLposition)",                    NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLsentinel(NCAOLposition)                    ))))) { (void)puts("\t\tsentinel");                       } \
    if (0x00 != caolCheckstrs("target (NCAOL_VA_ARGS)",                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtarget((NCAOL_VA_ARGS))                    ))))) { (void)puts("\t\ttarget");                         } \
    if (0x00 != caolCheckstrs("target_version(NCAOLoption)",                NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtarget_version(NCAOLoption)                ))))) { (void)puts("\t\ttarget_version");                 } \
    if (0x00 != caolCheckstrs("target_clones(NCAOLoptions)",                NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtarget_clones(NCAOLoptions)                ))))) { (void)puts("\t\ttarget_clones");                  } \
    if (0x00 != caolCheckstrs("tls_model(NCAOLtls_model)",                  NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtls_model(NCAOLtls_model)                  ))))) { (void)puts("\t\ttls_model");                      } \
    if (0x00 != caolCheckstrs("transparent_union",                          NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtransparent_union                          ))))) { (void)puts("\t\ttransparent_union");              } \
    if (0x00 != caolCheckstrs("unavailable(NCAOLmsg)",                      NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLunavailable(NCAOLmsg)                      ))))) { (void)puts("\t\tunavailable");                    } \
    if (0x00 != caolCheckstrs("uninitialized",                              NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLuninitialized                              ))))) { (void)puts("\t\tuninitialized");                  } \
    if (0x00 != caolCheckstrs("unsequenced",                                NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLunsequenced                                ))))) { (void)puts("\t\tunsequenced");                    } \
    if (0x00 != caolCheckstrs("unused",                                     NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmaybe_unused                               ))))) { (void)puts("\t\tmaybe_unused");                   } \
    if (0x00 != caolCheckstrs("used",                                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLused                                       ))))) { (void)puts("\t\tused");                           } \
    if (0x00 != caolCheckstrs("vector_size(NCAOLbytes)",                    NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLvector_size(NCAOLbytes)                    ))))) { (void)puts("\t\tvector_size");                    } \
    if (0x00 != caolCheckstrs("visibility(NCAOLvisibility_type)",           NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLvisibility(NCAOLvisibility_type)           ))))) { (void)puts("\t\tvisibility");                     } \
    if (0x00 != caolCheckstrs("warn_unused_result",                         NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnodiscard                                  ))))) { (void)puts("\t\tnodiscard");                      } \
    if (0x00 != caolCheckstrs("weak",                                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLweak                                       ))))) { (void)puts("\t\tweak");                           } \
    if (0x00 != caolCheckstrs("weakref(NCAOLtarget)",                       NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLweakref(NCAOLtarget)                       ))))) { (void)puts("\t\tweakref");                        } \
    if (0x00 != caolCheckstrs("zero_call_used_regs(NCAOLchoice)",           NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLzero_call_used_regs(NCAOLchoice)           ))))) { (void)puts("\t\tzero_call_used_regs");            } \
    (void)puts("\t}\n}")

#define caolDiagnosisCompEXTs() \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalias(NCAOLtarget)                         )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLaligned(NCAOLalignment)                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalloc_align(NCAOLposition)                 )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalloc_size((NCAOL_VA_ARGS))                )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLalways_inline                              )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLartificial                                 )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLassume_aligned((NCAOL_VA_ARGS))            )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLbtf_decl_tag(NCAOLstr)                     )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLbtf_type_tag(NCAOLarg)                     )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcleanup(NCAOLfunc)                         )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcold                                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLhot                                        )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcommon                                     )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnocommon                                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLconst                                      )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLconstructor(NCAOLpriority)                 )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLdestructor(NCAOLpriority)                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLcounted_by(NCAOLcount)                     )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLdeprecated(NCAOLmsg)                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLerror(NCAOLmsg)                            )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLwarning(NCAOLmsg)                          )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLflag_enum                                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLflatten                                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLformat(NCAOLarchT, NCAOLindex, NCAOLcheck) )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLformat_arg(NCAOLstring_index)              )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLgnu_inline                                 )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLifunc(NCAOLresolver)                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLinterrupt                                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLleaf                                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmalloc((NCAOL_VA_ARGS))                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmay_alias                                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmode(NCAOLmode)                            )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmusttail                                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnaked                                      )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_profile_instrument_function             )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_sanitize(NCAOLoption)                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_sanitize_address                        )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_sanitize_thread                         )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_split_stack                             )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLno_stack_protector                         )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnoinline                                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnonnull((NCAOL_VA_ARGS))                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnonstring                                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnoreturn                                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnothrow                                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLoptimize                                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLpacked                                     )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLpatchable_function_entry                   )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLpure                                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLreproducible                               )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLretain                                     )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLreturns_nonnull                            )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLreturns_twice                              )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLsection(NCAOLsection)                      )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLsentinel(NCAOLposition)                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtarget((NCAOL_VA_ARGS))                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtarget_version(NCAOLoption)                )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtarget_clones(NCAOLoptions)                )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtls_model(NCAOLtls_model)                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLtransparent_union                          )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLunavailable(NCAOLmsg)                      )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLuninitialized                              )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLunsequenced                                )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLmaybe_unused                               )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLused                                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLvector_size(NCAOLbytes)                    )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLvisibility(NCAOLvisibility_type)           )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLnodiscard                                  )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLweak                                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLweakref(NCAOLtarget)                       )))); \
    (void)puts(NCAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(NCAOL_EXT_GET(NCAOLzero_call_used_regs(NCAOLchoice)           ))))


#endif
