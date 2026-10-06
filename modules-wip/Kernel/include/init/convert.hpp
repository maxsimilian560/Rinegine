#pragma once

#if defined(__SSE4_1__)
#include <smmintrin.h>
#endif

constexpr unsigned int CP_UTF8 = 65001;

static const uint8_t utf8d[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    8,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    0xa,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x4,0x3,0x3,
    0xb,0x6,0x6,0x6,0x5,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8
};

namespace Rinegine {
  namespace Kernel {
    template <typename T>
    concept con_any_string = requires(const T & str) {
      { str.data() } -> Util::same_as<const typename T::value_type*>;
      { str.c_str() } -> Util::same_as<const typename T::value_type*>;
      { str.size() } -> Util::convertible_to<size_t>;
      { str.length() } -> Util::convertible_to<size_t>;
      { str.empty() } -> Util::convertible_to<bool>;
    };
    template <typename T>
    concept con_wstring = con_any_string<T> && Util::same_as<typename T::value_type, wchar_t>;

    template <typename T>
    concept con_string = con_any_string<T> && Util::same_as<typename T::value_type, char>;

    namespace Converter {
      static int multi_byte_to_wide_char(
        unsigned int code_page, [[maybe_unused]] unsigned long flags,
        const char* mb_str, int cb_mb,
        char16_t* wc_str, int cch_wc
      ) {
        if (!mb_str || cb_mb == 0 || cch_wc < 0 || code_page != CP_UTF8) return 0;

        bool process_until_zero = (cb_mb < 0);
        size_t input_len = process_until_zero ? 0 : static_cast<size_t>(cb_mb);

        size_t count = 0;
        size_t i = 0;


#if defined(__SSE4_1__)


        while ((process_until_zero || (i + 16 <= input_len)) && (!wc_str || static_cast<int>(count + 16) <= cch_wc)) {
          if (process_until_zero && mb_str[i] == '\0') break;


          __m128i chunk = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&mb_str[i]));


          int mask = _mm_movemask_epi8(chunk);


          if (process_until_zero) {
            __m128i zero_cmp = _mm_cmpeq_epi8(chunk, _mm_setzero_si128());
            int zero_mask = _mm_movemask_epi8(zero_cmp);
            if (zero_mask != 0) {
              break;
            }
          }

          if (mask == 0) {

            if (wc_str) {

              __m128i low = _mm_cvtepu8_epi16(chunk);
              _mm_storeu_si128(reinterpret_cast<__m128i*>(&wc_str[count]), low);


              __m128i high = _mm_cvtepu8_epi16(_mm_srli_si128(chunk, 8));
              _mm_storeu_si128(reinterpret_cast<__m128i*>(&wc_str[count + 8]), high);
            }
            i += 16;
            count += 16;
          }
          else {
            break;
          }
        }
#endif


        uint32_t state = 0;
        uint32_t cp = 0;

        while (true) {
          if (process_until_zero) {
            if (mb_str[i] == '\0') break;
          }
          else {
            if (i >= input_len) break;
          }

          uint8_t byte = static_cast<uint8_t>(mb_str[i++]);

          if (state == 0 && byte < 0x80) {
            if (wc_str && static_cast<int>(count) < cch_wc) wc_str[count] = static_cast<char16_t>(byte);
            count++;
            continue;
          }

          uint8_t type = utf8d[byte];
          cp = (state != 0) ? (byte & 0x3FU) | (cp << 6) : (0xFFU >> type) & byte;
          state = utf8d[256 + state * 16 + type];

          if (state == 0) {
            if (cp <= 0xFFFF) {
              if (wc_str && static_cast<int>(count) < cch_wc) wc_str[count] = static_cast<char16_t>(cp);
              count++;
            }
            else if (cp <= 0x10FFFF) {
              cp -= 0x10000;
              if (wc_str && static_cast<int>(count + 1) < cch_wc) {
                wc_str[count] = static_cast<char16_t>((cp >> 10) + 0xD800);
                wc_str[count + 1] = static_cast<char16_t>((cp & 0x3FF) + 0xDC00);
              }
              count += 2;
            }
          }
          else if (state == 1) {
            state = 0;
          }
        }

        if (process_until_zero) {
          if (wc_str && static_cast<int>(count) < cch_wc) wc_str[count] = 0;
          count++;
        }

        if (cch_wc > 0 && static_cast<int>(count) > cch_wc) return 0;
        return static_cast<int>(count);
      }


      static int wide_char_to_multi_byte(
        unsigned int code_page, [[maybe_unused]] unsigned long flags,
        const char16_t* wc_str, int cch_wc,
        char* mb_str, int cb_mb,
        const char* default_char, int* used_default_char
      ) {
        if (!wc_str || cch_wc == 0 || cb_mb < 0 || code_page != CP_UTF8) return 0;
        if (default_char != nullptr || used_default_char != nullptr) return 0;

        bool process_until_zero = (cch_wc < 0);
        size_t input_len = process_until_zero ? 0 : static_cast<size_t>(cch_wc);

        size_t count = 0;
        size_t i = 0;


#if defined(__SSE4_1__)
        while ((process_until_zero || (i + 16 <= input_len)) && (!mb_str || static_cast<int>(count + 16) <= cb_mb)) {
          if (process_until_zero && wc_str[i] == 0) break;


          __m128i chunk1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&wc_str[i]));
          __m128i chunk2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&wc_str[i + 8]));



          __m128i packed = _mm_packus_epi16(chunk1, chunk2);


          __m128i ascii_mask1 = _mm_cmpeq_epi16(_mm_andnot_si128(_mm_set1_epi16(0x00FF), chunk1), _mm_setzero_si128());
          __m128i ascii_mask2 = _mm_cmpeq_epi16(_mm_andnot_si128(_mm_set1_epi16(0x00FF), chunk2), _mm_setzero_si128());

          int m1 = _mm_movemask_epi8(ascii_mask1);
          int m2 = _mm_movemask_epi8(ascii_mask2);


          if (process_until_zero) {
            __m128i zero1 = _mm_cmpeq_epi16(chunk1, _mm_setzero_si128());
            __m128i zero2 = _mm_cmpeq_epi16(chunk2, _mm_setzero_si128());
            if (_mm_movemask_epi8(zero1) != 0 || _mm_movemask_epi8(zero2) != 0) {
              break;
            }
          }

          if (m1 == 0xFFFF && m2 == 0xFFFF) {

            if (mb_str) {
              _mm_storeu_si128(reinterpret_cast<__m128i*>(&mb_str[count]), packed);
            }
            i += 16;
            count += 16;
          }
          else {
            break;
          }
        }
#endif


        while (true) {
          if (process_until_zero) {
            if (wc_str[i] == 0) break;
          }
          else {
            if (i >= input_len) break;
          }

          uint32_t cp = wc_str[i++];

          if (cp >= 0xD800 && cp <= 0xDBFF) {
            if (process_until_zero || i < input_len) {
              char16_t low = wc_str[i];
              if (low >= 0xDC00 && low <= 0xDFFF) {
                cp = 0x10000 + (((cp - 0xD800) << 10) | (low - 0xDC00));
                i++;
              }
            }
          }

          if (cp <= 0x7F) {
            if (mb_str && static_cast<int>(count) < cb_mb) mb_str[count] = static_cast<char>(cp);
            count++;
          }
          else if (cp <= 0x7FF) {
            if (mb_str && static_cast<int>(count + 1) < cb_mb) {
              mb_str[count] = static_cast<char>(0xC0 | (cp >> 6));
              mb_str[count + 1] = static_cast<char>(0x80 | (cp & 0x3F));
            }
            count += 2;
          }
          else if (cp <= 0xFFFF) {
            if (mb_str && static_cast<int>(count + 2) < cb_mb) {
              mb_str[count] = static_cast<char>(0xE0 | (cp >> 12));
              mb_str[count + 1] = static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
              mb_str[count + 2] = static_cast<char>(0x80 | (cp & 0x3F));
            }
            count += 3;
          }
          else if (cp <= 0x10FFFF) {
            if (mb_str && static_cast<int>(count + 3) < cb_mb) {
              mb_str[count] = static_cast<char>(0xF0 | (cp >> 18));
              mb_str[count + 1] = static_cast<char>(0x80 | ((cp >> 12) & 0x3F));
              mb_str[count + 2] = static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
              mb_str[count + 3] = static_cast<char>(0x80 | (cp & 0x3F));
            }
            count += 4;
          }
        }

        if (process_until_zero) {
          if (mb_str && static_cast<int>(count) < cb_mb) mb_str[count] = '\0';
          count++;
        }

        if (cb_mb > 0 && static_cast<int>(count) > cb_mb) return 0;
        return static_cast<int>(count);
      }

#ifdef RG_SYS_WINDOWS
      inline auto* base_utf8_to_utf16 = MultiByteToWideChar;
      inline auto* base_utf16_to_utf8 = WideCharToMultiByte;
#else
      inline auto* base_utf8_to_utf16 = multi_byte_to_wide_char;
      inline auto* base_utf16_to_utf8 = wide_char_to_multi_byte;
#endif
      template <con_string Tin, con_wstring Tout>
      Tout utf8_to_utf16(const Tin& utf8_str) {
        if (utf8_str.empty()) {
          return Tout();
        }
        int size_needed = MultiByteToWideChar(
          CP_UTF8, 0,
          utf8_str.data(), (int)utf8_str.size(),
          nullptr, 0
        );
        if (size_needed <= 0) {
          return Tout();
        }
        Tout utf16_str(size_needed, 0);
        MultiByteToWideChar(
          CP_UTF8, 0,
          utf8_str.data(), (int)utf8_str.size(),
          utf16_str.data(), size_needed
        );
        return utf16_str;
      }
      template <con_wstring Tin, con_string Tout>
      Tout utf16_to_utf8(const Tin& utf16_str) {
        if (utf16_str.empty()) return Tout();
        int size_needed = WideCharToMultiByte(
          CP_UTF8, 0,
          utf16_str.data(), (int)utf16_str.size(),
          nullptr, 0, nullptr, nullptr
        );
        if (size_needed <= 0) return Tout();
        Tout utf8_str(size_needed, 0);
        WideCharToMultiByte(
          CP_UTF8, 0,
          utf16_str.data(), (int)utf16_str.size(),
          utf8_str.data(), size_needed, nullptr, nullptr
        );
        return utf8_str;
      }
    };
  }
}