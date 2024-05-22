// module.cpp
#include "ModuleChild.hpp"

extern "C" Interface* CreateModule() {
  return new ModuleChild;
}