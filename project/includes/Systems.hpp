/**
 * @file Systems.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup user
 * @{
 */

#ifndef SYSTEMS_HPP
#define SYSTEMS_HPP

#include "Registry.hpp"
#include "Component.hpp"
#include "System.hpp"

namespace user {

    class MovementSystem: public ecs::System {
        public:
            MovementSystem(std::string name): _name(name) {};
            ~MovementSystem() = default;

            void lambda(ecs::Registry &r) override {
                std::cout << "----- " << _name << " Move Begin -----" << std::endl;
                auto& positions = r.getComponents<Position>();
                auto& velocities = r.getComponents<Velocity>();

                for (size_t i = 0; i < positions.size(); ++i) {
                    if (!positions[i] || !velocities[i]) {
                    continue;
                    }

                    positions[i]->x += velocities[i]->x;
                    positions[i]->y += velocities[i]->y;
                }
            }
        private:
            std::string _name;
    };

    class Math {
        public:
            Math() = default;
            ~Math() = default;

            int sqrt(int a) {
                return a * a;
            }
    };

    class DisplaySystem: public ecs::System {
        public:
            DisplaySystem(Math& math): _math(math) {};
            ~DisplaySystem() = default;

            void lambda(ecs::Registry &r) override {
                std::cout << "----- Display Begin -----" << std::endl;
                auto& positions = r.getComponents<Position>();
                auto& velocities = r.getComponents<Velocity>();

                for (size_t i = 0; i < positions.size(); ++i) {
                    if (!positions[i]) {
                    continue;
                    }

                    std::cout << "Position: " << *positions[i] << std::endl;
                    std::cout << "Velocity: " << *velocities[i] << std::endl;

                    //turn text to red color 
                    std::cout << RED << "sqrtPosX " <<  _math.sqrt(positions[i]->x) << std::endl;
                    std::cout << "sqrtPosX " <<  _math.sqrt(positions[i]->y) << RESET << std::endl;
                }
            }

        private:

            Math& _math;
            const std::string RED = "\033[31m";
            const std::string RESET = "\033[0m";


    };

}

#endif // SYSTEMS_HPP