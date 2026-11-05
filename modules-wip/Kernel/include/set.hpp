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

#include "init/set.hpp"
#include "low/set.hpp"
#include "med/set.hpp"

#include "postinit/set.hpp"

/** @} */