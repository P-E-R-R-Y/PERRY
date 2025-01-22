/**
 * @brief file with main function
 * @author @Perry-chouteau
 */

#include "ECS.hpp"
#include "Component.hpp"
#include "System.hpp"

#include <unistd.h>

int main() {
    registry reg;
    //reg.registerComponent<Position>();
    //reg.registerComponent<Velocity>();

    //reg.registerComponents<Position, Velocity>();
    reg.registerComponentsByExtraction<std::tuple<Position, Velocity>>();

    entity_t boat = reg.spawnEntity();
    entity_t car = reg.spawnEntity();

//    boat.addComponent<Position>(Position{.x = 1}, reg);
//    boat.addComponent<Velocity>(Velocity{.x = 4}, reg);
//
//    car.addComponent<Position>(Position{.x = 2}, reg);
//    car.addComponent<Velocity>(Velocity{.x = 8}, reg);

    reg.addComponent(boat, Position{.x = 1});
    reg.addComponent(boat, Velocity{.x = 1});

    reg.addComponent(car, Position{.x = 2});
    reg.addComponent(car, Velocity{.x = 2});

    reg.addSystem(movementSystem);
    reg.addSystem(displaySystem);

    while (true) {

        reg.update();

        auto positions = reg.getComponents<Position>();

        positions.display();

        usleep(1000000);
    }

    return 0;
}