#pragma once
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

// extern "C" BOOL WINAPI _CRT_INIT(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);


namespace Rinegine::Kernel {
  __attribute__((weak)) void EarlyInit();
}

namespace Rinegine::Kernel {
  __attribute__((constructor(101)))
    static void EarlyInitCall() {
    if (Rinegine::Kernel::EarlyInit != nullptr) {
      Rinegine::Kernel::EarlyInit();
    }
  }
}
#if defined(__clang__)
#pragma clang diagnostic pop
#endif