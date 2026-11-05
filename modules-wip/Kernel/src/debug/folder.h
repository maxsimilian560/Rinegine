#pragma once
/**
 * @file
 * @brief TODO1 srcBRIEF
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */


namespace Rinegine {
bool Kernel::isDirectory(Rinegine::Kernel::String path) {
  if (std::filesystem::is_directory(path.c_str())) {
    return true;
  }
  return false;
}
bool Kernel::isDirectory(std::wstring path) {
  if (std::filesystem::is_directory(path.c_str())) {
    return true;
  }
  return false;
}
bool Kernel::CreateFolder(Rinegine::Kernel::String path) {
  if (!isDirectory(path)) {
    if(!std::filesystem::create_directory(path.c_str())){
      return false;
    };
  }
  return true;
}
bool Kernel::CreateFolder(std::wstring path) {
  if (!isDirectory(path)) {
    if(!std::filesystem::create_directory(path.c_str())){
      return false;
    };
  }
  return true;
}
}