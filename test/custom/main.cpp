#include <iostream>
#include <tuple>
#include <string>

// Example Parent Class 1
class Parent1 {
public:
    using Params = int; // Single parameter type for this class

    Parent1(int value) {
        std::cout << "Parent1 constructed with value: " << value << std::endl;
    }
};

// Example Parent Class 2
class Parent2 {
public:
    using Params = std::string; // Single parameter type for this class

    Parent2(const std::string& value) {
        std::cout << "Parent2 constructed with value: " << value << std::endl;
    }
};

// Example Parent Class 3
class Parent3 {
public:
    using Params = std::tuple<int, double>; // Multiple parameter types for this class

    Parent3(int value1, double value2) {
        std::cout << "Parent3 constructed with values: " << value1 << ", " << value2 << std::endl;
    }
};

class Parent4 {
public:
    using Params = std::tuple<>; // Empty tuple for no arguments

    Parent4() {
        std::cout << "Parent3 constructed with no parameters." << std::endl;
    }
};


// Custom Class
template <typename... Parents>
class Custom : public Parents... {
public:
    // Constructor: Accepts parameters for each parent class
    Custom(typename Parents::Params... params)
        : Parents(constructParent<Parents>(params))... { // Forward parameters to the parent constructors
    }

private:
    // Helper function to construct a parent with the correct parameters
    template <typename Parent, typename Arg>
    static Parent constructParent(Arg&& arg) {
        if constexpr (std::is_same_v<typename Parent::Params, std::tuple<>>) {
            // If the parent's Params is an empty tuple, call the default constructor
            return Parent();
        } else if constexpr (std::is_same_v<Arg, std::tuple<>>) {
            // Special case: handle an empty tuple passed as a parameter
            return Parent();
        } else if constexpr (std::is_same_v<typename Parent::Params, std::tuple<int, double>>) {
            // If the parent's Params is a tuple, unpack it
            return std::apply([](auto&&... unpackedArgs) {
                return Parent(std::forward<decltype(unpackedArgs)>(unpackedArgs)...);
            }, std::forward<Arg>(arg));
        } else {
            // Otherwise, directly forward the single argument
            return Parent(std::forward<Arg>(arg));
        }
    }
};

int main() {
    // Create the Custom class, combining Parent1, Parent2, and Parent3
    Custom<Parent1, Parent2, Parent3, Parent4> obj(42, "Hello, World!", std::make_tuple(7, 3.14), std::make_tuple());

    return 0;
}