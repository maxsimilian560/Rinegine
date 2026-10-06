#pragma once

namespace Rinegine {
  namespace Kernel {
    struct Raw_Pointer { // [exp]
      void* ptr = nullptr;
      size_t typesize = 0;
      size_t arrsize = 0;
      // init test
      bool is_init() const;

      
      void* get() const;

      
      Raw_Pointer();
      Raw_Pointer(void* in);
      
      Raw_Pointer(const Raw_Pointer&) = default;
      Raw_Pointer& operator=(const Raw_Pointer&) = default;
      Raw_Pointer(Raw_Pointer&&) = default;
      Raw_Pointer& operator=(Raw_Pointer&&) = default;

      
      void init();
      void init(void* in);
      
      Raw_Pointer& operator=(void* in);
      void* operator->();

      void clear();
      operator void* () const;
      ~Raw_Pointer();
    };
  }
} // namespace Rinegine