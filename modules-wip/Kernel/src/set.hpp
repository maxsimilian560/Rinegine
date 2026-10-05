#pragma once
namespace Rinegine::LinkTest::Kernel {
  //Test -lrg-kernel
  void ERROR_likely_you_forgot_to_link_lrg_kernel() {}
}
// #undef RG_HERE_FILE_NAME
// #define RG_HERE_FILE_NAME "kernel/kernel"

#include "setup.hpp"
#include "version.hpp"
#include "include.hpp"
#include "main.hpp"

#include "defined/set.hpp"
#include "convert/set.hpp"
#include "debug/set.hpp"
#include "allocator/set.hpp"
#include "console/set.hpp"
#include "pointer/set.hpp"
#include "array/set.hpp"
// #include "string/set.h"//[TODO]
#include "map/set.hpp"
#include "files/set.hpp"
#include "earlyinit.hpp"
