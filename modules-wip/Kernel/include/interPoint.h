#pragma once

namespace Rinegine::LinkTest::Kernel {

#if defined(_WIN32)
  #if defined(_MSC_VER) || (defined(__clang__) && !defined(__MINGW32__))
    #pragma comment(linker, "/FAILIFMISMATCH:RINEGINE_KERNEL_LINKED=1")
    void ERROR_likely_you_forgot_to_link_lrg_kernel();
  #else
    // --- ОКРУЖЕНИЕ MINGW / GNU-таргет на Windows ---
    void ERROR_likely_you_forgot_to_link_lrg_kernel() __asm__(
        "\n\n============================================================\n"
        "❌ RINEGINE LINK ERROR:\n"
        "👉 You forgot to link the kernel library: -lrg-kernel 👈\n"
        "============================================================\n\n"
    );
  #endif
#else
  // --- ОКРУЖЕНИЕ LINUX (Твой рабочий цветной вариант) ---
  void ERROR_likely_you_forgot_to_link_lrg_kernel() __asm__(
      "\n\n\033[1;31m============================================================\n"
      "❌ RINEGINE LINK ERROR:\n"
      "👉 \033[1;4mYou forgot to link the kernel library: -lrg-kernel\033[0m\033[1;31m 👈\n"
      "============================================================\033[0m\n\n"
  );
#endif

  struct LinkChecker {
    inline LinkChecker() {
      ERROR_likely_you_forgot_to_link_lrg_kernel();
    }
  };
}



#ifndef RinegineLib
#ifdef RG_UTF
int wmain(int argc, wchar_t* argv[]) {
  // Rinegine::LinkTest::Kernel::LinkChecker __link_check;
  return Rinegine::Kernel::InterPoint(argc, argv, Rinegine::Kernel::rg_main);
}
#else
int main(int argc, char* argv[]) {
  // Rinegine::LinkTest::Kernel::LinkChecker __link_check;
  return Rinegine::Kernel::InterPoint(argc, argv, Rinegine::Kernel::rg_main);
}
#endif
#endif

