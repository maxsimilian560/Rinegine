#pragma once

#ifndef _GLIBCXX_NOEXCEPT
#define _GLIBCXX_NOEXCEPT noexcept
#endif
#ifndef _GLIBCXX_NOEXCEPT_PARM
#define _GLIBCXX_NOEXCEPT_PARM
#endif
#ifndef _GLIBCXX_NOEXCEPT_QUAL
#define _GLIBCXX_NOEXCEPT_QUAL noexcept
#endif
#ifndef _GLIBCXX_CONSTEXPR
#define _GLIBCXX_CONSTEXPR constexpr
#endif
#ifndef _GLIBCXX17_CONSTEXPR
#define _GLIBCXX17_CONSTEXPR constexpr
#endif
#ifndef _GLIBCXX_USE_NOEXCEPT
#define _GLIBCXX_USE_NOEXCEPT noexcept
#endif
namespace Rinegine::Kernel::Util {
#if defined(__clang__) && __has_builtin(__is_trivially_destructible)
#undef __has_trivial_destructor
#define __has_trivial_destructor(T) __is_trivially_destructible(T)
#endif

template <typename T, typename... Args>
struct is_trivially_constructible {
  static constexpr bool value = __is_trivially_constructible(T, Args...);
};
template <typename T, typename... Args>
inline constexpr bool is_trivially_constructible_v =
    is_trivially_constructible<T, Args...>::value;

template <typename T>
struct is_trivially_copyable {
  static constexpr bool value = __is_trivially_copyable(T);
};

template <typename T>
inline constexpr bool is_trivially_copyable_v = is_trivially_copyable<T>::value;

template <typename T>
struct is_trivial {
  static constexpr bool value = __is_trivial(T);
};
template <typename T>
inline constexpr bool is_trivial_v = is_trivial<T>::value;

template <typename T>
struct has_trivial_destructor {
  static constexpr bool value = __has_trivial_destructor(T);
};
template <typename T>
inline constexpr bool has_trivial_destructor_v =
    has_trivial_destructor<T>::value;

template <typename T>
__attribute__((__always_inline__)) inline _GLIBCXX_CONSTEXPR T *
__addressof(T &__r) _GLIBCXX_NOEXCEPT {
  return __builtin_addressof(__r);
}

template <typename _Tp>
[[__nodiscard__, __gnu__::__always_inline__]]
inline _GLIBCXX17_CONSTEXPR _Tp *addressof(_Tp &__r) noexcept {
  return Util::__addressof(__r);
}

template <typename _Tp>
struct remove_reference {
  using type = _Tp;
};

template <typename _Tp>
struct remove_reference<_Tp &> {
  using type = _Tp;
};

template <typename _Tp>
struct remove_reference<_Tp &&> {
  using type = _Tp;
};

template <typename _Tp>
using remove_reference_t = typename remove_reference<_Tp>::type;

template <typename _Tp>
[[__nodiscard__, __gnu__::__always_inline__]]
inline constexpr _Tp &&forward(remove_reference_t<_Tp> &__t) noexcept {
  return static_cast<_Tp &&>(__t);
}

template <typename T>
struct is_lvalue_reference {
  static constexpr bool value = false;
};

template <typename T>
struct is_lvalue_reference<T &> {
  static constexpr bool value = true;
};

template <typename T>
inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

template <typename _Tp>
[[__nodiscard__, __gnu__::__always_inline__]]
inline constexpr _Tp &&forward(remove_reference_t<_Tp> &&__t) noexcept {
  static_assert(
      !is_lvalue_reference_v<_Tp>,
      "template argument substituting _Tp is an lvalue reference type");
  return static_cast<_Tp &&>(__t);
}

template <bool Condition, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  using type = T;
};
template <bool Condition, typename T = void>
using enable_if_t = typename enable_if<Condition, T>::type;
template <typename From, typename To>
class is_convertible {
private:
  typedef char yes_type;
  struct no_type {
    char padding[2];
  };

  static yes_type test(To);

  template <typename U>
  static no_type test(...);

  static From declval();

public:
  static constexpr bool value = sizeof(test(declval())) == sizeof(yes_type);
};

template <typename From, typename To>
inline constexpr bool is_convertible_v = is_convertible<From, To>::value;

template <typename From, typename To>
concept convertible_to = is_convertible_v<From, To>;

template <typename T, typename Enable = void>
struct Hash;

template <>
struct Hash<int> {
  inline size_t operator()(int key) const noexcept {
    return static_cast<size_t>(key);
  }
};

template <>
struct Hash<unsigned int> {
  inline size_t operator()(unsigned int key) const noexcept {
    return static_cast<size_t>(key);
  }
};

template <>
struct Hash<size_t> {
  inline size_t operator()(size_t key) const noexcept { return key; }
};

template <typename T>
struct Hash<T *> {
  inline size_t operator()(T *key) const noexcept {
    return reinterpret_cast<size_t>(key);
  }
};
template <>
struct Hash<std::string_view> {
  inline size_t operator()(std::string_view key) const noexcept {
    size_t hash = 14695981039346656037ULL;
    for (char c : key) {
      hash ^= static_cast<unsigned char>(c);
      hash *= 1099511628211ULL;
    }
    return hash;
  }
};

template <>
struct Hash<std::u32string_view> {
  inline size_t operator()(std::u32string_view key) const noexcept {
    size_t hash = 14695981039346656037ULL;
    for (char32_t cp : key) {
      hash ^= static_cast<size_t>(cp);
      hash *= 1099511628211ULL;
    }
    return hash;
  }
};

// template <> struct Hash<Kernel::String_view> {
//   inline size_t operator()(std::string_view key) const noexcept {
//     size_t hash = 14695981039346656037ULL;
//     for (char c : key) {
//       hash ^= static_cast<unsigned char>(c);
//       hash *= 1099511628211ULL;
//     }
//     return hash;
//   }
// };

// template <> struct Hash<Kernel::String32_view> {
//   inline size_t operator()(std::u32string_view key) const noexcept {
//     size_t hash = 14695981039346656037ULL;
//     for (char32_t cp : key) {
//       hash ^= static_cast<size_t>(cp);
//       hash *= 1099511628211ULL;
//     }
//     return hash;
//   }
// };

template <typename T>
concept HasInternalHash = requires(const T &obj) {
  { obj.hash() } -> convertible_to<size_t>;
};

template <typename T>
struct Hash<T, enable_if_t<HasInternalHash<T>>> {
  inline size_t operator()(const T &key) const noexcept {
    return key.hash();
  }
};

} // namespace Rinegine::Kernel::Util