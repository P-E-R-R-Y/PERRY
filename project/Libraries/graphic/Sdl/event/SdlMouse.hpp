/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-10 19:59:08
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-25 19:30:25
 * @ Description: Raylib Encapsulation for IMouse
 */

#ifndef SDLMOUSE_HPP_
#define SDLMOUSE_HPP_

//Interface
#include "../../../../Interfaces/graphic/event/IMouse.hpp"
#include "SdlEvent.hpp"

//Sdl
#include <SDL2/SDL.h>

class SdlMouse : public graphic::IMouse {

    public:
        SdlMouse(graphic::IEvent *event) {

        }

        ~SdlMouse() {
        }

        bool isButtonPressed(Buttons key) const override {
            return false;
        }
        bool isButtonDown(Buttons key) const override {
            return false;
        }
        bool isButtonReleased(Buttons key) const override {
            return false;
        }
        bool isButtonUp(Buttons key) const override {
            return false;
        }
        
        __v2f_t getPosition() const override {
            return {static_cast<float>(0), static_cast<float>(0)};
        }
        void setPosition(__v2f_t position) override {
            std::cout << "SdlMouse::setPosition not implemented yet" << std::endl;
        }

        float GetMouseWheelMove() const override {
            return GetMouseWheelMove();
        }

        void update() override {};

    private:
        SdlEvent *_event;
};

#endif /* !SDLMOUSE_HPP_ */