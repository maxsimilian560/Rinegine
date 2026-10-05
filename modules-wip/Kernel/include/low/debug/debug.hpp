#pragma once

#ifdef RGLOCK_DEBUG
#define RGLOCK_DEBUG_INLINE __FILE__, __LINE__
#else
#define RGLOCK_DEBUG_INLINE RG_HERE_FILE_NAME, -1
#endif

namespace Rinegine {
  namespace Kernel {

    class Debug {       // [done]
      struct DebugVars; // [done]
      // static DebugVars _vars; // [done]

      public:
      static uint8 Log_Level;
      Debug();                                      // [done]
      Debug(rg_string);                             // [done]
      static void init();                           // [done]
      static void init(rg_string);                  // [done]
      static void open_log_after_error(bool);       // [done]
      static void open_shell(bool);                 // [done] (same as open_log_after_error)
      static rg_string log_path();                  // [done]
      static void update();                         // [done]
      static void stop() __attribute__((noreturn)); // [done]
      static void no_close();                       // [done]
      static DebugVars& DebugVars_safe_get();       //[done]
      ~Debug();                                     // [done]

      static void add(String, Log::Types, bool, String, int); //[done]
      static void addl(String, Log::Types, bool, String, int);//[done]

      static void add(const char*, Log::Types, bool, const char*, int);
      static void addl(const char*, Log::Types, bool, const char*, int);

      static void add(std::string, Log::Types, bool, const char*, int);
      static void addl(std::string, Log::Types, bool, const char*, int);
      // //*special add/addl for dif os
      // static void add(String, Log::Types, bool, String, int); // [done]

      // template <class string1, class string2>
      // static void add(string1, Log::Types, bool, string2, int);   // [done]

      // static void addl(Log::Types, String, bool, String, int); // [done]

      // static void addl(const char* in, Log::Types type, bool print, const char* file, int line){

      // }

      // static void add(const char* in, Log::Types type, bool print, const char* file, int line){

      // }
    }; // [done]
  } // namespace Kernel
} // namespace Rinegine
