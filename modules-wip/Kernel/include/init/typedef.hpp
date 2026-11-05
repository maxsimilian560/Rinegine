#pragma once
/**
 * @file
 * @brief Defining certain elementary types using typedef
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "kernel/typedef"

typedef unsigned int uint;
typedef unsigned char uchar;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef int16_t int16;
#ifdef RG_SYS_WINDOWS
typedef __int32 int32;
#else
typedef __int32_t int32;
#ifndef WORD
typedef uint16_t WORD;
#endif
#ifndef DWORD
typedef uint32_t DWORD;
#endif
#endif
typedef long int lint;
typedef long unsigned int luint;

namespace Rinegine {
  typedef unsigned char BYTE;
  typedef BYTE byte;

  enum CONSOLE_COLOR {
    C_BLACK = 0,
    C_RED,
    C_GREEN,
    C_YELLOW,
    C_BLUE,
    C_MAGENTA,
    C_CYAN,
    C_WHITE,
    C_TEXT = 30,
    C_BACKGROUND = 40,
    C_BRIGHT = 60
  };

  namespace Log {
    enum Types {
      CRITICAL, ERR, WARNING, INFO, DEBUG, MEM
    };
  }
  enum Mouse_State {
    MNPress,
    MPress,
    MRelease,
  };
  struct Error {
    enum Log {
      RG_OWN_ERROR = -1,                 //-1
      RG_ERROR_WINDOWS_NO_CREATED,       // 0
      RG_ERROR_FREETYPE,                 // 1
      RG_ERROR_FREETYPE_FONTS_NOT_FOUND, // 2
      RG_ERROR_OUT_OF_MEMORY,            // 3
      RG_ERROR_FREETYPE_CHAR_NOT_LOAD,   // 4
      RG_ERROR_GLFW_INIT_ERR,            // 5
      RG_ERROR_FILE_NOT_FOUND,           // 6
      RG_ERROR_RGARRAY_SIZE0,            // 7
      RG_ERROR_RGARRAY_SIZE1,            // 8
      RG_ERROR_RGARRAY_SIZE2,            // 9
      RG_ERROR_LOAD_NOT4CNT_IMAGE,       // 10
      RG_ERROR_MATERIAL_MISUSE,          // 11
      RG_ERROR_RGMATRIX_SIZE0,           // 12
      RG_ERROR_LOAD_TEXTURE,             // 13
      RG_ERROR_PLANET_NOT_FOUND,         // 14
      RG_ERROR_BLOCK_TYPE_INCORRECT,     // 15
      RG_ERROR_FIND_TEXTURE,             // 16
    }code;
    Error() = default;
    Error(int err_code) : code(static_cast<Log>(err_code)) {}
    operator int() const {
      return static_cast<int>(this->code);
    }
    inline static const char* const Code[]{
      "NULL",                                             //-1
      "Error creating window.",                           // 0
      "Font loading error.",                              // 1
      "Font not found.",                                  // 2
      "Out of RAM memory.",                               // 3
      "Symbol not found.",                                // 4
      "GLFW initialization error.",                       // 5
      "File not found.",                                  // 6
      "RG_Array access error, RG_Array size = 0.",        // 7
      "RG_Array access error, RG_Array size < [i].",      // 8
      "RG_Array access error, RG_Array size - i > size.", // 9
      "The loaded texture has fewer color channels supported (less than "
      "4).",                                              // 10
      "Incorrect use of the material creation function.", // 11
      "RG_Matrix access error, RG_Matrix size = 0 or width < "
      "getPoint(width).", // 12
      "RG_LoadTexture(string path) - the wrong path was passed to the "
      "function.",                                        // 13
      "RG_FindPlanet(string) could not find the planet.", // 14
      "RG_GetBlockType could not find the block.",        // 15
      "RG_GetTexture could not find the texture.",        // 16
    };
  };


  enum s_delete_errors {
    SD_NO_ERR = 0,
    SD_NO_RG_TYPE,
    SD_PTR_IS_NULLPTR,
    SD_DEALOC_ERROR
  };
  struct DATA_OUT {
    size_t size = 0;
    char magnum[2] = { 'R', 'G' };
  };
  namespace Kernel {

    template <typename T>
    concept std_string_exist = requires { typename std::string; }&&
      requires { typename Util::conditional_t < requires { typename std::string; }, std::string, void > ; }&&
    Util::same_as < T, Util::conditional_t < requires { typename std::string; }, std::string, void >> ;

    template <typename T>
    concept std_string_like = \
      !Util::same_as<T, const char*>&&
      requires(T t) {
        { t.c_str() } -> Util::same_as<const char*>;
        { t.size() }  -> Util::same_as<size_t>;
        { t.empty() } -> Util::same_as<bool>;
    };
    struct StdStringViewLike {//[TODO]
      const char* _c_str;
      size_t  _size;
      bool  _empty;
    };
  }
} // namespace Rinegine
