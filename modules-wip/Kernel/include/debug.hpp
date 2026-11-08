#pragma once


typedef short SHORT;







class LogPost {
  template<size_t log_size, size_t label_size>
  struct LogUnit {
    char text[log_size];
    char file[label_size];

  };
};



//TODO^description


#define GET_MACRO(_1, _2, NAME, ...) NAME

#define RG_LOG_FATAL(...)                                                      \
  GET_MACRO(__VA_ARGS__, RG_LOG_FATAL_2, RG_LOG_FATAL_1)(__VA_ARGS__)

#define RG_LOG_CRITICAL(...)                                                   \
  GET_MACRO(__VA_ARGS__, RG_LOG_FATAL_2, RG_LOG_FATAL_1)(__VA_ARGS__) 

#define RG_LOG_FATAL_2(__msg, ...)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::CRITICAL,  __VA_ARGS__,   \
                                __FILE__, __LINE__)

#define RG_LOG_FATAL_1(__msg)                                                  \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::CRITICAL,  true,          \
                                __FILE__, __LINE__)
#ifndef RGLOCK_DEBUG
#define RG_LOG_LOCK_FATAL(...)                                                 \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_FATAL_2, RG_LOG_LOCK_FATAL_1)(__VA_ARGS__)

#define RG_LOG_LOCK_CRITICAL(...)                                              \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_FATAL_2, RG_LOG_LOCK_FATAL_1)(__VA_ARGS__)

#define RG_LOG_LOCK_FATAL_2(__msg, ...)                                        \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::CRITICAL,  __VA_ARGS__,   \
                                RG_HERE_FILE_NAME, -1)

#define RG_LOG_LOCK_FATAL_1(__msg)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::CRITICAL,  true,          \
                                RG_HERE_FILE_NAME, -1)

#else
#define RG_LOG_LOCK_FATAL(...)                                                 \
  GET_MACRO(__VA_ARGS__, RG_LOG_FATAL_2, RG_LOG_FATAL_1)(__VA_ARGS__)

#define RG_LOG_LOCK_CRITICAL(...)                                              \
  GET_MACRO(__VA_ARGS__, RG_LOG_FATAL_2, RG_LOG_FATAL_1)(__VA_ARGS__)

#define RG_LOG_LOCK_FATAL_2(__msg, ...)                                        \
  Rinegine::Kernel::Debug::addl(__msg, Rinegine::Log::CRITICAL,  __VA_ARGS__,   \
                                __FILE__, __LINE__)

#define RG_LOG_LOCK_FATAL_1(__msg)                                             \
  Rinegine::Kernel::Debug::addl(__msg, Rinegine::Log::CRITICAL,  true,          \
                                __FILE__, __LINE__)
#endif


#ifdef RG_DEBUG
/**
 * @def GET_MACRO(_1, _2, NAME, ...)
 * @brief Helper macro for function overloading based on number of arguments.
 * @internal Used by logging macros to select 1-arg or 2-arg version.
 * @ingroup logging
 */

 /**
  * @def RG_LOG_DEBUG(...)
  * @brief Logs a debug message. Accepts 1 or 2 arguments.
  * @param __msg Message Rinegine::Kernel::String.
  * @param ... Optional additional arguments (formatted).
  * @ingroup logging
  */
#define RG_LOG_DEBUG(...)                                                      \
  GET_MACRO(__VA_ARGS__, RG_LOG_DEBUG_2, RG_LOG_DEBUG_1)(__VA_ARGS__)

  /**
   * @def RG_LOG_INFO(...)
   * @brief Logs an info message.
   * @ingroup logging
   */
#define RG_LOG_INFO(...)                                                       \
  GET_MACRO(__VA_ARGS__, RG_LOG_INFO_2, RG_LOG_INFO_1)(__VA_ARGS__)

   /**
    * @def RG_LOG_WARN(...) / RG_LOG_WARNING(...)
    * @brief Logs a warning message. Synonyms.
    * @ingroup logging
    */
#define RG_LOG_WARN(...)                                                       \
  GET_MACRO(__VA_ARGS__, RG_LOG_WARN_2, RG_LOG_WARN_1)(__VA_ARGS__)
#define RG_LOG_WARNING(...)                                                    \
  GET_MACRO(__VA_ARGS__, RG_LOG_WARN_2, RG_LOG_WARN_1)(__VA_ARGS__)

    /**
     * @def RG_LOG_ERROR(...)
     * @brief Logs an error message.
     * @ingroup logging
     */
#define RG_LOG_ERROR(...)                                                      \
  GET_MACRO(__VA_ARGS__, RG_LOG_ERROR_2, RG_LOG_ERROR_1)(__VA_ARGS__)

     /**
      * @def RG_LOG_FATAL(...) / RG_LOG_CRITICAL(...)
      * @brief Logs a critical/fatal message.
      * @ingroup logging
      */

      /**
       * @def RG_LOG_MEM(...)
       * @brief Logs memory-related event.
       * @ingroup logging
       */
#define RG_LOG_MEM(...)                                                        \
  GET_MACRO(__VA_ARGS__, RG_LOG_MEM_2, RG_LOG_MEM_1)(__VA_ARGS__)


       /**
        * @def RG_LOG_DEBUG_2(__msg, ...)
        * @brief 2-argument debug log with formatting.
        * @ingroup logging
        */
#define RG_LOG_DEBUG_2(__msg, ...)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::DEBUG,  __VA_ARGS__,      \
                                __FILE__, __LINE__)
#define RG_LOG_INFO_2(__msg, ...)                                              \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::INFO,  __VA_ARGS__,       \
                                __FILE__, __LINE__)
#define RG_LOG_WARN_2(__msg, ...)                                              \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::WARNING,  __VA_ARGS__,    \
                                __FILE__, __LINE__)
#define RG_LOG_ERROR_2(__msg, ...)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::ERR,  __VA_ARGS__,        \
                                __FILE__, __LINE__)
#define RG_LOG_MEM_2(__msg, ...)                                               \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::MEM,  __VA_ARGS__,        \
                                __FILE__, __LINE__)

#define RG_LOG_DEBUG_1(__msg)                                                  \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::DEBUG,  true, __FILE__,   \
                                __LINE__)
#define RG_LOG_INFO_1(__msg)                                                   \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::INFO,  true, __FILE__,    \
                                __LINE__)
#define RG_LOG_WARN_1(__msg)                                                   \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::WARNING,  true, __FILE__, \
                                __LINE__)
#define RG_LOG_ERROR_1(__msg)                                                  \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::ERR,  true, __FILE__,     \
                                __LINE__)
#define RG_LOG_MEM_1(__msg)                                                    \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::MEM,  true, __FILE__,     \
                                __LINE__)

#ifndef RGLOCK_DEBUG

#define RG_LOG_LOCK_DEBUG(...)                                                 \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_DEBUG_2, RG_LOG_LOCK_DEBUG_1)(__VA_ARGS__)
#define RG_LOG_LOCK_INFO(...)                                                  \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_INFO_2, RG_LOG_LOCK_INFO_1)(__VA_ARGS__)
#define RG_LOG_LOCK_WARN(...)                                                  \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_WARN_2, RG_LOG_LOCK_WARN_1)(__VA_ARGS__)
#define RG_LOG_LOCK_WARNING(...)                                               \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_WARN_2, RG_LOG_LOCK_WARN_1)(__VA_ARGS__)
#define RG_LOG_LOCK_ERROR(...)                                                 \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_ERROR_2, RG_LOG_LOCK_ERROR_1)(__VA_ARGS__)
#define RG_LOG_LOCK_MEM(...)                                                   \
  GET_MACRO(__VA_ARGS__, RG_LOG_LOCK_MEM_2, RG_LOG_LOCK_MEM_1)(__VA_ARGS__)

#define RG_LOG_LOCK_DEBUG_2(__msg, ...)                                        \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::DEBUG,  __VA_ARGS__,      \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_INFO_2(__msg, ...)                                         \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::INFO,  __VA_ARGS__,       \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_WARN_2(__msg, ...)                                         \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::WARNING,  __VA_ARGS__,    \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_ERROR_2(__msg, ...)                                        \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::ERR,  __VA_ARGS__,        \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_MEM_2(__msg, ...)                                          \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::MEM,  __VA_ARGS__,        \
                                RG_HERE_FILE_NAME, -1)

#define RG_LOG_LOCK_DEBUG_1(__msg)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::DEBUG,  true,             \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_INFO_1(__msg)                                              \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::INFO,  true,              \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_WARN_1(__msg)                                              \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::WARNING,  true,           \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_ERROR_1(__msg)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::ERR,  true,               \
                                RG_HERE_FILE_NAME, -1)
#define RG_LOG_LOCK_MEM_1(__msg)                                               \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::MEM,  true,               \
                                RG_HERE_FILE_NAME, -1)
#else
#define RG_LOG_LOCK_DEBUG(...)                                                 \
  GET_MACRO(__VA_ARGS__, RG_LOG_DEBUG_2, RG_LOG_DEBUG_1)(__VA_ARGS__)
#define RG_LOG_LOCK_INFO(...)                                                  \
  GET_MACRO(__VA_ARGS__, RG_LOG_INFO_2, RG_LOG_INFO_1)(__VA_ARGS__)
#define RG_LOG_LOCK_WARN(...)                                                  \
  GET_MACRO(__VA_ARGS__, RG_LOG_WARN_2, RG_LOG_WARN_1)(__VA_ARGS__)
#define RG_LOG_LOCK_WARNING(...)                                               \
  GET_MACRO(__VA_ARGS__, RG_LOG_WARN_2, RG_LOG_WARN_1)(__VA_ARGS__)
#define RG_LOG_LOCK_ERROR(...)                                                 \
  GET_MACRO(__VA_ARGS__, RG_LOG_ERROR_2, RG_LOG_ERROR_1)(__VA_ARGS__)
#define RG_LOG_LOCK_MEM(...)                                                   \
  GET_MACRO(__VA_ARGS__, RG_LOG_MEM_2, RG_LOG_MEM_1)(__VA_ARGS__)

#define RG_LOG_LOCK_DEBUG_2(__msg, ...)                                        \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::DEBUG,  __VA_ARGS__,      \
                                __FILE__, __LINE__)
#define RG_LOG_LOCK_INFO_2(__msg, ...)                                         \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::INFO,  __VA_ARGS__,       \
                                __FILE__, __LINE__)
#define RG_LOG_LOCK_WARN_2(__msg, ...)                                         \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::WARNING,  __VA_ARGS__,    \
                                __FILE__, __LINE__)
#define RG_LOG_LOCK_ERROR_2(__msg, ...)                                        \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::ERR,  __VA_ARGS__,        \
                                __FILE__, __LINE__)
#define RG_LOG_LOCK_MEM_2(__msg, ...)                                          \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::MEM,  __VA_ARGS__,        \
                                __FILE__, __LINE__)

#define RG_LOG_LOCK_DEBUG_1(__msg)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::DEBUG,  true, __FILE__,   \
                                __LINE__)
#define RG_LOG_LOCK_INFO_1(__msg)                                              \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::INFO,  true, __FILE__,    \
                                __LINE__)
#define RG_LOG_LOCK_WARN_1(__msg)                                              \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::WARNING,  true, __FILE__, \
                                __LINE__)
#define RG_LOG_LOCK_ERROR_1(__msg)                                             \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::ERR,  true, __FILE__,     \
                                __LINE__)
#define RG_LOG_LOCK_MEM_1(__msg)                                               \
  Rinegine::Kernel::Debug::addl(__msg,Rinegine::Log::MEM,  true, __FILE__,     \
                                __LINE__)
#endif
#else

#define RG_LOG_DEBUG(...){}
#define RG_LOG_INFO(...){}
#define RG_LOG_WARN(...){}
#define RG_LOG_WARNING(...){}
#define RG_LOG_ERROR(...){}
#define RG_LOG_MEM(...){}
#define RG_LOG_LOCK_DEBUG(...){}
#define RG_LOG_LOCK_INFO(...){}
#define RG_LOG_LOCK_WARN(...){}
#define RG_LOG_LOCK_WARNING(...){}
#define RG_LOG_LOCK_ERROR(...){}
#define RG_LOG_LOCK_MEM(...){}
#endif



