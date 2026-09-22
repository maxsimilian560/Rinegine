#pragma once
#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "graph/high/init"

namespace RG{
  namespace Lock{
    namespace Graphics{
      void init(){
        Rinegine::init();
      }
    }
  }
}
#define RG_GRAPH_INIT RG::Lock::Graphics::init()