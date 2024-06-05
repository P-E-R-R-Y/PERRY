/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-10 19:59:08
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-25 19:23:21
 * @ Description: Raylib Encapsulation for IMouse
 */

#ifndef RAYMOUSE_HPP_
#define RAYMOUSE_HPP_

//Interface
#include "../../../../Interfaces/graphic/event/IMouse.hpp"
#include "RayEvent.hpp"

//Raylib
#include <raylib.h>

class RayMouse : public graphic::IMouse {

    public:
        RayMouse(graphic::IEvent *event) {
        }

        ~RayMouse() {
        }

        bool isButtonPressed(Buttons key) const override {
            return IsMouseButtonPressed(key);
        }
        bool isButtonDown(Buttons key) const override {
            return IsMouseButtonDown(key);
        }
        bool isButtonReleased(Buttons key) const override {
            return IsMouseButtonReleased(key);
        }
        bool isButtonUp(Buttons key) const override {
            return IsMouseButtonUp(key);
        }
        
        __v2f_t getPosition() const override {
            return {float(GetMouseX()), float(GetMouseY())};
        }
        void setPosition(__v2f_t position) override {
            SetMousePosition(int(position.x), int(position.y));
        }

        float GetMouseWheelMove() const override {
            return GetMouseWheelMove();
        }

        void update() override {};

    private:
};

#endif /* !RAYMOUSE_HPP_ */