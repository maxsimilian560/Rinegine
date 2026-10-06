#pragma once

namespace Rinegine {
  namespace Kernel {
    struct Main {
      static Kernel::Array<Rinegine::Kernel::String>& Arguments;
      
      
      
      
      
      
      
      static Rinegine::Kernel::String& Folder;   // TODO
      
      
      static void InitFolder(const Rinegine::Kernel::String& exePath);

    };
  }
}