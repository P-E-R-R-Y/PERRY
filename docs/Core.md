# Core

ICore
v

```cpp
template <class ... T>
class Engine: public ICore, T... {
```

Push to the limits

```cpp
#include <iostream>
#include <string>

class Feature1 {
public:
    using Params; // Parameter type for Feature1

    Feature1(const Params& data) {
        std::cout << "Feature1 initialized with string: " << data << std::endl;
    }
};

class Feature2 {
public:
    using Params = int; // Parameter type for Feature2

    Feature2(const Params& value) {
        std::cout << "Feature2 initialized with int: " << value << std::endl;
    }
};

template <class... T>
class Engine : public T... {
public:
    // Constructor takes variadic arguments corresponding to each class's Params type
    Engine(typename T::Params... args)
        : T(args)... // Forward arguments to each class's constructor
    {
        // Additional initialization logic if needed
    }
};

int main() {
    // Parameters for each feature
    std::string feature1Data = "Feature1 configuration data";
    int feature2Value = 42;

    // Initialize the Engine with feature-specific parameters
    Engine<Feature1, Feature2> engine(feature1Data, feature2Value);

    return 0;
}
```