#pragma once

namespace Rinegine {
  namespace Kernel {
    struct Main {
      static Kernel::Array<Rinegine::Kernel::String>& AArguments;
      static Kernel::Array<std::wstring>& WArguments;
      // #ifdef RG_SYS_WINDOWS
      //       static std::wstring WFolder; // TODO
      //       static std::string AFolder;   // TODO
      //       static rg_string Folder; // TODO
      // #elif defined(RG_SYS_LINUX)
      static std::wstring& WFolder; // TODO
      static Rinegine::Kernel::String& AFolder;   // TODO
      static rg_string& Folder; // TODO
      // #endif
      static void InitFolder(const Rinegine::Kernel::String& exePath);

    };
  }
}