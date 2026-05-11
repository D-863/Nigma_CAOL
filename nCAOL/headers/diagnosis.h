#ifndef NIGMA_CAOL_DIAGNOSIS_H
#define NIGMA_CAOL_DIAGNOSIS_H

#include "CAOL.h"

extern uint8_t checkstrs(char *sA, char *sB);

#define CAOL_DIAGNOSIS_DEF_FSTR(y) #y
#define CAOL_DIAGNOSIS_DEF_STR(x) CAOL_DIAGNOSIS_DEF_FSTR(x)

#define caolDiagnosis() \
    printf("Architecture (NOT YET IMPLEMENTED)\nStandard<%s> {\n\tID<%u>\n}\nC-Standard Library<%s> {\n\tID<%u>\n}\nCompiler<%s> {\n\tSubject<%u>,\n\tDomain<%u>,\n\tID<%u>,\n\tExtensions(THAT ARE NOT SUPPORTED): {\n", \
        caolStandilics(CURRENT, STD, NAME),                                 \
        caolStandilics(CURRENT, STD, ID),                                   \
                                                                            \
        caolSTDLibraspecs(CURRENT, LIB, NAME),                              \
        caolSTDLibraspecs(CURRENT, LIB, ID),                                \
                                                                            \
        caolCompilifics(CURRENT, COMPILER, NAME),                           \
        caolCompilifics(CURRENT, COMPILER, SUBJECT),                        \
        caolCompilifics(CURRENT, COMPILER, DOMAIN),                         \
        caolCompilifics(CURRENT, COMPILER, ID)                              \
    );                                                                      \
    if (0x00 != checkstrs("alias(target)",                                   CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, alias(target)                                  )))) { puts("alias");                          } \
    if (0x00 != checkstrs("aligned(alignment)",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, aligned(alignment)                             )))) { puts("aligned");                        } \
    if (0x00 != checkstrs("alloc_align(position)",                           CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, alloc_align(position)                          )))) { puts("alloc_align");                    } \
    if (0x00 != checkstrs("alloc_size(...)",                                 CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, alloc_size(...)                                )))) { puts("alloc_size");                     } \
    if (0x00 != checkstrs("always_inline static inline ...",                 CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, always_inline(...)                             )))) { puts("always_inline");                  } \
    if (0x00 != checkstrs("artificial",                                      CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, artificial                                     )))) { puts("artificial");                     } \
    if (0x00 != checkstrs("assume_aligned(...)",                             CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, assume_aligned(...)                            )))) { puts("assume_aligned");                 } \
    if (0x00 != checkstrs("btf_decl_tag(str)",                               CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, btf_decl_tag(str)                              )))) { puts("btf_decl_tag");                   } \
    if (0x00 != checkstrs("btf_type_tag(arg)",                               CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, btf_type_tag(arg)                              )))) { puts("btf_type_tag");                   } \
    if (0x00 != checkstrs("cleanup(func)",                                   CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, cleanup(func)                                  )))) { puts("cleanup");                        } \
    if (0x00 != checkstrs("cold",                                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, cold                                           )))) { puts("cold");                           } \
    if (0x00 != checkstrs("hot",                                             CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, hot                                            )))) { puts("hot");                            } \
    if (0x00 != checkstrs("common",                                          CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, common                                         )))) { puts("common");                         } \
    if (0x00 != checkstrs("nocommon",                                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, nocommon                                       )))) { puts("nocommon");                       } \
    if (0x00 != checkstrs("const",                                           CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, const                                          )))) { puts("const");                          } \
    if (0x00 != checkstrs("constructor(priority)",                           CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, constructor(priority)                          )))) { puts("constructor");                    } \
    if (0x00 != checkstrs("destructor(priority)",                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, destructor(priority)                           )))) { puts("destructor");                     } \
    if (0x00 != checkstrs("counted_by(count)",                               CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, counted_by(count)                              )))) { puts("counted_by");                     } \
    if (0x00 != checkstrs("deprecated(msg)",                                 CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, deprecated(msg)                                )))) { puts("deprecated");                     } \
    if (0x00 != checkstrs("error(msg)",                                      CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, error(msg)                                     )))) { puts("error");                          } \
    if (0x00 != checkstrs("warning(msg)",                                    CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, warning(msg)                                   )))) { puts("warning");                        } \
    if (0x00 != checkstrs("flag_enum",                                       CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, flag_enum                                      )))) { puts("flag_enum");                      } \
    if (0x00 != checkstrs("flatten",                                         CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, flatten                                        )))) { puts("flatten");                        } \
    if (0x00 != checkstrs("format(archetype, string_index, first_to_check)", CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, format(archetype, string_index, first_to_check))))) { puts("format");                         } \
    if (0x00 != checkstrs("format_arg(string_index)",                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, format_arg(string_index)                       )))) { puts("format_arg");                     } \
    if (0x00 != checkstrs("gnu_inline",                                      CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, gnu_inline                                     )))) { puts("gnu_inline");                     } \
    if (0x00 != checkstrs("ifunc(resolver)",                                 CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, ifunc(resolver)                                )))) { puts("ifunc");                          } \
    if (0x00 != checkstrs("interrupt",                                       CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, interrupt                                      )))) { puts("interrupt");                      } \
    if (0x00 != checkstrs("leaf",                                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, leaf                                           )))) { puts("leaf");                           } \
    if (0x00 != checkstrs("malloc ...",                                      CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, malloc(...)                                    )))) { puts("malloc");                         } \
    if (0x00 != checkstrs("may_alias",                                       CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, may_alias                                      )))) { puts("may_alias");                      } \
    if (0x00 != checkstrs("mode(mode)",                                      CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, mode(mode)                                     )))) { puts("mode");                           } \
    if (0x00 != checkstrs("musttail",                                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, musttail                                       )))) { puts("musttail");                       } \
    if (0x00 != checkstrs("naked",                                           CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, naked                                          )))) { puts("naked");                          } \
    if (0x00 != checkstrs("no_profile_instrument_function",                  CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_profile_instrument_function(...)            )))) { puts("no_profile_instrument_function"); } \
    if (0x00 != checkstrs("no_sanitize(option)",                             CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_sanitize(option)                            )))) { puts("no_sanitize");                    } \
    if (0x00 != checkstrs("no_sanitize_address",                             CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_sanitize_address                            )))) { puts("no_sanitize_address");            } \
    if (0x00 != checkstrs("no_address_safety_analysis",                      CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_address_safety_analysis(...)                )))) { puts("no_address_safety_analysis");     } \
    if (0x00 != checkstrs("no_sanitize_thread",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_sanitize_thread                             )))) { puts("no_sanitize_thread");             } \
    if (0x00 != checkstrs("no_split_stack",                                  CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_split_stack                                 )))) { puts("no_split_stack");                 } \
    if (0x00 != checkstrs("no_stack_protector",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_stack_protector                             )))) { puts("no_stack_protector");             } \
    if (0x00 != checkstrs("no_stack_protector",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, no_stack_protector                             )))) { puts("no_stack_protector");             } \
    if (0x00 != checkstrs("noinline",                                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, noinline                                       )))) { puts("noinline");                       } \
    if (0x00 != checkstrs("nonnull ...",                                     CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, nonnull(...)                                   )))) { puts("nonnull");                        } \
    if (0x00 != checkstrs("nonstring",                                       CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, nonstring                                      )))) { puts("nonstring");                      } \
    if (0x00 != checkstrs("noreturn",                                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, noreturn                                       )))) { puts("noreturn");                       } \
    if (0x00 != checkstrs("nothrow",                                         CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, nothrow                                        )))) { puts("nothrow");                        } \
    if (0x00 != checkstrs("optimize",                                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, optimize                                       )))) { puts("optimize");                       } \
    if (0x00 != checkstrs("packed",                                          CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, packed                                         )))) { puts("packed");                         } \
    if (0x00 != checkstrs("patchable_function_entry",                        CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, patchable_function_entry                       )))) { puts("patchable_function_entry");       } \
    if (0x00 != checkstrs("pure",                                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, pure                                           )))) { puts("pure");                           } \
    if (0x00 != checkstrs("reproducible",                                    CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, reproducible                                   )))) { puts("reproducible");                   } \
    if (0x00 != checkstrs("retain",                                          CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, retain                                         )))) { puts("retain");                         } \
    if (0x00 != checkstrs("returns_nonnull",                                 CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, returns_nonnull                                )))) { puts("returns_nonnull");                } \
    if (0x00 != checkstrs("returns_twice",                                   CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, returns_twice                                  )))) { puts("returns_twice");                  } \
    if (0x00 != checkstrs("section(section)",                                CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, section(section)                               )))) { puts("section");                        } \
    if (0x00 != checkstrs("sentinel(position)",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, sentinel(position)                             )))) { puts("sentinel");                       } \
    if (0x00 != checkstrs("target(...)",                                     CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, target(...)                                    )))) { puts("target");                         } \
    if (0x00 != checkstrs("target_version(option)",                          CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, target_version(option)                         )))) { puts("target_version");                 } \
    if (0x00 != checkstrs("target_clones(options)",                          CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, target_clones(options)                         )))) { puts("target_clones");                  } \
    if (0x00 != checkstrs("tls_model(tls_model)",                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, tls_model(tls_model)                           )))) { puts("tls_model");                      } \
    if (0x00 != checkstrs("transparent_union",                               CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, transparent_union                              )))) { puts("transparent_union");              } \
    if (0x00 != checkstrs("unavailable(msg)",                                CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, unavailable(msg)                               )))) { puts("unavailable");                    } \
    if (0x00 != checkstrs("uninitialized",                                   CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, uninitialized                                  )))) { puts("uninitialized");                  } \
    if (0x00 != checkstrs("unsequenced",                                     CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, unsequenced                                    )))) { puts("unsequenced");                    } \
    if (0x00 != checkstrs("unused",                                          CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, maybe_unused                                   )))) { puts("maybe_unused");                   } \
    if (0x00 != checkstrs("used",                                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, used                                           )))) { puts("used");                           } \
    if (0x00 != checkstrs("vector_size(bytes)",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, vector_size(bytes)                             )))) { puts("vector_size");                    } \
    if (0x00 != checkstrs("visibility(visibility_type)",                     CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, visibility(visibility_type)                    )))) { puts("visibility");                     } \
    if (0x00 != checkstrs("warn_unused_result",                              CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, nodiscard                                      )))) { puts("nodiscard");                      } \
    if (0x00 != checkstrs("weak",                                            CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, weak                                           )))) { puts("weak");                           } \
    if (0x00 != checkstrs("weakref(target)",                                 CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, weakref(target)                                )))) { puts("weakref");                        } \
    if (0x00 != checkstrs("zero_call_used_regs(choice)",                     CAOL_DIAGNOSIS_DEF_STR(caolCompilifics(EXT, GET, zero_call_used_regs(choice)                    )))) { puts("zero_call_used_regs");            } \
    puts("\t}\n}")

#endif