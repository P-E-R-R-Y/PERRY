#include "Systems.hpp"
#include "World.hpp"

int main() {
    World world;

    // Add systems
    world.addSystem<DisplaySystem>(5);

    // Update systems
    world.update();

    // Remove systems
    world.removeSystem<DisplaySystem>();

    world.update();

    // Add existing system
    std::unique_ptr<System> ds = std::make_unique<DisplaySystem>(10);
    world.addSystem(std::move(ds));

    world.update();

    return 0;
}