#pragma once


namespace Rinegine::Kernel {
  int Console::Write(Rinegine::Kernel::String in) {
    // rg_cout<<in;
    Rinegine::Kernel::IOstream::write_raw(Rinegine::Kernel::IOstream::get_stdout_handle(), in.c_str(), in.size());
    return 0;
  }
  int Console::WriteLine(Rinegine::Kernel::String in) {
    // char out[in.size() + m_buffer_index + 1];
    char* out = (char*)Rinegine::Kernel::Allocator::GetDefault().allocate(in.size() + m_buffer_index + 1);
    memcpy(out, m_buffer, m_buffer_index);
    memcpy(out + m_buffer_index, in.c_str(), in.size());
    out[in.size() + m_buffer_index] = '\n';
    Rinegine::Kernel::IOstream::write_raw(Rinegine::Kernel::IOstream::get_stdout_handle(), out, in.size() + m_buffer_index + 1);
    Rinegine::Kernel::Allocator::GetDefault().deallocate(out);
    return 0;
  }
  int Write(const char*, size_t) {
    return 0;
  }
  int WriteLine(const char*, size_t) {
    return 0;
  }

  int Write(const char) {
    return 0;
  }
  int WriteLine(const char) {
    return 0;
  }
}