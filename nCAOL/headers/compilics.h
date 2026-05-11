#ifndef NIGMA_CAOL_COMPILIFICS_H
#define NIGMA_CAOL_COMPILIFICS_H

#include "standilics.h"

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
#define CAOL_COMPILIFICS_DEF_COMPSUB_FPGA    0
#define CAOL_COMPILIFICS_DEF_COMPSUB_ARM     1
#define CAOL_COMPILIFICS_DEF_COMPSUB_RiscV   2
#define CAOL_COMPILIFICS_DEF_COMPSUB_Generic 3

#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_Altium             0
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_KEIL               1
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_ARMCompiler        2
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_Clang              3
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_GCC                4
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_MicrosoftVisualCPP 5
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_MinGW              6

#define CAOL_COMPILIFICS_DEF_COMPID_MicroBlazeC        0
#define CAOL_COMPILIFICS_DEF_COMPID_CtoHardware        1
#define CAOL_COMPILIFICS_DEF_COMPID_CARM               2
#define CAOL_COMPILIFICS_DEF_COMPID_C166               3
#define CAOL_COMPILIFICS_DEF_COMPID_C51                4
#define CAOL_COMPILIFICS_DEF_COMPID_ARMCompiler        5
#define CAOL_COMPILIFICS_DEF_COMPID_Clang              6
#define CAOL_COMPILIFICS_DEF_COMPID_GCC                7
#define CAOL_COMPILIFICS_DEF_COMPID_MicrosoftVisualCPP 8
#define CAOL_COMPILIFICS_DEF_COMPID_MinGW32            9
#define CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_32B       10
#define CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_64B       11

#define CAOL_COMPILIFICS_DEF_COMPNAME_MicroBlazeC        "Altium MicroBlaze C"
#define CAOL_COMPILIFICS_DEF_COMPNAME_CtoHardware        "Altium C-to-Hardware"
#define CAOL_COMPILIFICS_DEF_COMPNAME_CARM               "KEIL CARM"
#define CAOL_COMPILIFICS_DEF_COMPNAME_C166               "KEIL C166"
#define CAOL_COMPILIFICS_DEF_COMPNAME_C51                "KEIL C51"
#define CAOL_COMPILIFICS_DEF_COMPNAME_ARMCompiler        "ARM Compiler"
#define CAOL_COMPILIFICS_DEF_COMPNAME_Clang              "Clang"
#define CAOL_COMPILIFICS_DEF_COMPNAME_GCC                "GCC"
#define CAOL_COMPILIFICS_DEF_COMPNAME_MicrosoftVisualCPP "Microsoft Visual C++"
#define CAOL_COMPILIFICS_DEF_COMPNAME_MinGW32            "MinGW32"
#define CAOL_COMPILIFICS_DEF_COMPNAME_MinGWw64_32B       "MinGW-w64 32B"
#define CAOL_COMPILIFICS_DEF_COMPNAME_MinGWw64_64B       "MinGW-w64 64B"

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
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_FPGA
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_Altium
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_MicroBlazeC
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_MicroBlazeC
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_FPGA
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_Altium
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_CtoHardware
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_CtoHardware
#elif (defined(__CA__) || defined(__KEIL__))
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //KEIL CARM
    /*
        __CA__ = VRR
        V: Version
        RR: Revision
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_KEIL
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_CARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_CARM
#elif defined(__C166__)
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //KEIL C166
    /*
        __C166__ = VRR
        V: Version
        RR: Revision
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_KEIL
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_C166
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_C166
#elif (defined(__C51__) || defined(__CX51__))
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented nor tested."
    //KEIL C51
    /*
        __C51__ = VRR
        V: Version
        RR: Revision
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_KEIL
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_C51
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_C51
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_ARMCompiler
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_ARMCompiler
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_ARMCompiler
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_Generic
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_Clang
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_Clang
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_Clang

    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>

    
    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__


    #define CAOL_COMPILIFICS_DEF_EXTENSION_NAMESPACE clang
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_START __attribute__((
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_STOP ))

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_always_inline                                   always_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_artificial                                      artificial
    #define CAOL_COMPILIFICS_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cold                                            cold
    #define CAOL_COMPILIFICS_DEF_EXTNAME_hot                                             hot
    #define CAOL_COMPILIFICS_DEF_EXTNAME_common                                          common
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nocommon                                        nocommon
    #define CAOL_COMPILIFICS_DEF_EXTNAME_const                                           const
    #define CAOL_COMPILIFICS_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flag_enum                                       flag_enum
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flatten                                         flatten
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_interrupt                                       interrupt
    #define CAOL_COMPILIFICS_DEF_EXTNAME_leaf                                            leaf
    #define CAOL_COMPILIFICS_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_may_alias                                       may_alias
    #define CAOL_COMPILIFICS_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_musttail                                        musttail
    #define CAOL_COMPILIFICS_DEF_EXTNAME_naked                                           naked
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_noinline                                        noinline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonstring                                       nonstring
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nothrow                                         nothrow
    #define CAOL_COMPILIFICS_DEF_EXTNAME_optimize                                        optimize
    #define CAOL_COMPILIFICS_DEF_EXTNAME_packed                                          packed
    #define CAOL_COMPILIFICS_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_EXTNAME_pure                                            pure
    #define CAOL_COMPILIFICS_DEF_EXTNAME_retain                                          retain
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_twice                                   returns_twice
    #define CAOL_COMPILIFICS_DEF_EXTNAME_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_transparent_union                               transparent_union
    #define CAOL_COMPILIFICS_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_uninitialized                                   uninitialized
    #define CAOL_COMPILIFICS_DEF_EXTNAME_used                                            used
    #define CAOL_COMPILIFICS_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weak                                            weak
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif defined(__GNUC__)
    //GCC
    /*
        __GNUC__ = V
            V: Version
        __GNUC_MINOR__ = R
            R: Revision
        __GNUC_PATCHLEVEL__ = P
            P: Patch (introduced in version 3.0)
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_Generic
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_GCC
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_GCC
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_GCC

    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>


    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__


    #define CAOL_COMPILIFICS_DEF_EXTENSION_NAMESPACE gnu
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_START __attribute__((
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_STOP ))

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_always_inline                                   always_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_artificial                                      artificial
    #define CAOL_COMPILIFICS_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cold                                            cold
    #define CAOL_COMPILIFICS_DEF_EXTNAME_hot                                             hot
    #define CAOL_COMPILIFICS_DEF_EXTNAME_common                                          common
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nocommon                                        nocommon
    #define CAOL_COMPILIFICS_DEF_EXTNAME_const                                           const
    #define CAOL_COMPILIFICS_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough                                     fallthrough
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flag_enum                                       flag_enum
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flatten                                         flatten
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_interrupt                                       interrupt
    #define CAOL_COMPILIFICS_DEF_EXTNAME_leaf                                            leaf
    #define CAOL_COMPILIFICS_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_may_alias                                       may_alias
    #define CAOL_COMPILIFICS_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_musttail                                        musttail
    #define CAOL_COMPILIFICS_DEF_EXTNAME_naked                                           naked
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_noinline                                        noinline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonstring                                       nonstring
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nothrow                                         nothrow
    #define CAOL_COMPILIFICS_DEF_EXTNAME_optimize                                        optimize
    #define CAOL_COMPILIFICS_DEF_EXTNAME_packed                                          packed
    #define CAOL_COMPILIFICS_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_EXTNAME_pure                                            pure
    #define CAOL_COMPILIFICS_DEF_EXTNAME_retain                                          retain
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_twice                                   returns_twice
    #define CAOL_COMPILIFICS_DEF_EXTNAME_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_transparent_union                               transparent_union
    #define CAOL_COMPILIFICS_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_uninitialized                                   uninitialized
    #define CAOL_COMPILIFICS_DEF_EXTNAME_used                                            used
    #define CAOL_COMPILIFICS_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weak                                            weak
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif defined(_MSC_VER)
    //Microsoft Visual C++:
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_Generic
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_MicrosoftVisualCPP
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPID_MicrosoftVisualCPP
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPNAME_MicrosoftVisualCPP

    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>


    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__


    #define CAOL_COMPILIFICS_DEF_EXTENSION_NAMESPACE gnu
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_START __attribute__((
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_STOP ))

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_always_inline                                   always_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_artificial                                      artificial
    #define CAOL_COMPILIFICS_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cold                                            cold
    #define CAOL_COMPILIFICS_DEF_EXTNAME_hot                                             hot
    #define CAOL_COMPILIFICS_DEF_EXTNAME_common                                          common
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nocommon                                        nocommon
    #define CAOL_COMPILIFICS_DEF_EXTNAME_const                                           const
    #define CAOL_COMPILIFICS_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough                                     fallthrough
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flag_enum                                       flag_enum
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flatten                                         flatten
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_interrupt                                       interrupt
    #define CAOL_COMPILIFICS_DEF_EXTNAME_leaf                                            leaf
    #define CAOL_COMPILIFICS_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_may_alias                                       may_alias
    #define CAOL_COMPILIFICS_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_musttail                                        musttail
    #define CAOL_COMPILIFICS_DEF_EXTNAME_naked                                           naked
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_noinline                                        noinline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonstring                                       nonstring
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nothrow                                         nothrow
    #define CAOL_COMPILIFICS_DEF_EXTNAME_optimize                                        optimize
    #define CAOL_COMPILIFICS_DEF_EXTNAME_packed                                          packed
    #define CAOL_COMPILIFICS_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_EXTNAME_pure                                            pure
    #define CAOL_COMPILIFICS_DEF_EXTNAME_retain                                          retain
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_twice                                   returns_twice
    #define CAOL_COMPILIFICS_DEF_EXTNAME_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_transparent_union                               transparent_union
    #define CAOL_COMPILIFICS_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_uninitialized                                   uninitialized
    #define CAOL_COMPILIFICS_DEF_EXTNAME_used                                            used
    #define CAOL_COMPILIFICS_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weak                                            weak
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif (defined(__MINGW32__) || defined(__MINGW32_MAJOR_VERSION) || defined(__MINGW32_MINOR_VERSION))
    //MinGW
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_Generic
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_MinGW

    #if (defined(__MINGW64_VERSION_MAJOR) || defined(__MINGW64_VERSION_MINOR))
        #if defined(__MINGW64__)
            //MinGW-w64_64B
            #define CAOL_COMPILIFICS_DEF_COMPILER_ID   CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_64B
            #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_MinGWw64_64B
        #else
            //MinGW-w64_32B
            #define CAOL_COMPILIFICS_DEF_COMPILER_ID   CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_32B
            #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_MinGWw64_32B
        #endif
    #else
        //MinGW32
        #define CAOL_COMPILIFICS_DEF_COMPILER_ID   CAOL_COMPILIFICS_DEF_COMPID_MinGW32
        #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_MinGW32
    #endif

    //System-specific C89 standard header that Hopefully defines the utilized C-Standard Library's identifier.
    //(The inclusion of other C-Standard headers are continued within stdlibraspecs.h)
    #include <limits.h>


    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__


    #define CAOL_COMPILIFICS_DEF_EXTENSION_NAMESPACE gnu
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_START __attribute__((
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_STOP ))

    #if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_EXTNAME_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_EXTNAME_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_always_inline                                   always_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_artificial                                      artificial
    #define CAOL_COMPILIFICS_DEF_EXTNAME_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_cold                                            cold
    #define CAOL_COMPILIFICS_DEF_EXTNAME_hot                                             hot
    #define CAOL_COMPILIFICS_DEF_EXTNAME_common                                          common
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nocommon                                        nocommon
    #define CAOL_COMPILIFICS_DEF_EXTNAME_const                                           const
    #define CAOL_COMPILIFICS_DEF_EXTNAME_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_fallthrough                                     fallthrough
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flag_enum                                       flag_enum
    #define CAOL_COMPILIFICS_DEF_EXTNAME_flatten                                         flatten
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_gnu_inline                                      gnu_inline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_interrupt                                       interrupt
    #define CAOL_COMPILIFICS_DEF_EXTNAME_leaf                                            leaf
    #define CAOL_COMPILIFICS_DEF_EXTNAME_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_may_alias                                       may_alias
    #define CAOL_COMPILIFICS_DEF_EXTNAME_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_musttail                                        musttail
    #define CAOL_COMPILIFICS_DEF_EXTNAME_naked                                           naked
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_profile_instrument_function                  no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_address                             no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_address_safety_analysis                      no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_thread                              no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_split_stack                                  no_split_stack
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_EXTNAME_noinline                                        noinline
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nonstring                                       nonstring
    #define CAOL_COMPILIFICS_DEF_EXTNAME_nothrow                                         nothrow
    #define CAOL_COMPILIFICS_DEF_EXTNAME_optimize                                        optimize
    #define CAOL_COMPILIFICS_DEF_EXTNAME_packed                                          packed
    #define CAOL_COMPILIFICS_DEF_EXTNAME_patchable_function_entry                        patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_EXTNAME_pure                                            pure
    #define CAOL_COMPILIFICS_DEF_EXTNAME_retain                                          retain
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_nonnull                                 returns_nonnull
    #define CAOL_COMPILIFICS_DEF_EXTNAME_returns_twice                                   returns_twice
    #define CAOL_COMPILIFICS_DEF_EXTNAME_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_transparent_union                               transparent_union
    #define CAOL_COMPILIFICS_DEF_EXTNAME_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_uninitialized                                   uninitialized
    #define CAOL_COMPILIFICS_DEF_EXTNAME_used                                            used
    #define CAOL_COMPILIFICS_DEF_EXTNAME_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weak                                            weak
    #define CAOL_COMPILIFICS_DEF_EXTNAME_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_EXTNAME_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#else
    #error "nCAOL: Apologizes, but it seems like the utilized compiler is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

#if (caolStandilics(CURRENT, STD, ID) < caolStandilics(STD, ID, C23))
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_FUNC(extName) CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_START extName CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_STOP
#else
    #define CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_FUNC(extName) [[CAOL_COMPILIFICS_DEF_EXTENSION_NAMESPACE::extName]]
#endif


#define caolCompilifics(t, ...) CAOL_COMPILIFICS_INTER_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_COMPILER(t, ...) CAOL_COMPILIFICS_INTER_COMPILER_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT(t) CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT_##t
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN(t)  CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_##t
#define CAOL_COMPILIFICS_INTER_COMPILER_ID(t)      CAOL_COMPILIFICS_INTER_COMPILER_ID_##t

#define CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT_FPGA    CAOL_COMPILIFICS_DEF_COMPSUB_FPGA
#define CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT_ARM     CAOL_COMPILIFICS_DEF_COMPSUB_ARM
#define CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT_RiscV   CAOL_COMPILIFICS_DEF_COMPSUB_RiscV
#define CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT_Generic CAOL_COMPILIFICS_DEF_COMPSUB_Generic

#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_Altium      CAOL_COMPILIFICS_DEF_COMPDOMAIN_Altium
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_KEIL        CAOL_COMPILIFICS_DEF_COMPDOMAIN_KEIL
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_ARMCompiler CAOL_COMPILIFICS_DEF_COMPDOMAIN_ARMCompiler
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_Clang       CAOL_COMPILIFICS_DEF_COMPDOMAIN_Clang
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_GCC         CAOL_COMPILIFICS_DEF_COMPDOMAIN_GCC
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_MinGW       CAOL_COMPILIFICS_DEF_COMPDOMAIN_MinGW

#define CAOL_COMPILIFICS_INTER_COMPILER_ID_MicroBlazeC  CAOL_COMPILIFICS_DEF_COMPID_MicroBlazeC
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_CtoHardware  CAOL_COMPILIFICS_DEF_COMPID_CtoHardware
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_CARM         CAOL_COMPILIFICS_DEF_COMPID_CARM
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_C166         CAOL_COMPILIFICS_DEF_COMPID_C166
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_C51          CAOL_COMPILIFICS_DEF_COMPID_C51
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_ARMCompiler  CAOL_COMPILIFICS_DEF_COMPID_ARMCompiler
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_Clang        CAOL_COMPILIFICS_DEF_COMPID_Clang
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_GCC          CAOL_COMPILIFICS_DEF_COMPID_GCC
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_MinGW32      CAOL_COMPILIFICS_DEF_COMPID_MinGW32
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_MinGWw64_32B CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_32B
#define CAOL_COMPILIFICS_INTER_COMPILER_ID_MinGWw64_64B CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_64B


#define CAOL_COMPILIFICS_INTER_CURRENT(t, ...) CAOL_COMPILIFICS_INTER_CURRENT_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER(t) CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_##t
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_NAME    CAOL_COMPILIFICS_DEF_COMPILER_NAME
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPILER_ID

#define CAOL_COMPILIFICS_INTER_CURRENT_FUNC() CAOL_COMPILIFICS_DEF_CURRENT_FUNC
#define CAOL_COMPILIFICS_INTER_CURRENT_FILE() CAOL_COMPILIFICS_DEF_CURRENT_FILE
#define CAOL_COMPILIFICS_INTER_CURRENT_LINE() CAOL_COMPILIFICS_DEF_CURRENT_LINE
#define CAOL_COMPILIFICS_INTER_CURRENT_DATE() CAOL_COMPILIFICS_DEF_CURRENT_DATE
#define CAOL_COMPILIFICS_INTER_CURRENT_TIME() CAOL_COMPILIFICS_DEF_CURRENT_TIME


#define CAOL_COMPILIFICS_INTER_EXT(t, ...) CAOL_COMPILIFICS_INTER_EXT_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT_NAMESPACE()     CAOL_COMPILIFICS_DEF_EXTENSION_NAMESPACE
#define CAOL_COMPILIFICS_INTER_EXT_START()         CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_START
#define CAOL_COMPILIFICS_INTER_EXT_STOP()          CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_STOP
#define CAOL_COMPILIFICS_INTER_EXT_GET(ext)        CAOL_COMPILIFICS_INTER_EXTENSION_NAME_##ext
#define CAOL_COMPILIFICS_INTER_EXT_WRAP(ext)       CAOL_COMPILIFICS_DEF_EXTENSION_WRAP_FUNC(CAOL_COMPILIFICS_INTER_EXT_GET(ext))


#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_alias(target)                                   CAOL_COMPILIFICS_DEF_EXTNAME_alias(target)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_aligned(alignment)                              CAOL_COMPILIFICS_DEF_EXTNAME_aligned(alignment)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_alloc_align(position)                           CAOL_COMPILIFICS_DEF_EXTNAME_alloc_align(position)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_alloc_size(...)                                 CAOL_COMPILIFICS_DEF_EXTNAME_alloc_size(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_always_inline(...)                              CAOL_COMPILIFICS_DEF_EXTNAME_always_inline static inline __VA_ARGS__
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_artificial                                      CAOL_COMPILIFICS_DEF_EXTNAME_artificial
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_assume_aligned(...)                             CAOL_COMPILIFICS_DEF_EXTNAME_assume_aligned(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_btf_decl_tag(str)                               CAOL_COMPILIFICS_DEF_EXTNAME_btf_decl_tag(str)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_btf_type_tag(arg)                               CAOL_COMPILIFICS_DEF_EXTNAME_btf_type_tag(arg)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_cleanup(func)                                   CAOL_COMPILIFICS_DEF_EXTNAME_cleanup(func)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_cold                                            CAOL_COMPILIFICS_DEF_EXTNAME_cold
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_hot                                             CAOL_COMPILIFICS_DEF_EXTNAME_hot
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_common                                          CAOL_COMPILIFICS_DEF_EXTNAME_common
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_nocommon                                        CAOL_COMPILIFICS_DEF_EXTNAME_nocommon
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_const                                           CAOL_COMPILIFICS_DEF_EXTNAME_const
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_constructor(priority)                           CAOL_COMPILIFICS_DEF_EXTNAME_constructor(priority)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_destructor(priority)                            CAOL_COMPILIFICS_DEF_EXTNAME_destructor(priority)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_counted_by(count)                               CAOL_COMPILIFICS_DEF_EXTNAME_counted_by(count)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_deprecated(msg)                                 CAOL_COMPILIFICS_DEF_EXTNAME_deprecated(msg)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_error(msg)                                      CAOL_COMPILIFICS_DEF_EXTNAME_error(msg)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_warning(msg)                                    CAOL_COMPILIFICS_DEF_EXTNAME_warning(msg)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_flag_enum                                       CAOL_COMPILIFICS_DEF_EXTNAME_flag_enum
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_flatten                                         CAOL_COMPILIFICS_DEF_EXTNAME_flatten
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_format(archetype, string_index, first_to_check) CAOL_COMPILIFICS_DEF_EXTNAME_format(archetype, string_index, first_to_check)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_format_arg(string_index)                        CAOL_COMPILIFICS_DEF_EXTNAME_format_arg(string_index)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_gnu_inline                                      CAOL_COMPILIFICS_DEF_EXTNAME_gnu_inline
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_ifunc(resolver)                                 CAOL_COMPILIFICS_DEF_EXTNAME_ifunc(resolver)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_interrupt                                       CAOL_COMPILIFICS_DEF_EXTNAME_interrupt
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_leaf                                            CAOL_COMPILIFICS_DEF_EXTNAME_leaf
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_malloc(...)                                     CAOL_COMPILIFICS_DEF_EXTNAME_malloc(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_may_alias                                       CAOL_COMPILIFICS_DEF_EXTNAME_may_alias
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_mode(mode)                                      CAOL_COMPILIFICS_DEF_EXTNAME_mode(mode)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_musttail                                        CAOL_COMPILIFICS_DEF_EXTNAME_musttail
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_naked                                           CAOL_COMPILIFICS_DEF_EXTNAME_naked
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_profile_instrument_function(...)             CAOL_COMPILIFICS_DEF_EXTNAME_no_profile_instrument_function
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_sanitize(option)                             CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize(option)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_sanitize_address                             CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_address
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_address_safety_analysis(...)                 CAOL_COMPILIFICS_DEF_EXTNAME_no_address_safety_analysis
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_sanitize_thread                              CAOL_COMPILIFICS_DEF_EXTNAME_no_sanitize_thread
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_split_stack                                  CAOL_COMPILIFICS_DEF_EXTNAME_no_split_stack
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_stack_protector                              CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_no_stack_protector                              CAOL_COMPILIFICS_DEF_EXTNAME_no_stack_protector
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_noinline                                        CAOL_COMPILIFICS_DEF_EXTNAME_noinline
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_nonnull(...)                                    CAOL_COMPILIFICS_DEF_EXTNAME_nonnull(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_nonstring                                       CAOL_COMPILIFICS_DEF_EXTNAME_nonstring
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_noreturn                                        CAOL_COMPILIFICS_DEF_EXTNAME_noreturn
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_nothrow                                         CAOL_COMPILIFICS_DEF_EXTNAME_nothrow
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_optimize                                        CAOL_COMPILIFICS_DEF_EXTNAME_optimize
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_packed                                          CAOL_COMPILIFICS_DEF_EXTNAME_packed
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_patchable_function_entry                        CAOL_COMPILIFICS_DEF_EXTNAME_patchable_function_entry
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_pure                                            CAOL_COMPILIFICS_DEF_EXTNAME_pure
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_reproducible                                    CAOL_COMPILIFICS_DEF_EXTNAME_reproducible
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_retain                                          CAOL_COMPILIFICS_DEF_EXTNAME_retain
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_returns_nonnull                                 CAOL_COMPILIFICS_DEF_EXTNAME_returns_nonnull
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_returns_twice                                   CAOL_COMPILIFICS_DEF_EXTNAME_returns_twice
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_section(section)                                CAOL_COMPILIFICS_DEF_EXTNAME_section(section)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_sentinel(position)                              CAOL_COMPILIFICS_DEF_EXTNAME_sentinel(position)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_target(...)                                     CAOL_COMPILIFICS_DEF_EXTNAME_target(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_target_version(option)                          CAOL_COMPILIFICS_DEF_EXTNAME_target_version(option)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_target_clones(options)                          CAOL_COMPILIFICS_DEF_EXTNAME_target_clones(options)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_tls_model(tls_model)                            CAOL_COMPILIFICS_DEF_EXTNAME_tls_model(tls_model)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_transparent_union                               CAOL_COMPILIFICS_DEF_EXTNAME_transparent_union
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_unavailable(msg)                                CAOL_COMPILIFICS_DEF_EXTNAME_unavailable(msg)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_uninitialized                                   CAOL_COMPILIFICS_DEF_EXTNAME_uninitialized
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_unsequenced                                     CAOL_COMPILIFICS_DEF_EXTNAME_unsequenced
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_maybe_unused                                    CAOL_COMPILIFICS_DEF_EXTNAME_maybe_unused
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_used                                            CAOL_COMPILIFICS_DEF_EXTNAME_used
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_vector_size(bytes)                              CAOL_COMPILIFICS_DEF_EXTNAME_vector_size(bytes)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_visibility(visibility_type)                     CAOL_COMPILIFICS_DEF_EXTNAME_visibility(visibility_type)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_nodiscard                                       CAOL_COMPILIFICS_DEF_EXTNAME_nodiscard
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_weak                                            CAOL_COMPILIFICS_DEF_EXTNAME_weak
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_weakref(target)                                 CAOL_COMPILIFICS_DEF_EXTNAME_weakref(target)
#define CAOL_COMPILIFICS_INTER_EXTENSION_NAME_zero_call_used_regs(choice)                     CAOL_COMPILIFICS_DEF_EXTNAME_zero_call_used_regs(choice)

#endif