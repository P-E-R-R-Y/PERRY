// module_child.h
#include "Interface.hpp"
#include <iostream>

class ModuleChild : public Interface {
 public:
  void DoSomething() override {
    std::cout << "ModuleChild::DoSomething()" << std::endl;
  }
};
