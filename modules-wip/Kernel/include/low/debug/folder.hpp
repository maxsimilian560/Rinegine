#pragma once

namespace Rinegine {
  namespace Kernel {
    template <class type> class Base_String;
    typedef Base_String<char> String;
    bool isDirectory(Rinegine::Kernel::String path);
    bool isDirectory(std::wstring path);
    bool CreateFolder(Rinegine::Kernel::String path);
    bool CreateFolder(std::wstring path);
  }
}