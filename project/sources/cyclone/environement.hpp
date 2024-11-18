/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-06-07 16:57:46
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-06-07 23:47:00
 * @ Description:
 */

#include "types.hpp"

namespace physics {

  class Environment {
      public :

        Environment() = default;
        Environment(double gravity, double airDensity, Zone zone) : _gravity(gravity), _density(airDensity), _zone(zone) {}
        ~Environment() = default;
        bool world; 
        Zone _zone;
        double _density;
        double _gravity;
  };

}