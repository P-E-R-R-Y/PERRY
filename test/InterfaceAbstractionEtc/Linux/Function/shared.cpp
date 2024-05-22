#include <iostream>

void myprint(int num) {
    std::cout << ">>> " << num << std::endl;
}

extern "C" void print(int num) {
    myprint(num);
}