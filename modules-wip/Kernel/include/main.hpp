#pragma once
/**
 * @file
 * @brief Implementation of the Main struct for monitoring, managing, and storing input arguments.
 * @author Maximilian Panteleev
 * @copyright Managed under the Rinemest License (see LICENSE file).
 * @ingroup Kernel
 */



namespace Rinegine {
  namespace Kernel {
    struct Main {
      static Kernel::Array<Rinegine::Kernel::String>& Arguments;
      static Rinegine::Kernel::String& Folder;   // TODO
      static void InitFolder(const Rinegine::Kernel::String& exePath);
    };
  }
}