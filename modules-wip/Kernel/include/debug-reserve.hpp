#pragma once
// #include "../string/set.hpp"
/**
 * @file
 * @brief Implementing debugging features
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */



#ifdef RGLOCK_DEBUG
#define RGLOCK_DEBUG_INLINE __FILE__, __LINE__
#else
#define RGLOCK_DEBUG_INLINE RG_HERE_FILE_NAME, -1
#endif

namespace Rinegine {
  namespace Kernel {
    class Debug {       // [done]
      struct DebugVars; // [done]


      public:
      static uint8 Log_Level;
      Debug();                                      //  [done]
      Debug(Rinegine::Kernel::String);              //  [done]
      static void init();                           //  [done]
      static void init(Rinegine::Kernel::String);   //  [done]
      static void open_log_after_error(bool);       //  [done]
      static void open_shell(bool);                 //  [done] (same as open_log_after_error)
      static Rinegine::Kernel::String log_path();   //  [done]
      static void update();                         //  [done]
      static void stop() __attribute__((noreturn)); //  [done]
      static void no_close();                       //  [done]
      static DebugVars& DebugVars_safe_get();       //  [done]
      ~Debug();                                     //  [done]

      static void add(const Rinegine::Kernel::String&, Log::Types, bool, const Rinegine::Kernel::String&, int);   //[done]
      static void addl(const Rinegine::Kernel::String&, Log::Types, bool, const Rinegine::Kernel::String&, int);  //[done]

      static void add(const char*, Log::Types, bool, const char*, int);                             //[done]
      static void addl(const char*, Log::Types, bool, const char*, int);                            //[done]

      static void add(StdStringViewLike, Log::Types, bool, const char*, int);                             //[done]
      static void addl(StdStringViewLike, Log::Types, bool, const char*, int);                            //[done]

      template <std_string_like S>
      static void addl(S msg, Log::Types type, bool a, const char* b, int c) {
        addl(StdStringViewLike({ ._c_str = msg.c_str(),._size = msg.size(),._empty = msg.empty() }), type, a, b, c);
      }
      template <std_string_like S>
      static void add(S msg, Log::Types type, bool a, const char* b, int c) {
        add(StdStringViewLike({ ._c_str = msg.c_str(),._size = msg.size(),._empty = msg.empty() }), type, a, b, c);
      }
      // static void add(std::string, Log::Types, bool, const char*, int);                             //[done]
      // static void addl(std::string, Log::Types, bool, const char*, int);                            //[done]

    }; // [done]
  } // namespace Kernel
} // namespace Rinegine
