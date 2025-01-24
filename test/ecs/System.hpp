#include "ECS.hpp"
#include "Component.hpp"

// Forward declaration of Registry
class registry;
using registryRef = registry &; // Alias for registry reference

// Base class for systems

void movementSystem(registry &r) {
    std::cout << "1" << std::endl;
    std::cout << "Move Begin" << std::endl;
    auto& positions = r.getComponents<Position>();
    auto& velocities = r.getComponents<Velocity>();

    for (size_t i = 0; i < positions.size(); ++i) {
        if (!positions[i] || !velocities[i]) {
          continue;
        }

        positions[i]->x += velocities[i]->x;
    }

    positions.display();
    std::cout << "Move End" << std::endl;
}

void displaySystem(registry &r) {
    std::cout << "2" << std::endl;
    std::cout << "Display Begin" << std::endl;
    auto& positions = r.getComponents<Position>();
    auto& velocities = r.getComponents<Velocity>();

    for (size_t i = 0; i < positions.size(); ++i) {
        if (!positions[i] || !velocities[i]) {
          continue;
        }

        positions[i]->display();
    }

    std::cout << "Display End" << std::endl;
}