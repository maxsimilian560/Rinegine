#pragma once
namespace Rinegine::LinkTest::Kernel {
  //Test -lrg-kernel
  void ERROR_likely_you_forgot_to_link_lrg_kernel() {}
}
// #undef RG_HERE_FILE_NAME
// #define RG_HERE_FILE_NAME "kernel/kernel"

#include "setup.hpp"
#include "version.h"
#include "include.h"
#include "main.hpp"

#include "defined/set.h"
#include "convert/set.h"
#include "debug/set.h"
#include "allocator/set.h"
#include "console/set.hpp"
#include "pointer/set.h"
#include "array/set.h"
// #include "string/set.h"//[TODO]
#include "map/set.h"
#include "files/set.h"
#include "earlyinit.hpp"
