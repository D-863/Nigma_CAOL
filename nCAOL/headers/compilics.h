#ifndef NIGMA_CAOL_COMPILIFICS_H
#define NIGMA_CAOL_COMPILIFICS_H

/*Compiler-Specific identifications:
FPGA_Specfic:
    Altium:
        MicroBlaze C
        __CMB__

        C-to-Hardware
        __CHC__

ARM_Specfic:
    KEIL:
        CARM
        (__CA__ || __KEIL__)

        C166
        __C166__

        C51
        (__C51__ || __CX51__)

    ARM-Compiler
    __CC_ARM

    IAR:
    //To be found.

RISC-V_Specific:
        For what I know, the compiler used is very Architecture specific,
        which makes by RISC-V's nature.

        So I will add this in the future when I got a working RP2350.
    - Sincerly, Nigma -

Generic:
    Clang
    __clang__

    GCC
    __GNUC__

    MinGW:
        MinGW32
        (
            (
                __MINGW32__ ||
                __MINGW32_MAJOR_VERSION ||
                __MINGW32_MINOR_VERSION
            )
        )

        MinGW-w64_32B
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

        MinGW-w64_64B
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

#define CAOL_COMPILIFICS_DEF_COMPNAME_Altium      0
#define CAOL_COMPILIFICS_DEF_COMPNAME_KEIL        1
#define CAOL_COMPILIFICS_DEF_COMPNAME_ARMCompiler 2
#define CAOL_COMPILIFICS_DEF_COMPNAME_Clang       3
#define CAOL_COMPILIFICS_DEF_COMPNAME_GCC         4
#define CAOL_COMPILIFICS_DEF_COMPNAME_MinGW       5

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
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented."
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_Altium
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_MicroBlazeC

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented."
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_Altium
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_CtoHardware

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented."
    //KEIL CARM
    /*
        __CA__ = VRR
        V: Version
        RR: Revision
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_KEIL
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_CARM

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented."
    //KEIL C166
    /*
        __C166__ = VRR
        V: Version
        RR: Revision
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_KEIL
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_C166

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented."
    //KEIL C51
    /*
        __C51__ = VRR
        V: Version
        RR: Revision
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_KEIL
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_C51

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #error "nCAOL: Apologizes, but while this compiler is supported, it has yet to be implemented."
    //ARM Compiler
    /*
        __ARMCC_VERSION = VRPBBB
            V: Version
            R: Revision
            P: Patch
            BBB: Build
    */
    #define CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT CAOL_COMPILIFICS_DEF_COMPSUB_ARM
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_ARMCompiler
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_ARMCompiler

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_Clang
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_Clang

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline                                   always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial                                      artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold                                            cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot                                             hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common                                          common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon                                        nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const                                           const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum                                       flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten                                         flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline                                      gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt                                       interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf                                            leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias                                       may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail                                        musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked                                           naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function                  no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address                             no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis                      no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread                              no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack                                  no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline                                        noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring                                       nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow                                         nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize                                        optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed                                          packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry                        patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure                                            pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain                                          retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull                                 returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice                                   returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union                               transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized                                   uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used                                            used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak                                            weak
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_GCC
    #define CAOL_COMPILIFICS_DEF_COMPILER_ID CAOL_COMPILIFICS_DEF_COMPID_GCC

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
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
    #define CAOL_COMPILIFICS_DEF_COMPILER_NAME CAOL_COMPILIFICS_DEF_COMPNAME_MinGW

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

    #if (__STDC_VERSION__ != 202311L)
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
    #define CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ...) CAOL_COMPILIFICS_DEF_GETEXT_##single(ext, __VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_0(ext, ...) CAOL_COMPILIFICS_DEF_EXT_NAMESPACE(CAOL_COMPILIFICS_DEF_GETEXT_##ext(__VA_ARGS__))
    #define CAOL_COMPILIFICS_DEF_GETEXT_1(ext, ...) CAOL_COMPILIFICS_DEF_EXT(CAOL_COMPILIFICS_DEF_GETEXT_0(ext, __VA_ARGS__))

    #define CAOL_COMPILIFICS_DEF_GETEXT_alias(target)                                   alias(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_aligned(alignment)                              aligned(alignment)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_align(position)                           alloc_align(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_alloc_size(...)                                 alloc_size(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_always_inline                                   always_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_artificial                                      artificial
    #define CAOL_COMPILIFICS_DEF_GETEXT_assume_aligned(...)                             assume_aligned(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_decl_tag(str)                               btf_decl_tag(str)
    #define CAOL_COMPILIFICS_DEF_GETEXT_btf_type_tag(arg)                               btf_type_tag(arg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cleanup(func)                                   cleanup(func)
    #define CAOL_COMPILIFICS_DEF_GETEXT_cold                                            cold
    #define CAOL_COMPILIFICS_DEF_GETEXT_hot                                             hot
    #define CAOL_COMPILIFICS_DEF_GETEXT_common                                          common
    #define CAOL_COMPILIFICS_DEF_GETEXT_nocommon                                        nocommon
    #define CAOL_COMPILIFICS_DEF_GETEXT_const                                           const
    #define CAOL_COMPILIFICS_DEF_GETEXT_constructor(priority)                           constructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_destructor(priority)                            destructor(priority)
    #define CAOL_COMPILIFICS_DEF_GETEXT_counted_by(count)                               counted_by(count)
    #define CAOL_COMPILIFICS_DEF_GETEXT_error(msg)                                      error(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_warning(msg)                                    warning(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_flag_enum                                       flag_enum
    #define CAOL_COMPILIFICS_DEF_GETEXT_flatten                                         flatten
    #define CAOL_COMPILIFICS_DEF_GETEXT_format(archetype, string_index, first_to_check) format(archetype, string_index, first_to_check)
    #define CAOL_COMPILIFICS_DEF_GETEXT_format_arg(string_index)                        format_arg(string_index)
    #define CAOL_COMPILIFICS_DEF_GETEXT_gnu_inline                                      gnu_inline
    #define CAOL_COMPILIFICS_DEF_GETEXT_ifunc(resolver)                                 ifunc(resolver)
    #define CAOL_COMPILIFICS_DEF_GETEXT_interrupt                                       interrupt
    #define CAOL_COMPILIFICS_DEF_GETEXT_leaf                                            leaf
    #define CAOL_COMPILIFICS_DEF_GETEXT_malloc(...)                                     malloc __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_may_alias                                       may_alias
    #define CAOL_COMPILIFICS_DEF_GETEXT_mode(mode)                                      mode(mode)
    #define CAOL_COMPILIFICS_DEF_GETEXT_musttail                                        musttail
    #define CAOL_COMPILIFICS_DEF_GETEXT_naked                                           naked
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_profile_instrument_function                  no_profile_instrument_function
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize(option)                             no_sanitize(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_address                             no_sanitize_address
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_address_safety_analysis                      no_address_safety_analysis
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_sanitize_thread                              no_sanitize_thread
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_split_stack                                  no_split_stack
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_no_stack_protector                              no_stack_protector
    #define CAOL_COMPILIFICS_DEF_GETEXT_noinline                                        noinline
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonnull(...)                                    nonnull __VA_ARGS__
    #define CAOL_COMPILIFICS_DEF_GETEXT_nonstring                                       nonstring
    #define CAOL_COMPILIFICS_DEF_GETEXT_nothrow                                         nothrow
    #define CAOL_COMPILIFICS_DEF_GETEXT_optimize                                        optimize
    #define CAOL_COMPILIFICS_DEF_GETEXT_packed                                          packed
    #define CAOL_COMPILIFICS_DEF_GETEXT_patchable_function_entry                        patchable_function_entry
    #define CAOL_COMPILIFICS_DEF_GETEXT_pure                                            pure
    #define CAOL_COMPILIFICS_DEF_GETEXT_retain                                          retain
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_nonnull                                 returns_nonnull
    #define CAOL_COMPILIFICS_DEF_GETEXT_returns_twice                                   returns_twice
    #define CAOL_COMPILIFICS_DEF_GETEXT_section(section)                                section(section)
    #define CAOL_COMPILIFICS_DEF_GETEXT_sentinel(position)                              sentinel(position)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target(...)                                     target(__VA_ARGS__)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_version(option)                          target_version(option)
    #define CAOL_COMPILIFICS_DEF_GETEXT_target_clones(options)                          target_clones(options)
    #define CAOL_COMPILIFICS_DEF_GETEXT_tls_model(tls_model)                            tls_model(tls_model)
    #define CAOL_COMPILIFICS_DEF_GETEXT_transparent_union                               transparent_union
    #define CAOL_COMPILIFICS_DEF_GETEXT_unavailable(msg)                                unavailable(msg)
    #define CAOL_COMPILIFICS_DEF_GETEXT_uninitialized                                   uninitialized
    #define CAOL_COMPILIFICS_DEF_GETEXT_used                                            used
    #define CAOL_COMPILIFICS_DEF_GETEXT_vector_size(bytes)                              vector_size(bytes)
    #define CAOL_COMPILIFICS_DEF_GETEXT_visibility(visibility_type)                     visibility(visibility_type)
    #define CAOL_COMPILIFICS_DEF_GETEXT_weak                                            weak
    #define CAOL_COMPILIFICS_DEF_GETEXT_weakref(target)                                 weakref(target)
    #define CAOL_COMPILIFICS_DEF_GETEXT_zero_call_used_regs(choice)                     zero_call_used_regs(choice)
#else
    #error "nCAOL: Apologizes, but it seems like the utilized compiler is unsupported! - But please do feel free to send a request, if you have the spare time."
#endif

/*
    ? = Compier specific keywords.
    () = Passable syntax, (a, b, c) resolves into [a], [b], [c] respectively.
    [...] = Syntax, if () isn't used.

    t:COMPILER(t, ...) {
        [t]:SUBJECT = Current Compiler's subject.
        [t]:NAME    = Current Compiler's name.
        [t]:ID      = Current Compiler's ID.
    }
    t:EXT(t, ...) {
        [t]:INLINE(...)     = "?static inline [...]"
        [t]:DEPRECATED(msg) = "[...] ?:[msg]"
        [t]:FALLTHROUGH     = "?"
        [t]:NODISCARD       = "?"
        [t]:MAYBE_UNUSED    = "?"
        [t]:NORETURN        = "?"
        [t]:UNSEQUENCED     = "?"
        [t]:REPRODUCIBLE    = "?"
    }
    t:PACK(t, ...) {
        [t]:X(...)     = "? [...]"
        [t]:VAR(...)   = "? [...]"
        [t]:UNION(...) = "union ? [...]"
        [t]:STRUC(...) = "struct ? [...]"
    }
    t:FSTART(...) = "? [...]"
    t:FSTOP(...)  = "? [...]"
*/
#define caolCompilifics(t, ...) CAOL_COMPILIFICS_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_COMPILER(t, ...)   CAOL_COMPILIFICS_COMPILER_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_COMPILER_SUBJECT() CAOL_COMPILIFICS_DEF_COMPILER_SUBJECT
#define CAOL_COMPILIFICS_COMPILER_NAME()    CAOL_COMPILIFICS_DEF_COMPILER_NAME
#define CAOL_COMPILIFICS_COMPILER_ID()      CAOL_COMPILIFICS_DEF_COMPILER_ID

#define CAOL_COMPILIFICS_EXT_START()    CAOL_COMPILIFICS_DEF_EXT_START
#define CAOL_COMPILIFICS_EXT_STOP()     CAOL_COMPILIFICS_DEF_EXT_STOP
#define CAOL_COMPILIFICS_GETEXT(ext, ...) CAOL_COMPILIFICS_EXT_##ext(0, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_EXT(ext, ...)    CAOL_COMPILIFICS_EXT_##ext(1, ext, __VA_ARGS__)

#define CAOL_COMPILIFICS_EXT_alias(single, ext, target)                                   CAOL_COMPILIFICS_DEF_GETEXT(single, ext, target)
#define CAOL_COMPILIFICS_EXT_aligned(single, ext, alignment)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, alignment)
#define CAOL_COMPILIFICS_EXT_alloc_align(single, ext, position)                           CAOL_COMPILIFICS_DEF_GETEXT(single, ext, position)
#define CAOL_COMPILIFICS_EXT_alloc_size(single, ext, ...)                                 CAOL_COMPILIFICS_DEF_GETEXT(single, ext, __VA_ARGS__) //(posA, ?posB)
#define CAOL_COMPILIFICS_EXT_always_inline(single, ext, ...)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, ) static inline __VA_ARGS__
#define CAOL_COMPILIFICS_EXT_artificial(single, ext)                                      CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_assume_aligned(single, ext, ...)                             CAOL_COMPILIFICS_DEF_GETEXT(single, ext, __VA_ARGS__) //(alignment, ?offset)
#define CAOL_COMPILIFICS_EXT_btf_decl_tag(single, ext, str)                               CAOL_COMPILIFICS_DEF_GETEXT(single, ext, str)
#define CAOL_COMPILIFICS_EXT_btf_type_tag(single, ext, arg)                               CAOL_COMPILIFICS_DEF_GETEXT(single, ext, arg)
#define CAOL_COMPILIFICS_EXT_cleanup(single, ext, func)                                   CAOL_COMPILIFICS_DEF_GETEXT(single, ext, func)
#define CAOL_COMPILIFICS_EXT_cold(single, ext)                                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_hot(single, ext)                                             CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_common(single, ext)                                          CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_nocommon(single, ext)                                        CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_const(single, ext)                                           CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_constructor(single, ext, priority)                           CAOL_COMPILIFICS_DEF_GETEXT(single, ext, priority)
#define CAOL_COMPILIFICS_EXT_destructor(single, ext, priority)                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, priority)
#define CAOL_COMPILIFICS_EXT_counted_by(single, ext, count)                               CAOL_COMPILIFICS_DEF_GETEXT(single, ext, count)
#define CAOL_COMPILIFICS_EXT_error(single, ext, msg)                                      CAOL_COMPILIFICS_DEF_GETEXT(single, ext, msg)
#define CAOL_COMPILIFICS_EXT_warning(single, ext, msg)                                    CAOL_COMPILIFICS_DEF_GETEXT(single, ext, msg)
#define CAOL_COMPILIFICS_EXT_flag_enum(single, ext)                                       CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_flatten(single, ext)                                         CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_format(single, ext, archetype, string_index, first_to_check) CAOL_COMPILIFICS_DEF_GETEXT(single, ext, archetype, string_index, first_to_check)
#define CAOL_COMPILIFICS_EXT_format_arg(single, ext, string_index)                        CAOL_COMPILIFICS_DEF_GETEXT(single, ext, string_index)
#define CAOL_COMPILIFICS_EXT_gnu_inline(single, ext)                                      CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_ifunc(single, ext, resolver)                                 CAOL_COMPILIFICS_DEF_GETEXT(single, ext, resolver)
#define CAOL_COMPILIFICS_EXT_interrupt(single, ext)                                       CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_leaf(single, ext)                                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_malloc(single, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(single, ext, __VA_ARGS__) //?(deallocator, ?ptr_index)
#define CAOL_COMPILIFICS_EXT_may_alias(single, ext)                                       CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_mode(single, ext, mode)                                      CAOL_COMPILIFICS_DEF_GETEXT(single, ext, mode)
#define CAOL_COMPILIFICS_EXT_musttail(single, ext)                                        CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_naked(single, ext)                                           CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_profile_instrument_function(single, ext)                  CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_sanitize(single, ext, option)                             CAOL_COMPILIFICS_DEF_GETEXT(single, ext, option)
#define CAOL_COMPILIFICS_EXT_no_sanitize_address(single, ext)                             CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_address_safety_analysis(single, ext)                      CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_sanitize_thread(single, ext)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_split_stack(single, ext)                                  CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_stack_protector(single, ext)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_no_stack_protector(single, ext)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_noinline(single, ext)                                        CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_nonnull(single, ext, ...)                                    CAOL_COMPILIFICS_DEF_GETEXT(single, ext, __VA_ARGS__) //?(arg_index0, ?...)
#define CAOL_COMPILIFICS_EXT_nonstring(single, ext)                                       CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_nothrow(single, ext)                                         CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_optimize(single, ext)                                        CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_packed(single, ext)                                          CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_patchable_function_entry(single, ext)                        CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_pure(single, ext)                                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_retain(single, ext)                                          CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_returns_nonnull(single, ext)                                 CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_returns_twice(single, ext)                                   CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_section(single, ext, section)                                CAOL_COMPILIFICS_DEF_GETEXT(single, ext, section)
#define CAOL_COMPILIFICS_EXT_sentinel(single, ext, position)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, position)
#define CAOL_COMPILIFICS_EXT_target(single, ext, ...)                                     CAOL_COMPILIFICS_DEF_GETEXT(single, ext, __VA_ARGS__)
#define CAOL_COMPILIFICS_EXT_target_version(single, ext, option)                          CAOL_COMPILIFICS_DEF_GETEXT(single, ext, option)
#define CAOL_COMPILIFICS_EXT_target_clones(single, ext, options)                          CAOL_COMPILIFICS_DEF_GETEXT(single, ext, options)
#define CAOL_COMPILIFICS_EXT_tls_model(single, ext, tls_model)                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, tls_model)
#define CAOL_COMPILIFICS_EXT_transparent_union(single, ext)                               CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_unavailable(single, ext, msg)                                CAOL_COMPILIFICS_DEF_GETEXT(single, ext, msg)
#define CAOL_COMPILIFICS_EXT_uninitialized(single, ext)                                   CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_used(single, ext)                                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_vector_size(single, ext, bytes)                              CAOL_COMPILIFICS_DEF_GETEXT(single, ext, bytes)
#define CAOL_COMPILIFICS_EXT_visibility(single, ext, visibility_type)                     CAOL_COMPILIFICS_DEF_GETEXT(single, ext, visibility_type)
#define CAOL_COMPILIFICS_EXT_weak(single, ext)                                            CAOL_COMPILIFICS_DEF_GETEXT(single, ext, )
#define CAOL_COMPILIFICS_EXT_weakref(single, ext, target)                                 CAOL_COMPILIFICS_DEF_GETEXT(single, ext, target)
#define CAOL_COMPILIFICS_EXT_zero_call_used_regs(single, ext, choice)                     CAOL_COMPILIFICS_DEF_GETEXT(single, ext, choice)


#define CAOL_COMPILIFICS_PACK(t, ...) CAOL_COMPILIFICS_PACK_##t(__VA_ARGS__)
#define CAOL_COMPILIFICS_PACK_X(...) __attribute__((packed)) __VA_ARGS__
#define CAOL_COMPILIFICS_PACK_VAR(...) __attribute__((packed)) __VA_ARGS__
#define CAOL_COMPILIFICS_PACK_UNION(...) union __attribute__((packed)) __VA_ARGS__
#define CAOL_COMPILIFICS_PACK_STRUCT(...) struct __attribute__((packed)) __VA_ARGS__

#define CAOL_COMPILIFICS_FSTART(...) __attribute__((constructor)) __VA_ARGS__
#define CAOL_COMPILIFICS_FSTOP(...) __attribute__((destructor)) __VA_ARGS__

#endif