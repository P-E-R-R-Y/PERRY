/**
 *
 * File: RayWindow.hpp (header.v2)
 * Created Date: Tue 14/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef RAYWINDOW_HPP_
#define RAYWINDOW_HPP_

//Interface
#include "../../Interface/Window/IWindow.hpp"

//Raylib
#include "raylib.h"
#include <iostream>

class RayModel2;

class RayWindow : public IWindow {

    public:
        RayWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
            InitWindow(screenWidth, screenHeight, title.c_str());
        };

        ~RayWindow() = default;

        //GLOBAL
        bool isOpen() override {
            return !WindowShouldClose();
        };

        void close() override {
            CloseWindow();
        };

        //DRAW
        void beginDraw() override {
            BeginDrawing();
            ClearBackground(BLACK);
        };

        virtual void draw2(IModel2 *model) override;

        void endDraw() override {
            EndDrawing();
        };

        //EVENT
        bool isPoll() override {
            return false;
        }

        bool pollEvent() override {
            return false;
        }

        void eventClose() override {
        };

    private:
};

//encapsulation
#include "../Graphics/RayModel2.hpp"

void RayWindow::draw2(IModel2 *model) {
    RayModel2 *raymodel = static_cast<RayModel2 *>(model);

    Rectangle posSize = {float(raymodel->getPosition().x), float(raymodel->getPosition().y),
                        float(raymodel->getSize().x), float(raymodel->getSize().y) };

    DrawTexturePro(raymodel->_texture, raymodel->_crop, posSize, {0,0}, 0, WHITE);
};

#endif /* !RAYWINDOW_HPP_ */