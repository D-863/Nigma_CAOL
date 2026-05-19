#ifndef NIGMA_CAOL_DIAGNOSIS_H
#define NIGMA_CAOL_DIAGNOSIS_H


#include "nCAOL.h"

extern uint8_t caolCheckstrs(char *sA, char *sB);

#define CAOL_DIAGNOSIS_DEF_FSTR(y) #y
#define CAOL_DIAGNOSIS_DEF_STR(x) CAOL_DIAGNOSIS_DEF_FSTR(x)


#define caolDiagnosis() \
    printf("Architecture<%s> {\n\tClass<%u>,\n\tID<%u>\n}\n",                                                     \
        caolSpecsArch(CURRENT, ARCH, NAME),                                                                       \
        caolSpecsArch(CURRENT, ARCH, CLASS),                                                                      \
        caolSpecsArch(CURRENT, ARCH, ID)                                                                          \
    );                                                                                                            \
    printf("C-Standard<%s> {\n\tID<%u>\n}\n",                                                                     \
        caolSpecsCSTD(CURRENT, STD, NAME),                                                                        \
        caolSpecsCSTD(CURRENT, STD, ID)                                                                           \
    );                                                                                                            \
    printf("OS<%s> {\n\tSubject<%u>,\n\tDomain<%u>,\n\tID<%u>\n}\n",                                              \
        caolSpecsOS(CURRENT, OS, NAME),                                                                           \
        caolSpecsOS(CURRENT, OS, SUBJECT),                                                                        \
        caolSpecsOS(CURRENT, OS, DOMAIN),                                                                         \
        caolSpecsOS(CURRENT, OS, ID)                                                                              \
    );                                                                                                            \
    printf("C-STDLIB<%s> {\n\tID<%u>\n}\n",                                                                       \
        caolSpecsCSTDLIB(CURRENT, LIB, NAME),                                                                     \
        caolSpecsCSTDLIB(CURRENT, LIB, ID)                                                                        \
    );                                                                                                            \
    printf("Compiler<%s> {\n\tSubject<%u>,\n\tDomain<%u>,\n\tID<%u>,\n\tExtensions(THAT ARE NOT SUPPORTED): {\n", \
        caolSpecsComp(CURRENT, COMPILER, NAME),                                                                   \
        caolSpecsComp(CURRENT, COMPILER, SUBJECT),                                                                \
        caolSpecsComp(CURRENT, COMPILER, DOMAIN),                                                                 \
        caolSpecsComp(CURRENT, COMPILER, ID)                                                                      \
    );                                                                                                            \
    if (0x00 != caolCheckstrs("alias(target)",                                   CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, alias(target)                                  )))) { puts("\t\talias");                          } \
    if (0x00 != caolCheckstrs("aligned(alignment)",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, aligned(alignment)                             )))) { puts("\t\taligned");                        } \
    if (0x00 != caolCheckstrs("alloc_align(position)",                           CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, alloc_align(position)                          )))) { puts("\t\talloc_align");                    } \
    if (0x00 != caolCheckstrs("alloc_size(...)",                                 CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, alloc_size(...)                                )))) { puts("\t\talloc_size");                     } \
    if (0x00 != caolCheckstrs("always_inline static inline ...",                 CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, always_inline(...)                             )))) { puts("\t\talways_inline");                  } \
    if (0x00 != caolCheckstrs("artificial",                                      CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, artificial                                     )))) { puts("\t\tartificial");                     } \
    if (0x00 != caolCheckstrs("assume_aligned(...)",                             CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, assume_aligned(...)                            )))) { puts("\t\tassume_aligned");                 } \
    if (0x00 != caolCheckstrs("btf_decl_tag(str)",                               CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, btf_decl_tag(str)                              )))) { puts("\t\tbtf_decl_tag");                   } \
    if (0x00 != caolCheckstrs("btf_type_tag(arg)",                               CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, btf_type_tag(arg)                              )))) { puts("\t\tbtf_type_tag");                   } \
    if (0x00 != caolCheckstrs("cleanup(func)",                                   CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, cleanup(func)                                  )))) { puts("\t\tcleanup");                        } \
    if (0x00 != caolCheckstrs("cold",                                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, cold                                           )))) { puts("\t\tcold");                           } \
    if (0x00 != caolCheckstrs("hot",                                             CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, hot                                            )))) { puts("\t\thot");                            } \
    if (0x00 != caolCheckstrs("common",                                          CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, common                                         )))) { puts("\t\tcommon");                         } \
    if (0x00 != caolCheckstrs("nocommon",                                        CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nocommon                                       )))) { puts("\t\tnocommon");                       } \
    if (0x00 != caolCheckstrs("const",                                           CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, const                                          )))) { puts("\t\tconst");                          } \
    if (0x00 != caolCheckstrs("constructor(priority)",                           CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, constructor(priority)                          )))) { puts("\t\tconstructor");                    } \
    if (0x00 != caolCheckstrs("destructor(priority)",                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, destructor(priority)                           )))) { puts("\t\tdestructor");                     } \
    if (0x00 != caolCheckstrs("counted_by(count)",                               CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, counted_by(count)                              )))) { puts("\t\tcounted_by");                     } \
    if (0x00 != caolCheckstrs("deprecated(msg)",                                 CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, deprecated(msg)                                )))) { puts("\t\tdeprecated");                     } \
    if (0x00 != caolCheckstrs("error(msg)",                                      CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, error(msg)                                     )))) { puts("\t\terror");                          } \
    if (0x00 != caolCheckstrs("warning(msg)",                                    CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, warning(msg)                                   )))) { puts("\t\twarning");                        } \
    if (0x00 != caolCheckstrs("flag_enum",                                       CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, flag_enum                                      )))) { puts("\t\tflag_enum");                      } \
    if (0x00 != caolCheckstrs("flatten",                                         CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, flatten                                        )))) { puts("\t\tflatten");                        } \
    if (0x00 != caolCheckstrs("format(archetype, string_index, first_to_check)", CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, format(archetype, string_index, first_to_check))))) { puts("\t\tformat");                         } \
    if (0x00 != caolCheckstrs("format_arg(string_index)",                        CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, format_arg(string_index)                       )))) { puts("\t\tformat_arg");                     } \
    if (0x00 != caolCheckstrs("gnu_inline",                                      CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, gnu_inline                                     )))) { puts("\t\tgnu_inline");                     } \
    if (0x00 != caolCheckstrs("ifunc(resolver)",                                 CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, ifunc(resolver)                                )))) { puts("\t\tifunc");                          } \
    if (0x00 != caolCheckstrs("interrupt",                                       CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, interrupt                                      )))) { puts("\t\tinterrupt");                      } \
    if (0x00 != caolCheckstrs("leaf",                                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, leaf                                           )))) { puts("\t\tleaf");                           } \
    if (0x00 != caolCheckstrs("malloc ...",                                      CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, malloc(...)                                    )))) { puts("\t\tmalloc");                         } \
    if (0x00 != caolCheckstrs("may_alias",                                       CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, may_alias                                      )))) { puts("\t\tmay_alias");                      } \
    if (0x00 != caolCheckstrs("mode(mode)",                                      CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, mode(mode)                                     )))) { puts("\t\tmode");                           } \
    if (0x00 != caolCheckstrs("musttail",                                        CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, musttail                                       )))) { puts("\t\tmusttail");                       } \
    if (0x00 != caolCheckstrs("naked",                                           CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, naked                                          )))) { puts("\t\tnaked");                          } \
    if (0x00 != caolCheckstrs("no_profile_instrument_function",                  CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_profile_instrument_function(...)            )))) { puts("\t\tno_profile_instrument_function"); } \
    if (0x00 != caolCheckstrs("no_sanitize(option)",                             CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_sanitize(option)                            )))) { puts("\t\tno_sanitize");                    } \
    if (0x00 != caolCheckstrs("no_sanitize_address",                             CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_sanitize_address                            )))) { puts("\t\tno_sanitize_address");            } \
    if (0x00 != caolCheckstrs("no_address_safety_analysis",                      CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_address_safety_analysis(...)                )))) { puts("\t\tno_address_safety_analysis");     } \
    if (0x00 != caolCheckstrs("no_sanitize_thread",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_sanitize_thread                             )))) { puts("\t\tno_sanitize_thread");             } \
    if (0x00 != caolCheckstrs("no_split_stack",                                  CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_split_stack                                 )))) { puts("\t\tno_split_stack");                 } \
    if (0x00 != caolCheckstrs("no_stack_protector",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_stack_protector                             )))) { puts("\t\tno_stack_protector");             } \
    if (0x00 != caolCheckstrs("no_stack_protector",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_stack_protector                             )))) { puts("\t\tno_stack_protector");             } \
    if (0x00 != caolCheckstrs("noinline",                                        CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, noinline                                       )))) { puts("\t\tnoinline");                       } \
    if (0x00 != caolCheckstrs("nonnull ...",                                     CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nonnull(...)                                   )))) { puts("\t\tnonnull");                        } \
    if (0x00 != caolCheckstrs("nonstring",                                       CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nonstring                                      )))) { puts("\t\tnonstring");                      } \
    if (0x00 != caolCheckstrs(CAOL_DIAGNOSIS_DEF_STR(noreturn),                  CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, noreturn                                       )))) { puts("\t\tnoreturn");                       } \
    if (0x00 != caolCheckstrs("nothrow",                                         CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nothrow                                        )))) { puts("\t\tnothrow");                        } \
    if (0x00 != caolCheckstrs("optimize",                                        CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, optimize                                       )))) { puts("\t\toptimize");                       } \
    if (0x00 != caolCheckstrs("packed",                                          CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, packed                                         )))) { puts("\t\tpacked");                         } \
    if (0x00 != caolCheckstrs("patchable_function_entry",                        CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, patchable_function_entry                       )))) { puts("\t\tpatchable_function_entry");       } \
    if (0x00 != caolCheckstrs("pure",                                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, pure                                           )))) { puts("\t\tpure");                           } \
    if (0x00 != caolCheckstrs("reproducible",                                    CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, reproducible                                   )))) { puts("\t\treproducible");                   } \
    if (0x00 != caolCheckstrs("retain",                                          CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, retain                                         )))) { puts("\t\tretain");                         } \
    if (0x00 != caolCheckstrs("returns_nonnull",                                 CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, returns_nonnull                                )))) { puts("\t\treturns_nonnull");                } \
    if (0x00 != caolCheckstrs("returns_twice",                                   CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, returns_twice                                  )))) { puts("\t\treturns_twice");                  } \
    if (0x00 != caolCheckstrs("section(section)",                                CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, section(section)                               )))) { puts("\t\tsection");                        } \
    if (0x00 != caolCheckstrs("sentinel(position)",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, sentinel(position)                             )))) { puts("\t\tsentinel");                       } \
    if (0x00 != caolCheckstrs("target(...)",                                     CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, target(...)                                    )))) { puts("\t\ttarget");                         } \
    if (0x00 != caolCheckstrs("target_version(option)",                          CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, target_version(option)                         )))) { puts("\t\ttarget_version");                 } \
    if (0x00 != caolCheckstrs("target_clones(options)",                          CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, target_clones(options)                         )))) { puts("\t\ttarget_clones");                  } \
    if (0x00 != caolCheckstrs("tls_model(tls_model)",                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, tls_model(tls_model)                           )))) { puts("\t\ttls_model");                      } \
    if (0x00 != caolCheckstrs("transparent_union",                               CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, transparent_union                              )))) { puts("\t\ttransparent_union");              } \
    if (0x00 != caolCheckstrs("unavailable(msg)",                                CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, unavailable(msg)                               )))) { puts("\t\tunavailable");                    } \
    if (0x00 != caolCheckstrs("uninitialized",                                   CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, uninitialized                                  )))) { puts("\t\tuninitialized");                  } \
    if (0x00 != caolCheckstrs("unsequenced",                                     CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, unsequenced                                    )))) { puts("\t\tunsequenced");                    } \
    if (0x00 != caolCheckstrs("unused",                                          CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, maybe_unused                                   )))) { puts("\t\tmaybe_unused");                   } \
    if (0x00 != caolCheckstrs("used",                                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, used                                           )))) { puts("\t\tused");                           } \
    if (0x00 != caolCheckstrs("vector_size(bytes)",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, vector_size(bytes)                             )))) { puts("\t\tvector_size");                    } \
    if (0x00 != caolCheckstrs("visibility(visibility_type)",                     CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, visibility(visibility_type)                    )))) { puts("\t\tvisibility");                     } \
    if (0x00 != caolCheckstrs("warn_unused_result",                              CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nodiscard                                      )))) { puts("\t\tnodiscard");                      } \
    if (0x00 != caolCheckstrs("weak",                                            CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, weak                                           )))) { puts("\t\tweak");                           } \
    if (0x00 != caolCheckstrs("weakref(target)",                                 CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, weakref(target)                                )))) { puts("\t\tweakref");                        } \
    if (0x00 != caolCheckstrs("zero_call_used_regs(choice)",                     CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, zero_call_used_regs(choice)                    )))) { puts("\t\tzero_call_used_regs");            } \
    puts("\t}\n}")

#define caolDiagnosisCompEXTs() \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, alias(target)                                  ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, aligned(alignment)                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, alloc_align(position)                          ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, alloc_size(...)                                ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, always_inline(...)                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, artificial                                     ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, assume_aligned(...)                            ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, btf_decl_tag(str)                              ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, btf_type_tag(arg)                              ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, cleanup(func)                                  ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, cold                                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, hot                                            ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, common                                         ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nocommon                                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, const                                          ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, constructor(priority)                          ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, destructor(priority)                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, counted_by(count)                              ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, deprecated(msg)                                ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, error(msg)                                     ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, warning(msg)                                   ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, flag_enum                                      ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, flatten                                        ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, format(archetype, string_index, first_to_check)))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, format_arg(string_index)                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, gnu_inline                                     ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, ifunc(resolver)                                ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, interrupt                                      ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, leaf                                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, malloc(...)                                    ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, may_alias                                      ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, mode(mode)                                     ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, musttail                                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, naked                                          ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_profile_instrument_function(...)            ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_sanitize(option)                            ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_sanitize_address                            ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_address_safety_analysis(...)                ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_sanitize_thread                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_split_stack                                 ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_stack_protector                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, no_stack_protector                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, noinline                                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nonnull(...)                                   ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nonstring                                      ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, noreturn                                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nothrow                                        ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, optimize                                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, packed                                         ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, patchable_function_entry                       ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, pure                                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, reproducible                                   ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, retain                                         ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, returns_nonnull                                ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, returns_twice                                  ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, section(section)                               ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, sentinel(position)                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, target(...)                                    ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, target_version(option)                         ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, target_clones(options)                         ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, tls_model(tls_model)                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, transparent_union                              ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, unavailable(msg)                               ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, uninitialized                                  ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, unsequenced                                    ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, maybe_unused                                   ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, used                                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, vector_size(bytes)                             ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, visibility(visibility_type)                    ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, nodiscard                                      ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, weak                                           ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, weakref(target)                                ))); \
    puts(CAOL_DIAGNOSIS_DEF_STR(caolSpecsComp(EXT, GET, zero_call_used_regs(choice)                    )))

#endif