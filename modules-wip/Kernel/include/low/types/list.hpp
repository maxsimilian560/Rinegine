#pragma once

#define RG_FORCEINLINE inline __attribute__((always_inline)) 
namespace Rinegine::Kernel {

  
  
  template<class T>
  struct NODE {
    T data;
    NODE* next = nullptr;
    NODE* prev = nullptr;
  };

  
  template <class T>
  struct LIST {
    NODE<T>* head = nullptr;
    NODE<T>* _end = nullptr;
    size_t count = 0;

    class Iterator {
      NODE<T>* current;
    public:
      RG_FORCEINLINE explicit Iterator(NODE<T>* node) noexcept : current(node) {}

      RG_FORCEINLINE Iterator& operator++() noexcept {
        current = current->next;
        return *this;
      }

      RG_FORCEINLINE T& operator*() const noexcept {
        return current->data;
      }

      RG_FORCEINLINE bool operator!=(const Iterator& other) const noexcept {
        return current != other.current;
      }
    };

    RG_FORCEINLINE Iterator begin() noexcept {
      return Iterator(head);
    }

    RG_FORCEINLINE Iterator end() noexcept {
      return Iterator(nullptr);
    }
    //[INIT]
    LIST() {
      init();
    }
    int init() {
      head = nullptr;
      _end = nullptr;
      count = 0;
      return 0;
    }
    //[DESTROY]
    ~LIST() {
      clear();
    }
    template <typename U = T>
    int clear() requires Util::has_trivial_destructor_v<U> {
      NODE<T>* tmp = head; 
      while (tmp != nullptr) {
        NODE<T>* next = tmp->next;
        Rinegine::Kernel::Allocator::GetDefault().deallocate(tmp);
        tmp = next;
      }
      head = nullptr;
      _end = nullptr;
      count = 0;
      return 0;
    }
    template <typename U = T>
    int clear() requires (!Util::has_trivial_destructor_v<U>) {
      NODE<T>* tmp = head;
      while (tmp != nullptr) {
        NODE<T>* next = tmp->next;
        tmp->data.~T();
        Rinegine::Kernel::Allocator::GetDefault().deallocate(tmp);
        tmp = next;
      }
      head = nullptr;
      _end = nullptr;
      count = 0;
      return 0;
    }
    //[PUSH]
    RG_FORCEINLINE NODE<T>* push() {
      NODE<T>* node = reinterpret_cast<NODE<T>*>(Rinegine::Kernel::Allocator::GetDefault().allocate(sizeof(NODE<T>)));

      node->next = nullptr;
      node->prev = _end;
      if (_end) _end->next = node;
      else head = node; 
      
      _end = node;
      ++count;
      return node;
    }

    RG_FORCEINLINE NODE<T>* push(T in) requires (sizeof(T) <= 8 && Rinegine::Kernel::Util::is_trivially_constructible_v<T>) {
      NODE<T>* node = push();
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(in);
      return node;
    }

    RG_FORCEINLINE NODE<T>* push(const T& in) requires (sizeof(T) > 8 || !Rinegine::Kernel::Util::is_trivially_constructible_v<T>) {
      NODE<T>* node = push();
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(in); 

      return node;
    }

    RG_FORCEINLINE NODE<T>* push(T&& in) requires (sizeof(T) > 8 || !Rinegine::Kernel::Util::is_trivially_constructible_v<T>) {
      NODE<T>* node = push();
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(std::move(in)); 
      return node;
    }

    RG_FORCEINLINE NODE<T>* push_front() {
      NODE<T>* node = reinterpret_cast<NODE<T>*>(Rinegine::Kernel::Allocator::GetDefault().allocate(sizeof(NODE<T>)));

      node->next = head;
      node->prev = nullptr;
      if (head) [[likely]] head->prev = node;
      else _end = node;
      
      head = node;
      ++count;
      return node;
    }

    RG_FORCEINLINE NODE<T>* push_front(const T& in) {
      NODE<T>* node = push_front();
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(in);
      return node;
    }

    RG_FORCEINLINE NODE<T>* push_front(T&& in) {
      NODE<T>* node = push_front();
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(std::move(in));
      return node;
    }

    
    
    

    RG_FORCEINLINE NODE<T>* insert_before(NODE<T>* pos, const T& in) {
      if (!pos) return push(in);  
      NODE<T>* node = static_cast<NODE<T>*>(Rinegine::Kernel::Allocator::GetDefault().allocate(sizeof(NODE<T>)));
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(in);

      node->prev = pos->prev;
      node->next = pos;
      if (pos->prev) pos->prev->next = node;
      else head = node;
      pos->prev = node;
      ++count;
      return node;
    }

    RG_FORCEINLINE NODE<T>* insert_before(NODE<T>* pos, T&& in) {
      if (!pos) return push(std::move(in));
      NODE<T>* node = reinterpret_cast<NODE<T>*>(Rinegine::Kernel::Allocator::GetDefault().allocate(sizeof(NODE<T>)));
      ::new (static_cast<void*>(Rinegine::Kernel::Util::addressof(node->data))) T(std::move(in));

      node->prev = pos->prev;
      node->next = pos;
      if (pos->prev) pos->prev->next = node;
      else head = node;
      pos->prev = node;
      ++count;
      return node;
    }

    RG_FORCEINLINE NODE<T>* erase(NODE<T>* pos) {
      if (!pos) return nullptr;
      NODE<T>* next = pos->next;
      NODE<T>* prev = pos->prev;

      
      if constexpr (!Util::has_trivial_destructor_v<T>) {
        pos->data.~T();
      }
      Rinegine::Kernel::Allocator::GetDefault().deallocate(pos);

      if (prev) prev->next = next;
      else head = next;
      if (next) next->prev = prev;
      else _end = prev;
      --count;
      return next;
    }

    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    

    
    RG_FORCEINLINE T* back() {
      return _end ? Util::addressof(_end->data) : nullptr;
    }

    
    RG_FORCEINLINE T* front() {
      return head ? Util::addressof(head->data) : nullptr;
    }

    
    template<typename... Args>
    RG_FORCEINLINE  int emplace(Args&&... args) requires Util::is_trivially_constructible_v<T, Args...> {
      NODE<T>* new_node = static_cast<NODE<T>*>(Rinegine::Kernel::Allocator::GetDefault().allocate(sizeof(NODE<T>)));

      
      new_node->next = nullptr;
      new_node->prev = nullptr;

      
      new_node->data = T(static_cast<Args&&>(args)...);

      if (_end) _end->next = new_node;
      else head = new_node;
      _end = new_node;
      ++count;
      return 0;
    }

    
    template<typename... Args>
    RG_FORCEINLINE  int emplace(Args&&... args) requires (!Util::is_trivially_constructible_v<T, Args...>) {
      NODE<T>* new_node = static_cast<NODE<T>*>(Rinegine::Kernel::Allocator::GetDefault().allocate(sizeof(NODE<T>)));

      
      new_node->next = nullptr;
      new_node->prev = nullptr;

      
      T* data_ptr = &new_node->data;
      new (data_ptr) T(static_cast<Args&&>(args)...);

      if (_end) _end->next = new_node;
      else head = new_node;
      _end = new_node;
      ++count;
      return 0;
    }

    
    
    
    
    //[POP]

  };

}