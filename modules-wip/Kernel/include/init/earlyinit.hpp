#pragma once
/**
 * @file
 * @brief Implementation of early initialization (even before the framework initializes; be careful, especially with the GCC compiler).
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif




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