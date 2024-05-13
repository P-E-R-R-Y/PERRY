/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-13 15:55:00
 * @ Description:
 */

#ifndef SDLEVENT_HPP
#define SDLEVENT_HPP

//Interface
#include "../../../Interfaces/graphic3/event/IEvent.hpp"

//Sdl
#include <SDL2/SDL.h>

class SdlEvent : public graphic3::IEvent {
  public:
    friend class SdlWindow;
    friend class SdlKeyboard;
    friend class SdlMouse;

    SdlEvent() {}
    ~SdlEvent() {}
  protected:
    SDL_Event _event;
};

#endif // SDLEVENT_HPP
