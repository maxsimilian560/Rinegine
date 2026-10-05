#pragma once

namespace Rinegine {
  namespace Kernel {
    template <class type> class Base_String;
    using String = Base_String<char>;
    bool isDirectory(Rinegine::Kernel::String path);
    bool isDirectory(std::wstring path);
    bool CreateFolder(Rinegine::Kernel::String path);
    bool CreateFolder(std::wstring path);
  }
}