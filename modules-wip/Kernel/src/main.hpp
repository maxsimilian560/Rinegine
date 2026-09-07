#pragma once

namespace Rinegine {
  namespace Kernel {

    alignas(std::wstring) static char storage_WFolder[sizeof(std::wstring)];
    alignas(Rinegine::Kernel::String)  static char storage_AFolder[sizeof(Rinegine::Kernel::String)];
    alignas(rg_string)    static char storage_Folder[sizeof(rg_string)];
    alignas(Kernel::Array<Rinegine::Kernel::String>)  static char storage_AArguments[sizeof(Kernel::Array<Rinegine::Kernel::String>)];
    alignas(Kernel::Array<std::wstring>)  static char storage_WArguments[sizeof(Kernel::Array<std::wstring>)];
    static bool folders_initialized = false;

    std::wstring& Main::WFolder = *reinterpret_cast<std::wstring*>(storage_WFolder);
    Rinegine::Kernel::String& Main::AFolder = *reinterpret_cast<Rinegine::Kernel::String*>(storage_AFolder);
    rg_string& Main::Folder = *reinterpret_cast<rg_string*>(storage_Folder);

    Kernel::Array<Rinegine::Kernel::String>& Main::AArguments = *reinterpret_cast<Kernel::Array<Rinegine::Kernel::String>  *>(storage_AArguments);
    Kernel::Array<std::wstring>& Main::WArguments = *reinterpret_cast<Kernel::Array<std::wstring> *>(storage_WArguments);

    void Main::InitFolder(const Rinegine::Kernel::String& exePath) {
      if (folders_initialized) return;

      new (storage_WFolder) std::wstring(rg_to_stringw(std::string(exePath)));
      new (storage_AFolder) Rinegine::Kernel::String(exePath);
      new (storage_Folder)  rg_string(rg_to_string(std::string(exePath)));
      // new (storage_Folder)  Rinegine::Kernel::String((exePath));//TODO


      folders_initialized = true;
    }

  }
}