#include "Core.hpp"

int main(int ac, char **av) {
    ICore *core = new GameEngine();

    return core->Run();
}