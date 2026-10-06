#pragma once


// debug




namespace Rinegine {

  int TryCatch(std::function<void()> func);

} // namespace Rinegine

#define RG_CATCH_ERROR return Rinegine::TryCatch([&]() {
#define RG_ERROR_LOG  });

