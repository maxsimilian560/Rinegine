#pragma once

/*GCC RAW*/
#if defined(_LP64) or defined(__LP64__)
#define TYPE64 long
#elif defined(_LLP64) or defined(__LLP64__) or defined(_WIN64)
#define TYPE64 long long
#endif
//*MODES
// #define __ATOMIC_RELAXED 0 Самый быстрый режим из всех возможных
// #define __ATOMIC_CONSUME 1 Используется только при чтении. Облегченная версия ACQUIRE
// #define __ATOMIC_ACQUIRE 2 Используется только при чтении (load/read)
// #define __ATOMIC_RELEASE 3 Используется только при записи (store/write)
// #define __ATOMIC_ACQ_REL 4 Используется для операций типа RMW (Read-Modify-Write) — когда одновременно читается, и пишется (например, __atomic_fetch_add или compare_exchange)
// #define __ATOMIC_SEQ_CST 5 Это режим по умолчанию, если используется std::atomic и параметры не указываются вручную.
/*
*Пример
int data = 0;
bool ready = false;

void thread_1() {
  data = 42; // Обычная запись

  /*Публикуем флаг готовности.
  /*RELEASE гарантирует, что data = 42 выполнится ДО того, как ready станет true!
  __atomic_store_n(&ready, true, __ATOMIC_RELEASE);
}
*/
//! MODES
#if __BITINT_MAXWIDTH__ >= 128
typedef _BitInt(128) int128;
typedef unsigned _BitInt(128) uint128;
#if __BITINT_MAXWIDTH__ >= 256
typedef _BitInt(256) int256;
typedef unsigned _BitInt(256) uint256;

#else
struct int256 {
  _BitInt(128) low;
  _BitInt(128) high;
};
struct uint256 {
  unsigned _BitInt(128) low;
  unsigned _BitInt(128) high;
};
#endif
#else
struct int128 {
  _BitInt(64) low;
  _BitInt(64) high;
};
struct int256 {
  int128 low;
  int128 high;
};
struct uint128 {
  unsigned _BitInt(64) low;
  unsigned _BitInt(64) high;
};
struct uint256 {
  unsigned _BitInt(64)  low;
  unsigned _BitInt(64)  med1;
  unsigned _BitInt(64)  med2;
  unsigned _BitInt(64)  high;
};
#endif


#ifdef __BOOL_WIDTH__

#else

#endif
#ifdef __BYTE_ORDER__

#else

#endif
#ifdef __CHAR16_TYPE__

#else

#endif
#ifdef __CHAR32_TYPE__

#else

#endif
#ifdef __CHAR_BIT__

#else

#endif
#ifdef __CLANG_ATOMIC_BOOL_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_CHAR16_T_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_CHAR32_T_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_CHAR_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_INT_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_LLONG_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_LONG_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_POINTER_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_SHORT_LOCK_FREE

#else

#endif
#ifdef __CLANG_ATOMIC_WCHAR_T_LOCK_FREE

#else

#endif
#ifdef __CONSTANT_CFSTRINGS__

#else

#endif
#ifdef __DBL_DECIMAL_DIG__

#else

#endif
#ifdef __DBL_DENORM_MIN__

#else

#endif
#ifdef __DBL_DIG__

#else

#endif
#ifdef __DBL_EPSILON__

#else

#endif
#ifdef __DBL_HAS_DENORM__

#else

#endif
#ifdef __DBL_HAS_INFINITY__

#else

#endif
#ifdef __DBL_HAS_QUIET_NAN__

#else

#endif
#ifdef __DBL_MANT_DIG__

#else

#endif
#ifdef __DBL_MAX_10_EXP__

#else

#endif
#ifdef __DBL_MAX_EXP__

#else

#endif
#ifdef __DBL_MAX__

#else

#endif
#ifdef __DBL_MIN_10_EXP__

#else

#endif
#ifdef __DBL_MIN_EXP__

#else

#endif
#ifdef __DBL_MIN__

#else

#endif
#ifdef __DBL_NORM_MAX__

#else

#endif
#ifdef __DECIMAL_DIG__

#else

#endif
#ifdef __ELF__

#else

#endif
#ifdef __FINITE_MATH_ONLY__

#else

#endif
#ifdef __FLOAT128__

#else

#endif
#ifdef __FLT16_DECIMAL_DIG__

#else

#endif
#ifdef __FLT16_DENORM_MIN__

#else

#endif
#ifdef __FLT16_DIG__

#else

#endif
#ifdef __FLT16_EPSILON__

#else

#endif
#ifdef __FLT16_HAS_DENORM__

#else

#endif
#ifdef __FLT16_HAS_INFINITY__

#else

#endif
#ifdef __FLT16_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT16_MANT_DIG__

#else

#endif
#ifdef __FLT16_MAX_10_EXP__

#else

#endif
#ifdef __FLT16_MAX_EXP__

#else

#endif
#ifdef __FLT16_MAX__

#else

#endif
#ifdef __FLT16_MIN_10_EXP__

#else

#endif
#ifdef __FLT16_MIN_EXP__

#else

#endif
#ifdef __FLT16_MIN__

#else

#endif
#ifdef __FLT16_NORM_MAX__

#else

#endif
#ifdef __FLT_DECIMAL_DIG__

#else

#endif
#ifdef __FLT_DENORM_MIN__

#else

#endif
#ifdef __FLT_DIG__

#else

#endif
#ifdef __FLT_EPSILON__

#else

#endif
#ifdef __FLT_HAS_DENORM__

#else

#endif
#ifdef __FLT_HAS_INFINITY__

#else

#endif
#ifdef __FLT_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT_MANT_DIG__

#else

#endif
#ifdef __FLT_MAX_10_EXP__

#else

#endif
#ifdef __FLT_MAX_EXP__

#else

#endif
#ifdef __FLT_MAX__

#else

#endif
#ifdef __FLT_MIN_10_EXP__

#else

#endif
#ifdef __FLT_MIN_EXP__

#else

#endif
#ifdef __FLT_MIN__

#else

#endif
#ifdef __FLT_NORM_MAX__

#else

#endif
#ifdef __FLT_RADIX__

#else

#endif
#ifdef __FPCLASS_NEGINF

#else

#endif
#ifdef __FPCLASS_NEGNORMAL

#else

#endif
#ifdef __FPCLASS_NEGSUBNORMAL

#else

#endif
#ifdef __FPCLASS_NEGZERO

#else

#endif
#ifdef __FPCLASS_POSINF

#else

#endif
#ifdef __FPCLASS_POSNORMAL

#else

#endif
#ifdef __FPCLASS_POSSUBNORMAL

#else

#endif
#ifdef __FPCLASS_POSZERO

#else

#endif
#ifdef __FPCLASS_QNAN

#else

#endif
#ifdef __FPCLASS_SNAN

#else

#endif
#ifdef __FXSR__

#else

#endif
#ifdef __GCC_ASM_FLAG_OUTPUTS__

#else

#endif
#ifdef __GCC_ATOMIC_BOOL_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_CHAR16_T_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_CHAR32_T_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_CHAR_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_INT_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_LLONG_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_LONG_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_POINTER_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_SHORT_LOCK_FREE

#else

#endif
#ifdef __GCC_ATOMIC_TEST_AND_SET_TRUEVAL

#else

#endif
#ifdef __GCC_ATOMIC_WCHAR_T_LOCK_FREE

#else

#endif
#ifdef __GCC_CONSTRUCTIVE_SIZE

#else

#endif
#ifdef __GCC_DESTRUCTIVE_SIZE

#else

#endif
#ifdef __GCC_HAVE_DWARF2_CFI_ASM

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

#else

#endif
#ifdef __GNUC_MINOR__

#else

#endif
#ifdef __GNUC_PATCHLEVEL__

#else

#endif
#ifdef __GNUC_STDC_INLINE__

#else

#endif
#ifdef __GNUC__

#else

#endif
#ifdef __GXX_ABI_VERSION

#else

#endif
#ifdef __INT16_C

#else

#endif
#ifdef __INT16_C_SUFFIX__

#else

#endif
#ifdef __INT16_FMTd__

#else

#endif
#ifdef __INT16_FMTi__

#else

#endif
#ifdef __INT16_MAX__

#else

#endif
#ifdef __INT16_TYPE__

#else

#endif
#ifdef __INT32_C

#else

#endif
#ifdef __INT32_C_SUFFIX__

#else

#endif
#ifdef __INT32_FMTd__

#else

#endif
#ifdef __INT32_FMTi__

#else

#endif
#ifdef __INT32_MAX__

#else

#endif
#ifdef __INT32_TYPE__

#else

#endif
#ifdef __INT64_C

#else

#endif
#ifdef __INT64_C_SUFFIX__

#else

#endif
#ifdef __INT64_FMTd__

#else

#endif
#ifdef __INT64_FMTi__

#else

#endif
#ifdef __INT64_MAX__

#else

#endif
#ifdef __INT64_TYPE__

#else

#endif
#ifdef __INT8_C

#else

#endif
#ifdef __INT8_C_SUFFIX__

#else

#endif
#ifdef __INT8_FMTd__

#else

#endif
#ifdef __INT8_FMTi__

#else

#endif
#ifdef __INT8_MAX__

#else

#endif
#ifdef __INT8_TYPE__

#else

#endif
#ifdef __INTMAX_C

#else

#endif
#ifdef __INTMAX_C_SUFFIX__

#else

#endif
#ifdef __INTMAX_FMTd__

#else

#endif
#ifdef __INTMAX_FMTi__

#else

#endif
#ifdef __INTMAX_MAX__

#else

#endif
#ifdef __INTMAX_TYPE__

#else

#endif
#ifdef __INTMAX_WIDTH__

#else

#endif
#ifdef __INTPTR_FMTd__

#else

#endif
#ifdef __INTPTR_FMTi__

#else

#endif
#ifdef __INTPTR_MAX__

#else

#endif
#ifdef __INTPTR_TYPE__

#else

#endif
#ifdef __INTPTR_WIDTH__

#else

#endif
#ifdef __INT_FAST16_FMTd__

#else

#endif
#ifdef __INT_FAST16_FMTi__

#else

#endif
#ifdef __INT_FAST16_MAX__

#else

#endif
#ifdef __INT_FAST16_TYPE__

#else

#endif
#ifdef __INT_FAST16_WIDTH__

#else

#endif
#ifdef __INT_FAST32_FMTd__

#else

#endif
#ifdef __INT_FAST32_FMTi__

#else

#endif
#ifdef __INT_FAST32_MAX__

#else

#endif
#ifdef __INT_FAST32_TYPE__

#else

#endif
#ifdef __INT_FAST32_WIDTH__

#else

#endif
#ifdef __INT_FAST64_FMTd__

#else

#endif
#ifdef __INT_FAST64_FMTi__

#else

#endif
#ifdef __INT_FAST64_MAX__

#else

#endif
#ifdef __INT_FAST64_TYPE__

#else

#endif
#ifdef __INT_FAST64_WIDTH__

#else

#endif
#ifdef __INT_FAST8_FMTd__

#else

#endif
#ifdef __INT_FAST8_FMTi__

#else

#endif
#ifdef __INT_FAST8_MAX__

#else

#endif
#ifdef __INT_FAST8_TYPE__

#else

#endif
#ifdef __INT_FAST8_WIDTH__

#else

#endif
#ifdef __INT_LEAST16_FMTd__

#else

#endif
#ifdef __INT_LEAST16_FMTi__

#else

#endif
#ifdef __INT_LEAST16_MAX__

#else

#endif
#ifdef __INT_LEAST16_TYPE__

#else

#endif
#ifdef __INT_LEAST16_WIDTH__

#else

#endif
#ifdef __INT_LEAST32_FMTd__

#else

#endif
#ifdef __INT_LEAST32_FMTi__

#else

#endif
#ifdef __INT_LEAST32_MAX__

#else

#endif
#ifdef __INT_LEAST32_TYPE__

#else

#endif
#ifdef __INT_LEAST32_WIDTH__

#else

#endif
#ifdef __INT_LEAST64_FMTd__

#else

#endif
#ifdef __INT_LEAST64_FMTi__

#else

#endif
#ifdef __INT_LEAST64_MAX__

#else

#endif
#ifdef __INT_LEAST64_TYPE__

#else

#endif
#ifdef __INT_LEAST64_WIDTH__

#else

#endif
#ifdef __INT_LEAST8_FMTd__

#else

#endif
#ifdef __INT_LEAST8_FMTi__

#else

#endif
#ifdef __INT_LEAST8_MAX__

#else

#endif
#ifdef __INT_LEAST8_TYPE__

#else

#endif
#ifdef __INT_LEAST8_WIDTH__

#else

#endif
#ifdef __INT_MAX__

#else

#endif
#ifdef __INT_WIDTH__

#else

#endif
#ifdef __LDBL_DECIMAL_DIG__

#else

#endif
#ifdef __LDBL_DENORM_MIN__

#else

#endif
#ifdef __LDBL_DIG__

#else

#endif
#ifdef __LDBL_EPSILON__

#else

#endif
#ifdef __LDBL_HAS_DENORM__

#else

#endif
#ifdef __LDBL_HAS_INFINITY__

#else

#endif
#ifdef __LDBL_HAS_QUIET_NAN__

#else

#endif
#ifdef __LDBL_MANT_DIG__

#else

#endif
#ifdef __LDBL_MAX_10_EXP__

#else

#endif
#ifdef __LDBL_MAX_EXP__

#else

#endif
#ifdef __LDBL_MAX__

#else

#endif
#ifdef __LDBL_MIN_10_EXP__

#else

#endif
#ifdef __LDBL_MIN_EXP__

#else

#endif
#ifdef __LDBL_MIN__

#else

#endif
#ifdef __LDBL_NORM_MAX__

#else

#endif
#ifdef __LITTLE_ENDIAN__

#else

#endif
#ifdef __LLONG_WIDTH__

#else

#endif
#ifdef __LONG_LONG_MAX__

#else

#endif
#ifdef __LONG_MAX__

#else

#endif
#ifdef __LONG_WIDTH__

#else

#endif
#ifdef __LP64__

#else

#endif
#ifdef __MEMORY_SCOPE_CLUSTR

#else

#endif
#ifdef __MEMORY_SCOPE_DEVICE

#else

#endif
#ifdef __MEMORY_SCOPE_SINGLE

#else

#endif
#ifdef __MEMORY_SCOPE_SYSTEM

#else

#endif
#ifdef __MEMORY_SCOPE_WRKGRP

#else

#endif
#ifdef __MEMORY_SCOPE_WVFRNT

#else

#endif
#ifdef __MMX__

#else

#endif
#ifdef __NO_INLINE__

#else

#endif
#ifdef __NO_MATH_INLINES

#else

#endif
#ifdef __OBJC_BOOL_IS_BOOL

#else

#endif
#ifdef __OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES

#else

#endif
#ifdef __OPENCL_MEMORY_SCOPE_DEVICE

#else

#endif
#ifdef __OPENCL_MEMORY_SCOPE_SUB_GROUP

#else

#endif
#ifdef __OPENCL_MEMORY_SCOPE_WORK_GROUP

#else

#endif
#ifdef __OPENCL_MEMORY_SCOPE_WORK_ITEM

#else

#endif
#ifdef __ORDER_BIG_ENDIAN__

#else

#endif
#ifdef __ORDER_LITTLE_ENDIAN__

#else

#endif
#ifdef __ORDER_PDP_ENDIAN__

#else

#endif
#ifdef __PIC__

#else

#endif
#ifdef __PIE__

#else

#endif
#ifdef __POINTER_WIDTH__

#else

#endif
#ifdef __PRAGMA_REDEFINE_EXTNAME

#else

#endif
#ifdef __PTRDIFF_FMTd__

#else

#endif
#ifdef __PTRDIFF_FMTi__

#else

#endif
#ifdef __PTRDIFF_MAX__

#else

#endif
#ifdef __PTRDIFF_TYPE__

#else

#endif
#ifdef __PTRDIFF_WIDTH__

#else

#endif
#ifdef __REGISTER_PREFIX__

#else

#endif
#ifdef __SCHAR_MAX__

#else

#endif
#ifdef __SEG_FS

#else

#endif
#ifdef __SEG_GS

#else

#endif
#ifdef __SHRT_MAX__

#else

#endif
#ifdef __SHRT_WIDTH__

#else

#endif
#ifdef __SIG_ATOMIC_MAX__

#else

#endif
#ifdef __SIG_ATOMIC_WIDTH__

#else

#endif
#ifdef __SIZEOF_DOUBLE__

#else

#endif
#ifdef __SIZEOF_FLOAT128__

#else

#endif
#ifdef __SIZEOF_FLOAT__

#else

#endif
#ifdef __SIZEOF_INT128__

#else

#endif
#ifdef __SIZEOF_INT__

#else

#endif
#ifdef __SIZEOF_LONG_DOUBLE__

#else

#endif
#ifdef __SIZEOF_LONG_LONG__

#else

#endif
#ifdef __SIZEOF_LONG__

#else

#endif
#ifdef __SIZEOF_POINTER__

#else

#endif
#ifdef __SIZEOF_PTRDIFF_T__

#else

#endif
#ifdef __SIZEOF_SHORT__

#else

#endif
#ifdef __SIZEOF_SIZE_T__

#else

#endif
#ifdef __SIZEOF_WCHAR_T__

#else

#endif
#ifdef __SIZEOF_WINT_T__

#else

#endif
#ifdef __SIZE_FMTX__

#else

#endif
#ifdef __SIZE_FMTo__

#else

#endif
#ifdef __SIZE_FMTu__

#else

#endif
#ifdef __SIZE_FMTx__

#else

#endif
#ifdef __SIZE_MAX__

#else

#endif
#ifdef __SIZE_TYPE__

#else

#endif
#ifdef __SIZE_WIDTH__

#else

#endif
#ifdef __SSE2_MATH__

#else

#endif
#ifdef __SSE2__

#else

#endif
#ifdef __SSE_MATH__

#else

#endif
#ifdef __SSE__

#else

#endif
#ifdef __SSP_STRONG__

#else

#endif
#ifdef __STDC_EMBED_EMPTY__

#else

#endif
#ifdef __STDC_EMBED_FOUND__

#else

#endif
#ifdef __STDC_EMBED_NOT_FOUND__

#else

#endif
#ifdef __STDC_HOSTED__

#else

#endif
#ifdef __STDC_UTF_16__

#else

#endif
#ifdef __STDC_UTF_32__

#else

#endif
#ifdef __STDC_VERSION__

#else

#endif
#ifdef __STDC__

#else

#endif
#ifdef __UINT16_C

#else

#endif
#ifdef __UINT16_C_SUFFIX__

#else

#endif
#ifdef __UINT16_FMTX__

#else

#endif
#ifdef __UINT16_FMTo__

#else

#endif
#ifdef __UINT16_FMTu__

#else

#endif
#ifdef __UINT16_FMTx__

#else

#endif
#ifdef __UINT16_MAX__

#else

#endif
#ifdef __UINT16_TYPE__

#else

#endif
#ifdef __UINT32_C

#else

#endif
#ifdef __UINT32_C_SUFFIX__

#else

#endif
#ifdef __UINT32_FMTX__

#else

#endif
#ifdef __UINT32_FMTo__

#else

#endif
#ifdef __UINT32_FMTu__

#else

#endif
#ifdef __UINT32_FMTx__

#else

#endif
#ifdef __UINT32_MAX__

#else

#endif
#ifdef __UINT32_TYPE__

#else

#endif
#ifdef __UINT64_C

#else

#endif
#ifdef __UINT64_C_SUFFIX__

#else

#endif
#ifdef __UINT64_FMTX__

#else

#endif
#ifdef __UINT64_FMTo__

#else

#endif
#ifdef __UINT64_FMTu__

#else

#endif
#ifdef __UINT64_FMTx__

#else

#endif
#ifdef __UINT64_MAX__

#else

#endif
#ifdef __UINT64_TYPE__

#else

#endif
#ifdef __UINT8_C

#else

#endif
#ifdef __UINT8_C_SUFFIX__

#else

#endif
#ifdef __UINT8_FMTX__

#else

#endif
#ifdef __UINT8_FMTo__

#else

#endif
#ifdef __UINT8_FMTu__

#else

#endif
#ifdef __UINT8_FMTx__

#else

#endif
#ifdef __UINT8_MAX__

#else

#endif
#ifdef __UINT8_TYPE__

#else

#endif
#ifdef __UINTMAX_C

#else

#endif
#ifdef __UINTMAX_C_SUFFIX__

#else

#endif
#ifdef __UINTMAX_FMTX__

#else

#endif
#ifdef __UINTMAX_FMTo__

#else

#endif
#ifdef __UINTMAX_FMTu__

#else

#endif
#ifdef __UINTMAX_FMTx__

#else

#endif
#ifdef __UINTMAX_MAX__

#else

#endif
#ifdef __UINTMAX_TYPE__

#else

#endif
#ifdef __UINTMAX_WIDTH__

#else

#endif
#ifdef __UINTPTR_FMTX__

#else

#endif
#ifdef __UINTPTR_FMTo__

#else

#endif
#ifdef __UINTPTR_FMTu__

#else

#endif
#ifdef __UINTPTR_FMTx__

#else

#endif
#ifdef __UINTPTR_MAX__

#else

#endif
#ifdef __UINTPTR_TYPE__

#else

#endif
#ifdef __UINTPTR_WIDTH__

#else

#endif
#ifdef __UINT_FAST16_FMTX__

#else

#endif
#ifdef __UINT_FAST16_FMTo__

#else

#endif
#ifdef __UINT_FAST16_FMTu__

#else

#endif
#ifdef __UINT_FAST16_FMTx__

#else

#endif
#ifdef __UINT_FAST16_MAX__

#else

#endif
#ifdef __UINT_FAST16_TYPE__

#else

#endif
#ifdef __UINT_FAST32_FMTX__

#else

#endif
#ifdef __UINT_FAST32_FMTo__

#else

#endif
#ifdef __UINT_FAST32_FMTu__

#else

#endif
#ifdef __UINT_FAST32_FMTx__

#else

#endif
#ifdef __UINT_FAST32_MAX__

#else

#endif
#ifdef __UINT_FAST32_TYPE__

#else

#endif
#ifdef __UINT_FAST64_FMTX__

#else

#endif
#ifdef __UINT_FAST64_FMTo__

#else

#endif
#ifdef __UINT_FAST64_FMTu__

#else

#endif
#ifdef __UINT_FAST64_FMTx__

#else

#endif
#ifdef __UINT_FAST64_MAX__

#else

#endif
#ifdef __UINT_FAST64_TYPE__

#else

#endif
#ifdef __UINT_FAST8_FMTX__

#else

#endif
#ifdef __UINT_FAST8_FMTo__

#else

#endif
#ifdef __UINT_FAST8_FMTu__

#else

#endif
#ifdef __UINT_FAST8_FMTx__

#else

#endif
#ifdef __UINT_FAST8_MAX__

#else

#endif
#ifdef __UINT_FAST8_TYPE__

#else

#endif
#ifdef __UINT_LEAST16_FMTX__

#else

#endif
#ifdef __UINT_LEAST16_FMTo__

#else

#endif
#ifdef __UINT_LEAST16_FMTu__

#else

#endif
#ifdef __UINT_LEAST16_FMTx__

#else

#endif
#ifdef __UINT_LEAST16_MAX__

#else

#endif
#ifdef __UINT_LEAST16_TYPE__

#else

#endif
#ifdef __UINT_LEAST32_FMTX__

#else

#endif
#ifdef __UINT_LEAST32_FMTo__

#else

#endif
#ifdef __UINT_LEAST32_FMTu__

#else

#endif
#ifdef __UINT_LEAST32_FMTx__

#else

#endif
#ifdef __UINT_LEAST32_MAX__

#else

#endif
#ifdef __UINT_LEAST32_TYPE__

#else

#endif
#ifdef __UINT_LEAST64_FMTX__

#else

#endif
#ifdef __UINT_LEAST64_FMTo__

#else

#endif
#ifdef __UINT_LEAST64_FMTu__

#else

#endif
#ifdef __UINT_LEAST64_FMTx__

#else

#endif
#ifdef __UINT_LEAST64_MAX__

#else

#endif
#ifdef __UINT_LEAST64_TYPE__

#else

#endif
#ifdef __UINT_LEAST8_FMTX__

#else

#endif
#ifdef __UINT_LEAST8_FMTo__

#else

#endif
#ifdef __UINT_LEAST8_FMTu__

#else

#endif
#ifdef __UINT_LEAST8_FMTx__

#else

#endif
#ifdef __UINT_LEAST8_MAX__

#else

#endif
#ifdef __UINT_LEAST8_TYPE__

#else

#endif
#ifdef __USER_LABEL_PREFIX__

#else

#endif
#ifdef __VERSION__

#else

#endif
#ifdef __WCHAR_MAX__

#else

#endif
#ifdef __WCHAR_TYPE__

#else

#endif
#ifdef __WCHAR_WIDTH__

#else

#endif
#ifdef __WINT_MAX__

#else

#endif
#ifdef __WINT_TYPE__

#else

#endif
#ifdef __WINT_UNSIGNED__

#else

#endif
#ifdef __WINT_WIDTH__

#else

#endif
#ifdef __amd64

#else

#endif
#ifdef __amd64__

#else

#endif
#ifdef __clang__

#else

#endif
#ifdef __clang_literal_encoding__

#else

#endif
#ifdef __clang_major__

#else

#endif
#ifdef __clang_minor__

#else

#endif
#ifdef __clang_patchlevel__

#else

#endif
#ifdef __clang_version__

#else

#endif
#ifdef __clang_wide_literal_encoding__

#else

#endif
#ifdef __code_model_small__

#else

#endif
#ifdef __gnu_linux__

#else

#endif
#ifdef __k8

#else

#endif
#ifdef __k8__

#else

#endif
#ifdef __linux

#else

#endif
#ifdef __linux__

#else

#endif
#ifdef __llvm__

#else

#endif
#ifdef __pic__

#else

#endif
#ifdef __pie__

#else

#endif
#ifdef __seg_fs

#else

#endif
#ifdef __seg_gs

#else

#endif
#ifdef __tune_k8__

#else

#endif
#ifdef __unix

#else

#endif
#ifdef __unix__

#else

#endif
#ifdef __x86_64

#else

#endif
#ifdef __x86_64__

#else

#endif
#ifdef linux

#else

#endif
#ifdef unix

#else

#endif

/*CLANG RAW*/

#ifdef __DBL_MIN_EXP__

#else

#endif
#ifdef __LDBL_MANT_DIG__

#else

#endif
#ifdef __UINT_LEAST16_MAX__

#else

#endif
#ifdef __FLT16_HAS_QUIET_NAN__

#else

#endif
#ifdef __ATOMIC_ACQUIRE

#else

#endif
#ifdef __WCHAR_MAX__

#else

#endif
#ifdef __FLT128_MAX_10_EXP__

#else

#endif
#ifdef __FLT_MIN__

#else

#endif
#ifdef __GCC_IEC_559_COMPLEX

#else

#endif
#ifdef __UINT_LEAST8_TYPE__

#else

#endif
#ifdef __SIZEOF_FLOAT80__

#else

#endif
#ifdef __BFLT16_DENORM_MIN__

#else

#endif
#ifdef __INTMAX_C

#else

#endif
#ifdef __CHAR_BIT__

#else

#endif
#ifdef __UINT8_MAX__

#else

#endif
#ifdef __SCHAR_WIDTH__

#else

#endif
#ifdef __WINT_MAX__

#else

#endif
#ifdef __FLT32_MIN_EXP__

#else

#endif
#ifdef __BFLT16_NORM_MAX__

#else

#endif
#ifdef __BFLT16_MIN_10_EXP__

#else

#endif
#ifdef __ORDER_LITTLE_ENDIAN__

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

#else

#endif
#ifdef __GCC_ATOMIC_CHAR_LOCK_FREE

#else

#endif
#ifdef __GCC_IEC_559

#else

#endif
#ifdef __FLT32X_DECIMAL_DIG__

#else

#endif
#ifdef __FLT_EVAL_METHOD__

#else

#endif
#ifdef __FLT64_DECIMAL_DIG__

#else

#endif
#ifdef __GCC_ATOMIC_CHAR32_T_LOCK_FREE

#else

#endif
#ifdef __UINT_FAST64_MAX__

#else

#endif
#ifdef __SIG_ATOMIC_TYPE__

#else

#endif
#ifdef __DBL_MIN_10_EXP__

#else

#endif
#ifdef __FINITE_MATH_ONLY__

#else

#endif
#ifdef __FLT32X_MAX_EXP__

#else

#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1

#else

#endif
#ifdef __FLT32_HAS_DENORM__

#else

#endif
#ifdef __UINT_FAST8_MAX__

#else

#endif
#ifdef __FLT32_MAX_10_EXP__

#else

#endif
#ifdef __DEC64_MAX_EXP__

#else

#endif
#ifdef __INT8_C

#else

#endif
#ifdef __INT_LEAST8_WIDTH__

#else

#endif
#ifdef __UINT_LEAST64_MAX__

#else

#endif
#ifdef __SHRT_MAX__

#else

#endif
#ifdef __LDBL_MAX__

#else

#endif
#ifdef __FLT64X_MAX_10_EXP__

#else

#endif
#ifdef __BFLT16_MAX_10_EXP__

#else

#endif
#ifdef __BFLT16_MAX_EXP__

#else

#endif
#ifdef __LDBL_IS_IEC_60559__

#else

#endif
#ifdef __FLT64X_HAS_QUIET_NAN__

#else

#endif
#ifdef __UINT_LEAST8_MAX__

#else

#endif
#ifdef __GCC_ATOMIC_BOOL_LOCK_FREE

#else

#endif
#ifdef __FLT128_DENORM_MIN__

#else

#endif
#ifdef __UINTMAX_TYPE__

#else

#endif
#ifdef __BFLT16_DECIMAL_DIG__

#else

#endif
#ifdef __linux

#else

#endif
#ifdef __DEC32_EPSILON__

#else

#endif
#ifdef __FLT_EVAL_METHOD_TS_18661_3__

#else

#endif
#ifdef __UINT32_MAX__

#else

#endif
#ifdef __DBL_DENORM_MIN__

#else

#endif
#ifdef __FLT128_MIN_EXP__

#else

#endif
#ifdef __DEC64X_MAX_EXP__

#else

#endif
#ifdef __WINT_MIN__

#else

#endif
#ifdef __FLT128_MIN_10_EXP__

#else

#endif
#ifdef __FLT32X_IS_IEC_60559__

#else

#endif
#ifdef __INT_LEAST16_WIDTH__

#else

#endif
#ifdef __SCHAR_MAX__

#else

#endif
#ifdef __FLT128_MANT_DIG__

#else

#endif
#ifdef __WCHAR_MIN__

#else

#endif
#ifdef __INT64_C

#else

#endif
#ifdef __SSP_STRONG__

#else

#endif
#ifdef __GCC_ATOMIC_POINTER_LOCK_FREE

#else

#endif
#ifdef __ATOMIC_SEQ_CST

#else

#endif
#ifdef __unix

#else

#endif
#ifdef __INT_LEAST64_MAX__

#else

#endif
#ifdef __FLT32X_MANT_DIG__

#else

#endif
#ifdef __FLT64X_EPSILON__

#else

#endif
#ifdef __STDC_HOSTED__

#else

#endif
#ifdef __DEC64_MIN_EXP__

#else

#endif
#ifdef __DBL_DIG__

#else

#endif
#ifdef __STDC_EMBED_EMPTY__

#else

#endif
#ifdef __FLT_EPSILON__

#else

#endif
#ifdef __SHRT_WIDTH__

#else

#endif
#ifdef __FLT32_IS_IEC_60559__

#else

#endif
#ifdef __LDBL_MIN__

#else

#endif
#ifdef __STDC_UTF_16__

#else

#endif
#ifdef __DBL_IS_IEC_60559__

#else

#endif
#ifdef __DEC32_MAX__

#else

#endif
#ifdef __CHAR8_TYPE__

#else

#endif
#ifdef __FLT64X_DENORM_MIN__

#else

#endif
#ifdef __FLT32X_HAS_INFINITY__

#else

#endif
#ifdef __unix__

#else

#endif
#ifdef __INT_WIDTH__

#else

#endif
#ifdef __STDC_IEC_559__

#else

#endif
#ifdef __STDC_ISO_10646__

#else

#endif
#ifdef __GCC_ATOMIC_CHAR8_T_LOCK_FREE

#else

#endif
#ifdef __DECIMAL_DIG__

#else

#endif
#ifdef __STDC_IEC_559_COMPLEX__

#else

#endif
#ifdef __gnu_linux__

#else

#endif
#ifdef __FLT64X_MIN_10_EXP__

#else

#endif
#ifdef __LDBL_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT16_MIN_EXP__

#else

#endif
#ifdef __FLT64_MANT_DIG__

#else

#endif
#ifdef __FLT64X_MANT_DIG__

#else

#endif
#ifdef __BFLT16_DIG__

#else

#endif
#ifdef __GNUC__

#else

#endif
#ifdef __pie__

#else

#endif
#ifdef __MMX__

#else

#endif
#ifdef __FLT_HAS_DENORM__

#else

#endif
#ifdef __SIZEOF_LONG_DOUBLE__

#else

#endif
#ifdef __LDBL_DIG__

#else

#endif
#ifdef __BIGGEST_ALIGNMENT__

#else

#endif
#ifdef __FLT64_MAX_10_EXP__

#else

#endif
#ifdef __BFLT16_IS_IEC_60559__

#else

#endif
#ifdef __FLT16_MAX_10_EXP__

#else

#endif
#ifdef __DBL_MAX__

#else

#endif
#ifdef __INT_FAST32_MAX__

#else

#endif
#ifdef __DBL_HAS_INFINITY__

#else

#endif
#ifdef __INT64_MAX__

#else

#endif
#ifdef __SIZEOF_FLOAT__

#else

#endif
#ifdef __HAVE_SPECULATION_SAFE_VALUE

#else

#endif
#ifdef __DEC32_MIN_EXP__

#else

#endif
#ifdef __INTPTR_WIDTH__

#else

#endif
#ifdef __UINT_LEAST32_MAX__

#else

#endif
#ifdef __FLT32X_HAS_DENORM__

#else

#endif
#ifdef __INT_FAST16_TYPE__

#else

#endif
#ifdef __MMX_WITH_SSE__

#else

#endif
#ifdef __LDBL_HAS_DENORM__

#else

#endif
#ifdef __SEG_GS

#else

#endif
#ifdef __BFLT16_EPSILON__

#else

#endif
#ifdef __FLT128_HAS_INFINITY__

#else

#endif
#ifdef __DEC32_MIN__

#else

#endif
#ifdef __DBL_MAX_EXP__

#else

#endif
#ifdef __WCHAR_WIDTH__

#else

#endif
#ifdef __FLT32_MAX__

#else

#endif
#ifdef __DEC128_EPSILON__

#else

#endif
#ifdef __FLT16_DECIMAL_DIG__

#else

#endif
#ifdef __SSE2_MATH__

#else

#endif
#ifdef __ATOMIC_HLE_RELEASE

#else

#endif
#ifdef __PTRDIFF_MAX__

#else

#endif
#ifdef __amd64

#else

#endif
#ifdef __DEC64X_MAX__

#else

#endif
#ifdef __ATOMIC_HLE_ACQUIRE

#else

#endif
#ifdef __LONG_LONG_MAX__

#else

#endif
#ifdef __SIZEOF_SIZE_T__

#else

#endif
#ifdef __BFLT16_HAS_INFINITY__

#else

#endif
#ifdef __FLT64X_MIN_EXP__

#else

#endif
#ifdef __SIZEOF_WINT_T__

#else

#endif
#ifdef __LONG_LONG_WIDTH__

#else

#endif
#ifdef __FLT32_MAX_EXP__

#else

#endif
#ifdef __GXX_ABI_VERSION

#else

#endif
#ifdef __FLT_MIN_EXP__

#else

#endif
#ifdef __GCC_HAVE_DWARF2_CFI_ASM

#else

#endif
#ifdef __INT16_MAX__

#else

#endif
#ifdef __x86_64

#else

#endif
#ifdef __INT_FAST64_TYPE__

#else

#endif
#ifdef __BFLT16_MAX__

#else

#endif
#ifdef __BFLT16_HAS_DENORM__

#else

#endif
#ifdef __FLT64_DENORM_MIN__

#else

#endif
#ifdef __FLT16_DENORM_MIN__

#else

#endif
#ifdef __FLT128_EPSILON__

#else

#endif
#ifdef __FLT64X_NORM_MAX__

#else

#endif
#ifdef __SIZEOF_POINTER__

#else

#endif
#ifdef __SIZE_TYPE__

#else

#endif
#ifdef __LP64__

#else

#endif
#ifdef __DBL_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT32X_EPSILON__

#else

#endif
#ifdef __LDBL_MAX_EXP__

#else

#endif
#ifdef __DECIMAL_BID_FORMAT__

#else

#endif
#ifdef __FLT64_MIN_EXP__

#else

#endif
#ifdef __FLT64_MIN_10_EXP__

#else

#endif
#ifdef __FLT16_MIN_10_EXP__

#else

#endif
#ifdef __FLT64X_DECIMAL_DIG__

#else

#endif
#ifdef __DEC128_MIN__

#else

#endif
#ifdef __REGISTER_PREFIX__

#else

#endif
#ifdef __UINT16_MAX__

#else

#endif
#ifdef __DBL_HAS_DENORM__

#else

#endif
#ifdef __FLT32_MIN__

#else

#endif
#ifdef __UINT8_TYPE__

#else

#endif
#ifdef __FLT_DIG__

#else

#endif
#ifdef __NO_INLINE__

#else

#endif
#ifdef __DEC_EVAL_METHOD__

#else

#endif
#ifdef __FLT_MANT_DIG__

#else

#endif
#ifdef __LDBL_DECIMAL_DIG__

#else

#endif
#ifdef __VERSION__

#else

#endif
#ifdef __UINT64_C

#else

#endif
#ifdef __DEC64X_MIN__

#else

#endif
#ifdef _STDC_PREDEF_H

#else

#endif
#ifdef __INT_LEAST32_MAX__

#else

#endif
#ifdef __GCC_ATOMIC_INT_LOCK_FREE

#else

#endif
#ifdef __FLT128_MAX_EXP__

#else

#endif
#ifdef __FLT32_MANT_DIG__

#else

#endif
#ifdef __FLOAT_WORD_ORDER__

#else

#endif
#ifdef __FLT32X_MIN_EXP__

#else

#endif
#ifdef __STDC_IEC_60559_COMPLEX__

#else

#endif
#ifdef __BFLT16_MIN__

#else

#endif
#ifdef __FLT128_HAS_DENORM__

#else

#endif
#ifdef __FLT32_DECIMAL_DIG__

#else

#endif
#ifdef __FLT128_DIG__

#else

#endif
#ifdef __INT32_C

#else

#endif
#ifdef __DEC64_EPSILON__

#else

#endif
#ifdef __ORDER_PDP_ENDIAN__

#else

#endif
#ifdef __DEC128_MIN_EXP__

#else

#endif
#ifdef __DEC128_MAX__

#else

#endif
#ifdef __INT_FAST32_TYPE__

#else

#endif
#ifdef __UINT_LEAST16_TYPE__

#else

#endif
#ifdef __DEC64X_MANT_DIG__

#else

#endif
#ifdef __DEC128_MAX_EXP__

#else

#endif
#ifdef unix

#else

#endif
#ifdef __UINT64_MAX__

#else

#endif
#ifdef __FLT_IS_IEC_60559__

#else

#endif
#ifdef __GNUC_WIDE_EXECUTION_CHARSET_NAME

#else

#endif
#ifdef __FLT64X_DIG__

#else

#endif
#ifdef __INT8_TYPE__

#else

#endif
#ifdef __ELF__

#else

#endif
#ifdef __GCC_ASM_FLAG_OUTPUTS__

#else

#endif
#ifdef __UINT32_TYPE__

#else

#endif
#ifdef __BFLT16_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT_RADIX__

#else

#endif
#ifdef __INT_LEAST16_TYPE__

#else

#endif
#ifdef __LDBL_EPSILON__

#else

#endif
#ifdef __UINTMAX_C

#else

#endif
#ifdef __DEC64X_EPSILON__

#else

#endif
#ifdef __FLT16_DIG__

#else

#endif
#ifdef __SSE_MATH__

#else

#endif
#ifdef __k8

#else

#endif
#ifdef __FLT32X_MIN__

#else

#endif
#ifdef __SIG_ATOMIC_MAX__

#else

#endif
#ifdef __GCC_ATOMIC_WCHAR_T_LOCK_FREE

#else

#endif
#ifdef __USER_LABEL_PREFIX__

#else

#endif
#ifdef __STDC_IEC_60559_BFP__

#else

#endif
#ifdef __SIZEOF_PTRDIFF_T__

#else

#endif
#ifdef __FLT64X_HAS_INFINITY__

#else

#endif
#ifdef __FLT32_HAS_INFINITY__

#else

#endif
#ifdef __SIZEOF_LONG__

#else

#endif
#ifdef __FLT64_IS_IEC_60559__

#else

#endif
#ifdef __x86_64__

#else

#endif
#ifdef __FLT16_IS_IEC_60559__

#else

#endif
#ifdef __FLT16_MAX_EXP__

#else

#endif
#ifdef __DEC32_SUBNORMAL_MIN__

#else

#endif
#ifdef __STDC_EMBED_FOUND__

#else

#endif
#ifdef __INT_FAST16_MAX__

#else

#endif
#ifdef __GCC_CONSTRUCTIVE_SIZE

#else

#endif
#ifdef __FLT64_DIG__

#else

#endif
#ifdef __UINT_FAST32_MAX__

#else

#endif
#ifdef __UINT_LEAST64_TYPE__

#else

#endif
#ifdef __FLT16_EPSILON__

#else

#endif
#ifdef __FLT_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT_MAX_10_EXP__

#else

#endif
#ifdef __LONG_MAX__

#else

#endif
#ifdef __FLT64X_HAS_DENORM__

#else

#endif
#ifdef __DEC128_SUBNORMAL_MIN__

#else

#endif
#ifdef __FLT_HAS_INFINITY__

#else

#endif
#ifdef __GNUC_EXECUTION_CHARSET_NAME

#else

#endif
#ifdef __UINT_FAST16_TYPE__

#else

#endif
#ifdef __DEC64_MAX__

#else

#endif
#ifdef __STDC_EMBED_NOT_FOUND__

#else

#endif
#ifdef __INT_FAST32_WIDTH__

#else

#endif
#ifdef __CHAR16_TYPE__

#else

#endif
#ifdef __PRAGMA_REDEFINE_EXTNAME

#else

#endif
#ifdef __DEC64X_SUBNORMAL_MIN__

#else

#endif
#ifdef __SIZE_WIDTH__

#else

#endif
#ifdef __SEG_FS

#else

#endif
#ifdef __BITINT_MAXWIDTH__

#else

#endif
#ifdef __INT_LEAST16_MAX__

#else

#endif
#ifdef __FLT16_NORM_MAX__

#else

#endif
#ifdef __DEC64_MANT_DIG__

#else

#endif
#ifdef __FLT32_DENORM_MIN__

#else

#endif
#ifdef __SIG_ATOMIC_WIDTH__

#else

#endif
#ifdef __INT_LEAST64_TYPE__

#else

#endif
#ifdef __INT16_TYPE__

#else

#endif
#ifdef __INT_LEAST8_TYPE__

#else

#endif
#ifdef __FLT16_MAX__

#else

#endif
#ifdef __FLT128_MIN__

#else

#endif
#ifdef __STDC_VERSION__

#else

#endif
#ifdef __SIZEOF_INT__

#else

#endif
#ifdef __DEC32_MAX_EXP__

#else

#endif
#ifdef __INT_FAST8_MAX__

#else

#endif
#ifdef __FLT128_MAX__

#else

#endif
#ifdef __INTPTR_MAX__

#else

#endif
#ifdef linux

#else

#endif
#ifdef __FLT64_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT32_MIN_10_EXP__

#else

#endif
#ifdef __FLT32X_DIG__

#else

#endif
#ifdef __UINT16_C

#else

#endif
#ifdef __PTRDIFF_WIDTH__

#else

#endif
#ifdef __INT_FAST16_WIDTH__

#else

#endif
#ifdef __FLT64_HAS_INFINITY__

#else

#endif
#ifdef __FLT64X_MAX__

#else

#endif
#ifdef __FLT16_HAS_INFINITY__

#else

#endif
#ifdef __SIG_ATOMIC_MIN__

#else

#endif
#ifdef __code_model_small__

#else

#endif
#ifdef __GCC_ATOMIC_LONG_LOCK_FREE

#else

#endif
#ifdef __DEC32_MANT_DIG__

#else

#endif
#ifdef __FLT16_MANT_DIG__

#else

#endif
#ifdef __k8__

#else

#endif
#ifdef __INTPTR_TYPE__

#else

#endif
#ifdef __UINT16_TYPE__

#else

#endif
#ifdef __WCHAR_TYPE__

#else

#endif
#ifdef __pic__

#else

#endif
#ifdef __UINTPTR_MAX__

#else

#endif
#ifdef __INT_FAST64_WIDTH__

#else

#endif
#ifdef __LDBL_HAS_INFINITY__

#else

#endif
#ifdef __INT_FAST64_MAX__

#else

#endif
#ifdef __GCC_ATOMIC_TEST_AND_SET_TRUEVAL

#else

#endif
#ifdef __FLT_NORM_MAX__

#else

#endif
#ifdef __FLT64X_MAX_EXP__

#else

#endif
#ifdef __UINT_FAST64_TYPE__

#else

#endif
#ifdef __BFLT16_MIN_EXP__

#else

#endif
#ifdef __INT_MAX__

#else

#endif
#ifdef __linux__

#else

#endif
#ifdef __INT64_TYPE__

#else

#endif
#ifdef __FLT_MAX_EXP__

#else

#endif
#ifdef __ORDER_BIG_ENDIAN__

#else

#endif
#ifdef __DBL_MANT_DIG__

#else

#endif
#ifdef __SIZEOF_FLOAT128__

#else

#endif
#ifdef __BFLT16_MANT_DIG__

#else

#endif
#ifdef __GCC_ATOMIC_CHAR16_T_LOCK_FREE

#else

#endif
#ifdef __DEC64_MIN__

#else

#endif
#ifdef __WINT_TYPE__

#else

#endif
#ifdef __UINT_LEAST32_TYPE__

#else

#endif
#ifdef __SIZEOF_SHORT__

#else

#endif
#ifdef __FLT32_NORM_MAX__

#else

#endif
#ifdef __SSE__

#else

#endif
#ifdef __LDBL_MIN_EXP__

#else

#endif
#ifdef __FLT64_MAX__

#else

#endif
#ifdef __DEC64X_MIN_EXP__

#else

#endif
#ifdef __amd64__

#else

#endif
#ifdef __WINT_WIDTH__

#else

#endif
#ifdef __INT_LEAST8_MAX__

#else

#endif
#ifdef __INT_LEAST64_WIDTH__

#else

#endif
#ifdef __FLT32X_MAX_10_EXP__

#else

#endif
#ifdef __SIZEOF_INT128__

#else

#endif
#ifdef __FLT16_MIN__

#else

#endif
#ifdef __FLT64X_IS_IEC_60559__

#else

#endif
#ifdef __LDBL_MAX_10_EXP__

#else

#endif
#ifdef __ATOMIC_RELAXED

#else

#endif
#ifdef __DBL_EPSILON__

#else

#endif
#ifdef __INT_LEAST32_TYPE__

#else

#endif
#ifdef _LP64

#else

#endif
#ifdef __UINT8_C

#else

#endif
#ifdef __FLT64_MAX_EXP__

#else

#endif
#ifdef __SIZEOF_WCHAR_T__

#else

#endif
#ifdef __UINT64_TYPE__

#else

#endif
#ifdef __GNUC_PATCHLEVEL__

#else

#endif
#ifdef __FLT128_NORM_MAX__

#else

#endif
#ifdef __FLT64_NORM_MAX__

#else

#endif
#ifdef __FLT128_HAS_QUIET_NAN__

#else

#endif
#ifdef __INTMAX_MAX__

#else

#endif
#ifdef __INT_FAST8_TYPE__

#else

#endif
#ifdef __FLT64X_MIN__

#else

#endif
#ifdef __FLT64_EPSILON__

#else

#endif
#ifdef __GNUC_STDC_INLINE__

#else

#endif
#ifdef __FLT64_HAS_DENORM__

#else

#endif
#ifdef __FLT32_EPSILON__

#else

#endif
#ifdef __FLT16_HAS_DENORM__

#else

#endif
#ifdef __DBL_DECIMAL_DIG__

#else

#endif
#ifdef __STDC_UTF_32__

#else

#endif
#ifdef __INT_FAST8_WIDTH__

#else

#endif
#ifdef __FXSR__

#else

#endif
#ifdef __FLT32X_MAX__

#else

#endif
#ifdef __DBL_NORM_MAX__

#else

#endif
#ifdef __BYTE_ORDER__

#else

#endif
#ifdef __GCC_DESTRUCTIVE_SIZE

#else

#endif
#ifdef __INTMAX_WIDTH__

#else

#endif
#ifdef __FLT32_DIG__

#else

#endif
#ifdef __UINT32_C

#else

#endif
#ifdef __FLT_DENORM_MIN__

#else

#endif
#ifdef __FLT128_IS_IEC_60559__

#else

#endif
#ifdef __INT8_MAX__

#else

#endif
#ifdef __LONG_WIDTH__

#else

#endif
#ifdef __DBL_MIN__

#else

#endif
#ifdef __PIC__

#else

#endif
#ifdef __INT32_MAX__

#else

#endif
#ifdef __UINT_FAST32_TYPE__

#else

#endif
#ifdef __FLT32X_NORM_MAX__

#else

#endif
#ifdef __CHAR32_TYPE__

#else

#endif
#ifdef __FLT_MAX__

#else

#endif
#ifdef __SSE2__

#else

#endif
#ifdef __INT32_TYPE__

#else

#endif
#ifdef __SIZEOF_DOUBLE__

#else

#endif
#ifdef __FLT_MIN_10_EXP__

#else

#endif
#ifdef __FLT64_MIN__

#else

#endif
#ifdef __INT_LEAST32_WIDTH__

#else

#endif
#ifdef __INTMAX_TYPE__

#else

#endif
#ifdef __FLT32X_HAS_QUIET_NAN__

#else

#endif
#ifdef __ATOMIC_CONSUME

#else

#endif
#ifdef __GNUC_MINOR__

#else

#endif
#ifdef __UINTMAX_MAX__

#else

#endif
#ifdef __PIE__

#else

#endif
#ifdef __FLT32X_DENORM_MIN__

#else

#endif
#ifdef __DBL_MAX_10_EXP__

#else

#endif
#ifdef __LDBL_DENORM_MIN__

#else

#endif
#ifdef __INT16_C

#else

#endif
#ifdef __ATOMIC_RELEASE

#else

#endif
#ifdef __STDC__

#else

#endif
#ifdef __PTRDIFF_TYPE__

#else

#endif
#ifdef __FLT32X_MIN_10_EXP__

#else

#endif
#ifdef __UINTPTR_TYPE__

#else

#endif
#ifdef __DEC64_SUBNORMAL_MIN__

#else

#endif
#ifdef __DEC128_MANT_DIG__

#else

#endif
#ifdef __LDBL_MIN_10_EXP__

#else

#endif
#ifdef __SIZEOF_LONG_LONG__

#else

#endif
#ifdef __FLT128_DECIMAL_DIG__

#else

#endif
#ifdef __GCC_ATOMIC_LLONG_LOCK_FREE

#else

#endif
#ifdef __FLT32_HAS_QUIET_NAN__

#else

#endif
#ifdef __FLT_DECIMAL_DIG__

#else

#endif
#ifdef __UINT_FAST16_MAX__

#else

#endif
#ifdef __LDBL_NORM_MAX__

#else

#endif
#ifdef __GCC_ATOMIC_SHORT_LOCK_FREE

#else

#endif
#ifdef __SIZE_MAX__

#else

#endif
#ifdef __UINT_FAST8_TYPE__

#else

#endif
#ifdef __ATOMIC_ACQ_REL

#else

#endif