#pragma once
/**
 * @file
 * @brief Post init
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


#include <functional>






namespace Rinegine {

  int TryCatch(std::function<void()> func);

} // namespace Rinegine

#define RG_CATCH_ERROR return Rinegine::TryCatch([&]() {
#define RG_ERROR_LOG  });

