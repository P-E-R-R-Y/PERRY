#include "System.hpp"

class DisplaySystem : public System {
  public:
    DisplaySystem(int x): _x(x) {};

    void lambda() override {
        std::cout << _x << " DisplaySystem running!" << std::endl;
    }

    int _x;
};