#pragma once

namespace Rinegine {
namespace Kernel {
template <class type = char>
class Base_String {
private:
  Rinegine::Kernel::Array<type> m_buffer;

public:
  Base_String() = default;
  explicit Base_String(const type *str) {
    if (str != nullptr) {
      for (size_t i = 0; str[i] != '\0'; ++i) {
        m_buffer.push_back(str[i]);
      }
      m_buffer.reserve(m_buffer.size() + 1);
      m_buffer[m_buffer.size()] = '\0';
    }
  }

  const type *c_str() const { return m_buffer.data() ? m_buffer.data() : ""; }

  size_t size() const { return m_buffer.size(); }
  size_t length() const noexcept {
    size_t char_count = 0;
    unsigned char *mm_buffer = (unsigned char *)m_buffer.data();
    for (size_t i = 0; i < m_buffer.size() * sizeof(type) && mm_buffer[i] != '\0'; ++i) {
      if ((static_cast<unsigned char>(mm_buffer[i]) & 0xC0) != 0x80) {
        char_count++;
      }
    }

    return char_count;
  }
  Base_String &operator+=(const type *str) {
    if (str != nullptr) {
      for (size_t i = 0; str[i] != '\0'; ++i) {
        m_buffer.push_back(str[i]);
      }
      m_buffer.reserve(m_buffer.size() + 1);
      m_buffer[m_buffer.size()] = '\0';
    }
    return *this;
  }

  Base_String &operator+=(const Base_String &other) { return *this += other.c_str(); }

  type operator[](size_t index) const { return m_buffer[index]; }
  type &operator[](size_t index) { return m_buffer[index]; }

  bool operator==(const Base_String &other) const {
    if (size() != other.size())
      return false;
    return std::strcmp(c_str(), other.c_str()) == 0;
  }

  bool operator==(const type *str) const {
    if (str == nullptr)
      return false;
    return std::strcmp(c_str(), str) == 0;
  }

  bool operator<(const Base_String &other) const {
    return std::strcmp(c_str(), other.c_str()) < 0;
  }
  Base_String &operator=(Rinegine::Kernel::String in) {
    m_buffer.reserve(in.size() + 1);
    m_buffer.resize(in.size());
    if (!in.empty()) {
      std::memcpy(m_buffer.data(), in.data(), in.size());
    }
    m_buffer[m_buffer.size()] = '\0';
    return *this;
  }
  explicit operator Rinegine::Kernel::String() const {
    return Rinegine::Kernel::String(m_buffer.data(), m_buffer.size());
  }
};

template <class type = char>
inline Base_String<type> operator+(Base_String<type> lhs, const type *rhs) {
  lhs += rhs;
  return lhs;
}
template <class type = char>
inline std::ostream &operator<<(std::ostream &os, const Base_String<type> &str) {
  os << str.c_str();
  return os;
}
typedef Base_String<char> String;
// inline Base_String operator""(const char* str, size_t) {
//   return Base_String(str);
// }

} // namespace Kernel
} // namespace Rinegine