#include <iostream>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>

class System {
  public:
    virtual ~System() = default;  // Virtual destructor for polymorphic behavior

    // The main function to override in derived systems
    virtual void lambda() = 0;
};