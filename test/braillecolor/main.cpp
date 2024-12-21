#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <locale>
#include <iostream>

class BrailleColor {
    public:
      static const char *get256(int color, double limit = 256) {
        const int length = 9;
        const char* cp[9] = {"\u2800", "\u2840", "\u2844", "\u2846", "\u2847", "\u284F", "\u285F", "\u287F", "\u28FF"};
        if (color <0) {
            return cp[0];
        }
        if (color > limit - 1) {
            return cp[8];
        }
        double tmp = limit / length;
        return cp[static_cast<int>(std::floor(color / tmp))];
      }
};

int main() {
    std::cout << BrailleColor::get256(28) << std::endl;
    return 0;
}