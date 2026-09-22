#pragma once
#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "kernel/setup"

// #if __cplusplus < 202302L
// #define ___FATAL_ERROR_STOP_COMPILATION___  <Rinegine Framework requires C++23 or higher. Please add '-std=c++23' to your compiler flags.> 
// #include ___FATAL_ERROR_STOP_COMPILATION___
// #endif

#if __cplusplus < 202302L
namespace Rinegine::CompileTest {
  template <auto Standard>
  struct CheckCpp23 {
    static_assert(Standard >= 202302L, 
      "\n\n============================================================\n"
      "❌ RINEGINE COMPILATION ERROR:\n"
      "👉 Rinegine Framework requires C++23 or higher. 👈\n"
      "👉 Please add '-std=c++23' or '-std=c++2b' to your flags. 👈\n"
      "============================================================\n"
    );
  };
  inline CheckCpp23<__cplusplus> trigger;
}
static_assert(true, "Rinegine Framework requires C++23 or higher.");
#include <^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>
#endif



#define RG_V_MAJOR 0
#define RG_V_MINOR 3
#define RG_V_PATCH 0
#define RG_V_WIP 1



#ifndef UINT_MAX
#define UINT_MAX 4294967295
#endif

// #define rg_min(num1, num2) (num1 < num2 ? num1 : num2)
// #define rg_max(num1, num2) (num1 > num2 ? num1 : num2)

#ifdef RG_UTF

#define rg_cout std::wcout
#define rg_ostrem std::wostream

#define rg_cin std::wcin
#define rg_string std::wstring
#define rg_char wchar_t
#define rg_to_string_(in) to_wstring(in)
#define RG_L L""
#else

#define rg_cout std::cout
#define rg_ostrem std::ostream

#define rg_cin std::cin
#define rg_string std::string
#define rg_char char
#define RG_L
#endif



#define elif else if

#define to_rvalue(type) const type & //todo 
#define to_rrvalue(type) const type //todo 



// #define RG_DEPRECATED_MACRO(name) 

#ifdef _WIN32
#define RG_WIN          RG_DEPRECATED_MACRO(RG_WIN)
#define RG_WINos        RG_DEPRECATED_MACRO(RG_WINos)
#define RG_Win          RG_DEPRECATED_MACRO(RG_Win)
#define RG_Winos        RG_DEPRECATED_MACRO(RG_Winos)
#define RG_Windows      RG_DEPRECATED_MACRO(RG_Windows)
#define RG_Windowsos    RG_DEPRECATED_MACRO(RG_Windowsos)
#endif

#ifdef __linux__
#define RG_Linux        RG_DEPRECATED_MACRO(RG_Linux)
#define RG_Linuxos      RG_DEPRECATED_MACRO(RG_Linuxos)
#define RG_LINUX        RG_DEPRECATED_MACRO(RG_LINUX)
#define RG_LINUXos      RG_DEPRECATED_MACRO(RG_LINUXos)
#define RG_LNX          RG_DEPRECATED_MACRO(RG_LNX)
#define RG_LNXos        RG_DEPRECATED_MACRO(RG_LNXos)
#endif
// #warning "Macros RG_WIN, RG_WINos, RG_Win, RG_Winos, RG_Windows, RG_Windowsos, RG_Linux, RG_Linuxos, RG_LINUX, RG_LINUXos, RG_LNX and RG_LNXos is outdated! Use modern alternative.")

#ifdef _WIN32
#define RG_SYS_WINDOWS
#endif
#ifdef __linux__
#define RG_SYS_LINUX
#endif
#ifdef __ANDROID__
#define RG_SYS_ANDROID
#endif

#if !defined(__linux__) && !defined(_WIN32) && !defined(__ANDROID__)
#error "OS isn't supported!"
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__) || defined(_M_ARM64)
#define RG_SYS_x64
#define RG_SYS_x32
#elif defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(_M_ARM)
#define RG_SYS_x32
#else
#error "Unsupported architecture"
#endif

#if defined(__aarch64__) || defined(_M_ARM64) || defined(__arm__) || defined(_M_ARM)
#define RG_SYS_ARM
#endif


#if defined(UNICODE) && !defined(RG_UTF)
#define RG_UTF
#endif

#ifdef RG_UTF
#define _GLIBCXX_USE_WCHAR_T
#endif

#if defined(RG_GLFW_NATIVE_WIN32) && defined(RG_SYS_WINDOWSos)
#define GLFW_EXPOSE_NATIVE_WIN32
#endif


namespace Rinegine {
  void GetVersion(int& major, int& minor, int& patch, int& wip);
  void GetVersion(int& major, int& minor, int& patch);
  constexpr const char* VERSION = "0.3.0";
  constexpr const char* EDITION = "Beginning";

  inline void nop(...) {
    __asm__ __volatile__("nop");
  }
  inline void nop() {
    __asm__ __volatile__("nop");
  }
}




//TYPES

typedef __UINT8_TYPE__ uint8;
typedef __UINT16_TYPE__ uint16;
typedef __UINT32_TYPE__ uint32;
typedef __UINT64_TYPE__ uint64;





#ifdef DO_NOT_ENABLE_THIS_FLAG_UNLESS_YOU_WANT_TO_BREAK_THE_BUILD
/*clang*/
//-march=native
#define _LP64 1
#define __ADX__ 1
#define __AES__ 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_RELEASE 3
#define __ATOMIC_SEQ_CST 5
#define __AVX2__ 1
#define __AVX512BF16__ 1
#define __AVX512BITALG__ 1
#define __AVX512BW__ 1
#define __AVX512CD__ 1
#define __AVX512DQ__ 1
#define __AVX512F__ 1
#define __AVX512IFMA__ 1
#define __AVX512VBMI2__ 1
#define __AVX512VBMI__ 1
#define __AVX512VL__ 1
#define __AVX512VNNI__ 1
#define __AVX512VPOPCNTDQ__ 1
#define __AVX__ 1
#define __BIGGEST_ALIGNMENT__ 16
#define __BITINT_MAXWIDTH__ 8388608
//[todo]
#define __BMI2__ 1
#define __BMI__ 1
#define __BOOL_WIDTH__ 1
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __CHAR16_TYPE__ unsigned short
#define __CHAR32_TYPE__ unsigned int
#define __CHAR_BIT__ 8
#define __CLANG_ATOMIC_BOOL_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR_LOCK_FREE 2
#define __CLANG_ATOMIC_INT_LOCK_FREE 2
#define __CLANG_ATOMIC_LLONG_LOCK_FREE 2
#define __CLANG_ATOMIC_LONG_LOCK_FREE 2
#define __CLANG_ATOMIC_POINTER_LOCK_FREE 2
#define __CLANG_ATOMIC_SHORT_LOCK_FREE 2
#define __CLANG_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __CLFLUSHOPT__ 1
#define __CLWB__ 1
#define __CLZERO__ 1
#define __CONSTANT_CFSTRINGS__ 1
#define __CRC32__ 1
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
#define __DBL_DIG__ 15
#define __DBL_EPSILON__ 2.2204460492503131e-16
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_MAX_10_EXP__ 308
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX__ 1.7976931348623157e+308
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN__ 2.2250738585072014e-308
#define __DBL_NORM_MAX__ 1.7976931348623157e+308
#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
#define __ELF__ 1
#define __F16C__ 1
#define __FINITE_MATH_ONLY__ 0
#define __FLOAT128__ 1
#define __FLT16_DECIMAL_DIG__ 5
#define __FLT16_DENORM_MIN__ 5.9604644775390625e-8F16
#define __FLT16_DIG__ 3
#define __FLT16_EPSILON__ 9.765625e-4F16
#define __FLT16_HAS_DENORM__ 1
#define __FLT16_HAS_INFINITY__ 1
#define __FLT16_HAS_QUIET_NAN__ 1
#define __FLT16_MANT_DIG__ 11
#define __FLT16_MAX_10_EXP__ 4
#define __FLT16_MAX_EXP__ 16
#define __FLT16_MAX__ 6.5504e+4F16
#define __FLT16_MIN_10_EXP__ (-4)
#define __FLT16_MIN_EXP__ (-13)
#define __FLT16_MIN__ 6.103515625e-5F16
#define __FLT16_NORM_MAX__ 6.5504e+4F16
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_DENORM_MIN__ 1.40129846e-45F
#define __FLT_DIG__ 6
#define __FLT_EPSILON__ 1.19209290e-7F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_MANT_DIG__ 24
#define __FLT_MAX_10_EXP__ 38
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX__ 3.40282347e+38F
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN__ 1.17549435e-38F
#define __FLT_NORM_MAX__ 3.40282347e+38F
#define __FLT_RADIX__ 2
#define __FMA__ 1
#define __FPCLASS_NEGINF 0x0004
#define __FPCLASS_NEGNORMAL 0x0008
#define __FPCLASS_NEGSUBNORMAL 0x0010
#define __FPCLASS_NEGZERO 0x0020
#define __FPCLASS_POSINF 0x0200
#define __FPCLASS_POSNORMAL 0x0100
#define __FPCLASS_POSSUBNORMAL 0x0080
#define __FPCLASS_POSZERO 0x0040
#define __FPCLASS_QNAN 0x0002
#define __FPCLASS_SNAN 0x0001
#define __FSGSBASE__ 1
#define __FXSR__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __GCC_CONSTRUCTIVE_SIZE 64
#define __GCC_DESTRUCTIVE_SIZE 64
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __GFNI__ 1
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 1
#define __GNUC_STDC_INLINE__ 1
#define __GNUC__ 4
#define __GXX_ABI_VERSION 1002
#define __INT16_C(c) c
#define __INT16_C_SUFFIX__ 
#define __INT16_FMTd__ "hd"
#define __INT16_FMTi__ "hi"
#define __INT16_MAX__ 32767
#define __INT16_TYPE__ short
#define __INT32_C(c) c
#define __INT32_C_SUFFIX__ 
#define __INT32_FMTd__ "d"
#define __INT32_FMTi__ "i"
#define __INT32_MAX__ 2147483647
#define __INT32_TYPE__ int
#define __INT64_C(c) c##L
#define __INT64_C_SUFFIX__ L
#define __INT64_FMTd__ "ld"
#define __INT64_FMTi__ "li"
#define __INT64_MAX__ 9223372036854775807L
#define __INT64_TYPE__ long int
#define __INT8_C(c) c
#define __INT8_C_SUFFIX__ 
#define __INT8_FMTd__ "hhd"
#define __INT8_FMTi__ "hhi"
#define __INT8_MAX__ 127
#define __INT8_TYPE__ signed char
#define __INTMAX_C(c) c##L
#define __INTMAX_C_SUFFIX__ L
#define __INTMAX_FMTd__ "ld"
#define __INTMAX_FMTi__ "li"
#define __INTMAX_MAX__ 9223372036854775807L
#define __INTMAX_TYPE__ long int
#define __INTMAX_WIDTH__ 64
#define __INTPTR_FMTd__ "ld"
#define __INTPTR_FMTi__ "li"
#define __INTPTR_MAX__ 9223372036854775807L
#define __INTPTR_TYPE__ long int
#define __INTPTR_WIDTH__ 64
#define __INT_FAST16_FMTd__ "hd"
#define __INT_FAST16_FMTi__ "hi"
#define __INT_FAST16_MAX__ 32767
#define __INT_FAST16_TYPE__ short
#define __INT_FAST16_WIDTH__ 16
#define __INT_FAST32_FMTd__ "d"
#define __INT_FAST32_FMTi__ "i"
#define __INT_FAST32_MAX__ 2147483647
#define __INT_FAST32_TYPE__ int
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_FMTd__ "ld"
#define __INT_FAST64_FMTi__ "li"
#define __INT_FAST64_MAX__ 9223372036854775807L
#define __INT_FAST64_TYPE__ long int
#define __INT_FAST64_WIDTH__ 64
#define __INT_FAST8_FMTd__ "hhd"
#define __INT_FAST8_FMTi__ "hhi"
#define __INT_FAST8_MAX__ 127
#define __INT_FAST8_TYPE__ signed char
#define __INT_FAST8_WIDTH__ 8
#define __INT_LEAST16_FMTd__ "hd"
#define __INT_LEAST16_FMTi__ "hi"
#define __INT_LEAST16_MAX__ 32767
#define __INT_LEAST16_TYPE__ short
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_FMTd__ "d"
#define __INT_LEAST32_FMTi__ "i"
#define __INT_LEAST32_MAX__ 2147483647
#define __INT_LEAST32_TYPE__ int
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_FMTd__ "ld"
#define __INT_LEAST64_FMTi__ "li"
#define __INT_LEAST64_MAX__ 9223372036854775807L
#define __INT_LEAST64_TYPE__ long int
#define __INT_LEAST64_WIDTH__ 64
#define __INT_LEAST8_FMTd__ "hhd"
#define __INT_LEAST8_FMTi__ "hhi"
#define __INT_LEAST8_MAX__ 127
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST8_WIDTH__ 8
#define __INT_MAX__ 2147483647
#define __INT_WIDTH__ 32
#define __INVPCID__ 1
#define __LAHF_SAHF__ 1
#define __LDBL_DECIMAL_DIG__ 21
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
#define __LDBL_DIG__ 18
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 64
#define __LDBL_MAX_10_EXP__ 4932
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MAX__ 1.18973149535723176502e+4932L
#define __LDBL_MIN_10_EXP__ (-4931)
#define __LDBL_MIN_EXP__ (-16381)
#define __LDBL_MIN__ 3.36210314311209350626e-4932L
#define __LDBL_NORM_MAX__ 1.18973149535723176502e+4932L
#define __LITTLE_ENDIAN__ 1
#define __LLONG_WIDTH__ 64
#define __LONG_LONG_MAX__ 9223372036854775807LL
#define __LONG_MAX__ 9223372036854775807L
#define __LONG_WIDTH__ 64
#define __LP64__ 1
#define __LZCNT__ 1
#define __MEMORY_SCOPE_CLUSTR 5
#define __MEMORY_SCOPE_DEVICE 1
#define __MEMORY_SCOPE_SINGLE 4
#define __MEMORY_SCOPE_SYSTEM 0
#define __MEMORY_SCOPE_WRKGRP 2
#define __MEMORY_SCOPE_WVFRNT 3
#define __MMX__ 1
#define __MOVBE__ 1
#define __MWAITX__ 1
#define __NO_INLINE__ 1
#define __NO_MATH_INLINES 1
#define __OBJC_BOOL_IS_BOOL 0
#define __OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES 3
#define __OPENCL_MEMORY_SCOPE_DEVICE 2
#define __OPENCL_MEMORY_SCOPE_SUB_GROUP 4
#define __OPENCL_MEMORY_SCOPE_WORK_GROUP 1
#define __OPENCL_MEMORY_SCOPE_WORK_ITEM 0
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_PDP_ENDIAN__ 3412
#define __PCLMUL__ 1
#define __PIC__ 2
#define __PIE__ 2
#define __PKU__ 1
#define __POINTER_WIDTH__ 64
#define __POPCNT__ 1
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __PRFCHW__ 1
#define __PTRDIFF_FMTd__ "ld"
#define __PTRDIFF_FMTi__ "li"
#define __PTRDIFF_MAX__ 9223372036854775807L
#define __PTRDIFF_TYPE__ long int
#define __PTRDIFF_WIDTH__ 64
#define __RDPID__ 1
#define __RDPRU__ 1
#define __RDRND__ 1
#define __RDSEED__ 1
#define __REGISTER_PREFIX__ 
#define __SCHAR_MAX__ 127
#define __SEG_FS 1
#define __SEG_GS 1
#define __SHA__ 1
#define __SHRT_MAX__ 32767
#define __SHRT_WIDTH__ 16
#define __SHSTK__ 1
#define __SIG_ATOMIC_MAX__ 2147483647
#define __SIG_ATOMIC_WIDTH__ 32
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_FLOAT128__ 16
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_INT128__ 16
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG_DOUBLE__ 16
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_LONG__ 8
#define __SIZEOF_POINTER__ 8
#define __SIZEOF_PTRDIFF_T__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_SIZE_T__ 8
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZE_FMTX__ "lX"
#define __SIZE_FMTo__ "lo"
#define __SIZE_FMTu__ "lu"
#define __SIZE_FMTx__ "lx"
#define __SIZE_MAX__ 18446744073709551615UL
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 64
#define __SSE2_MATH__ 1
#define __SSE2__ 1
#define __SSE3__ 1
#define __SSE4A__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSE__ 1
#define __SSP_STRONG__ 2
#define __SSSE3__ 1
#define __STDC_EMBED_EMPTY__ 2
#define __STDC_EMBED_FOUND__ 1
#define __STDC_EMBED_NOT_FOUND__ 0
#define __STDC_HOSTED__ 1
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_VERSION__ 201710L
#define __STDC__ 1
#define __UINT16_C(c) c
#define __UINT16_C_SUFFIX__ 
#define __UINT16_FMTX__ "hX"
#define __UINT16_FMTo__ "ho"
#define __UINT16_FMTu__ "hu"
#define __UINT16_FMTx__ "hx"
#define __UINT16_MAX__ 65535
#define __UINT16_TYPE__ unsigned short
#define __UINT32_C(c) c##U
#define __UINT32_C_SUFFIX__ U
#define __UINT32_FMTX__ "X"
#define __UINT32_FMTo__ "o"
#define __UINT32_FMTu__ "u"
#define __UINT32_FMTx__ "x"
#define __UINT32_MAX__ 4294967295U
#define __UINT32_TYPE__ unsigned int
#define __UINT64_C(c) c##UL
#define __UINT64_C_SUFFIX__ UL
#define __UINT64_FMTX__ "lX"
#define __UINT64_FMTo__ "lo"
#define __UINT64_FMTu__ "lu"
#define __UINT64_FMTx__ "lx"
#define __UINT64_MAX__ 18446744073709551615UL
#define __UINT64_TYPE__ long unsigned int
#define __UINT8_C(c) c
#define __UINT8_C_SUFFIX__ 
#define __UINT8_FMTX__ "hhX"
#define __UINT8_FMTo__ "hho"
#define __UINT8_FMTu__ "hhu"
#define __UINT8_FMTx__ "hhx"
#define __UINT8_MAX__ 255
#define __UINT8_TYPE__ unsigned char
#define __UINTMAX_C(c) c##UL
#define __UINTMAX_C_SUFFIX__ UL
#define __UINTMAX_FMTX__ "lX"
#define __UINTMAX_FMTo__ "lo"
#define __UINTMAX_FMTu__ "lu"
#define __UINTMAX_FMTx__ "lx"
#define __UINTMAX_MAX__ 18446744073709551615UL
#define __UINTMAX_TYPE__ long unsigned int
#define __UINTMAX_WIDTH__ 64
#define __UINTPTR_FMTX__ "lX"
#define __UINTPTR_FMTo__ "lo"
#define __UINTPTR_FMTu__ "lu"
#define __UINTPTR_FMTx__ "lx"
#define __UINTPTR_MAX__ 18446744073709551615UL
#define __UINTPTR_TYPE__ long unsigned int
#define __UINTPTR_WIDTH__ 64
#define __UINT_FAST16_FMTX__ "hX"
#define __UINT_FAST16_FMTo__ "ho"
#define __UINT_FAST16_FMTu__ "hu"
#define __UINT_FAST16_FMTx__ "hx"
#define __UINT_FAST16_MAX__ 65535
#define __UINT_FAST16_TYPE__ unsigned short
#define __UINT_FAST32_FMTX__ "X"
#define __UINT_FAST32_FMTo__ "o"
#define __UINT_FAST32_FMTu__ "u"
#define __UINT_FAST32_FMTx__ "x"
#define __UINT_FAST32_MAX__ 4294967295U
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_FMTX__ "lX"
#define __UINT_FAST64_FMTo__ "lo"
#define __UINT_FAST64_FMTu__ "lu"
#define __UINT_FAST64_FMTx__ "lx"
#define __UINT_FAST64_MAX__ 18446744073709551615UL
#define __UINT_FAST64_TYPE__ long unsigned int
#define __UINT_FAST8_FMTX__ "hhX"
#define __UINT_FAST8_FMTo__ "hho"
#define __UINT_FAST8_FMTu__ "hhu"
#define __UINT_FAST8_FMTx__ "hhx"
#define __UINT_FAST8_MAX__ 255
#define __UINT_FAST8_TYPE__ unsigned char
#define __UINT_LEAST16_FMTX__ "hX"
#define __UINT_LEAST16_FMTo__ "ho"
#define __UINT_LEAST16_FMTu__ "hu"
#define __UINT_LEAST16_FMTx__ "hx"
#define __UINT_LEAST16_MAX__ 65535
#define __UINT_LEAST16_TYPE__ unsigned short
#define __UINT_LEAST32_FMTX__ "X"
#define __UINT_LEAST32_FMTo__ "o"
#define __UINT_LEAST32_FMTu__ "u"
#define __UINT_LEAST32_FMTx__ "x"
#define __UINT_LEAST32_MAX__ 4294967295U
#define __UINT_LEAST32_TYPE__ unsigned int
#define __UINT_LEAST64_FMTX__ "lX"
#define __UINT_LEAST64_FMTo__ "lo"
#define __UINT_LEAST64_FMTu__ "lu"
#define __UINT_LEAST64_FMTx__ "lx"
#define __UINT_LEAST64_MAX__ 18446744073709551615UL
#define __UINT_LEAST64_TYPE__ long unsigned int
#define __UINT_LEAST8_FMTX__ "hhX"
#define __UINT_LEAST8_FMTo__ "hho"
#define __UINT_LEAST8_FMTu__ "hhu"
#define __UINT_LEAST8_FMTx__ "hhx"
#define __UINT_LEAST8_MAX__ 255
#define __UINT_LEAST8_TYPE__ unsigned char
#define __USER_LABEL_PREFIX__ 
#define __VAES__ 1
#define __VERSION__ "Clang 22.1.8"
#define __VPCLMULQDQ__ 1
#define __WBNOINVD__ 1
#define __WCHAR_MAX__ 2147483647
#define __WCHAR_TYPE__ int
#define __WCHAR_WIDTH__ 32
#define __WINT_MAX__ 4294967295U
#define __WINT_TYPE__ unsigned int
#define __WINT_UNSIGNED__ 1
#define __WINT_WIDTH__ 32
#define __XSAVEC__ 1
#define __XSAVEOPT__ 1
#define __XSAVES__ 1
#define __XSAVE__ 1
#define __amd64 1
#define __amd64__ 1
#define __clang__ 1
#define __clang_literal_encoding__ "UTF-8"
#define __clang_major__ 22
#define __clang_minor__ 1
#define __clang_patchlevel__ 8
#define __clang_version__ "22.1.8 "
#define __clang_wide_literal_encoding__ "UTF-32"
#define __code_model_small__ 1
#define __gnu_linux__ 1
#define __linux 1
#define __linux__ 1
#define __llvm__ 1
#define __pic__ 2
#define __pie__ 2
#define __seg_fs __attribute__((address_space(257)))
#define __seg_gs __attribute__((address_space(256)))
#define __tune_znver4__ 1
#define __unix 1
#define __unix__ 1
#define __x86_64 1
#define __x86_64__ 1
#define __znver4 1
#define __znver4__ 1
#define linux 1
#define unix 1

//default build
#define _LP64 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_RELEASE 3
#define __ATOMIC_SEQ_CST 5
#define __BIGGEST_ALIGNMENT__ 16
#define __BITINT_MAXWIDTH__ 8388608
#define __BOOL_WIDTH__ 1
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __CHAR16_TYPE__ unsigned short
#define __CHAR32_TYPE__ unsigned int
#define __CHAR_BIT__ 8
#define __CLANG_ATOMIC_BOOL_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR_LOCK_FREE 2
#define __CLANG_ATOMIC_INT_LOCK_FREE 2
#define __CLANG_ATOMIC_LLONG_LOCK_FREE 2
#define __CLANG_ATOMIC_LONG_LOCK_FREE 2
#define __CLANG_ATOMIC_POINTER_LOCK_FREE 2
#define __CLANG_ATOMIC_SHORT_LOCK_FREE 2
#define __CLANG_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __CONSTANT_CFSTRINGS__ 1
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
#define __DBL_DIG__ 15
#define __DBL_EPSILON__ 2.2204460492503131e-16
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_MAX_10_EXP__ 308
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX__ 1.7976931348623157e+308
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN__ 2.2250738585072014e-308
#define __DBL_NORM_MAX__ 1.7976931348623157e+308
#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
#define __ELF__ 1
#define __FINITE_MATH_ONLY__ 0
#define __FLOAT128__ 1
#define __FLT16_DECIMAL_DIG__ 5
#define __FLT16_DENORM_MIN__ 5.9604644775390625e-8F16
#define __FLT16_DIG__ 3
#define __FLT16_EPSILON__ 9.765625e-4F16
#define __FLT16_HAS_DENORM__ 1
#define __FLT16_HAS_INFINITY__ 1
#define __FLT16_HAS_QUIET_NAN__ 1
#define __FLT16_MANT_DIG__ 11
#define __FLT16_MAX_10_EXP__ 4
#define __FLT16_MAX_EXP__ 16
#define __FLT16_MAX__ 6.5504e+4F16
#define __FLT16_MIN_10_EXP__ (-4)
#define __FLT16_MIN_EXP__ (-13)
#define __FLT16_MIN__ 6.103515625e-5F16
#define __FLT16_NORM_MAX__ 6.5504e+4F16
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_DENORM_MIN__ 1.40129846e-45F
#define __FLT_DIG__ 6
#define __FLT_EPSILON__ 1.19209290e-7F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_MANT_DIG__ 24
#define __FLT_MAX_10_EXP__ 38
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX__ 3.40282347e+38F
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN__ 1.17549435e-38F
#define __FLT_NORM_MAX__ 3.40282347e+38F
#define __FLT_RADIX__ 2
#define __FPCLASS_NEGINF 0x0004
#define __FPCLASS_NEGNORMAL 0x0008
#define __FPCLASS_NEGSUBNORMAL 0x0010
#define __FPCLASS_NEGZERO 0x0020
#define __FPCLASS_POSINF 0x0200
#define __FPCLASS_POSNORMAL 0x0100
#define __FPCLASS_POSSUBNORMAL 0x0080
#define __FPCLASS_POSZERO 0x0040
#define __FPCLASS_QNAN 0x0002
#define __FPCLASS_SNAN 0x0001
#define __FXSR__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __GCC_CONSTRUCTIVE_SIZE 64
#define __GCC_DESTRUCTIVE_SIZE 64
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 1
#define __GNUC_STDC_INLINE__ 1
#define __GNUC__ 4
#define __GXX_ABI_VERSION 1002
#define __INT16_C(c) c
#define __INT16_C_SUFFIX__ 
#define __INT16_FMTd__ "hd"
#define __INT16_FMTi__ "hi"
#define __INT16_MAX__ 32767
#define __INT16_TYPE__ short
#define __INT32_C(c) c
#define __INT32_C_SUFFIX__ 
#define __INT32_FMTd__ "d"
#define __INT32_FMTi__ "i"
#define __INT32_MAX__ 2147483647
#define __INT32_TYPE__ int
#define __INT64_C(c) c##L
#define __INT64_C_SUFFIX__ L
#define __INT64_FMTd__ "ld"
#define __INT64_FMTi__ "li"
#define __INT64_MAX__ 9223372036854775807L
#define __INT64_TYPE__ long int
#define __INT8_C(c) c
#define __INT8_C_SUFFIX__ 
#define __INT8_FMTd__ "hhd"
#define __INT8_FMTi__ "hhi"
#define __INT8_MAX__ 127
#define __INT8_TYPE__ signed char
#define __INTMAX_C(c) c##L
#define __INTMAX_C_SUFFIX__ L
#define __INTMAX_FMTd__ "ld"
#define __INTMAX_FMTi__ "li"
#define __INTMAX_MAX__ 9223372036854775807L
#define __INTMAX_TYPE__ long int
#define __INTMAX_WIDTH__ 64
#define __INTPTR_FMTd__ "ld"
#define __INTPTR_FMTi__ "li"
#define __INTPTR_MAX__ 9223372036854775807L
#define __INTPTR_TYPE__ long int
#define __INTPTR_WIDTH__ 64
#define __INT_FAST16_FMTd__ "hd"
#define __INT_FAST16_FMTi__ "hi"
#define __INT_FAST16_MAX__ 32767
#define __INT_FAST16_TYPE__ short
#define __INT_FAST16_WIDTH__ 16
#define __INT_FAST32_FMTd__ "d"
#define __INT_FAST32_FMTi__ "i"
#define __INT_FAST32_MAX__ 2147483647
#define __INT_FAST32_TYPE__ int
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_FMTd__ "ld"
#define __INT_FAST64_FMTi__ "li"
#define __INT_FAST64_MAX__ 9223372036854775807L
#define __INT_FAST64_TYPE__ long int
#define __INT_FAST64_WIDTH__ 64
#define __INT_FAST8_FMTd__ "hhd"
#define __INT_FAST8_FMTi__ "hhi"
#define __INT_FAST8_MAX__ 127
#define __INT_FAST8_TYPE__ signed char
#define __INT_FAST8_WIDTH__ 8
#define __INT_LEAST16_FMTd__ "hd"
#define __INT_LEAST16_FMTi__ "hi"
#define __INT_LEAST16_MAX__ 32767
#define __INT_LEAST16_TYPE__ short
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_FMTd__ "d"
#define __INT_LEAST32_FMTi__ "i"
#define __INT_LEAST32_MAX__ 2147483647
#define __INT_LEAST32_TYPE__ int
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_FMTd__ "ld"
#define __INT_LEAST64_FMTi__ "li"
#define __INT_LEAST64_MAX__ 9223372036854775807L
#define __INT_LEAST64_TYPE__ long int
#define __INT_LEAST64_WIDTH__ 64
#define __INT_LEAST8_FMTd__ "hhd"
#define __INT_LEAST8_FMTi__ "hhi"
#define __INT_LEAST8_MAX__ 127
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST8_WIDTH__ 8
#define __INT_MAX__ 2147483647
#define __INT_WIDTH__ 32
#define __LDBL_DECIMAL_DIG__ 21
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
#define __LDBL_DIG__ 18
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 64
#define __LDBL_MAX_10_EXP__ 4932
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MAX__ 1.18973149535723176502e+4932L
#define __LDBL_MIN_10_EXP__ (-4931)
#define __LDBL_MIN_EXP__ (-16381)
#define __LDBL_MIN__ 3.36210314311209350626e-4932L
#define __LDBL_NORM_MAX__ 1.18973149535723176502e+4932L
#define __LITTLE_ENDIAN__ 1
#define __LLONG_WIDTH__ 64
#define __LONG_LONG_MAX__ 9223372036854775807LL
#define __LONG_MAX__ 9223372036854775807L
#define __LONG_WIDTH__ 64
#define __LP64__ 1
#define __MEMORY_SCOPE_CLUSTR 5
#define __MEMORY_SCOPE_DEVICE 1
#define __MEMORY_SCOPE_SINGLE 4
#define __MEMORY_SCOPE_SYSTEM 0
#define __MEMORY_SCOPE_WRKGRP 2
#define __MEMORY_SCOPE_WVFRNT 3
#define __MMX__ 1
#define __NO_INLINE__ 1
#define __NO_MATH_INLINES 1
#define __OBJC_BOOL_IS_BOOL 0
#define __OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES 3
#define __OPENCL_MEMORY_SCOPE_DEVICE 2
#define __OPENCL_MEMORY_SCOPE_SUB_GROUP 4
#define __OPENCL_MEMORY_SCOPE_WORK_GROUP 1
#define __OPENCL_MEMORY_SCOPE_WORK_ITEM 0
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_PDP_ENDIAN__ 3412
#define __PIC__ 2
#define __PIE__ 2
#define __POINTER_WIDTH__ 64
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __PTRDIFF_FMTd__ "ld"
#define __PTRDIFF_FMTi__ "li"
#define __PTRDIFF_MAX__ 9223372036854775807L
#define __PTRDIFF_TYPE__ long int
#define __PTRDIFF_WIDTH__ 64
#define __REGISTER_PREFIX__ 
#define __SCHAR_MAX__ 127
#define __SEG_FS 1
#define __SEG_GS 1
#define __SHRT_MAX__ 32767
#define __SHRT_WIDTH__ 16
#define __SIG_ATOMIC_MAX__ 2147483647
#define __SIG_ATOMIC_WIDTH__ 32
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_FLOAT128__ 16
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_INT128__ 16
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG_DOUBLE__ 16
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_LONG__ 8
#define __SIZEOF_POINTER__ 8
#define __SIZEOF_PTRDIFF_T__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_SIZE_T__ 8
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZE_FMTX__ "lX"
#define __SIZE_FMTo__ "lo"
#define __SIZE_FMTu__ "lu"
#define __SIZE_FMTx__ "lx"
#define __SIZE_MAX__ 18446744073709551615UL
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 64
#define __SSE2_MATH__ 1
#define __SSE2__ 1
#define __SSE_MATH__ 1
#define __SSE__ 1
#define __SSP_STRONG__ 2
#define __STDC_EMBED_EMPTY__ 2
#define __STDC_EMBED_FOUND__ 1
#define __STDC_EMBED_NOT_FOUND__ 0
#define __STDC_HOSTED__ 1
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_VERSION__ 201710L
#define __STDC__ 1
#define __UINT16_C(c) c
#define __UINT16_C_SUFFIX__ 
#define __UINT16_FMTX__ "hX"
#define __UINT16_FMTo__ "ho"
#define __UINT16_FMTu__ "hu"
#define __UINT16_FMTx__ "hx"
#define __UINT16_MAX__ 65535
#define __UINT16_TYPE__ unsigned short
#define __UINT32_C(c) c##U
#define __UINT32_C_SUFFIX__ U
#define __UINT32_FMTX__ "X"
#define __UINT32_FMTo__ "o"
#define __UINT32_FMTu__ "u"
#define __UINT32_FMTx__ "x"
#define __UINT32_MAX__ 4294967295U
#define __UINT32_TYPE__ unsigned int
#define __UINT64_C(c) c##UL
#define __UINT64_C_SUFFIX__ UL
#define __UINT64_FMTX__ "lX"
#define __UINT64_FMTo__ "lo"
#define __UINT64_FMTu__ "lu"
#define __UINT64_FMTx__ "lx"
#define __UINT64_MAX__ 18446744073709551615UL
#define __UINT64_TYPE__ long unsigned int
#define __UINT8_C(c) c
#define __UINT8_C_SUFFIX__ 
#define __UINT8_FMTX__ "hhX"
#define __UINT8_FMTo__ "hho"
#define __UINT8_FMTu__ "hhu"
#define __UINT8_FMTx__ "hhx"
#define __UINT8_MAX__ 255
#define __UINT8_TYPE__ unsigned char
#define __UINTMAX_C(c) c##UL
#define __UINTMAX_C_SUFFIX__ UL
#define __UINTMAX_FMTX__ "lX"
#define __UINTMAX_FMTo__ "lo"
#define __UINTMAX_FMTu__ "lu"
#define __UINTMAX_FMTx__ "lx"
#define __UINTMAX_MAX__ 18446744073709551615UL
#define __UINTMAX_TYPE__ long unsigned int
#define __UINTMAX_WIDTH__ 64
#define __UINTPTR_FMTX__ "lX"
#define __UINTPTR_FMTo__ "lo"
#define __UINTPTR_FMTu__ "lu"
#define __UINTPTR_FMTx__ "lx"
#define __UINTPTR_MAX__ 18446744073709551615UL
#define __UINTPTR_TYPE__ long unsigned int
#define __UINTPTR_WIDTH__ 64
#define __UINT_FAST16_FMTX__ "hX"
#define __UINT_FAST16_FMTo__ "ho"
#define __UINT_FAST16_FMTu__ "hu"
#define __UINT_FAST16_FMTx__ "hx"
#define __UINT_FAST16_MAX__ 65535
#define __UINT_FAST16_TYPE__ unsigned short
#define __UINT_FAST32_FMTX__ "X"
#define __UINT_FAST32_FMTo__ "o"
#define __UINT_FAST32_FMTu__ "u"
#define __UINT_FAST32_FMTx__ "x"
#define __UINT_FAST32_MAX__ 4294967295U
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_FMTX__ "lX"
#define __UINT_FAST64_FMTo__ "lo"
#define __UINT_FAST64_FMTu__ "lu"
#define __UINT_FAST64_FMTx__ "lx"
#define __UINT_FAST64_MAX__ 18446744073709551615UL
#define __UINT_FAST64_TYPE__ long unsigned int
#define __UINT_FAST8_FMTX__ "hhX"
#define __UINT_FAST8_FMTo__ "hho"
#define __UINT_FAST8_FMTu__ "hhu"
#define __UINT_FAST8_FMTx__ "hhx"
#define __UINT_FAST8_MAX__ 255
#define __UINT_FAST8_TYPE__ unsigned char
#define __UINT_LEAST16_FMTX__ "hX"
#define __UINT_LEAST16_FMTo__ "ho"
#define __UINT_LEAST16_FMTu__ "hu"
#define __UINT_LEAST16_FMTx__ "hx"
#define __UINT_LEAST16_MAX__ 65535
#define __UINT_LEAST16_TYPE__ unsigned short
#define __UINT_LEAST32_FMTX__ "X"
#define __UINT_LEAST32_FMTo__ "o"
#define __UINT_LEAST32_FMTu__ "u"
#define __UINT_LEAST32_FMTx__ "x"
#define __UINT_LEAST32_MAX__ 4294967295U
#define __UINT_LEAST32_TYPE__ unsigned int
#define __UINT_LEAST64_FMTX__ "lX"
#define __UINT_LEAST64_FMTo__ "lo"
#define __UINT_LEAST64_FMTu__ "lu"
#define __UINT_LEAST64_FMTx__ "lx"
#define __UINT_LEAST64_MAX__ 18446744073709551615UL
#define __UINT_LEAST64_TYPE__ long unsigned int
#define __UINT_LEAST8_FMTX__ "hhX"
#define __UINT_LEAST8_FMTo__ "hho"
#define __UINT_LEAST8_FMTu__ "hhu"
#define __UINT_LEAST8_FMTx__ "hhx"
#define __UINT_LEAST8_MAX__ 255
#define __UINT_LEAST8_TYPE__ unsigned char
#define __USER_LABEL_PREFIX__ 
#define __VERSION__ "Clang 22.1.8"
#define __WCHAR_MAX__ 2147483647
#define __WCHAR_TYPE__ int
#define __WCHAR_WIDTH__ 32
#define __WINT_MAX__ 4294967295U
#define __WINT_TYPE__ unsigned int
#define __WINT_UNSIGNED__ 1
#define __WINT_WIDTH__ 32
#define __amd64 1
#define __amd64__ 1
#define __clang__ 1
#define __clang_literal_encoding__ "UTF-8"
#define __clang_major__ 22
#define __clang_minor__ 1
#define __clang_patchlevel__ 8
#define __clang_version__ "22.1.8 "
#define __clang_wide_literal_encoding__ "UTF-32"
#define __code_model_small__ 1
#define __gnu_linux__ 1
#define __k8 1
#define __k8__ 1
#define __linux 1
#define __linux__ 1
#define __llvm__ 1
#define __pic__ 2
#define __pie__ 2
#define __seg_fs __attribute__((address_space(257)))
#define __seg_gs __attribute__((address_space(256)))
#define __tune_k8__ 1
#define __unix 1
#define __unix__ 1
#define __x86_64 1
#define __x86_64__ 1
#define linux 1
#define unix 1
/*gcc*/
//-march=native
#define __AVX512F__ 1
#define __UINT_LEAST16_MAX__ 0xffff
#define __FLT16_HAS_QUIET_NAN__ 1
#define __MWAITX__ 1
#define __ATOMIC_ACQUIRE 2
#define __GCC_IEC_559_COMPLEX 2
#define __SIZEOF_LONG__ 8
#define __FLT128_MIN_10_EXP__ (-4931)
#define __UINT_LEAST8_TYPE__ unsigned char
#define __SIZEOF_FLOAT80__ 16
#define __BFLT16_DENORM_MIN__ 9.18354961579912115600575419704879436e-41BF16
#define __DEC32_MIN_EXP__ (-94)
#define __AVX512BITALG__ 1
#define __INTMAX_C(c) c ## L
#define __MOVBE__ 1
#define __UINT8_MAX__ 0xff
#define __WINT_MAX__ 0xffffffffU
#define __BFLT16_NORM_MAX__ 3.38953138925153547590470800371487867e+38BF16
#define __BFLT16_MIN_10_EXP__ (-37)
#define __INT_LEAST8_WIDTH__ 8
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __SSE4_1__ 1
#define __STDC__ 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_IEC_559 2
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT_EVAL_METHOD__ 0
#define __FLT32_HAS_INFINITY__ 1
#define __FLT64_DECIMAL_DIG__ 17
#define __DBL_MIN_EXP__ (-1021)
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __RDPID__ 1
#define __UINT_FAST64_MAX__ 0xffffffffffffffffUL
#define __SIG_ATOMIC_TYPE__ int
#define __DBL_MIN_10_EXP__ (-307)
#define __FINITE_MATH_ONLY__ 0
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __FLT32_HAS_DENORM__ 1
#define __UINT_FAST8_MAX__ 0xff
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __FLT32_MAX_10_EXP__ 38
#define __DEC64_MAX_EXP__ 385
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffUL
#define __EVEX256__ 1
#define __SHRT_MAX__ 0x7fff
#define __FLT64X_MAX_10_EXP__ 4932
#define __BFLT16_MAX_10_EXP__ 38
#define __BFLT16_MAX_EXP__ 128
#define __FLT64X_IS_IEC_60559__ 1
#define __FLT64X_HAS_QUIET_NAN__ 1
#define __INT_FAST64_TYPE__ long int
#define __UINT_LEAST8_MAX__ 0xff
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128
#define __UINTMAX_TYPE__ long unsigned int
#define __linux 1
#define __DEC32_EPSILON__ 1E-6DF
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __UINT32_MAX__ 0xffffffffU
#define __STDC_EMBED_NOT_FOUND__ 0
#define __FLT64X_HAS_INFINITY__ 1
#define __FLT128_MIN_EXP__ (-16381)
#define __DEC64X_MAX_EXP__ 6145
#define __CHAR_BIT__ 8
#define __AVX512VBMI2__ 1
#define __FLT32X_IS_IEC_60559__ 1
#define __INT_LEAST16_WIDTH__ 16
#define __SCHAR_MAX__ 0x7f
#define __FLT128_MANT_DIG__ 113
#define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)
#define __INT64_C(c) c ## L
#define __SSP_STRONG__ 3
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __FLT32X_MAX_EXP__ 1024
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __WBNOINVD__ 1
#define __LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L
#define __FLT64X_EPSILON__ 1.08420217248550443400745280086994171e-19F64x
#define __STDC_HOSTED__ 1
#define __FP_FAST_FMAF32 1
#define __FP_FAST_FMAF 1
#define __AVX512VBMI__ 1
#define __STDC_EMBED_EMPTY__ 2
#define __FLT_EPSILON__ 1.19209289550781250000000000000000000e-7F
#define __ABM__ 1
#define __SHRT_WIDTH__ 16
#define __FLT128_MAX_10_EXP__ 4932
#define __unix 1
#define __FLT32_IS_IEC_60559__ 1
#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
#define __STDC_UTF_16__ 1
#define __DEC32_MAX__ 9.999999E96DF
#define __CHAR8_TYPE__ unsigned char
#define __FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x
#define __CRC32__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __SIZEOF_PTRDIFF_T__ 8
#define __unix__ 1
#define __SSE__ 1
#define __STDC_IEC_559__ 1
#define __STDC_ISO_10646__ 201706L
#define __GCC_ATOMIC_CHAR8_T_LOCK_FREE 2
#define __DECIMAL_DIG__ 21
#define __STDC_IEC_559_COMPLEX__ 1
#define __DBL_DIG__ 15
#define __gnu_linux__ 1
#define __FLT64X_MIN_10_EXP__ (-4931)
#define __LDBL_HAS_QUIET_NAN__ 1
#define __FLT16_MIN_EXP__ (-13)
#define __LDBL_MANT_DIG__ 64
#define __FLT64X_MANT_DIG__ 64
#define __BFLT16_DIG__ 2
#define __GNUC__ 16
#define __pie__ 2
#define __MMX__ 1
#define __FLT_HAS_DENORM__ 1
#define __SIZEOF_LONG_DOUBLE__ 16
#define __XSAVEOPT__ 1
#define __LDBL_DIG__ 18
#define __BIGGEST_ALIGNMENT__ 64
#define _STDC_PREDEF_H 1
#define __PRFCHW__ 1
#define __SIZE_TYPE__ long unsigned int
#define __FLT64_MAX_10_EXP__ 308
#define __BFLT16_IS_IEC_60559__ 0
#define __FLT16_DIG__ 3
#define __FLT16_MAX_10_EXP__ 4
#define __GNUC_STDC_INLINE__ 1
#define __DBL_IS_IEC_60559__ 1
#define __DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)
#define __XSAVES__ 1
#define __INT_FAST32_MAX__ 0x7fffffffffffffffL
#define __LDBL_HAS_DENORM__ 1
#define __FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x
#define __DBL_HAS_INFINITY__ 1
#define __SSE4_2__ 1
#define __SIZEOF_FLOAT__ 4
#define __RDSEED__ 1
#define __INTPTR_WIDTH__ 64
#define __AVX512IFMA__ 1
#define __FLT32X_HAS_DENORM__ 1
#define __INT_FAST16_TYPE__ long int
#define __MMX_WITH_SSE__ 1
#define __FLT_DIG__ 6
#define __AVX512BW__ 1
#define __SEG_GS 1
#define __BFLT16_EPSILON__ 7.81250000000000000000000000000000000e-3BF16
#define __FLT128_HAS_INFINITY__ 1
#define __DEC32_MIN__ 1E-95DF
#define __POPCNT__ 1
#define __DBL_MAX_EXP__ 1024
#define __VAES__ 1
#define __WCHAR_WIDTH__ 32
#define __FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32
#define __DEC128_EPSILON__ 1E-33DL
#define __FLT16_DECIMAL_DIG__ 5
#define __SSE2_MATH__ 1
#define __ATOMIC_HLE_RELEASE 131072
#define __PTRDIFF_MAX__ 0x7fffffffffffffffL
#define __FLT128_MAX_EXP__ 16384
#define __amd64 1
#define __AVX__ 1
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __SIZEOF_SIZE_T__ 8
#define __SIG_ATOMIC_WIDTH__ 32
#define __GFNI__ 1
#define __LZCNT__ 1
#define __DEC128_MANT_DIG__ 34
#define __BFLT16_HAS_INFINITY__ 1
#define __FLT64X_MIN_EXP__ (-16381)
#define __SIZEOF_WINT_T__ 4
#define __LONG_LONG_WIDTH__ 64
#define __FLT32_MAX_EXP__ 128
#define __ATOMIC_SEQ_CST 5
#define __GXX_ABI_VERSION 1021
#define __FLT_MIN_EXP__ (-125)
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __DEC64_MIN_EXP__ (-382)
#define __INT16_MAX__ 0x7fff
#define __x86_64 1
#define __znver4 1
#define __BFLT16_MAX__ 3.38953138925153547590470800371487867e+38BF16
#define __DBL_DECIMAL_DIG__ 17
#define __BFLT16_HAS_DENORM__ 1
#define __FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64
#define __CLFLUSHOPT__ 1
#define __FP_FAST_FMAF64 1
#define __PCLMUL__ 1
#define __FLT16_DENORM_MIN__ 5.96046447753906250000000000000000000e-8F16
#define __FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128
#define __FLT64X_NORM_MAX__ 1.18973149535723176502126385303097021e+4932F64x
#define __SIZEOF_POINTER__ 8
#define __F16C__ 1
#define __LP64__ 1
#define __INT_FAST8_WIDTH__ 8
#define __FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x
#define __LDBL_MAX_EXP__ 16384
#define __DECIMAL_BID_FORMAT__ 1
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64X_DECIMAL_DIG__ 21
#define __DEC128_MIN__ 1E-6143DL
#define __LAHF_SAHF__ 1
#define __REGISTER_PREFIX__ 
#define __UINT16_MAX__ 0xffff
#define __DBL_HAS_DENORM__ 1
#define __AVX512VL__ 1
#define __SCHAR_WIDTH__ 8
#define __FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32
#define __UINT8_TYPE__ unsigned char
#define __NO_INLINE__ 1
#define __CLWB__ 1
#define __DEC_EVAL_METHOD__ 2
#define __FLT32X_MAX_10_EXP__ 308
#define __LDBL_DECIMAL_DIG__ 21
#define __FLT16_MIN_10_EXP__ (-4)
#define __UINT64_C(c) c ## UL
#define __VPCLMULQDQ__ 1
#define __DEC64X_MIN__ 1E-6143D64x
#define __FMA__ 1
#define __AVX512CD__ 1
#define __FLT128_IS_IEC_60559__ 1
#define __LDBL_IS_IEC_60559__ 1
#define __INT_LEAST32_MAX__ 0x7fffffff
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __SHSTK__ 1
#define __tune_znver4__ 1
#define __FLT32_MANT_DIG__ 24
#define __FLT16_IS_IEC_60559__ 1
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __FLT32X_MIN_EXP__ (-1021)
#define __PKU__ 1
#define __DEC32_MANT_DIG__ 7
#define __STDC_IEC_60559_COMPLEX__ 201404L
#define __BFLT16_MIN__ 1.17549435082228750796873653722224568e-38BF16
#define __ATOMIC_HLE_ACQUIRE 65536
#define __FLT128_HAS_DENORM__ 1
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT128_DIG__ 33
#define __INT32_C(c) c
#define __DEC64_EPSILON__ 1E-15DD
#define __DEC128_MIN_EXP__ (-6142)
#define __BFLT16_DECIMAL_DIG__ 4
#define __INT_FAST32_TYPE__ long int
#define __ORDER_PDP_ENDIAN__ 3412
#define __linux__ 1
#define __FLT64_IS_IEC_60559__ 1
#define __FLT16_MIN__ 6.10351562500000000000000000000000000e-5F16
#define __AVX512VPOPCNTDQ__ 1
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __DEC64X_MANT_DIG__ 34
#define __DEC128_MAX_EXP__ 6145
#define unix 1
#define __UINT64_MAX__ 0xffffffffffffffffUL
#define __FLT_IS_IEC_60559__ 1
#define __GNUC_WIDE_EXECUTION_CHARSET_NAME "UTF-32LE"
#define __FLT64X_DIG__ 18
#define __INT8_TYPE__ signed char
#define __ELF__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __FLT64X_MAX_EXP__ 16384
#define __UINT32_TYPE__ unsigned int
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffL
#define __ORDER_BIG_ENDIAN__ 4321
#define __FP_FAST_FMA 1
#define __BFLT16_HAS_QUIET_NAN__ 1
#define __FLT_RADIX__ 2
#define __INT_LEAST16_TYPE__ short int
#define __LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L
#define __UINTMAX_C(c) c ## UL
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __DEC64X_EPSILON__ 1E-33D64x
#define __SSE_MATH__ 1
#define __WINT_MIN__ 0U
#define __FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x
#define __INT64_MAX__ 0x7fffffffffffffffL
#define __USER_LABEL_PREFIX__ 
#define __STDC_IEC_60559_BFP__ 201404L
#define __DEC64X_MAX__ 9.999999999999999999999999999999999E6144D64x
#define __BMI__ 1
#define __AVX512BF16__ 1
#define __INT_WIDTH__ 32
#define __x86_64__ 1
#define __FLT16_MAX_EXP__ 16
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF
#define __STDC_EMBED_FOUND__ 1
#define __INT_FAST16_MAX__ 0x7fffffffffffffffL
#define __AVX512DQ__ 1
#define __GCC_CONSTRUCTIVE_SIZE 64
#define __FLT64_DIG__ 15
#define __UINT_FAST32_MAX__ 0xffffffffffffffffUL
#define __UINT_LEAST64_TYPE__ long unsigned int
#define __FLT16_EPSILON__ 9.76562500000000000000000000000000000e-4F16
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_MAX_10_EXP__ 38
#define __FLT64X_HAS_DENORM__ 1
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL
#define __FLT_HAS_INFINITY__ 1
#define __GNUC_EXECUTION_CHARSET_NAME "UTF-8"
#define __UINT_FAST16_TYPE__ long unsigned int
#define __DEC64_MAX__ 9.999999999999999E384DD
#define __INT_FAST32_WIDTH__ 64
#define __CHAR16_TYPE__ short unsigned int
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __DEC64X_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143D64x
#define __DBL_NORM_MAX__ ((double)1.79769313486231570814527423731704357e+308L)
#define __SIZE_WIDTH__ 64
#define __BITINT_MAXWIDTH__ 65535
#define __INT_LEAST16_MAX__ 0x7fff
#define __FLT16_NORM_MAX__ 6.55040000000000000000000000000000000e+4F16
#define __DEC64_MANT_DIG__ 16
#define __FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32
#define __GCC_DESTRUCTIVE_SIZE 64
#define __INT_LEAST64_TYPE__ long int
#define __INT16_TYPE__ short int
#define __INT_LEAST8_TYPE__ signed char
#define __FLT16_MAX__ 6.55040000000000000000000000000000000e+4F16
#define __FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128
#define __STDC_VERSION__ 202311L
#define __SIZEOF_INT__ 4
#define __DEC32_MAX_EXP__ 97
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL
#define __INT_FAST8_MAX__ 0x7f
#define __FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128
#define __INTPTR_MAX__ 0x7fffffffffffffffL
#define linux 1
#define __FLT32_DIG__ 6
#define __AVX2__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT32_MIN_10_EXP__ (-37)
#define __SSSE3__ 1
#define __FLT32X_DIG__ 15
#define __RDRND__ 1
#define __UINT16_C(c) c
#define __PTRDIFF_WIDTH__ 64
#define __INT_FAST16_WIDTH__ 64
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x
#define __FLT16_HAS_INFINITY__ 1
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __code_model_small__ 1
#define __FLT16_MANT_DIG__ 11
#define __INTPTR_TYPE__ long int
#define __UINT16_TYPE__ short unsigned int
#define __WCHAR_TYPE__ int
#define __pic__ 2
#define __UINTPTR_MAX__ 0xffffffffffffffffUL
#define __INT_FAST64_WIDTH__ 64
#define __LDBL_HAS_INFINITY__ 1
#define __INT_FAST64_MAX__ 0x7fffffffffffffffL
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __FLT_NORM_MAX__ 3.40282346638528859811704183484516925e+38F
#define __UINT_FAST64_TYPE__ long unsigned int
#define __XSAVE__ 1
#define __BFLT16_MIN_EXP__ (-125)
#define __INT_MAX__ 0x7fffffff
#define __SHA__ 1
#define __INT64_TYPE__ long int
#define __FLT_MAX_EXP__ 128
#define __DBL_MANT_DIG__ 53
#define __SIZEOF_FLOAT128__ 16
#define __BFLT16_MANT_DIG__ 8
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __DEC64_MIN__ 1E-383DD
#define __WINT_TYPE__ unsigned int
#define __UINT_LEAST32_TYPE__ unsigned int
#define __SIZEOF_SHORT__ 2
#define __FLT32_NORM_MAX__ 3.40282346638528859811704183484516925e+38F32
#define __LDBL_MIN_EXP__ (-16381)
#define __FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64
#define __DEC64X_MIN_EXP__ (-6142)
#define __WINT_WIDTH__ 32
#define __INT_LEAST8_MAX__ 0x7f
#define __INT_LEAST64_WIDTH__ 64
#define __SIZEOF_INT128__ 16
#define __LDBL_MAX_10_EXP__ 4932
#define __ATOMIC_RELAXED 0
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)
#define __INT_LEAST32_TYPE__ int
#define __FLT32_MIN_EXP__ (-125)
#define _LP64 1
#define __UINT8_C(c) c
#define __FLT64_MAX_EXP__ 1024
#define __SIZEOF_WCHAR_T__ 4
#define __UINT64_TYPE__ long unsigned int
#define __GNUC_PATCHLEVEL__ 1
#define __FLT128_NORM_MAX__ 1.18973149535723176508575932662800702e+4932F128
#define __FLT_MIN__ 1.17549435082228750796873653722224568e-38F
#define __FLT64_NORM_MAX__ 1.79769313486231570814527423731704357e+308F64
#define __FLT128_HAS_QUIET_NAN__ 1
#define __INTMAX_MAX__ 0x7fffffffffffffffL
#define __SSE3__ 1
#define __INT_FAST8_TYPE__ signed char
#define __AVX512VNNI__ 1
#define __FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32
#define __FP_FAST_FMAF32x 1
#define __FLT16_HAS_DENORM__ 1
#define __STDC_UTF_32__ 1
#define __FXSR__ 1
#define __FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __amd64__ 1
#define __INTMAX_WIDTH__ 64
#define __UINT32_C(c) c ## U
#define __SEG_FS 1
#define __FLT_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F
#define __INT8_MAX__ 0x7f
#define __LONG_WIDTH__ 64
#define __DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)
#define __PIC__ 2
#define __INT32_MAX__ 0x7fffffff
#define __UINT_FAST32_TYPE__ long unsigned int
#define __FLT32X_NORM_MAX__ 1.79769313486231570814527423731704357e+308F32x
#define __CHAR32_TYPE__ unsigned int
#define __FLT_MAX__ 3.40282346638528859811704183484516925e+38F
#define __SSE2__ 1
#define __INT32_TYPE__ int
#define __SIZEOF_DOUBLE__ 8
#define __znver4__ 1
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MANT_DIG__ 24
#define __FLT64_MIN__ 2.22507385850720138309023271733240406e-308F64
#define __INT_LEAST32_WIDTH__ 32
#define __INTMAX_TYPE__ long int
#define __CLZERO__ 1
#define __FSGSBASE__ 1
#define __XSAVEC__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __ATOMIC_CONSUME 1
#define __GNUC_MINOR__ 2
#define __UINTMAX_MAX__ 0xffffffffffffffffUL
#define __PIE__ 2
#define __FLT32X_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F32x
#define __DBL_MAX_10_EXP__ 308
#define __LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L
#define __BMI2__ 1
#define __INT16_C(c) c
#define __ATOMIC_RELEASE 3
#define __AES__ 1
#define __PTRDIFF_TYPE__ long int
#define __VERSION__ "16.2.1 20260810"
#define __FLT64_MANT_DIG__ 53
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16 1
#define __ADX__ 1
#define __LONG_MAX__ 0x7fffffffffffffffL
#define __FLT32X_MIN_10_EXP__ (-307)
#define __UINTPTR_TYPE__ long unsigned int
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD
#define __LDBL_MIN_10_EXP__ (-4931)
#define __INT8_C(c) c
#define __SIZEOF_LONG_LONG__ 8
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __FLT128_DECIMAL_DIG__ 36
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __FLT32X_MANT_DIG__ 53
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT_DECIMAL_DIG__ 9
#define __UINT_FAST16_MAX__ 0xffffffffffffffffUL
#define __LDBL_NORM_MAX__ 1.18973149535723176502126385303097021e+4932L
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __WCHAR_MAX__ 0x7fffffff
#define __SIZE_MAX__ 0xffffffffffffffffUL
#define __UINT_FAST8_TYPE__ unsigned char
#define __UINT_LEAST32_MAX__ 0xffffffffU
#define __ATOMIC_ACQ_REL 4
#define __SSE4A__ 1

//default build
#define __DBL_MIN_EXP__ (-1021)
#define __LDBL_MANT_DIG__ 64
#define __UINT_LEAST16_MAX__ 0xffff
#define __FLT16_HAS_QUIET_NAN__ 1
#define __ATOMIC_ACQUIRE 2
#define __WCHAR_MAX__ 0x7fffffff
#define __FLT128_MAX_10_EXP__ 4932
#define __FLT_MIN__ 1.17549435082228750796873653722224568e-38F
#define __GCC_IEC_559_COMPLEX 2
#define __UINT_LEAST8_TYPE__ unsigned char
#define __SIZEOF_FLOAT80__ 16
#define __BFLT16_DENORM_MIN__ 9.18354961579912115600575419704879436e-41BF16
#define __INTMAX_C(c) c ## L
#define __CHAR_BIT__ 8
#define __UINT8_MAX__ 0xff
#define __SCHAR_WIDTH__ 8
#define __WINT_MAX__ 0xffffffffU
#define __FLT32_MIN_EXP__ (-125)
#define __BFLT16_NORM_MAX__ 3.38953138925153547590470800371487867e+38BF16
#define __BFLT16_MIN_10_EXP__ (-37)
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_IEC_559 2
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT_EVAL_METHOD__ 0
#define __FLT64_DECIMAL_DIG__ 17
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __UINT_FAST64_MAX__ 0xffffffffffffffffUL
#define __SIG_ATOMIC_TYPE__ int
#define __DBL_MIN_10_EXP__ (-307)
#define __FINITE_MATH_ONLY__ 0
#define __FLT32X_MAX_EXP__ 1024
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __FLT32_HAS_DENORM__ 1
#define __UINT_FAST8_MAX__ 0xff
#define __FLT32_MAX_10_EXP__ 38
#define __DEC64_MAX_EXP__ 385
#define __INT8_C(c) c
#define __INT_LEAST8_WIDTH__ 8
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffUL
#define __SHRT_MAX__ 0x7fff
#define __LDBL_MAX__ 1.18973149535723176502126385303097021e+4932L
#define __FLT64X_MAX_10_EXP__ 4932
#define __BFLT16_MAX_10_EXP__ 38
#define __BFLT16_MAX_EXP__ 128
#define __LDBL_IS_IEC_60559__ 1
#define __FLT64X_HAS_QUIET_NAN__ 1
#define __UINT_LEAST8_MAX__ 0xff
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __FLT128_DENORM_MIN__ 6.47517511943802511092443895822764655e-4966F128
#define __UINTMAX_TYPE__ long unsigned int
#define __BFLT16_DECIMAL_DIG__ 4
#define __linux 1
#define __DEC32_EPSILON__ 1E-6DF
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __UINT32_MAX__ 0xffffffffU
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544176568792868221372e-324L)
#define __FLT128_MIN_EXP__ (-16381)
#define __DEC64X_MAX_EXP__ 6145
#define __WINT_MIN__ 0U
#define __FLT128_MIN_10_EXP__ (-4931)
#define __FLT32X_IS_IEC_60559__ 1
#define __INT_LEAST16_WIDTH__ 16
#define __SCHAR_MAX__ 0x7f
#define __FLT128_MANT_DIG__ 113
#define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)
#define __INT64_C(c) c ## L
#define __SSP_STRONG__ 3
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __ATOMIC_SEQ_CST 5
#define __unix 1
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffL
#define __FLT32X_MANT_DIG__ 53
#define __FLT64X_EPSILON__ 1.08420217248550443400745280086994171e-19F64x
#define __STDC_HOSTED__ 1
#define __DEC64_MIN_EXP__ (-382)
#define __DBL_DIG__ 15
#define __STDC_EMBED_EMPTY__ 2
#define __FLT_EPSILON__ 1.19209289550781250000000000000000000e-7F
#define __SHRT_WIDTH__ 16
#define __FLT32_IS_IEC_60559__ 1
#define __LDBL_MIN__ 3.36210314311209350626267781732175260e-4932L
#define __STDC_UTF_16__ 1
#define __DBL_IS_IEC_60559__ 1
#define __DEC32_MAX__ 9.999999E96DF
#define __CHAR8_TYPE__ unsigned char
#define __FLT64X_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951F64x
#define __FLT32X_HAS_INFINITY__ 1
#define __unix__ 1
#define __INT_WIDTH__ 32
#define __STDC_IEC_559__ 1
#define __STDC_ISO_10646__ 201706L
#define __GCC_ATOMIC_CHAR8_T_LOCK_FREE 2
#define __DECIMAL_DIG__ 21
#define __STDC_IEC_559_COMPLEX__ 1
#define __gnu_linux__ 1
#define __FLT64X_MIN_10_EXP__ (-4931)
#define __LDBL_HAS_QUIET_NAN__ 1
#define __FLT16_MIN_EXP__ (-13)
#define __FLT64_MANT_DIG__ 53
#define __FLT64X_MANT_DIG__ 64
#define __BFLT16_DIG__ 2
#define __GNUC__ 16
#define __pie__ 2
#define __MMX__ 1
#define __FLT_HAS_DENORM__ 1
#define __SIZEOF_LONG_DOUBLE__ 16
#define __LDBL_DIG__ 18
#define __BIGGEST_ALIGNMENT__ 16
#define __FLT64_MAX_10_EXP__ 308
#define __BFLT16_IS_IEC_60559__ 0
#define __FLT16_MAX_10_EXP__ 4
#define __DBL_MAX__ ((double)1.79769313486231570814527423731704357e+308L)
#define __INT_FAST32_MAX__ 0x7fffffffffffffffL
#define __DBL_HAS_INFINITY__ 1
#define __INT64_MAX__ 0x7fffffffffffffffL
#define __SIZEOF_FLOAT__ 4
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __DEC32_MIN_EXP__ (-94)
#define __INTPTR_WIDTH__ 64
#define __UINT_LEAST32_MAX__ 0xffffffffU
#define __FLT32X_HAS_DENORM__ 1
#define __INT_FAST16_TYPE__ long int
#define __MMX_WITH_SSE__ 1
#define __LDBL_HAS_DENORM__ 1
#define __SEG_GS 1
#define __BFLT16_EPSILON__ 7.81250000000000000000000000000000000e-3BF16
#define __FLT128_HAS_INFINITY__ 1
#define __DEC32_MIN__ 1E-95DF
#define __DBL_MAX_EXP__ 1024
#define __WCHAR_WIDTH__ 32
#define __FLT32_MAX__ 3.40282346638528859811704183484516925e+38F32
#define __DEC128_EPSILON__ 1E-33DL
#define __FLT16_DECIMAL_DIG__ 5
#define __SSE2_MATH__ 1
#define __ATOMIC_HLE_RELEASE 131072
#define __PTRDIFF_MAX__ 0x7fffffffffffffffL
#define __amd64 1
#define __DEC64X_MAX__ 9.999999999999999999999999999999999E6144D64x
#define __ATOMIC_HLE_ACQUIRE 65536
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __SIZEOF_SIZE_T__ 8
#define __BFLT16_HAS_INFINITY__ 1
#define __FLT64X_MIN_EXP__ (-16381)
#define __SIZEOF_WINT_T__ 4
#define __LONG_LONG_WIDTH__ 64
#define __FLT32_MAX_EXP__ 128
#define __GXX_ABI_VERSION 1021
#define __FLT_MIN_EXP__ (-125)
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __INT16_MAX__ 0x7fff
#define __x86_64 1
#define __INT_FAST64_TYPE__ long int
#define __BFLT16_MAX__ 3.38953138925153547590470800371487867e+38BF16
#define __BFLT16_HAS_DENORM__ 1
#define __FLT64_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F64
#define __FLT16_DENORM_MIN__ 5.96046447753906250000000000000000000e-8F16
#define __FLT128_EPSILON__ 1.92592994438723585305597794258492732e-34F128
#define __FLT64X_NORM_MAX__ 1.18973149535723176502126385303097021e+4932F64x
#define __SIZEOF_POINTER__ 8
#define __SIZE_TYPE__ long unsigned int
#define __LP64__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __FLT32X_EPSILON__ 2.22044604925031308084726333618164062e-16F32x
#define __LDBL_MAX_EXP__ 16384
#define __DECIMAL_BID_FORMAT__ 1
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT16_MIN_10_EXP__ (-4)
#define __FLT64X_DECIMAL_DIG__ 21
#define __DEC128_MIN__ 1E-6143DL
#define __REGISTER_PREFIX__ 
#define __UINT16_MAX__ 0xffff
#define __DBL_HAS_DENORM__ 1
#define __FLT32_MIN__ 1.17549435082228750796873653722224568e-38F32
#define __UINT8_TYPE__ unsigned char
#define __FLT_DIG__ 6
#define __NO_INLINE__ 1
#define __DEC_EVAL_METHOD__ 2
#define __FLT_MANT_DIG__ 24
#define __LDBL_DECIMAL_DIG__ 21
#define __VERSION__ "16.2.1 20260810"
#define __UINT64_C(c) c ## UL
#define __DEC64X_MIN__ 1E-6143D64x
#define _STDC_PREDEF_H 1
#define __INT_LEAST32_MAX__ 0x7fffffff
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __FLT128_MAX_EXP__ 16384
#define __FLT32_MANT_DIG__ 24
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __FLT32X_MIN_EXP__ (-1021)
#define __STDC_IEC_60559_COMPLEX__ 201404L
#define __BFLT16_MIN__ 1.17549435082228750796873653722224568e-38BF16
#define __FLT128_HAS_DENORM__ 1
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT128_DIG__ 33
#define __INT32_C(c) c
#define __DEC64_EPSILON__ 1E-15DD
#define __ORDER_PDP_ENDIAN__ 3412
#define __DEC128_MIN_EXP__ (-6142)
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL
#define __INT_FAST32_TYPE__ long int
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __DEC64X_MANT_DIG__ 34
#define __DEC128_MAX_EXP__ 6145
#define unix 1
#define __UINT64_MAX__ 0xffffffffffffffffUL
#define __FLT_IS_IEC_60559__ 1
#define __GNUC_WIDE_EXECUTION_CHARSET_NAME "UTF-32LE"
#define __FLT64X_DIG__ 18
#define __INT8_TYPE__ signed char
#define __ELF__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __UINT32_TYPE__ unsigned int
#define __BFLT16_HAS_QUIET_NAN__ 1
#define __FLT_RADIX__ 2
#define __INT_LEAST16_TYPE__ short int
#define __LDBL_EPSILON__ 1.08420217248550443400745280086994171e-19L
#define __UINTMAX_C(c) c ## UL
#define __DEC64X_EPSILON__ 1E-33D64x
#define __FLT16_DIG__ 3
#define __SSE_MATH__ 1
#define __k8 1
#define __FLT32X_MIN__ 2.22507385850720138309023271733240406e-308F32x
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __USER_LABEL_PREFIX__ 
#define __STDC_IEC_60559_BFP__ 201404L
#define __SIZEOF_PTRDIFF_T__ 8
#define __FLT64X_HAS_INFINITY__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __SIZEOF_LONG__ 8
#define __FLT64_IS_IEC_60559__ 1
#define __x86_64__ 1
#define __FLT16_IS_IEC_60559__ 1
#define __FLT16_MAX_EXP__ 16
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF
#define __STDC_EMBED_FOUND__ 1
#define __INT_FAST16_MAX__ 0x7fffffffffffffffL
#define __GCC_CONSTRUCTIVE_SIZE 64
#define __FLT64_DIG__ 15
#define __UINT_FAST32_MAX__ 0xffffffffffffffffUL
#define __UINT_LEAST64_TYPE__ long unsigned int
#define __FLT16_EPSILON__ 9.76562500000000000000000000000000000e-4F16
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_MAX_10_EXP__ 38
#define __LONG_MAX__ 0x7fffffffffffffffL
#define __FLT64X_HAS_DENORM__ 1
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL
#define __FLT_HAS_INFINITY__ 1
#define __GNUC_EXECUTION_CHARSET_NAME "UTF-8"
#define __UINT_FAST16_TYPE__ long unsigned int
#define __DEC64_MAX__ 9.999999999999999E384DD
#define __STDC_EMBED_NOT_FOUND__ 0
#define __INT_FAST32_WIDTH__ 64
#define __CHAR16_TYPE__ short unsigned int
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __DEC64X_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143D64x
#define __SIZE_WIDTH__ 64
#define __SEG_FS 1
#define __BITINT_MAXWIDTH__ 65535
#define __INT_LEAST16_MAX__ 0x7fff
#define __FLT16_NORM_MAX__ 6.55040000000000000000000000000000000e+4F16
#define __DEC64_MANT_DIG__ 16
#define __FLT32_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F32
#define __SIG_ATOMIC_WIDTH__ 32
#define __INT_LEAST64_TYPE__ long int
#define __INT16_TYPE__ short int
#define __INT_LEAST8_TYPE__ signed char
#define __FLT16_MAX__ 6.55040000000000000000000000000000000e+4F16
#define __FLT128_MIN__ 3.36210314311209350626267781732175260e-4932F128
#define __STDC_VERSION__ 202311L
#define __SIZEOF_INT__ 4
#define __DEC32_MAX_EXP__ 97
#define __INT_FAST8_MAX__ 0x7f
#define __FLT128_MAX__ 1.18973149535723176508575932662800702e+4932F128
#define __INTPTR_MAX__ 0x7fffffffffffffffL
#define linux 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32X_DIG__ 15
#define __UINT16_C(c) c
#define __PTRDIFF_WIDTH__ 64
#define __INT_FAST16_WIDTH__ 64
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64X_MAX__ 1.18973149535723176502126385303097021e+4932F64x
#define __FLT16_HAS_INFINITY__ 1
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __code_model_small__ 1
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __DEC32_MANT_DIG__ 7
#define __FLT16_MANT_DIG__ 11
#define __k8__ 1
#define __INTPTR_TYPE__ long int
#define __UINT16_TYPE__ short unsigned int
#define __WCHAR_TYPE__ int
#define __pic__ 2
#define __UINTPTR_MAX__ 0xffffffffffffffffUL
#define __INT_FAST64_WIDTH__ 64
#define __LDBL_HAS_INFINITY__ 1
#define __INT_FAST64_MAX__ 0x7fffffffffffffffL
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __FLT_NORM_MAX__ 3.40282346638528859811704183484516925e+38F
#define __FLT64X_MAX_EXP__ 16384
#define __UINT_FAST64_TYPE__ long unsigned int
#define __BFLT16_MIN_EXP__ (-125)
#define __INT_MAX__ 0x7fffffff
#define __linux__ 1
#define __INT64_TYPE__ long int
#define __FLT_MAX_EXP__ 128
#define __ORDER_BIG_ENDIAN__ 4321
#define __DBL_MANT_DIG__ 53
#define __SIZEOF_FLOAT128__ 16
#define __BFLT16_MANT_DIG__ 8
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __DEC64_MIN__ 1E-383DD
#define __WINT_TYPE__ unsigned int
#define __UINT_LEAST32_TYPE__ unsigned int
#define __SIZEOF_SHORT__ 2
#define __FLT32_NORM_MAX__ 3.40282346638528859811704183484516925e+38F32
#define __SSE__ 1
#define __LDBL_MIN_EXP__ (-16381)
#define __FLT64_MAX__ 1.79769313486231570814527423731704357e+308F64
#define __DEC64X_MIN_EXP__ (-6142)
#define __amd64__ 1
#define __WINT_WIDTH__ 32
#define __INT_LEAST8_MAX__ 0x7f
#define __INT_LEAST64_WIDTH__ 64
#define __FLT32X_MAX_10_EXP__ 308
#define __SIZEOF_INT128__ 16
#define __FLT16_MIN__ 6.10351562500000000000000000000000000e-5F16
#define __FLT64X_IS_IEC_60559__ 1
#define __LDBL_MAX_10_EXP__ 4932
#define __ATOMIC_RELAXED 0
#define __DBL_EPSILON__ ((double)2.22044604925031308084726333618164062e-16L)
#define __INT_LEAST32_TYPE__ int
#define _LP64 1
#define __UINT8_C(c) c
#define __FLT64_MAX_EXP__ 1024
#define __SIZEOF_WCHAR_T__ 4
#define __UINT64_TYPE__ long unsigned int
#define __GNUC_PATCHLEVEL__ 1
#define __FLT128_NORM_MAX__ 1.18973149535723176508575932662800702e+4932F128
#define __FLT64_NORM_MAX__ 1.79769313486231570814527423731704357e+308F64
#define __FLT128_HAS_QUIET_NAN__ 1
#define __INTMAX_MAX__ 0x7fffffffffffffffL
#define __INT_FAST8_TYPE__ signed char
#define __FLT64X_MIN__ 3.36210314311209350626267781732175260e-4932F64x
#define __FLT64_EPSILON__ 2.22044604925031308084726333618164062e-16F64
#define __GNUC_STDC_INLINE__ 1
#define __FLT64_HAS_DENORM__ 1
#define __FLT32_EPSILON__ 1.19209289550781250000000000000000000e-7F32
#define __FLT16_HAS_DENORM__ 1
#define __DBL_DECIMAL_DIG__ 17
#define __STDC_UTF_32__ 1
#define __INT_FAST8_WIDTH__ 8
#define __FXSR__ 1
#define __FLT32X_MAX__ 1.79769313486231570814527423731704357e+308F32x
#define __DBL_NORM_MAX__ ((double)1.79769313486231570814527423731704357e+308L)
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __GCC_DESTRUCTIVE_SIZE 64
#define __INTMAX_WIDTH__ 64
#define __FLT32_DIG__ 6
#define __UINT32_C(c) c ## U
#define __FLT_DENORM_MIN__ 1.40129846432481707092372958328991613e-45F
#define __FLT128_IS_IEC_60559__ 1
#define __INT8_MAX__ 0x7f
#define __LONG_WIDTH__ 64
#define __DBL_MIN__ ((double)2.22507385850720138309023271733240406e-308L)
#define __PIC__ 2
#define __INT32_MAX__ 0x7fffffff
#define __UINT_FAST32_TYPE__ long unsigned int
#define __FLT32X_NORM_MAX__ 1.79769313486231570814527423731704357e+308F32x
#define __CHAR32_TYPE__ unsigned int
#define __FLT_MAX__ 3.40282346638528859811704183484516925e+38F
#define __SSE2__ 1
#define __INT32_TYPE__ int
#define __SIZEOF_DOUBLE__ 8
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT64_MIN__ 2.22507385850720138309023271733240406e-308F64
#define __INT_LEAST32_WIDTH__ 32
#define __INTMAX_TYPE__ long int
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __ATOMIC_CONSUME 1
#define __GNUC_MINOR__ 2
#define __UINTMAX_MAX__ 0xffffffffffffffffUL
#define __PIE__ 2
#define __FLT32X_DENORM_MIN__ 4.94065645841246544176568792868221372e-324F32x
#define __DBL_MAX_10_EXP__ 308
#define __LDBL_DENORM_MIN__ 3.64519953188247460252840593361941982e-4951L
#define __INT16_C(c) c
#define __ATOMIC_RELEASE 3
#define __STDC__ 1
#define __PTRDIFF_TYPE__ long int
#define __FLT32X_MIN_10_EXP__ (-307)
#define __UINTPTR_TYPE__ long unsigned int
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD
#define __DEC128_MANT_DIG__ 34
#define __LDBL_MIN_10_EXP__ (-4931)
#define __SIZEOF_LONG_LONG__ 8
#define __FLT128_DECIMAL_DIG__ 36
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT_DECIMAL_DIG__ 9
#define __UINT_FAST16_MAX__ 0xffffffffffffffffUL
#define __LDBL_NORM_MAX__ 1.18973149535723176502126385303097021e+4932L
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __SIZE_MAX__ 0xffffffffffffffffUL
#define __UINT_FAST8_TYPE__ unsigned char
#define __ATOMIC_ACQ_REL 4
/* !!! */

#endif