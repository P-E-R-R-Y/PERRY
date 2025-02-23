/**
 * @file SdlEvent.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29

 * @addtogroup SDL
 * @{
 */

#ifndef SDLEVENT_HPP
#define SDLEVENT_HPP

//Interface
#include "IEvent.hpp"

//Sdl
#include <SDL2/SDL.h>

/**
 * @brief Sdl Event class
 */
class SdlEvent : public graphic::IEvent {

    public:
        friend class SdlWindow;
        friend class SdlKeyboard;
        friend class SdlMouse;

        /**
         * @brief Construct a new Sdl Event object
         */
        SdlEvent() {}

        /**
         * @brief Destroy the Sdl Event object
         */
        ~SdlEvent() {}

    protected:

        SDL_Event _event;
};

#endif // SDLEVENT_HPP
