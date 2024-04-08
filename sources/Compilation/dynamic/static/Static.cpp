#include "Static.hpp"

Debug::Debug() {
    std::cout << "construct_DEBUG" << std::endl;
  }
Debug::~Debug() {
  }
void Debug::print_int(__int32_t v) {
    std::cout << v << std::endl;
  }

__int32_t add(__int32_t a, __int32_t b) {
  return a+b;
}