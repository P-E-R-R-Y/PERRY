#include <iostream>

class Parent {
public:
    static int value; // Shared by all derived classes
};

// Define static variable outside the class
int Parent::value = 0;

class Class1 : public Parent {};
class Class2 : public Parent {};

int main() {
    Class1 A;
    Class2 B;

    std::cout << A.value << std::endl; // Output: 0
    B.value = 1;
    std::cout << A.value << std::endl; // Output: 1 (Shared between Class1 & Class2)

    return 0;
}