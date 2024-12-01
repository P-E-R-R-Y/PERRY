#include <iostream>
#include <tuple>
#include <utility>  // For std::move
#include <string>   // For std::string

// Variadic function that takes multiple arguments
template <typename... Args>
void foo(Args&&... args) {
    // Process args here (for simplicity, we'll leave it empty)
}

int main() {
    // Create a tuple
    std::tuple<int, std::string> t = std::make_tuple(42, "Hello");

    // Unpack the tuple and pass its elements to the variadic function
    // Ensure that the tuple is moved and passed correctly
    std::apply([](auto&&... args) { foo(std::forward<decltype(args)>(args)...); }, std::move(t));

    return 0;
}