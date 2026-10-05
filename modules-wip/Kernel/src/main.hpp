#pragma once

namespace Rinegine {
  namespace Kernel {


    alignas(Rinegine::Kernel::String)  static char storage_Folder[sizeof(Rinegine::Kernel::String)];
    alignas(Kernel::Array<Rinegine::Kernel::String>)  static char storage_Arguments[sizeof(Kernel::Array<Rinegine::Kernel::String>)];

    static bool folders_initialized = false;

    Rinegine::Kernel::String& Main::Folder = *reinterpret_cast<Rinegine::Kernel::String*>(storage_Folder);

    Kernel::Array<Rinegine::Kernel::String>& Main::Arguments = *reinterpret_cast<Kernel::Array<Rinegine::Kernel::String>  *>(storage_Arguments);

    void Main::InitFolder(const Rinegine::Kernel::String& exePath) {
      if (folders_initialized) return;

      // new (storage_WFolder) std::wstring(rg_to_stringw(Rinegine::Kernel::String(exePath)));
      new (storage_Folder) Rinegine::Kernel::String(exePath);
      // new (storage_Folder)  rg_string(rg_to_string(Rinegine::Kernel::String(exePath)));
      // new (storage_Folder)  Rinegine::Kernel::String((exePath));//TODO


      folders_initialized = true;
    }

  }
}