#pragma once

namespace Rinegine::Kernel {
  inline bool IsColorSupported() noexcept {
#ifdef RG_SYS_LINUX
    if (!isatty(1)) return false;
    const char* term = std::getenv("TERM");
    if (term && std::string_view(term) == "dumb") return false;
    return true;
#elif defined(RG_SYS_WINDOWS)
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return false;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return false;
    return (dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0;
#else
    return false;
#endif
  }
  class Console {
    static bool IsColorSupport;
    static inline char m_buffer[4096];
    static inline size_t m_buffer_index = 0;
  public:
    static int Init() {
#ifdef RG_SYS_WINDOWS
      ::SetConsoleOutputCP(65001);
      ::SetConsoleCP(65001);
      HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
      if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (::GetConsoleMode(hOut, &dwMode)) {
          dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
          ::SetConsoleMode(hOut, dwMode);
        }
      }
#endif
      IsColorSupport = IsColorSupported();
      return 0;
    }
    static int Write(Rinegine::Kernel::String);
    static int WriteLine(Rinegine::Kernel::String);

    static int Write(const char*, size_t);
    static int WriteLine(const char*, size_t);

    static int Write(const char*);
    static int WriteLine(const char*);

  };
}