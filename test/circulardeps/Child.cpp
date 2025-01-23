#include "Child.hpp"
#include "Parent.hpp"

// Full template definition in the header
template <typename T>
Child<T>::Child(T number, Parent& parent) : number_(number), _parent(parent) {}

template <typename T>
void Child<T>::greetSelf() {
    _parent.greetChild(*this); // Use Parent's greetChild function
}
