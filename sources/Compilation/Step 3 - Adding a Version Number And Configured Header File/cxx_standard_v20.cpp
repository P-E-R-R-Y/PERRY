#include "iostream"

namespace a {
    namespace b {
        namespace c {
            int function() {
                return 32;
            }
        }
    }
}

int main() {
    const int inputValue = std::stod("24");
    char8_t a = 'a'; //cpp20 type (if running in 11 or less that 20 t will not work)
}