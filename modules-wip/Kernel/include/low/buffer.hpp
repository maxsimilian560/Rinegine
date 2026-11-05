
#pragma once
/**
 * @file
 * @brief Implementation of methods for converting wide (UTF-16) strings to Unicode (UTF-8) strings and vice versa.
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


#include <format>

namespace Rinegine {
  namespace Kernel {
    template <size_t MAX_CAPACITY>
    struct Buffer {
      BYTE buf[MAX_CAPACITY];
      size_t current_size = 0;

      Buffer() {
        buf[0] = 0;
      }

      template <typename... Args>
      Buffer(std::format_string<Args...> fmt, Args&&... args) {
        auto [out, count] = std::format_to_n(reinterpret_cast<char*>(buf), MAX_CAPACITY - 1, fmt, std::forward<Args>(args)...);
        *out = '\0';
        current_size = (static_cast<size_t>(count) < MAX_CAPACITY - 1) ? static_cast<size_t>(count) : (MAX_CAPACITY - 1);
      }

      void resize(size_t new_size) {
        if (new_size >= MAX_CAPACITY) {
          RG_LOG_LOCK_CRITICAL("Buffer: out of bounds");
        }
        current_size = new_size;
        buf[current_size] = 0;
      }

      const char* c_str() const { return reinterpret_cast<const char*>(buf); }
      const BYTE* data() const { return buf; }
      BYTE* data() { return buf; }
      size_t size() const { return current_size; }
      bool empty() const { return current_size == 0; }

      operator const char* () const {
        return reinterpret_cast<const char*>(buf);
      }
      operator char* () {
        return reinterpret_cast<char*>(buf);
      }
      operator void* () {
        return (void*)buf;
      }
      operator const void* () const {
        return (const void*)buf;
      }
      operator BYTE* () {
        return buf;
      }
      operator const BYTE* () const {
        return buf;
      }
    };
  }
}

