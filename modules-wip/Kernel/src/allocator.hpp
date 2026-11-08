#pragma once
/**
 * @file
 * @brief TODO1 srcBRIEF
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */



namespace Rinegine::Kernel {
#ifndef CACHE_LINE_SIZE_BYTE
#define CACHE_LINE_SIZE_BYTE 64
#endif




  const std::size_t low_level::CACHE_LINE_SIZE = CACHE_LINE_SIZE_BYTE;

  static_assert((low_level::CACHE_LINE_SIZE& (low_level::CACHE_LINE_SIZE - 1)) == 0, "CACHE_LINE_SIZE must be a power of 2");


  struct Allocator::ChainNode {
    BYTE* prev = nullptr;
    BYTE* next = nullptr;
    BYTE* end = nullptr;
    size_t cell_used = 0;
  };





  size_t Allocator::allocator_count = 0;

  Allocator::Allocator() {
    allocator_count++;
    heap.ptr = nullptr;
    heap.end = nullptr;
    heap.owns = nullptr;
    init();
  }
  Allocator::Allocator(const Allocator& in) {
    allocator_count++;
    heap.ptr = in.heap.ptr ;
    heap.end = in.heap.end ;    
    
  }
  bool Allocator::init() {
    if (heap.ptr != nullptr)return 1;
    size_of_allocate = rg_min(Allocator::max_alloc_page_size, Allocator::page_size() * Allocator::base_alloc_page_count * ((size_of_allocate / 2) + 1));
    heap.ptr = SYS_GET_RAW_MEM(size_of_allocate);
    ((ChainNode*)heap.ptr)->next = nullptr;
    ((ChainNode*)heap.ptr)->prev = nullptr;
    ((ChainNode*)heap.ptr)->cell_used = 0;
    ((ChainNode*)heap.ptr)->end = heap.ptr + size_of_allocate;
    heap.end = ((ChainNode*)heap.ptr)->end;
    heap.next = Rinegine::Kernel::low_level::align_ptr_to_cache_line(heap.ptr + sizeof(ChainNode));
    rg_cout<<"Allocator is init!\n";
    rg_cout.flush();
    return 1;
  }
  // bool Allocator::is_init(){
  //   return (heap.ptr!=nullptr);
  // }
  BYTE* Allocator::allocate(size_t in) {
    if (heap.next + in >= heap.end) [[unlikely]] {
      size_of_allocate = rg_max(rg_min(Allocator::max_alloc_page_size, Allocator::page_size() * Allocator::base_alloc_page_count * ((size_of_allocate / 2) + 1)), /*Rinegine::Kernel::low_level::align_to_cache_line(in)*/ in + low_level::CACHE_LINE_SIZE);
      BYTE* next_pool = SYS_GET_RAW_MEM(size_of_allocate);
      ((ChainNode*)heap.ptr)->next = next_pool;
      ((ChainNode*)next_pool)->next = nullptr;
      ((ChainNode*)next_pool)->prev = heap.ptr;
      ((ChainNode*)next_pool)->cell_used = 0;
      ((ChainNode*)next_pool)->end = next_pool + size_of_allocate;
      heap.end = ((ChainNode*)next_pool)->end;
      heap.ptr = next_pool;
      heap.next = Rinegine::Kernel::low_level::align_ptr_to_cache_line(heap.ptr + sizeof(ChainNode));

    }
    ((ChainNode*)heap.ptr)->cell_used++;
    BYTE* out = heap.next;
    heap.next += in;
    return out;
  }
  void Allocator::deallocate(void* ptr, size_t) {
    if (heap.ptr == nullptr) { RG_LOG_LOCK_ERROR("Deallocation of a memory cell from an already deallocated pool");return; }
    if (ptr == nullptr)return;
    BYTE* head = heap.ptr;
    while (!(ptr > head && ptr < ((ChainNode*)head)->end)) {
      head = ((ChainNode*)head)->prev;
      if (head == nullptr) [[unlikely]] {
        RG_LOG_LOCK_WARN(std::format("deallocate get a ptr, but this allocator hasn't this"));
        return;
      }
    }
    ((ChainNode*)head)->cell_used--;
    if (((ChainNode*)head)->cell_used == 0) [[unlikely]] {
      if (head != heap.ptr) [[unlikely]] {
        if (((ChainNode*)head)->prev)
          ((ChainNode*)(((ChainNode*)head)->prev))->next = ((ChainNode*)head)->next;
        if (((ChainNode*)head)->next)
          ((ChainNode*)(((ChainNode*)head)->next))->prev = ((ChainNode*)head)->prev;
        Rinegine::Kernel::SYS_DEL_RAW_MEM(heap.ptr, size_t(((ChainNode*)heap.ptr)->end - heap.ptr));
      }
      else {
        heap.next = Rinegine::Kernel::low_level::align_ptr_to_cache_line(heap.ptr + sizeof(ChainNode));
      }
    }


  }
  Allocator::~Allocator() {
    allocator_count--;
    if (allocator_count == 0) [[unlikely]] {
      while (heap.ptr != nullptr) {
        BYTE* head = ((ChainNode*)heap.ptr)->prev;
        Rinegine::Kernel::SYS_DEL_RAW_MEM(heap.ptr, size_t(((ChainNode*)heap.ptr)->end - heap.ptr));
        heap.ptr = head;
      }
    }
  }





}
