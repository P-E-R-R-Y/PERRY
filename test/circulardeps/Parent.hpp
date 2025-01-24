#ifndef PARENT_HPP
#define PARENT_HPP

#include <iostream>

template <typename T>
class Child; // Forward declaration of Child

// Full definition of Parent (move it before Child)
class Parent {
  public:
    template <typename T>
    Child<T> createChild(T number) {
        return Child<T>(number, *this); // Pass a reference to the Parent instance
    }

    template <typename T>
    void greetChild(const Child<T>& child) {
        std::cout << "Hello, " << child.number_ << std::endl;
    }
};

#endif // PARENT_HPP