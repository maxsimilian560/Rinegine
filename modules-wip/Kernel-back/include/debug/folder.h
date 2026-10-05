#pragma once

namespace Rinegine {
  namespace Kernel {
    bool isDirectory(Rinegine::Kernel::String path);
    bool isDirectory(std::wstring path);
    bool CreateFolder(Rinegine::Kernel::String path);
    bool CreateFolder(std::wstring path);
  }
}