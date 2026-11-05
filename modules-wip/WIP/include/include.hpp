#pragma once
/**
 * @file
 * @brief TODO1 BRIEF
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup TODO1 MODULE
 */



#include <limits>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <new>
#include <atomic>

#if defined(__linux__) || defined(__ANDROID__)
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#elif defined(_WIN32)
#include <windows.h>
#else
#error "Unsupported OS"
#endif
