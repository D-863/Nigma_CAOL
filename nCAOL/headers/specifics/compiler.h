#ifndef NIGMA_CAOL_SPECIFICS_COMPILER_H
#define NIGMA_CAOL_SPECIFICS_COMPILER_H


#include "cstandard.h"
#include "ID/compiler.h"

#if defined(NCAOL_SPECS_COMP_DEF_COMPILER_ID)
    #if (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MicroBlazeC)
        #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_CtoHardware)
        #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_CARM)
        #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_C166)
        #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_C51)
        #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_ARMCompiler)
        #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_Clang)
        //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
        //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
        #include <limits.h>

        
        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C99)
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __FUNCTION__
        #else
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __func__
        #endif
        #define NCAOL_SPECS_COMP_DEF_CURRENT_FILE __FILE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_LINE __LINE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_DATE __DATE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_TIME __TIME__


        #define NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE clang
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START __attribute__((
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP ))

        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C23)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            warn_unused_result
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #else
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            nodiscard
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         maybe_unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #endif
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(NCAOLtarget)                         alias(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(NCAOLalignment)                    aligned(NCAOLalignment)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(NCAOLposition)                 alloc_align(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(NCAOL_VA_ARGS)                  alloc_size NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                              always_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                 artificial
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(NCAOL_VA_ARGS)              assume_aligned NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(NCAOLstr)                     btf_decl_tag(NCAOLstr)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(NCAOLarg)                     btf_type_tag(NCAOLarg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(NCAOLfunc)                         cleanup(NCAOLfunc)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                       cold
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                        hot
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                     common
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                   nocommon
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                      const
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(NCAOLpriority)                 constructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(NCAOLpriority)                  destructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(NCAOLcount)                     counted_by(NCAOLcount)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(NCAOLmsg)                            error(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(NCAOLmsg)                          warning(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                  flag_enum
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                    flatten
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(NCAOLarchT, NCAOLindex, NCAOLcheck) format(NCAOLarchT, NCAOLindex, NCAOLcheck)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(NCAOLstring_index)              format_arg(NCAOLstring_index)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                 gnu_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(NCAOLresolver)                       ifunc(NCAOLresolver)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                  interrupt
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                       leaf
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(NCAOL_VA_ARGS)                      malloc NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                  may_alias
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(NCAOLmode)                            mode(NCAOLmode)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                   musttail
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                      naked
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function             no_profile_instrument_function
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(NCAOLoption)                   no_sanitize(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                        no_sanitize_address
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                         no_sanitize_thread
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                             no_split_stack
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                   noinline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(NCAOL_VA_ARGS)                     nonnull NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                  nonstring
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                    nothrow
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                   optimize
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                     packed
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                   patchable_function_entry
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                       pure
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                     retain
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                            returns_nonnull
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                              returns_twice
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(NCAOLsection)                      section(NCAOLsection)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(NCAOLposition)                    sentinel(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(NCAOL_VA_ARGS)                      target NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(NCAOLoption)                target_version(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(NCAOLoptions)                target_clones(NCAOLoptions)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(NCAOLtls_model)                  tls_model(NCAOLtls_model)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                          transparent_union
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(NCAOLmsg)                      unavailable(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                              uninitialized
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                       used
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(NCAOLbytes)                    vector_size(NCAOLbytes)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(NCAOLvisibility_type)           visibility(NCAOLvisibility_type)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                       weak
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(NCAOLtarget)                       weakref(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(NCAOLchoice)           zero_call_used_regs(NCAOLchoice)
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_GCC)
        //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
        //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
        #include <limits.h>


        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C99)
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __FUNCTION__
        #else
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __func__
        #endif
        #define NCAOL_SPECS_COMP_DEF_CURRENT_FILE __FILE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_LINE __LINE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_DATE __DATE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_TIME __TIME__


        #define NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE gnu
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START __attribute__((
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP ))

        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C23)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            warn_unused_result
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #else
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            nodiscard
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         maybe_unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #endif
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(NCAOLtarget)                         alias(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(NCAOLalignment)                    aligned(NCAOLalignment)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(NCAOLposition)                 alloc_align(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(NCAOL_VA_ARGS)                  alloc_size NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                              always_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                 artificial
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(NCAOL_VA_ARGS)              assume_aligned NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(NCAOLstr)                     btf_decl_tag(NCAOLstr)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(NCAOLarg)                     btf_type_tag(NCAOLarg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(NCAOLfunc)                         cleanup(NCAOLfunc)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                       cold
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                        hot
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                     common
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                   nocommon
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                      const
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(NCAOLpriority)                 constructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(NCAOLpriority)                  destructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(NCAOLcount)                     counted_by(NCAOLcount)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(NCAOLmsg)                            error(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(NCAOLmsg)                          warning(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough                                fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                  flag_enum
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                    flatten
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(NCAOLarchT, NCAOLindex, NCAOLcheck) format(NCAOLarchT, NCAOLindex, NCAOLcheck)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(NCAOLstring_index)              format_arg(NCAOLstring_index)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                 gnu_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(NCAOLresolver)                       ifunc(NCAOLresolver)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                  interrupt
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                       leaf
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(NCAOL_VA_ARGS)                      malloc NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                  may_alias
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(NCAOLmode)                            mode(NCAOLmode)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                   musttail
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                      naked
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function             no_profile_instrument_function
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(NCAOLoption)                   no_sanitize(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                        no_sanitize_address
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                         no_sanitize_thread
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                             no_split_stack
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                   noinline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(NCAOL_VA_ARGS)                     nonnull NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                  nonstring
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                    nothrow
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                   optimize
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                     packed
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                   patchable_function_entry
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                       pure
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                     retain
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                            returns_nonnull
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                              returns_twice
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(NCAOLsection)                      section(NCAOLsection)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(NCAOLposition)                    sentinel(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(NCAOL_VA_ARGS)                      target NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(NCAOLoption)                target_version(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(NCAOLoptions)                target_clones(NCAOLoptions)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(NCAOLtls_model)                  tls_model(NCAOLtls_model)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                          transparent_union
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(NCAOLmsg)                      unavailable(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                              uninitialized
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                       used
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(NCAOLbytes)                    vector_size(NCAOLbytes)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(NCAOLvisibility_type)           visibility(NCAOLvisibility_type)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                       weak
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(NCAOLtarget)                       weakref(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(NCAOLchoice)           zero_call_used_regs(NCAOLchoice)
    #elif (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MicrosoftVisualCPP)
        //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
        //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
        #include <limits.h>


        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C99)
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __FUNCTION__
        #else
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __func__
        #endif
        #define NCAOL_SPECS_COMP_DEF_CURRENT_FILE __FILE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_LINE __LINE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_DATE __DATE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_TIME __TIME__


        #define NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE gnu
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START __attribute__((
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP ))

        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C23)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            warn_unused_result
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #else
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            nodiscard
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         maybe_unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #endif
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(NCAOLtarget)                         alias(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(NCAOLalignment)                    aligned(NCAOLalignment)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(NCAOLposition)                 alloc_align(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(NCAOL_VA_ARGS)                  alloc_size NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                              always_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                 artificial
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(NCAOL_VA_ARGS)              assume_aligned NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(NCAOLstr)                     btf_decl_tag(NCAOLstr)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(NCAOLarg)                     btf_type_tag(NCAOLarg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(NCAOLfunc)                         cleanup(NCAOLfunc)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                       cold
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                        hot
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                     common
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                   nocommon
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                      const
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(NCAOLpriority)                 constructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(NCAOLpriority)                  destructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(NCAOLcount)                     counted_by(NCAOLcount)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(NCAOLmsg)                            error(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(NCAOLmsg)                          warning(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough                                fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                  flag_enum
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                    flatten
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(NCAOLarchT, NCAOLindex, NCAOLcheck) format(NCAOLarchT, NCAOLindex, NCAOLcheck)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(NCAOLstring_index)              format_arg(NCAOLstring_index)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                 gnu_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(NCAOLresolver)                       ifunc(NCAOLresolver)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                  interrupt
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                       leaf
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(NCAOL_VA_ARGS)                      malloc NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                  may_alias
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(NCAOLmode)                            mode(NCAOLmode)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                   musttail
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                      naked
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function             no_profile_instrument_function
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(NCAOLoption)                   no_sanitize(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                        no_sanitize_address
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                         no_sanitize_thread
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                             no_split_stack
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                   noinline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(NCAOL_VA_ARGS)                     nonnull NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                  nonstring
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                    nothrow
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                   optimize
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                     packed
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                   patchable_function_entry
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                       pure
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                     retain
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                            returns_nonnull
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                              returns_twice
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(NCAOLsection)                      section(NCAOLsection)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(NCAOLposition)                    sentinel(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(NCAOL_VA_ARGS)                      target NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(NCAOLoption)                target_version(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(NCAOLoptions)                target_clones(NCAOLoptions)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(NCAOLtls_model)                  tls_model(NCAOLtls_model)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                          transparent_union
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(NCAOLmsg)                      unavailable(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                              uninitialized
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                       used
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(NCAOLbytes)                    vector_size(NCAOLbytes)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(NCAOLvisibility_type)           visibility(NCAOLvisibility_type)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                       weak
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(NCAOLtarget)                       weakref(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(NCAOLchoice)           zero_call_used_regs(NCAOLchoice)
    #elif ((NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MinGW32)      || \
           (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MinGWw64_32B) || \
           (NCAOL_SPECS_COMP_DEF_COMPILER_ID == NCAOL_SPECS_COMP_VAL_ID_MinGWw64_64B)    \
        )
        //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
        //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
        #include <limits.h>


        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C99)
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __FUNCTION__
        #else
            #define NCAOL_SPECS_COMP_DEF_CURRENT_FUNC __func__
        #endif
        #define NCAOL_SPECS_COMP_DEF_CURRENT_FILE __FILE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_LINE __LINE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_DATE __DATE__
        #define NCAOL_SPECS_COMP_DEF_CURRENT_TIME __TIME__


        #if defined(__clang__)
            #define NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE clang
        #else
            //either '__GNUC__' is defined or we simply default to it.
            #define NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE gnu
        #endif
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START __attribute__((
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP ))

        #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C23)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            warn_unused_result
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #else
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(NCAOLmsg) deprecated(NCAOLmsg)
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough          fallthrough
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard            nodiscard
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused         maybe_unused
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn             noreturn
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced          unsequenced
            #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible         reproducible
        #endif
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(NCAOLtarget)                         alias(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(NCAOLalignment)                    aligned(NCAOLalignment)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(NCAOLposition)                 alloc_align(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(NCAOL_VA_ARGS)                  alloc_size NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                              always_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                 artificial
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(NCAOL_VA_ARGS)              assume_aligned NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(NCAOLstr)                     btf_decl_tag(NCAOLstr)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(NCAOLarg)                     btf_type_tag(NCAOLarg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(NCAOLfunc)                         cleanup(NCAOLfunc)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                       cold
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                        hot
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                     common
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                   nocommon
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                      const
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(NCAOLpriority)                 constructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(NCAOLpriority)                  destructor(NCAOLpriority)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(NCAOLcount)                     counted_by(NCAOLcount)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(NCAOLmsg)                            error(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(NCAOLmsg)                          warning(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough                                fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                  flag_enum
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                    flatten
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(NCAOLarchT, NCAOLindex, NCAOLcheck) format(NCAOLarchT, NCAOLindex, NCAOLcheck)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(NCAOLstring_index)              format_arg(NCAOLstring_index)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                 gnu_inline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(NCAOLresolver)                       ifunc(NCAOLresolver)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                  interrupt
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                       leaf
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(NCAOL_VA_ARGS)                      malloc NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                  may_alias
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(NCAOLmode)                            mode(NCAOLmode)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                   musttail
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                      naked
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function             no_profile_instrument_function
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(NCAOLoption)                   no_sanitize(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                        no_sanitize_address
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                         no_sanitize_thread
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                             no_split_stack
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                         no_stack_protector
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                   noinline
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(NCAOL_VA_ARGS)                     nonnull NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                  nonstring
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                    nothrow
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                   optimize
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                     packed
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                   patchable_function_entry
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                       pure
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                     retain
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                            returns_nonnull
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                              returns_twice
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(NCAOLsection)                      section(NCAOLsection)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(NCAOLposition)                    sentinel(NCAOLposition)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(NCAOL_VA_ARGS)                      target NCAOL_VA_ARGS
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(NCAOLoption)                target_version(NCAOLoption)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(NCAOLoptions)                target_clones(NCAOLoptions)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(NCAOLtls_model)                  tls_model(NCAOLtls_model)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                          transparent_union
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(NCAOLmsg)                      unavailable(NCAOLmsg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                              uninitialized
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                       used
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(NCAOLbytes)                    vector_size(NCAOLbytes)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(NCAOLvisibility_type)           visibility(NCAOLvisibility_type)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                       weak
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(NCAOLtarget)                       weakref(NCAOLtarget)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(NCAOLchoice)           zero_call_used_regs(NCAOLchoice)
    #endif

    #if (NCAOL_SPECS_CSTD_DEF_STD_ID < NCAOL_SPECS_CSTD_VAL_ID_C23)
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_FUNC(extName) NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START extName NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP
    #else
        #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_FUNC(extName) [[NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE::extName]]
    #endif
#else
    #error "nCAOL: Apologizes, but it seems like the utilized Compiler is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif


#endif