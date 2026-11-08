#pragma once


namespace Rinegine {
  namespace Kernel {
    class String {
      Rinegine::Kernel::Array<char> m_buffer;

    public:
      String() {
        m_buffer.push_back('\0');
      }

      String(const char* str) {
        if (str == nullptr) {
          m_buffer.push_back('\0');
        }
        else {
          size_t len = std::strlen(str);
          m_buffer.reserve(len + 1);

          for (size_t i = 0; i < len; ++i) {
            m_buffer.push_back(str[i]);
          }
          m_buffer.push_back('\0');
        }
      }

      const char* c_str() const {
        return m_buffer.data();
      }

      size_t size() const {
        return m_buffer.size() > 0 ? m_buffer.size() - 1 : 0;
      }

      // --- То, чего точно не хватает для базовой работы ---

      // 1. Добавление символов / строк (Конкатенация)
      String& operator+=(const char* str) {
        if (str == nullptr) return *this;

        size_t append_len = std::strlen(str);
        size_t current_len = size();

        m_buffer.reserve(current_len + append_len + 1);

        if (!m_buffer.empty()) {
          m_buffer.pop_back(); // Убираем старый '\0'
        }

        for (size_t i = 0; i < append_len; ++i) {
          m_buffer.push_back(str[i]);
        }
        m_buffer.push_back('\0');
        return *this;
      }

      String& operator+=(const String& other) {
        return *this += other.c_str();
      }

      // 2. Доступ по индексу (чтобы читать отдельные символы)
      char operator[](size_t index) const { return m_buffer[index]; }
      char& operator[](size_t index) { return m_buffer[index]; }

      // 3. Операторы сравнения (нужны для сортировки и поиска)
      bool operator==(const String& other) const {
        if (size() != other.size()) return false;
        return std::strcmp(c_str(), other.c_str()) == 0;
      }

      bool operator==(const char* str) const {
        if (str == nullptr) return false;
        return std::strcmp(c_str(), str) == 0;
      }

      bool operator<(const String& other) const {
        return std::strcmp(c_str(), other.c_str()) < 0;
      }
    };

    // Сложение строк: String s = s1 + " world";
    inline String operator+(String lhs, const char* rhs) {
      lhs += rhs;
      return lhs;
    }
    inline std::ostream& operator<<(std::ostream& os, const String& str) {
      os << str.c_str();
      return os;
    }
  }
}