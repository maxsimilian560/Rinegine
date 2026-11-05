#pragma once
/**
 * @file
 * @brief The basic definition of a low-level kernel submodule.
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */



namespace Rinegine {
  int TryCatch(std::function<void()> func);
  namespace Kernel {
    
    int RG_CMD(Rinegine::Kernel::String, bool = true);
    
#ifdef RG_SYS_WINDOWS
    std::wstring utf8_decode(const Rinegine::Kernel::String& str);
    Rinegine::Kernel::String utf8_encode(const std::wstring& wstr);
#endif //! DECODE ENCODE UNICODE
    namespace Lock {}
    

    int KeyIs(int in, bool sticky);
    int KeyIsPress(int in, bool sticky);
    int TestKeyIs(int in, bool sticky);
    //! Keys
    
    class SysTime {
      struct SysTimeVar;
      static SysTimeVar _vars;

    public:
      static void update();
      static Rinegine::Kernel::String Year();         // [done]
      static Rinegine::Kernel::String Month();        // [done]
      static Rinegine::Kernel::String DayOfWeek();    // [done]
      static Rinegine::Kernel::String Day();          // [done]
      static Rinegine::Kernel::String Hour();         // [done]
      static Rinegine::Kernel::String Minute();       // [done]
      static Rinegine::Kernel::String Second();       // [done]
      static Rinegine::Kernel::String Milliseconds(); // [done]
    };
    
    void SetColorConsole(WORD col);
    void SetTrueColorConsole(Kernel::vec3<uint8_t>,
      Rinegine::CONSOLE_COLOR = Rinegine::CONSOLE_COLOR::C_TEXT);      // [done,exp]
    //! SetColorCMD
    
    bool isSubstringAt(const char& a, const Rinegine::Kernel::String& b);
    bool isSubstringAt(const Rinegine::Kernel::String& a, const Rinegine::Kernel::String& b);
    //! Substring//TODO!!!!
    void Open(Rinegine::Kernel::String path);
    //! Open
    Rinegine::Kernel::String tolowstr(Rinegine::Kernel::String str);
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
