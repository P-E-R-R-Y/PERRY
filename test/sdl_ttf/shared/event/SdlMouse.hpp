/**
 * @file SdlMouse.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SDL
 * @{
 */

#ifndef SDLMOUSE_HPP_
#define SDLMOUSE_HPP_

//Interface
#include "IMouse.hpp"
#include "SdlEvent.hpp"

//Sdl
#include <SDL2/SDL.h>

/**
 * @brief Sdl Mouse class
 */
class SdlMouse : public graphic::IMouse {

    public:

        /**
         * @brief Construct a new Sdl Mouse object
         * 
         * @param event 
         */
        SdlMouse(graphic::IEvent *event) {

        }

        /**
         * @brief Destroy the Sdl Mouse object
         */
        ~SdlMouse() {
        }

        /**
         * @brief notice if a button is pressed
         * 
         * @param key 
         * @return true 
         * @return false 
         */
        bool isButtonPressed(Buttons key) const override {
            return false;
        }

        /**
         * @brief notice if a button is down
         * 
         * @param key 
         * @return true 
         * @return false 
         */
        bool isButtonDown(Buttons key) const override {
            return false;
        }

        /**
         * @brief notice if a button is released
         * 
         * @param key 
         * @return true 
         * @return false 
         */
        bool isButtonReleased(Buttons key) const override {
            return false;
        }

        /**
         * @brief notice if a button is up
         * 
         * @param key 
         * @return true 
         * @return false 
         */
        bool isButtonUp(Buttons key) const override {
            return false;
        }
        
        /**
         * @brief Get the Position object
         * 
         * @return __v2f_t 
         */
        __v2f_t getPosition() const override {
            return {static_cast<float>(0), static_cast<float>(0)};
        }

        /**
         * @brief Set the Position object
         * 
         * @param position 
         */
        void setPosition(__v2f_t position) override {
            std::cout << "SdlMouse::setPosition not implemented yet" << std::endl;
        }

        /**
         * @brief Get the Mouse Wheel Move object
         * 
         * @return float 
         */
        float GetMouseWheelMove() const override {
            return GetMouseWheelMove();
        }

        /**
         * @brief update the mouse
         */
        void update() override {};

    private:
        SdlEvent *_event;
};

#endif /* !SDLMOUSE_HPP_ */