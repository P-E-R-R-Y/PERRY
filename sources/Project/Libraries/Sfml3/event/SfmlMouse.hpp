/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-10 19:59:08
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-13 16:46:11
 * @ Description: Raylib Encapsulation for IMouse
 */

#ifndef SFMLMOUSE_HPP_
#define SFMLMOUSE_HPP_

//Interface
#include "../../../Interfaces/graphic3/event/IMouse.hpp"
#include "SfmlEvent.hpp"

//Sfml
#include <SFML/Window/Mouse.hpp>

class SfmlMouse : public graphic3::IMouse {

    public:
        SfmlMouse(graphic3::IEvent *event) {
            _event = static_cast<SfmlEvent *>(event);
        }

        ~SfmlMouse() {
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
            return {float(0), float(0)};
        }
        void setPosition(__v2f_t position) override {
        }

        float GetMouseWheelMove() const override {
            return 0;
        }

        void update() override {};

    private:
        SfmlEvent *_event;
};

#endif /* !SFMLMOUSE_HPP_ */