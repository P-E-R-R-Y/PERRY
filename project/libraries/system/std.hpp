#include <ostream>

namespace std {  // Open the std namespace (this is generally discouraged)
    // Define the manipulator inside the std namespace
    std::ostream& tab(std::ostream& os) {
        return os << '\t';
    }
}
