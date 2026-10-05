#pragma once

namespace Rinegine {
  // Console input
  int TryCatch(std::function<void()> func);


    // INTERPOINT
  namespace Kernel {
    // struct ConfigRunProgram {
    //   Rinegine::Kernel::String path = "err";
    //   bool assinhrone = true;
    //   bool InItFol = false;
    //   bool otherCMD = false;
    // };

    
    int RG_CMD(Rinegine::Kernel::String, bool = true);

    // int InterPoint(int argc, char** argv, int (*own_main)());

    // int InterPoint(int argc, wchar_t** argv, int (*own_main)());
    // DECODE ENCODE UNICODE
#ifdef RG_SYS_WINDOWS
    std::wstring utf8_decode(const Rinegine::Kernel::String& str);
    Rinegine::Kernel::String utf8_encode(const std::wstring& wstr);
#endif //! DECODE ENCODE UNICODE
    namespace Lock {}
    //   void addl(Log::Types type, Rinegine::Kernel::String text, bool print,
    //     Rinegine::Kernel::String file, int line);

    //   void addl(Log::Types type, std::wstring text, bool print,
    //     std::wstring file, int line); //! Lock::addl
    // }
    // rg_to_string
    std::wstring to_stringw(const Rinegine::Kernel::String& str);
    Rinegine::Kernel::String to_stringa(const std::wstring& str);
    std::wstring to_stringw(const std::wstring& str);
    Rinegine::Kernel::String to_stringa(const Rinegine::Kernel::String& str);

    //! rg_to_string

    // POINTs
    // 2D

    // Keys

    int KeyIs(int in, bool sticky);
    int KeyIsPress(int in, bool sticky);
    int TestKeyIs(int in, bool sticky);
    //! Keys
    // SysTime
    class SysTime {
      struct SysTimeVar;
      static SysTimeVar _vars;

    public:
      static void update();
      // W
      static std::wstring YearW();         // [done]
      static std::wstring MonthW();        // [done]
      static std::wstring DayOfWeekW();    // [done]
      static std::wstring DayW();          // [done]
      static std::wstring HourW();         // [done]
      static std::wstring MinuteW();       // [done]
      static std::wstring SecondW();       // [done]
      static std::wstring MillisecondsW(); // [done]
      // A
      static Rinegine::Kernel::String YearA();         // [done]
      static Rinegine::Kernel::String MonthA();        // [done]
      static Rinegine::Kernel::String DayOfWeekA();    // [done]
      static Rinegine::Kernel::String DayA();          // [done]
      static Rinegine::Kernel::String HourA();         // [done]
      static Rinegine::Kernel::String MinuteA();       // [done]
      static Rinegine::Kernel::String SecondA();       // [done]
      static Rinegine::Kernel::String MillisecondsA(); // [done]
      //
      static rg_string
        Year(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        Month(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        DayOfWeek(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        Day(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        Hour(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        Minute(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        Second(); // [outdate], may do some bug. In fact - outdate
      static rg_string
        Milliseconds(); // [outdate], may do some bug. In fact - outdate
    };
    // SetColorCMD

    void SetColorConsole(WORD col);
    void SetTrueColorConsole(Kernel::vec3<uint8_t>,
      Rinegine::CONSOLE_COLOR = Rinegine::CONSOLE_COLOR::C_TEXT);      // [done,exp]
    //! SetColorCMD
    // Substring//TODO!!!!

    bool isSubstringAt(const char& a, const Rinegine::Kernel::String& b);

    bool isSubstringAt(const wchar_t& a, const std::wstring& b);

    bool isSubstringAt(const Rinegine::Kernel::String& a, const Rinegine::Kernel::String& b);

    bool isSubstringAt(const Rinegine::Kernel::String& a, const std::wstring& b);
    //! Substring//TODO!!!!
    // Open
    void Open(Rinegine::Kernel::String path);
    void Open(std::wstring path);
    //! Open
    Rinegine::Kernel::String tolowstr(Rinegine::Kernel::String str);

    std::wstring tolowwstr(std::wstring str);
    //! tolowstr
    struct ConfigRunProgram {
      Rinegine::Kernel::String path = "err";
      bool assinhrone = true;
      bool InItFol = false;
      bool otherCMD = false;
    };
    int RunProgram(ConfigRunProgram conf);

    
  }

}// namespace Rinegine
