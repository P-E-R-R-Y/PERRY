/**
 * @file SfmlMouse.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29

 * @addtogroup SFML
 * @{
 */

#ifndef SFMLMOUSE_HPP_
#define SFMLMOUSE_HPP_

//Interface
#include "../../../../interfaces/graphic/event/IMouse.hpp"
#include "SfmlEvent.hpp"

//Sfml
#include <SFML/Window/Mouse.hpp>

class SfmlMouse : public graphic::IMouse {

    public:
        SfmlMouse(graphic::IEvent *event) {
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