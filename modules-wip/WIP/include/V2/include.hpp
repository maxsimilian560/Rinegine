#pragma once


#include <iostream>
#include <limits>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <new>
#include <atomic>
#include <cstring>
#include <thread>



#if defined RG_SYS_WINDOWS
#include <windows.h>
#elif defined(RG_SYS_LINUX) || defined(__ANDROID__)
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#else
#error "OS isn't supported or Rinegine doesn't initialized"
#endif















