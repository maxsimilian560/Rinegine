#define RG_DEBUG
#include <Rinegine/Kernel>                
// #include <Rinegine/Tokenize>                
#include <Rinegine/Graphics>
#include <Rinegine/Shorts>
// #include <Rinegine/WIP/Net>                
// #include <Rinegine/WIP/Neural>                
// #include <Rinegine/WIP/WebCore>                
// #include <Rinegine/WIP/Addons>
// #include <Rinegine/Old>                

namespace Rinegine::Kernel {
  void EarlyInit() {
    Rinegine::Kernel::Debug::Log_Level = 4;
  }
}
int Rinegine::Kernel::rg_main() {
  rg_cout << "Hello, World!" << std::endl;
  RG_LOG_DEBUG("Debug");
  RG_LOG_DEBUG("Debug2");
  RG_LOG_INFO("Info");
  RG_LOG_INFO("Info2");
  RG_LOG_WARN("Warn");
  RG_LOG_ERROR("Error");
  RG::K::Debug::no_close();
  RG_LOG_FATAL("Fatal no exit");
  RG_LOG_FATAL("Fatal no exit2");
  return 0;
}