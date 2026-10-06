#pragma once

namespace Rinegine::Kernel::Impl {
  struct safe_view_impl {
#if __cplusplus >= 202600L 
    template <class Filter>
    static constexpr auto operator()(Filter value) {
      return std::views::as_input | std::views::filter(std::move(value));
    }
#endif
  };
}