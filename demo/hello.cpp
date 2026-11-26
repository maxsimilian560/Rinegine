#define RG_DEBUG
#include <Rinegine/Kernel>
#include <Rinegine/Shorts>

namespace Rinegine::Kernel {
  void EarlyInit() {
    Rinegine::Kernel::Debug::Log_Level = 4;
  }
}

int Rinegine::Kernel::rg_main() {
  rg_cout << "=== Rinegine demo: Hello, World! ===" << std::endl;
  RG_LOG_INFO("Info message via Rinegine logger");
  RG_LOG_WARN("Warn message");

  // Тест собственных контейнеров фреймворка
  Rinegine::Kernel::String s("Rinegine");
  Rinegine::Kernel::Array<int> arr;
  for (int i = 1; i <= 5; ++i) arr.push_back(i * i);
  rg_cout << "String size: " << s.size() << ", squares:";
  for (size_t i = 0; i < arr.size(); ++i) rg_cout << " " << arr[i];
  rg_cout << std::endl;
  return 0;
}
