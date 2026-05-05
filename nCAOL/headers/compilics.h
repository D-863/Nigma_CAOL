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

#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_Altium      0
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_KEIL        1
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_ARMCompiler 2
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_Clang       3
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_GCC         4
#define CAOL_COMPILIFICS_DEF_COMPDOMAIN_MinGW       5

#define CAOL_COMPILIFICS_DEF_COMPID_MicroBlazeC  0
#define CAOL_COMPILIFICS_DEF_COMPID_CtoHardware  1
#define CAOL_COMPILIFICS_DEF_COMPID_CARM         2
#define CAOL_COMPILIFICS_DEF_COMPID_C166         3
#define CAOL_COMPILIFICS_DEF_COMPID_C51          4
#define CAOL_COMPILIFICS_DEF_COMPID_ARMCompiler  5
#define CAOL_COMPILIFICS_DEF_COMPID_Clang        6
#define CAOL_COMPILIFICS_DEF_COMPID_GCC          7
#define CAOL_COMPILIFICS_DEF_COMPID_MinGW32      8
#define CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_32B 9
#define CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_64B 10

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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) clang::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
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

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#elif (defined(__MINGW32__) || defined(__MINGW32_MAJOR_VERSION) || defined(__MINGW32_MINOR_VERSION))
    //MinGW
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_Generic
    #define CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPDOMAIN_MinGW

    #if (defined(__MINGW64_VERSION_MAJOR) || defined(__MINGW64_VERSION_MINOR))
        #if defined(__MINGW64__)
            //MinGW-w64_64B
            #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_64B
        #else
            //MinGW-w64_32B
            #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_MinGWw64_32B
        #endif
    #else
        //MinGW32
        #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_MinGW32
    #endif

    #if (caolStandilics(STD, ID) < caolStandilics(C99))
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __FUNCTION__
    #else
        #define CAOL_COMPILIFICS_DEF_CURRENT_FUNC __func__
    #endif
    #define CAOL_COMPILIFICS_DEF_CURRENT_FILE __FILE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_LINE __LINE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_DATE __DATE__
    #define CAOL_COMPILIFICS_DEF_CURRENT_TIME __TIME__

    #if (caolStandilics(STD, ID) < caolStandilics(C23))
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  __attribute__((ext))
        #define CAOL_COMPILIFICS_DEF_EXT_START __attribute__((
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ))

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       warn_unused_result
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #else
        #define CAOL_COMPILIFICS_DEF_EXT(ext)  [[ext]]
        #define CAOL_COMPILIFICS_DEF_EXT_START [[
        #define CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(ext) gnu::ext
        #define CAOL_COMPILIFICS_DEF_EXT_STOP ]]

        #define CAOL_COMPILIFICS_DEF_GETEXT_deprecated(msg) deprecated(msg)
        #define CAOL_COMPILIFICS_DEF_GETEXT_fallthrough     fallthrough
        #define CAOL_COMPILIFICS_DEF_GETEXT_nodiscard       nodiscard
        #define CAOL_COMPILIFICS_DEF_GETEXT_maybe_unused    maybe_unused
        #define CAOL_COMPILIFICS_DEF_GETEXT_noreturn        noreturn
        #define CAOL_COMPILIFICS_DEF_GETEXT_unsequenced     unsequenced
        #define CAOL_COMPILIFICS_DEF_GETEXT_reproducible    reproducible
    #endif
    #define CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##bWrap(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline()                                 always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial()                                    artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold()                                          cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot()                                           hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common()                                        common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon()                                      nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const()                                         const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum()                                     flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten()                                       flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline()                                    gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt()                                     interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf()                                          leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias()                                     may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail()                                      musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked()                                         naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function()                no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address()                           no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis()                    no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread()                            no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack()                                no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector()                            no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline()                                      noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring()                                     nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow()                                       nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize()                                      optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed()                                        packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry()                      patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure()                                          pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain()                                        retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull()                               returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice()                                 returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union()                             transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized()                                 uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used()                                          used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak()                                          weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#else
    #error "nCAOL: Apologizes, but it seems like the utilized compiler is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

#define caolCompilifics(t, ...) CAOL_COMPILIFICS_INTER_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_COMPILER(t, ...) CAOL_COMPILIFICS_INTER_COMPILER_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT(t, ...) CAOL_COMPILIFICS_INTER_COMPILER_SUBJECT_##t
#define CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN(t, ...)  CAOL_COMPILIFICS_INTER_COMPILER_DOMAIN_##t
#define CAOL_COMPILIFICS_INTER_COMPILER_ID(t, ...)      CAOL_COMPILIFICS_INTER_COMPILER_ID_##t

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
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER(t, ...) CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_##t
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_DOMAIN  CAOL_COMPILIFICS_DEF_COMPILER_DOMAIN
#define CAOL_COMPILIFICS_INTER_CURRENT_COMPILER_ID      CAOL_COMPILIFICS_DEF_COMPILER_ID

#define CAOL_COMPILIFICS_INTER_CURRENT_FUNC() CAOL_COMPILIFICS_DEF_CURRENT_FUNC
#define CAOL_COMPILIFICS_INTER_CURRENT_FILE() CAOL_COMPILIFICS_DEF_CURRENT_FILE
#define CAOL_COMPILIFICS_INTER_CURRENT_LINE() CAOL_COMPILIFICS_DEF_CURRENT_LINE
#define CAOL_COMPILIFICS_INTER_CURRENT_DATE() CAOL_COMPILIFICS_DEF_CURRENT_DATE
#define CAOL_COMPILIFICS_INTER_CURRENT_TIME() CAOL_COMPILIFICS_DEF_CURRENT_TIME


#define CAOL_COMPILIFICS_INTER_EXT_START() CAOL_COMPILIFICS_DEF_EXT_START
#define CAOL_COMPILIFICS_INTER_EXT_STOP()  CAOL_COMPILIFICS_DEF_EXT_STOP

#define CAOL_COMPILIFICS_INTER_GETEXT(ext, ...) CAOL_COMPILIFICS_INTER_EXT_##ext(0, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT(ext, ...)    CAOL_COMPILIFICS_INTER_EXT_##ext(1, ext, __VA_ARGS__)

#define CAOL_COMPILIFICS_INTER_EXT_alias(bWrap, ext, target)                                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, target)
#define CAOL_COMPILIFICS_INTER_EXT_aligned(bWrap, ext, alignment)                              CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, alignment)
#define CAOL_COMPILIFICS_INTER_EXT_alloc_align(bWrap, ext, position)                           CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, position)
#define CAOL_COMPILIFICS_INTER_EXT_alloc_size(bWrap, ext, ...)                                 CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT_always_inline(bWrap, ext, ...)                              CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, ) static inline __VA_ARGS__
#define CAOL_COMPILIFICS_INTER_EXT_artificial(bWrap, ext, ...)                                 CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_assume_aligned(bWrap, ext, ...)                             CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT_btf_decl_tag(bWrap, ext, str)                               CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, str)
#define CAOL_COMPILIFICS_INTER_EXT_btf_type_tag(bWrap, ext, arg)                               CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, arg)
#define CAOL_COMPILIFICS_INTER_EXT_cleanup(bWrap, ext, func)                                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, func)
#define CAOL_COMPILIFICS_INTER_EXT_cold(bWrap, ext, ...)                                       CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_hot(bWrap, ext, ...)                                        CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_common(bWrap, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_nocommon(bWrap, ext, ...)                                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_const(bWrap, ext, ...)                                      CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_constructor(bWrap, ext, priority)                           CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, priority)
#define CAOL_COMPILIFICS_INTER_EXT_destructor(bWrap, ext, priority)                            CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, priority)
#define CAOL_COMPILIFICS_INTER_EXT_counted_by(bWrap, ext, count)                               CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, count)
#define CAOL_COMPILIFICS_INTER_EXT_error(bWrap, ext, msg)                                      CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, msg)
#define CAOL_COMPILIFICS_INTER_EXT_warning(bWrap, ext, msg)                                    CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, msg)
#define CAOL_COMPILIFICS_INTER_EXT_flag_enum(bWrap, ext, ...)                                  CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_flatten(bWrap, ext, ...)                                    CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_format(bWrap, ext, archetype, string_index, first_to_check) CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, archetype, string_index, first_to_check)
#define CAOL_COMPILIFICS_INTER_EXT_format_arg(bWrap, ext, string_index)                        CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, string_index)
#define CAOL_COMPILIFICS_INTER_EXT_gnu_inline(bWrap, ext, ...)                                 CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_ifunc(bWrap, ext, resolver)                                 CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, resolver)
#define CAOL_COMPILIFICS_INTER_EXT_interrupt(bWrap, ext, ...)                                  CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_leaf(bWrap, ext, ...)                                       CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_malloc(bWrap, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT_may_alias(bWrap, ext, ...)                                  CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_mode(bWrap, ext, mode)                                      CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, mode)
#define CAOL_COMPILIFICS_INTER_EXT_musttail(bWrap, ext, ...)                                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_naked(bWrap, ext, ...)                                      CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_profile_instrument_function(bWrap, ext, ...)             CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_sanitize(bWrap, ext, option)                             CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, option)
#define CAOL_COMPILIFICS_INTER_EXT_no_sanitize_address(bWrap, ext, ...)                        CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_address_safety_analysis(bWrap, ext, ...)                 CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_sanitize_thread(bWrap, ext, ...)                         CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_split_stack(bWrap, ext, ...)                             CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_stack_protector(bWrap, ext, ...)                         CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_no_stack_protector(bWrap, ext, ...)                         CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_noinline(bWrap, ext, ...)                                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_nonnull(bWrap, ext, ...)                                    CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT_nonstring(bWrap, ext, ...)                                  CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_nothrow(bWrap, ext, ...)                                    CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_optimize(bWrap, ext, ...)                                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_packed(bWrap, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_patchable_function_entry(bWrap, ext, ...)                   CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_pure(bWrap, ext, ...)                                       CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_retain(bWrap, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_returns_nonnull(bWrap, ext, ...)                            CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_returns_twice(bWrap, ext, ...)                              CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_section(bWrap, ext, section)                                CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, section)
#define CAOL_COMPILIFICS_INTER_EXT_sentinel(bWrap, ext, position)                              CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, position)
#define CAOL_COMPILIFICS_INTER_EXT_target(bWrap, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_INTER_EXT_target_version(bWrap, ext, option)                          CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, option)
#define CAOL_COMPILIFICS_INTER_EXT_target_clones(bWrap, ext, options)                          CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, options)
#define CAOL_COMPILIFICS_INTER_EXT_tls_model(bWrap, ext, tls_model)                            CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, tls_model)
#define CAOL_COMPILIFICS_INTER_EXT_transparent_union(bWrap, ext, ...)                          CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_unavailable(bWrap, ext, msg)                                CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, msg)
#define CAOL_COMPILIFICS_INTER_EXT_uninitialized(bWrap, ext, ...)                              CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_used(bWrap, ext, ...)                                       CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_vector_size(bWrap, ext, bytes)                              CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, bytes)
#define CAOL_COMPILIFICS_INTER_EXT_visibility(bWrap, ext, visibility_type)                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, visibility_type)
#define CAOL_COMPILIFICS_INTER_EXT_weak(bWrap, ext, ...)                                       CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, )
#define CAOL_COMPILIFICS_INTER_EXT_weakref(bWrap, ext, target)                                 CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, target)
#define CAOL_COMPILIFICS_INTER_EXT_zero_call_used_regs(bWrap, ext, choice)                     CAOL_COMPILIFICS_DEF_GETEXT(bWrap, ext, choice)

#endif