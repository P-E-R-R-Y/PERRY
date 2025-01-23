#include "Entity.hpp"
#include "ComponentManager.hpp"

int main() {
    Registry r;
    r.registerComponents<int, float, double>();
    //r.registerComponent<Position>();
    //r.registerComponent<Velocity>();

    //auto e = r.createEntity();

    //r.addComponent(e, Position{1.0f, 2.0f});
//    e.addComponent<Position>({1.0f, 2.0f});
    //r.addComponent(e, Velocity{3.0f, 4.0f});
//    e.addComponent<Velocity>({3.0f, 4.0f});
        
    r.getComponents<Position>().print();

    return 0;
}