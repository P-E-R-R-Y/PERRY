#include <stdio>

class Debug() {
  void Debug() {
    std::cout << "construct_DEBUG" << std::endl;
  }
  void ~Debug() {
  }
  void print() {
    std::cout << "debugging" << std::endl;
  }
}