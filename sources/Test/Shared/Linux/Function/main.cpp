#include <iostream>
#include <dlfcn.h>
#include <unistd.h>

int main() {
  while (1) {
    // wait
    sleep(1);
    // dynamic loader
    void* lib = dlopen("./libshared.so", RTLD_NOW);
    if (!lib) {
      std::cerr << "Failed to load shared library: " << dlerror() << std::endl;
      continue;
    }

    typedef void (*print_func)(int);
    print_func print = reinterpret_cast<print_func>(dlsym(lib, "print"));
    if (!print) {
      std::cerr << "Failed to load symbol: " << dlerror() << std::endl;
      dlclose(lib);
      return 1;
    }

    int num = 31;
    print(num);

    dlclose(lib);
  }
  return 0;
}