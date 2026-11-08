#pragma once
/**
 * @defgroup Kernel Kernel module
 * @brief The framework's core toolkit, without which the other modules will not (and cannot) function.
 * @{
 */

/**
 * @file
 * @brief Central kernel file
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


#undef RG_HERE_FILE_NAME
#define RG_HERE_FILE_NAME "kernel/kernel"

#include "predefine.hpp" //[TODO]
#include "general.hpp"
#include "setup.hpp"
#include "include.hpp"
#include "impl.hpp"
#include "util.hpp"
#include "typedef.hpp"
#include "convert.hpp"

#include "folder.hpp"
#include "debug-reserve.hpp"
#include "debug.hpp"
#include "buffer.hpp"
#include "allocator.hpp"
#include "array.hpp"
#include "string.hpp"
#include "list.hpp"
#include "vec.hpp"
#include "pointer.hpp"
#include "stream.hpp"
#include "iostream.hpp"
#include "fstream.hpp"
#include "map.hpp"
#include "defined.hpp"
#include "main.hpp"
#include "kernel.hpp"
#include "console.hpp"
#include "files.hpp"
#include "matrix.hpp"

#include "other_define.hpp"
// #include "interPoint.hpp"

/** @} */