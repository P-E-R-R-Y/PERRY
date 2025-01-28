/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2025-01-28 02:09:58
 * @ Description:
 */

#ifndef RAYEVENT_HPP
#define RAYEVENT_HPP

//Interface
#include "../../../../interfaces/graphic/event/IEvent.hpp"

//Raylib
#include <raylib.h>

namespace raylib {

  /**
   * @brief Raylib Event class
   * @section graphic hello
   */
  class RayEvent : public graphic::IEvent {
    public:
      friend class RayKeyboard;
      friend class RayMouse;
      friend class RayWindow;

      RayEvent() = default;

      ~RayEvent() = default;

    protected:    //your variables here
  };

}

#endif // RAYEVENT_HPP
