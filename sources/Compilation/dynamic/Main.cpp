#include "Static.hpp"
#include "../../Project/Library/DynamicLoader.hpp"

int main() {
  std::cout << "a" << std::endl;
  std::cout << "b" << std::endl;
  DynamicLoader dl("libdynamic.dylib");
  //Core

  std::cout << "c" << std::endl;
  Debug *(*createDebug)() = reinterpret_cast<Debug *(*)()>(dl.findSymbol("debug"));
  std::cout << "d" << std::endl;
  Debug *debug = createDebug();
  std::cout << "e" << std::endl;
  debug->print_int(add(1,2));
  std::cout << "f" << std::endl;
}