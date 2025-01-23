#include "Entity_impl.hpp"
#include "Registry_impl.hpp"
#include "ComponentManager.hpp"
#include "System.hpp"

int main() {
    Registry r;
//    r.registerComponents<int, float, double>();
    r.registerComponent<Position>();
    r.registerComponent<Velocity>();

    auto e = r.createEntity();

    //r.addComponent(e, Position{1.0f, 2.0f});
    e.addComponent<Position>({1.0f, 2.0f});
    //r.addComponent(e, Velocity{3.0f, 4.0f});
    e.addComponent<Velocity>({3.0f, 4.0f});

    r.addSystem([](Registry &r) {
        auto &positions = r.getComponents<Position>();
        auto &velocities = r.getComponents<Velocity>();

        for (size_t i = 0; i < positions.size(); ++i) {
            positions[i]->x += velocities[i]->x;
            positions[i]->y += velocities[i]->y;
        }
    });

    r.getComponents<Position>().print();
    r.getComponents<Velocity>().print();

    std::cout << std::endl << "Update" << std::endl << std::endl;
    r.update();

    r.getComponents<Position>().print();
    r.getComponents<Velocity>().print();

    return 0;
}