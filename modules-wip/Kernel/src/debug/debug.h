#pragma once

#ifdef RGLOCK_DEBUG
#define RGLOCK_DEBUG_INLINE __FILE__, __LINE__
#else
#define RGLOCK_DEBUG_INLINE RG_HERE_FILE_NAME, -1
#endif

constexpr const rg_char* const RG_TYPE_DEBUG_STRING[]{ RG_L "Critical Error", RG_L "Error",
                                       RG_L "Warning",        RG_L "Info",
                                       RG_L "Debug",          RG_L "Memory" };

namespace Rinegine::Kernel {
#ifdef RG_SYS_WINDOWS
  inline void SetColorTCMD(WORD col) { // [done,exp]
    static HANDLE HandleMainConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(HandleMainConsole, col);
  }
  
  
  
  
    
    
    
#endif
  uint8_t Debug::Log_Level = 4;
  struct Debug::DebugVars {
    std::ofstream debug;
    rg_string path;
    rg_string textErr;
    bool INIT = false, ENDINIT = false, PREINIT = false, OPEN_SHELL = 1;
    bool noclose;
    Log::Types oldType;
    ~DebugVars() = default;
  };
  inline Debug::DebugVars& Debug::DebugVars_safe_get() {
    static DebugVars instance;
    return instance;
  }
  
  
  Debug::Debug() { init(RG_L "Logs"); }
  Debug::Debug(rg_string pat) { init(pat); }
  // init
  void Debug::init() {
    
    if (DebugVars_safe_get().INIT)
      return;
    init(RG_L "Logs");
  }
  void Debug::init(rg_string pat) {
    if (DebugVars_safe_get().INIT)
      return;
    DebugVars_safe_get().INIT = true;
    rg_string pathFol = Main::Folder + pat;
    if (!CreateFolder(pathFol)) {
      
      RG_LOG_WARNING("Log folder missing, folder creation error");
      pathFol.clear();
    };
    SysTime::update();
    DebugVars_safe_get().path = pathFol;
    if (!pathFol.empty()) {
      if (((pathFol[pathFol.size() - 1] != '\\') &&
        (pathFol[pathFol.size() - 1] != '/'))) {
        DebugVars_safe_get().path += RG_L "/";
      }
    }
    DebugVars_safe_get().path +=
      RG_L "log_" + SysTime::Year() + RG_L "-" + SysTime::Month() + RG_L "-" +
      SysTime::Day() + RG_L "_" + SysTime::Hour() + RG_L "-" +
      SysTime::Minute() + RG_L "-" + SysTime::Second() + RG_L ".txt";

    
    
    RG_LOG_LOCK_INFO("Log path: " + (DebugVars_safe_get().path))
      
      
      
  }
  
  void Debug::open_log_after_error(bool i) {
    DebugVars_safe_get().OPEN_SHELL = i;
  }
  void Debug::open_shell(bool i) { DebugVars_safe_get().OPEN_SHELL = i; }
  
  rg_string Debug::log_path() { return DebugVars_safe_get().path; }
  
  void Debug::update() {
    if (DebugVars_safe_get().textErr.empty())
      return;
    if (!DebugVars_safe_get().INIT)
      init();
    DebugVars_safe_get().debug.open(DebugVars_safe_get().path.c_str(), std::ios::app);
    if (!DebugVars_safe_get().debug.is_open()) {
      
      RG_LOG_LOCK_WARNING("Error opening log file");
      return;
    }

    DebugVars_safe_get().debug << to_stringa(DebugVars_safe_get().textErr);
    DebugVars_safe_get().debug.close();
    DebugVars_safe_get().textErr.clear();
  }
  
  void Debug::stop() {
    if (!DebugVars_safe_get().INIT)
      init();
    if (DebugVars_safe_get().OPEN_SHELL) {
      
      RG_LOG_LOCK_INFO("Open: " + (DebugVars_safe_get().path));
      update();
      Open(DebugVars_safe_get().path);
    }
    else
      update();
    throw(Error::RG_OWN_ERROR);
    __builtin_unreachable();
  }
  
  void Debug::no_close() { DebugVars_safe_get().noclose = 1; }
  
  Debug::~Debug() {
    
    
    RG_LOG_LOCK_DEBUG("Debug was destructed");
    if (DebugVars_safe_get().textErr.size() > 0)
      update();
  }
  
  
  
  
  void Debug::add(rg_string tex, Log::Types type, [[maybe_unused]] bool print, rg_string file, int line) {
    if (!RINEGINE_IS_INIT) {
      
      throw "Rinegine isn't init\n";
    }
    if (type > Log_Level)
      return;
    rg_string text;
    if (DebugVars_safe_get().oldType != type)
      text += rg_char(10);
    DebugVars_safe_get().oldType = type;

    SysTime::update();
    text += "[ " + SysTime::Hour() + ":" + SysTime::Minute() + ":" + SysTime::Second() + "." + SysTime::Milliseconds() + " | " + file + (((line >= 0) ? (line >= 0 ? (Rinegine::Kernel::String(":") + Kernel::to_string(line)) : "") : "")) + " ] " + RG_TYPE_DEBUG_STRING[type] + "\n\t" + tex;

#ifdef RG_DEBUG
    if (print) {
#ifdef RG_SYS_WINDOWS
      if (type ==
        Log::CRITICAL)   // todo add color enum for windows like on the linux
        SetColorTCMD(0x5); 
      if (type == Log::ERR)
        SetColorTCMD(0x4); 
      if (type == Log::WARNING)
        SetColorTCMD(0xe); 
      if (type == Log::INFO)
        SetColorTCMD(0x8); 
      if (type == Log::DEBUG)
        SetColorTCMD(0xf); 
      if (type == Log::MEM)
        SetColorTCMD(0xf); 
#elif defined(RG_SYS_LINUX)
      if (type == Log::CRITICAL) {
        SetColorConsole(CONSOLE_COLOR::C_WHITE + CONSOLE_COLOR::C_TEXT);
        SetColorConsole(CONSOLE_COLOR::C_RED + CONSOLE_COLOR::C_BACKGROUND);
      }
      if (type == Log::ERR)
        SetColorConsole(CONSOLE_COLOR::C_RED + CONSOLE_COLOR::C_TEXT);
      if (type == Log::WARNING)
        SetColorConsole(CONSOLE_COLOR::C_YELLOW + CONSOLE_COLOR::C_TEXT);
      if (type == Log::INFO)
        SetColorConsole(CONSOLE_COLOR::C_WHITE + CONSOLE_COLOR::C_TEXT);
      if (type == Log::DEBUG)
        SetColorConsole(CONSOLE_COLOR::C_BRIGHT + CONSOLE_COLOR::C_BLACK +
          CONSOLE_COLOR::C_TEXT);
      if (type == Log::MEM)
        SetColorConsole(CONSOLE_COLOR::C_BLUE + CONSOLE_COLOR::C_TEXT);
#endif
      rg_cout << text;
#ifdef RG_SYS_WINDOWS
      SetColorTCMD(7);
#else
      SetColorConsole(0);
#endif
    }
#endif

#ifdef RG_DEBUG_ALWAYS_UPDATE
    Debug::update();
#endif
    if (type == Log::CRITICAL && !DebugVars_safe_get().noclose) {
      Debug::stop();
      __builtin_unreachable();
    }
  }


  void Debug::addl(String text, Log::Types type, bool print,
    String file, int line) {
    add(text + rg_char(10), type, print, file, line);
  }

  void Debug::add(const char* text, Log::Types type, bool print, const char* file, int line) {
    add(String(text), type, print, String(file), line);
  }

  void Debug::addl(const char* text, Log::Types type, bool print, const char* file, int line) {
    addl(String(text), type, print, String(file), line);
  }
  void Debug::add(std::string text, Log::Types type, bool print, const char* file, int line) {
    add(String(text), type, print, String(file), line);
  }

  void Debug::addl(std::string text, Log::Types type, bool print, const char* file, int line) {
    addl(String(text), type, print, String(file), line);
  }

#ifdef RG_SYS_WINDOWS
  rg_string GetLastErrorString(DWORD errorCode) {
    if (errorCode == 0)
      return rg_to_string(L"Нет ошибки");

    LPWSTR buffer = nullptr;
    FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
      FORMAT_MESSAGE_IGNORE_INSERTS,
      nullptr, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      (LPWSTR)&buffer, 0, nullptr);

    std::wstring result = buffer ? buffer : L"Неизвестная ошибка";
    LocalFree(buffer);
    return rg_to_string(result);
  }
#else
  rg_string GetLastErrorString(DWORD errorCode) {
    if (errorCode == 0)
      return "No error";

    char buffer[1024];
    strerror_r((int)errorCode, buffer, sizeof(buffer));
    return Rinegine::Kernel::String(buffer);
  }
#endif

} // namespace Rinegine
