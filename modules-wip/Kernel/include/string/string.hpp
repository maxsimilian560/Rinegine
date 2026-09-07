#pragma once

namespace Rinegine {
namespace Kernel {
class String {
private:
  Rinegine::Kernel::Array<char> m_buffer;

public:
  String() = default;
  explicit String(const char *str) {
    if (str != nullptr) {
      for (size_t i = 0; str[i] != '\0'; ++i) {
        m_buffer.push_back(str[i]);
      }
      m_buffer.reserve(m_buffer.size() + 1);
      m_buffer[m_buffer.size()] = '\0';
    }
  }

  const char *c_str() const { return m_buffer.data() ? m_buffer.data() : ""; }

  size_t size() const { return m_buffer.size(); }
  size_t length() const noexcept {
    size_t char_count = 0;

    for (size_t i = 0; i < m_buffer.size() && m_buffer[i] != '\0'; ++i) {
      if ((static_cast<unsigned char>(m_buffer[i]) & 0xC0) != 0x80) {
        char_count++;
      }
    }

    return char_count;
  }
  String &operator+=(const char *str) {
    if (str != nullptr) {
      for (size_t i = 0; str[i] != '\0'; ++i) {
        m_buffer.push_back(str[i]);
      }
      m_buffer.reserve(m_buffer.size() + 1);
      m_buffer[m_buffer.size()] = '\0';
    }
    return *this;
  }

  String &operator+=(const String &other) { return *this += other.c_str(); }

  char operator[](size_t index) const { return m_buffer[index]; }
  char &operator[](size_t index) { return m_buffer[index]; }

  bool operator==(const String &other) const {
    if (size() != other.size())
      return false;
    return std::strcmp(c_str(), other.c_str()) == 0;
  }

  bool operator==(const char *str) const {
    if (str == nullptr)
      return false;
    return std::strcmp(c_str(), str) == 0;
  }

  bool operator<(const String &other) const {
    return std::strcmp(c_str(), other.c_str()) < 0;
  }
  String &operator=(std::string in) {
    m_buffer.reserve(in.size() + 1);
    m_buffer.resize(in.size());
    if (!in.empty()) {
      std::memcpy(m_buffer.data(), in.data(), in.size());
    }
    m_buffer[m_buffer.size()] = '\0';
    return *this;
  }
  explicit operator std::string() const {
    return std::string(m_buffer.data(), m_buffer.size());
  }
};

inline String operator+(String lhs, const char *rhs) {
  lhs += rhs;
  return lhs;
}
inline std::ostream &operator<<(std::ostream &os, const String &str) {
  os << str.c_str();
  return os;
}
// inline String operator""(const char* str, size_t) {
//   return String(str);
// }

} // namespace Kernel
} // namespace Rinegine