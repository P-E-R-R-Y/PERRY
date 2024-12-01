/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-11 12:16:58
 * @ Description:
 */

#ifndef SDLEVENT_HPP
#define SDLEVENT_HPP

//Interface
#include "../../../../interfaces/graphic/event/IEvent.hpp"

//Sdl
#include <SDL2/SDL.h>

class SdlEvent : public graphic::IEvent {
  public:
    friend class SdlWindow;
    friend class SdlKeyboard;
    friend class SdlMouse;

    SdlEvent() {}
    ~SdlEvent() {}
  protected:
    //std::vector<SDL_KeyCode> _actualKeys;
    //std::vector<SDL_KeyCode> _previousKeys;

    SDL_Event _event;
};

#endif // SDLEVENT_HPP
