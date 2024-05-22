// derived_class.h
#include <dlfcn.h>
#include "Interface.hpp"
#include <iostream>

class DerivedClass : public Interface {
 public:
  DerivedClass() {
    module_handle_ = dlopen("./module.so", RTLD_NOW);
    if (!module_handle_) {
      std::cerr << "Failed to load module: " << dlerror() << std::endl;
      return;
    }

    // Retrieve the function pointer for the module function
    create_module_ = reinterpret_cast<Interface* (*)()>(
        dlsym(module_handle_, "CreateModule"));

    if (!create_module_) {
      std::cerr << "Failed to load symbol: " << dlerror() << std::endl;
      dlclose(module_handle_);
      module_handle_ = nullptr;
      return;
    }
  }

  ~DerivedClass() {
    if (module_handle_) {
      dlclose(module_handle_);
      module_handle_ = nullptr;
    }
  }

  void DoSomething() override {
    if (!create_module_) {
      std::cerr << "No create_module_ function pointer available" << std::endl;
      return;
    }
    Interface* module_instance = create_module_();
    if (!module_instance) {
      std::cerr << "Failed to create module instance" << std::endl;
      return;
    }
    module_instance->DoSomething();
    delete module_instance;
  }

 private:
  void* module_handle_ = nullptr;
  Interface* (*create_module_)() = nullptr;
};
