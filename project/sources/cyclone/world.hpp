/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-06-07 17:37:45
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-06-07 17:39:49
 * @ Description:
 */

#ifndef WORLD_HPP
#define WORLD_HPP

#include "Component.hpp"

namespace physics
{
  class World {

    public :

      World() = default;
      World() {}
      ~World() = default;
      
      void updateForces();
      
  };

} // namespace physics

#endif //WORLD_HPP