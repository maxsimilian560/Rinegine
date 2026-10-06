#pragma once

namespace Rinegine {
  namespace Kernel {
    template <typename T>
    concept std_string_exist = requires { typename std::string; }&& Util::same_as<T, std::string>;


    template <class type = char>
    class Base_String {
      private:
      Rinegine::Kernel::Array<type> m_buffer;

      public:
      type* begin() noexcept { return m_buffer.begin(); }
      const type* begin() const noexcept { return m_buffer.begin(); }

      type* end() noexcept { return m_buffer.end(); }
      const type* end() const noexcept { return m_buffer.end(); }


      int compare(size_t pos, size_t count, const Base_String& other) const {
        size_t this_size = size();

        if (pos > this_size) {
          return 1;
        }
        size_t lhs_len = this_size - pos;
        if (lhs_len > count) {
          lhs_len = count;
        }
        size_t rhs_len = other.size();
        size_t min_len = (lhs_len < rhs_len) ? lhs_len : rhs_len;
        int result = memcmp(c_str() + pos, other.c_str(), min_len);
        if (result != 0) {
          return result;
        }
        if (lhs_len < rhs_len) return -1;
        if (lhs_len > rhs_len) return 1;
        return 0;
      }

      Base_String& erase(size_t index, size_t count) {
        size_t current_size = m_buffer.size();
        if (index >= current_size || count == 0) {
          return *this;
        }
        if (index + count > current_size) {
          count = current_size - index;
        }
        size_t new_size = current_size - count;
        if (index < new_size) {
          memmove(
            m_buffer.data() + index,
            m_buffer.data() + index + count,
            (new_size - index) * sizeof(type)
          );
        }
        m_buffer.resize(new_size);
        m_buffer[new_size] = '\0';
        return *this;
      }



      Base_String() = default;
      Base_String(const type* str) {
        if (str != nullptr) {
          for (size_t i = 0; str[i] != '\0'; ++i) {
            m_buffer.push_back(str[i]);
          }
          m_buffer.reserve(m_buffer.size() + 1);
          m_buffer[m_buffer.size()] = '\0';
        }
      }
      Base_String(size_t count, type chr) {
        if (count > 0) {
          m_buffer.reserve(count + 1);
          m_buffer.resize(count);
          memset(m_buffer.data(), chr, count);
          m_buffer[m_buffer.size()] = '\0';
        }
      }
      template <typename Iterator>
      Base_String(Iterator first, Iterator last) {
        if (first != last && first < last) {
          size_t count = static_cast<size_t>(last - first);
          m_buffer.reserve(count + 1);
          m_buffer.resize(count);
          memcpy(m_buffer.data(), &(*first), count * sizeof(type));
          m_buffer[m_buffer.size()] = '\0';
        }
      }
      template <typename S>
        requires std_string_exist<S>
      Base_String(S in) {
        if (!in.empty()) {
          size_t count = in.size();
          m_buffer.reserve(count + 1);
          m_buffer.resize(count);
          memcpy(m_buffer.data(), &(*in.c_str()), count * sizeof(type));
          m_buffer[m_buffer.size()] = '\0';
        }
      }
      Base_String(const Base_String&) = default;

      const type* c_str() const { return m_buffer.data() ? m_buffer.data() : ""; }
      type* data() { return m_buffer.data(); }

      size_t size() const { return m_buffer.size(); }
      size_t length() const noexcept {
        size_t char_count = 0;
        unsigned char* mm_buffer = (unsigned char*)m_buffer.data();
        for (size_t i = 0; i < m_buffer.size() * sizeof(type) && mm_buffer[i] != '\0'; ++i) {
          if ((static_cast<unsigned char>(mm_buffer[i]) & 0xC0) != 0x80) {
            char_count++;
          }
        }

        return char_count;
      }
      Base_String& operator+=(const type* str) {
        if (str != nullptr) {
          for (size_t i = 0; str[i] != '\0'; ++i) {
            m_buffer.push_back(str[i]);
          }
          m_buffer.reserve(m_buffer.size() + 1);
          m_buffer[m_buffer.size()] = '\0';
        }
        return *this;
      }
      Base_String& operator+=(type ch) {
        m_buffer.reserve(m_buffer.size() + 2);
        m_buffer.push_back(ch);
        m_buffer[m_buffer.size()] = '\0';
        return *this;
      }

      Base_String& operator+=(const Base_String& other) { return *this += other.c_str(); }

      type operator[](size_t index) const { return m_buffer[index]; }
      type& operator[](size_t index) { return m_buffer[index]; }

      bool operator==(const Base_String& other) const {
        if (size() != other.size())
          return false;
        return std::strcmp(c_str(), other.c_str()) == 0;
      }

      bool operator==(const type* str) const {
        if (str == nullptr)
          return false;
        return std::strcmp(c_str(), str) == 0;
      }

      bool operator<(const Base_String& other) const {
        return std::strcmp(c_str(), other.c_str()) < 0;
      }
      Base_String& operator=(Base_String in) {
        m_buffer.reserve(in.size() + 1);
        m_buffer.resize(in.size());
        if (!in.empty()) {
          std::memcpy(m_buffer.data(), in.data(), in.size());
        }
        m_buffer[m_buffer.size()] = '\0';
        return *this;
      }
      operator Base_String() const {
        return Base_String(m_buffer.data(), m_buffer.size());
      }
      bool empty() { return m_buffer.empty(); }
      void reserve(size_t new_capacity) {
        if (new_capacity <= m_buffer.capacity()) {
          return;
        }
        m_buffer.reserve(new_capacity + 1);
        if (m_buffer.size() > 0) {
          m_buffer[m_buffer.size()] = '\0';
        }
      }
      void clear() {
        m_buffer.clear();
      }
    };

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    template <typename T>
    concept Base_String_Compare_Add = requires(T t, Base_String<char> str) {
      { t += str } -> Util::convertible_to<Base_String<char>>;
    };
    template <typename T>
    concept Base_String_Compare_Convert = Util::convertible_to<T, Base_String<char>>;

    template <class type = char, Base_String_Compare_Add in1, class in2>
    inline Base_String<type> operator+(in1 lhs, in2 rhs) {
      lhs += rhs;
      return lhs;
    }

    template <class type = char, Base_String_Compare_Convert in1, class in2>
      requires (!Base_String_Compare_Add<in1>)
    inline Base_String<type> operator+(in1 lhs, in2 rhs) {
      Base_String<type> result(lhs);
      result += rhs;
      return result;
    }

    template <class type = char>
    inline std::ostream& operator<<(std::ostream& os, const Base_String<type>& str) {
      os << str.c_str();
      return os;
    }
    template <class type = char, typename IntegerType>
    inline Base_String<type> to_string(IntegerType value) {
      if (value == 0) {
        return Base_String<type>("0");
      }

      Base_String<type> result;
      bool is_negative = false;
      uint64_t absolute_value = 0;

      if constexpr (std::is_signed_v<IntegerType>) {
        if (value < 0) {
          is_negative = true;
          absolute_value = static_cast<uint64_t>(-(value + 1)) + 1;
        }
        else {
          absolute_value = static_cast<uint64_t>(value);
        }
      }
      else {
        absolute_value = static_cast<uint64_t>(value);
      }

      type buffer[32];
      size_t count = 0;

      while (absolute_value > 0) {
        buffer[count++] = static_cast<type>('0' + (absolute_value % 10));
        absolute_value /= 10;
      }

      if (is_negative) {
        buffer[count++] = static_cast<type>('-');
      }

      for (size_t i = count; i > 0; --i) {
        result += buffer[i - 1];
      }

      return result;
    }

    // typedef Base_String<char> String;
    
    
    

  } // namespace Kernel
} // namespace Rinegine