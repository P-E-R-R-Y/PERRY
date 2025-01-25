#include "Ecs.hpp"
#include "ComponentManager.hpp"

#include "Systems.hpp"

int main() {
    Registry r;
    Math m = Math();

    r.registerComponentsByExtraction<config::components_list>();
    auto e = r.createEntity();

    e.addComponent<Position>({0.0f, 0.0f});
    e.addComponent<Velocity>({1.0f, 2.0f});

    r.addSystem<MovementSystem>("Move");
    r.addSystem<DisplaySystem>(m);

    std::cout << "----------------" << std::endl;
    r.callSystem<DisplaySystem>();
    r.callSystem<MovementSystem>();
    r.callSystem<DisplaySystem>();
    std::cout << "----------------" << std::endl;

    return 0;
}