#pragma once

namespace Rinegine {
  namespace Kernel {
    /*class s_raw_ptr {
      Rinegine::DATA_OUT* ptr = nullptr;
    public:
      virtual operator void* () const { return ptr; }
      s_raw_ptr& operator=(s_raw_ptr&& in) {
        ptr = in.ptr;
        in.ptr = nullptr;
        return *this;
      }
      s_raw_ptr& operator=(Rinegine::DATA_OUT* in) {
        ptr = in;
        return *this;
      }
      virtual ~s_raw_ptr() { s_raw_delete(ptr); }
    };*///TODO
    /*template<class type>
    class s_ptr : public s_raw_ptr {
    public:
      virtual operator type* () const { return this->ptr; }
    };*///TODO
    /*struct RawMap {
      struct Node {
        s_raw_ptr* key = nullptr;
        s_raw_ptr* value = nullptr;
        Node* next = nullptr;
      };
    };*///TODO
  }
}



// namespace Rinegine::Kernel {









































// namespace Rinegine::Kernel{








