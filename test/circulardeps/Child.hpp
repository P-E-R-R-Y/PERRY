#ifndef CHILD_HPP
#define CHILD_HPP

#include "Parent.hpp"

// Forward declaration of Child template class
template <typename T>
class Child {
  public:
    explicit Child(T number, Parent& parent): number_(number), _parent(parent) {}

    void greetSelf() {
        _parent.greetChild(*this); // Use Parent's greetChild function
    }

    friend class Parent; // Grant Parent access to private members

  private:
    T number_;  // Stores the number
    Parent& _parent; // Reference to the parent instance
};

#endif // CHILD_HPP