/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-13 16:55:31
 * @ Description:
 */

#ifndef RAYEVENT_HPP
#define RAYEVENT_HPP

//Interface
#include "../../../Interfaces/graphic3/event/IEvent.hpp"

//Raylib
#include <raylib.h>

class RayEvent : public graphic3::IEvent {
  public:
    friend class RayKeyboard;
    friend class RayMouse;
    friend class RayWindow;

    RayEvent() {}

    ~RayEvent() {}

  protected:    //your variables here
};

#endif // RAYEVENT_HPP
