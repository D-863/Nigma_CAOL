#ifndef NIGMA_CAOL_SPECIFICS_COMPILER_H
#define NIGMA_CAOL_SPECIFICS_COMPILER_H

#include "cstandard.h"
#include "values/compiler.h"

/*Compiler-Specific identifications:
FPGA_Specfic:
    Altium:
        MicroBlaze C:
            __CMB__

        C-to-Hardware:
            __CHC__

ARM_Specfic:
    KEIL:
        CARM:
            (__CA__ || __KEIL__)

        C166:
            __C166__

        C51:
            (__C51__ || __CX51__)

    ARM-Compiler:
        __CC_ARM

    IAR:
        //To be found.

RISC-V_Specific:
        For what I know, the compiler used is very Architecture specific,
        which makes by RISC-V's nature.

        So I will add this in the future when I got a working RP2350.
    - Sincerly, Nigma -

Generic:
    Clang:
        __clang__

    GCC:
        __GNUC__

    Microsoft Visual C++:
        _MSC_VER

    MinGW:
        MinGW32:
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            )
        )

        MinGW-w64_32B:
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            ) || (
                __MINGW64_VERSION_MAJOR ||
                __MINGW64_VERSION_MINOR
            )
        )

        MinGW-w64_64B:
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            ) || (
                __MINGW64__ ||
                __MINGW64_VERSION_MAJOR ||
                __MINGW64_VERSION_MINOR
            )
        )
*/
#if defined(__CMB__)
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //Altium MicroBlaze C
    /*
        __VERSION__ = VRRR
            V: Version
            RRR: Revision
        __REVISION__ = P
            P: Patch
        __BUILD__ = VRRRPPP
            VRRRPPP: Build number
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_FPGA
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_Altium
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_MicroBlazeC
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_MicroBlazeC
#elif defined(__CHC__)
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //Altium C-to-Hardware
    /*
        __VERSION__ = VRRR
            V: Version
            RRR: Revision
        __REVISION__ = P
            P: Patch
        __BUILD__ = VRRRPPP
            VRRRPPP: Build number
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_FPGA
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_Altium
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_CtoHardware
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_CtoHardware
#elif (defined(__CA__) || defined(__KEIL__))
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //KEIL CARM
    /*
        __CA__ = VRR
        V: Version
        RR: Revision
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_CARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_CARM
#elif defined(__C166__)
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //KEIL C166
    /*
        __C166__ = VRR
        V: Version
        RR: Revision
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_C166
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_C166
#elif (defined(__C51__) || defined(__CX51__))
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //KEIL C51
    /*
        __C51__ = VRR
        V: Version
        RR: Revision
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_C51
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_C51
#elif defined(__CC_ARM)
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //ARM Compiler
    /*
        __ARMCC_VERSION = VRPBBB
            V: Version
            R: Revision
            P: Patch
            BBB: Build
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_ARM
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_ARMCompiler
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_ARMCompiler
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_ARMCompiler
#elif defined(__clang__)
    //Clang
    /*
        __clang_major__ = V
            V: Major version
        __clang_major__ = R
            R: Minor version
        __clang_major__ = P
            P: Patch level
        __clang_major__ = V.R.P
            V: Major version
            R: Minor version
            P: Patch level
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_Clang
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_Clang
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_Clang


    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>

    
    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
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

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       warn_unused_result
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #else
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       nodiscard
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    maybe_unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(target)                                   alias(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                                   always_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                      artificial
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                            cold
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                             hot
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                          common
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                        nocommon
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                           const
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(msg)                                      error(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                       flag_enum
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                         flatten
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                       interrupt
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                            leaf
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                       may_alias
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                        musttail
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                           naked
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                        noinline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                       nonstring
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                         nothrow
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                        optimize
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                          packed
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                            pure
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                          retain
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                                   returns_twice
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(section)                                section(section)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                               transparent_union
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                                   uninitialized
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                            used
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                            weak
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif defined(__GNUC__)
    //GCC
    /*
        __GNUC__ = V
            V: Version
        __GNUC_MINOR__ = R
            R: Revision

        (Version 3.0)
        __GNUC_PATCHLEVEL__ = P
            P: Patch
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_GCC
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_GCC
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_GCC


    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>


    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
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

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       warn_unused_result
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #else
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       nodiscard
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    maybe_unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(target)                                   alias(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                                   always_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                      artificial
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                            cold
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                             hot
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                          common
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                        nocommon
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                           const
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(msg)                                      error(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough                                     fallthrough
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                       flag_enum
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                         flatten
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                       interrupt
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                            leaf
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                       may_alias
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                        musttail
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                           naked
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                        noinline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                       nonstring
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                         nothrow
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                        optimize
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                          packed
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                            pure
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                          retain
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                                   returns_twice
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(section)                                section(section)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                               transparent_union
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                                   uninitialized
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                            used
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                            weak
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif defined(_MSC_VER)
    //Microsoft Visual C++
    /*
        _MSC_VER = VVRR
            VV: Version
            RR: Revision

        (Version 6.0)
        _MSC_FULL_VER = VVRRPPPP
            VV: Version
            RR: Revision
            PPPP: Patch

        (Version 8.0)
        _MSC_FULL_VER = VVRRPPPPP
            VV: Version
            RR: Revision
            PPPPP: Patch

        (Version 9.0)
        _MSC_BUILD = B
            B: Build number
    */
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_MicrosoftVisualCPP
    #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME    NCAOL_SPECS_COMP_VAL_NAME_MicrosoftVisualCPP
    #define NCAOL_SPECS_COMP_DEF_COMPILER_ID      NCAOL_SPECS_COMP_VAL_ID_MicrosoftVisualCPP


    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>


    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
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

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       warn_unused_result
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #else
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       nodiscard
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    maybe_unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(target)                                   alias(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                                   always_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                      artificial
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                            cold
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                             hot
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                          common
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                        nocommon
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                           const
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(msg)                                      error(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough                                     fallthrough
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                       flag_enum
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                         flatten
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                       interrupt
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                            leaf
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                       may_alias
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                        musttail
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                           naked
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                        noinline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                       nonstring
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                         nothrow
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                        optimize
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                          packed
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                            pure
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                          retain
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                                   returns_twice
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(section)                                section(section)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                               transparent_union
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                                   uninitialized
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                            used
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                            weak
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif (defined(__MINGW32__) || defined(__MINGW32_MAJOR_VERSION) || defined(__MINGW32_MINOR_VERSION))
    //MinGW
    #define NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT NCAOL_SPECS_COMP_VAL_SUB_Generic
    #define NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN  NCAOL_SPECS_COMP_VAL_DOMAIN_MinGW

    #if (defined(__MINGW64_VERSION_MAJOR) || defined(__MINGW64_VERSION_MINOR))
        //MinGW-w64
        /*
            __MINGW32_MAJOR_VERSION = V
                V: Version for MinGW32.
            __MINGW32_MINOR_VERSION = R
                R: Revision for MinGW32.

            __MINGW64_VERSION_MAJOR = V
                V: Version for MinGW-w64.
            __MINGW64_VERSION_MINOR = R
                R: Revision for MinGW-w64.
        */
        #if defined(__MINGW64__)
            //MinGW-w64_64B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME NCAOL_SPECS_COMP_VAL_NAME_MinGWw64_64B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_ID   NCAOL_SPECS_COMP_VAL_ID_MinGWw64_64B
        #else
            //MinGW-w64_32B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME NCAOL_SPECS_COMP_VAL_NAME_MinGWw64_32B
            #define NCAOL_SPECS_COMP_DEF_COMPILER_ID   NCAOL_SPECS_COMP_VAL_ID_MinGWw64_32B
        #endif
    #else
        //MinGW32
        /*
            __MINGW32_MAJOR_VERSION = V
                V: Version for MinGW32.
            __MINGW32_MINOR_VERSION = R
                R: Revision for MinGW32.
        */
        #define NCAOL_SPECS_COMP_DEF_COMPILER_NAME NCAOL_SPECS_COMP_VAL_NAME_MinGW32
        #define NCAOL_SPECS_COMP_DEF_COMPILER_ID   NCAOL_SPECS_COMP_VAL_ID_MinGW32
    #endif


    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>


    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
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

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       warn_unused_result
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #else
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough     fallthrough
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard       nodiscard
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused    maybe_unused
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn        noreturn
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced     unsequenced
        #define NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alias(target)                                   alias(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline                                   always_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_artificial                                      artificial
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_cold                                            cold
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_hot                                             hot
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_common                                          common
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon                                        nocommon
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_const                                           const
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_error(msg)                                      error(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_fallthrough                                     fallthrough
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum                                       flag_enum
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_flatten                                         flatten
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt                                       interrupt
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_leaf                                            leaf
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias                                       may_alias
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_musttail                                        musttail
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_naked                                           naked
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_noinline                                        noinline
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring                                       nonstring
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow                                         nothrow
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_optimize                                        optimize
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_packed                                          packed
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_pure                                            pure
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_retain                                          retain
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice                                   returns_twice
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_section(section)                                section(section)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union                               transparent_union
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized                                   uninitialized
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_used                                            used
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weak                                            weak
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#else
    #error "nCAOL: Apologizes, but it seems like the utilized compiler is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

#if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
    #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_FUNC(extName) NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START extName NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP
#else
    #define NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_FUNC(extName) [[NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE::extName]]
#endif


#define caolCompilifics(t, ...) NCAOL_SPECS_COMP_INTER_##t(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_COMPILER(t, ...) NCAOL_SPECS_COMP_INTER_COMPILER_##t(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_COMPILER_SUBJECT(t) NCAOL_SPECS_COMP_INTER_COMPILER_SUBJECT_##t
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN(t)  NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_##t
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME(t)    NCAOL_SPECS_COMP_INTER_COMPILER_NAME_##t
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID(t)      NCAOL_SPECS_COMP_INTER_COMPILER_ID_##t

#define NCAOL_SPECS_COMP_INTER_COMPILER_SUBJECT_FPGA    NCAOL_SPECS_COMP_VAL_SUB_FPGA
#define NCAOL_SPECS_COMP_INTER_COMPILER_SUBJECT_ARM     NCAOL_SPECS_COMP_VAL_SUB_ARM
#define NCAOL_SPECS_COMP_INTER_COMPILER_SUBJECT_RiscV   NCAOL_SPECS_COMP_VAL_SUB_RiscV
#define NCAOL_SPECS_COMP_INTER_COMPILER_SUBJECT_Generic NCAOL_SPECS_COMP_VAL_SUB_Generic

#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_Altium             NCAOL_SPECS_COMP_VAL_DOMAIN_Altium
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_KEIL               NCAOL_SPECS_COMP_VAL_DOMAIN_KEIL
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_ARMCompiler        NCAOL_SPECS_COMP_VAL_DOMAIN_ARMCompiler
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_Clang              NCAOL_SPECS_COMP_VAL_DOMAIN_Clang
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_GCC                NCAOL_SPECS_COMP_VAL_DOMAIN_GCC
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_MicrosoftVisualCPP NCAOL_SPECS_COMP_VAL_DOMAIN_MicrosoftVisualCPP
#define NCAOL_SPECS_COMP_INTER_COMPILER_DOMAIN_MinGW              NCAOL_SPECS_COMP_VAL_DOMAIN_MinGW

#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_MicroBlazeC        NCAOL_SPECS_COMP_VAL_NAME_MicroBlazeC
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_CtoHardware        NCAOL_SPECS_COMP_VAL_NAME_CtoHardware
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_CARM               NCAOL_SPECS_COMP_VAL_NAME_CARM
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_C166               NCAOL_SPECS_COMP_VAL_NAME_C166
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_C51                NCAOL_SPECS_COMP_VAL_NAME_C51
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_ARMCompiler        NCAOL_SPECS_COMP_VAL_NAME_ARMCompiler
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_Clang              NCAOL_SPECS_COMP_VAL_NAME_Clang
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_GCC                NCAOL_SPECS_COMP_VAL_NAME_GCC
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_MicrosoftVisualCPP NCAOL_SPECS_COMP_VAL_NAME_MicrosoftVisualCPP
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_MinGW32            NCAOL_SPECS_COMP_VAL_NAME_MinGW32
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_MinGWw64_32B       NCAOL_SPECS_COMP_VAL_NAME_MinGWw64_32B
#define NCAOL_SPECS_COMP_INTER_COMPILER_NAME_MinGWw64_64B       NCAOL_SPECS_COMP_VAL_NAME_MinGWw64_64B

#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_MicroBlazeC        NCAOL_SPECS_COMP_VAL_ID_MicroBlazeC
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_CtoHardware        NCAOL_SPECS_COMP_VAL_ID_CtoHardware
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_CARM               NCAOL_SPECS_COMP_VAL_ID_CARM
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_C166               NCAOL_SPECS_COMP_VAL_ID_C166
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_C51                NCAOL_SPECS_COMP_VAL_ID_C51
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_ARMCompiler        NCAOL_SPECS_COMP_VAL_ID_ARMCompiler
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_Clang              NCAOL_SPECS_COMP_VAL_ID_Clang
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_GCC                NCAOL_SPECS_COMP_VAL_ID_GCC
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_MicrosoftVisualCPP NCAOL_SPECS_COMP_VAL_ID_MicrosoftVisualCPP
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_MinGW32            NCAOL_SPECS_COMP_VAL_ID_MinGW32
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_MinGWw64_32B       NCAOL_SPECS_COMP_VAL_ID_MinGWw64_32B
#define NCAOL_SPECS_COMP_INTER_COMPILER_ID_MinGWw64_64B       NCAOL_SPECS_COMP_VAL_ID_MinGWw64_64B


#define NCAOL_SPECS_COMP_INTER_CURRENT(t, ...) NCAOL_SPECS_COMP_INTER_CURRENT_##t(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_CURRENT_COMPILER(t) NCAOL_SPECS_COMP_INTER_CURRENT_COMPILER_##t
#define NCAOL_SPECS_COMP_INTER_CURRENT_COMPILER_SUBJECT NCAOL_SPECS_COMP_DEF_COMPILER_SUBJECT
#define NCAOL_SPECS_COMP_INTER_CURRENT_COMPILER_DOMAIN  NCAOL_SPECS_COMP_DEF_COMPILER_DOMAIN
#define NCAOL_SPECS_COMP_INTER_CURRENT_COMPILER_NAME    NCAOL_SPECS_COMP_DEF_COMPILER_NAME
#define NCAOL_SPECS_COMP_INTER_CURRENT_COMPILER_ID      NCAOL_SPECS_COMP_DEF_COMPILER_ID

#define NCAOL_SPECS_COMP_INTER_CURRENT_FUNC() NCAOL_SPECS_COMP_DEF_CURRENT_FUNC
#define NCAOL_SPECS_COMP_INTER_CURRENT_FILE() NCAOL_SPECS_COMP_DEF_CURRENT_FILE
#define NCAOL_SPECS_COMP_INTER_CURRENT_LINE() NCAOL_SPECS_COMP_DEF_CURRENT_LINE
#define NCAOL_SPECS_COMP_INTER_CURRENT_DATE() NCAOL_SPECS_COMP_DEF_CURRENT_DATE
#define NCAOL_SPECS_COMP_INTER_CURRENT_TIME() NCAOL_SPECS_COMP_DEF_CURRENT_TIME


#define NCAOL_SPECS_COMP_INTER_EXT(t, ...) NCAOL_SPECS_COMP_INTER_EXT_##t(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_EXT_NAMESPACE() NCAOL_SPECS_COMP_DEF_EXTENSION_NAMESPACE
#define NCAOL_SPECS_COMP_INTER_EXT_START()     NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_START
#define NCAOL_SPECS_COMP_INTER_EXT_STOP()      NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_STOP
#define NCAOL_SPECS_COMP_INTER_EXT_GET(ext)    NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_##ext
#define NCAOL_SPECS_COMP_INTER_EXT_WRAP(ext)   NCAOL_SPECS_COMP_DEF_EXTENSION_WRAP_FUNC(NCAOL_SPECS_COMP_INTER_EXT_GET(ext))


#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_alias(target)                                   NCAOL_SPECS_COMP_DEF_EXTNAME_alias(target)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_aligned(alignment)                              NCAOL_SPECS_COMP_DEF_EXTNAME_aligned(alignment)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_alloc_align(position)                           NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_align(position)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_alloc_size(...)                                 NCAOL_SPECS_COMP_DEF_EXTNAME_alloc_size(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_always_inline(...)                              NCAOL_SPECS_COMP_DEF_EXTNAME_always_inline static inline __VA_ARGS__
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_artificial                                      NCAOL_SPECS_COMP_DEF_EXTNAME_artificial
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_assume_aligned(...)                             NCAOL_SPECS_COMP_DEF_EXTNAME_assume_aligned(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_btf_decl_tag(str)                               NCAOL_SPECS_COMP_DEF_EXTNAME_btf_decl_tag(str)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_btf_type_tag(arg)                               NCAOL_SPECS_COMP_DEF_EXTNAME_btf_type_tag(arg)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_cleanup(func)                                   NCAOL_SPECS_COMP_DEF_EXTNAME_cleanup(func)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_cold                                            NCAOL_SPECS_COMP_DEF_EXTNAME_cold
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_hot                                             NCAOL_SPECS_COMP_DEF_EXTNAME_hot
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_common                                          NCAOL_SPECS_COMP_DEF_EXTNAME_common
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_nocommon                                        NCAOL_SPECS_COMP_DEF_EXTNAME_nocommon
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_const                                           NCAOL_SPECS_COMP_DEF_EXTNAME_const
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_constructor(priority)                           NCAOL_SPECS_COMP_DEF_EXTNAME_constructor(priority)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_destructor(priority)                            NCAOL_SPECS_COMP_DEF_EXTNAME_destructor(priority)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_counted_by(count)                               NCAOL_SPECS_COMP_DEF_EXTNAME_counted_by(count)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_deprecated(msg)                                 NCAOL_SPECS_COMP_DEF_EXTNAME_deprecated(msg)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_error(msg)                                      NCAOL_SPECS_COMP_DEF_EXTNAME_error(msg)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_warning(msg)                                    NCAOL_SPECS_COMP_DEF_EXTNAME_warning(msg)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_flag_enum                                       NCAOL_SPECS_COMP_DEF_EXTNAME_flag_enum
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_flatten                                         NCAOL_SPECS_COMP_DEF_EXTNAME_flatten
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_format(archetype, string_index, first_to_check) NCAOL_SPECS_COMP_DEF_EXTNAME_format(archetype, string_index, first_to_check)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_format_arg(string_index)                        NCAOL_SPECS_COMP_DEF_EXTNAME_format_arg(string_index)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_gnu_inline                                      NCAOL_SPECS_COMP_DEF_EXTNAME_gnu_inline
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_ifunc(resolver)                                 NCAOL_SPECS_COMP_DEF_EXTNAME_ifunc(resolver)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_interrupt                                       NCAOL_SPECS_COMP_DEF_EXTNAME_interrupt
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_leaf                                            NCAOL_SPECS_COMP_DEF_EXTNAME_leaf
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_malloc(...)                                     NCAOL_SPECS_COMP_DEF_EXTNAME_malloc(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_may_alias                                       NCAOL_SPECS_COMP_DEF_EXTNAME_may_alias
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_mode(mode)                                      NCAOL_SPECS_COMP_DEF_EXTNAME_mode(mode)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_musttail                                        NCAOL_SPECS_COMP_DEF_EXTNAME_musttail
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_naked                                           NCAOL_SPECS_COMP_DEF_EXTNAME_naked
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_profile_instrument_function(...)             NCAOL_SPECS_COMP_DEF_EXTNAME_no_profile_instrument_function
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_sanitize(option)                             NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize(option)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_sanitize_address                             NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_address
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_address_safety_analysis(...)                 NCAOL_SPECS_COMP_DEF_EXTNAME_no_address_safety_analysis
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_sanitize_thread                              NCAOL_SPECS_COMP_DEF_EXTNAME_no_sanitize_thread
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_split_stack                                  NCAOL_SPECS_COMP_DEF_EXTNAME_no_split_stack
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_stack_protector                              NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_no_stack_protector                              NCAOL_SPECS_COMP_DEF_EXTNAME_no_stack_protector
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_noinline                                        NCAOL_SPECS_COMP_DEF_EXTNAME_noinline
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_nonnull(...)                                    NCAOL_SPECS_COMP_DEF_EXTNAME_nonnull(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_nonstring                                       NCAOL_SPECS_COMP_DEF_EXTNAME_nonstring
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_noreturn                                        NCAOL_SPECS_COMP_DEF_EXTNAME_noreturn
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_nothrow                                         NCAOL_SPECS_COMP_DEF_EXTNAME_nothrow
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_optimize                                        NCAOL_SPECS_COMP_DEF_EXTNAME_optimize
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_packed                                          NCAOL_SPECS_COMP_DEF_EXTNAME_packed
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_patchable_function_entry                        NCAOL_SPECS_COMP_DEF_EXTNAME_patchable_function_entry
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_pure                                            NCAOL_SPECS_COMP_DEF_EXTNAME_pure
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_reproducible                                    NCAOL_SPECS_COMP_DEF_EXTNAME_reproducible
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_retain                                          NCAOL_SPECS_COMP_DEF_EXTNAME_retain
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_returns_nonnull                                 NCAOL_SPECS_COMP_DEF_EXTNAME_returns_nonnull
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_returns_twice                                   NCAOL_SPECS_COMP_DEF_EXTNAME_returns_twice
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_section(section)                                NCAOL_SPECS_COMP_DEF_EXTNAME_section(section)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_sentinel(position)                              NCAOL_SPECS_COMP_DEF_EXTNAME_sentinel(position)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_target(...)                                     NCAOL_SPECS_COMP_DEF_EXTNAME_target(__VA_ARGS__)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_target_version(option)                          NCAOL_SPECS_COMP_DEF_EXTNAME_target_version(option)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_target_clones(options)                          NCAOL_SPECS_COMP_DEF_EXTNAME_target_clones(options)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_tls_model(tls_model)                            NCAOL_SPECS_COMP_DEF_EXTNAME_tls_model(tls_model)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_transparent_union                               NCAOL_SPECS_COMP_DEF_EXTNAME_transparent_union
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_unavailable(msg)                                NCAOL_SPECS_COMP_DEF_EXTNAME_unavailable(msg)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_uninitialized                                   NCAOL_SPECS_COMP_DEF_EXTNAME_uninitialized
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_unsequenced                                     NCAOL_SPECS_COMP_DEF_EXTNAME_unsequenced
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_maybe_unused                                    NCAOL_SPECS_COMP_DEF_EXTNAME_maybe_unused
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_used                                            NCAOL_SPECS_COMP_DEF_EXTNAME_used
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_vector_size(bytes)                              NCAOL_SPECS_COMP_DEF_EXTNAME_vector_size(bytes)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_visibility(visibility_type)                     NCAOL_SPECS_COMP_DEF_EXTNAME_visibility(visibility_type)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_nodiscard                                       NCAOL_SPECS_COMP_DEF_EXTNAME_nodiscard
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_weak                                            NCAOL_SPECS_COMP_DEF_EXTNAME_weak
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_weakref(target)                                 NCAOL_SPECS_COMP_DEF_EXTNAME_weakref(target)
#define NCAOL_SPECS_COMP_INTER_EXTENSION_NAME_zero_call_used_regs(choice)                     NCAOL_SPECS_COMP_DEF_EXTNAME_zero_call_used_regs(choice)

#endif