#include "Child.hpp"

int main() {
    Parent parent;

    // Create a Child instance with a specific number
    Child<float> child = parent.createChild<float>(42.5f);

    // The Child greets itself using the Parent's greetChild function
    child.greetSelf();

    return 0;
}