/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-11 12:19:17
 * @ Description:
 */

#ifndef RAYEVENT_HPP
#define RAYEVENT_HPP

//Interface
#include "../../../../interfaces/graphic/event/IEvent.hpp"

//Raylib
#include <raylib.h>

class RayEvent : public graphic::IEvent {
  public:
    friend class RayKeyboard;
    friend class RayMouse;
    friend class RayWindow;

    RayEvent() {}

    ~RayEvent() {}

  protected:    //your variables here
};

#endif // RAYEVENT_HPP
