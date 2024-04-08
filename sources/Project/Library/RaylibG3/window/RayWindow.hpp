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
//Raylib
#include "../raylib.h"

//Interface
#include "../../../Interface/graphic3/window/IWindow.hpp"
//encapsulation
#include "../graphic/RayModel2.hpp"
#include "../graphic/RayModel3.hpp"
#include "RayCamera.hpp"


#include <iostream>

//class RayModel2;

class RayWindow : public graphic3::IWindow {

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

        virtual void draw2(graphic3::IModel2 *model) override;

        void endDraw() override {
            EndDrawing();
        };

        //Draw3 (Carve)
        void beginMode3(graphic3::ICamera *camera) override;
        
        virtual void draw3(graphic3::IModel3 *model) override;

        void endMode3() override {
            EndMode3D();
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

void RayWindow::draw2(graphic3::IModel2 *model) {
    RayModel2 *raymodel = static_cast<RayModel2 *>(model);
    Rectangle posSize = {float(raymodel->getPosition().x), float(raymodel->getPosition().y),
                        float(raymodel->getSize().x), float(raymodel->getSize().y) };

    DrawTexturePro(raymodel->_texture, raymodel->_crop, posSize, {0,0}, 0, WHITE);
};

void RayWindow::beginMode3(graphic3::ICamera *camera) {
    RayCamera *raycamera = static_cast<RayCamera *>(camera);

    BeginMode3D(raycamera->_camera);
};

void RayWindow::draw3(graphic3::IModel3 *model) {
    RayModel3 *raymodel = static_cast<RayModel3 *>(model);

    DrawCube(raymodel->_position, 1, 1, 1, RED);
    DrawCubeWires(raymodel->_position, 1.f, 1.f, 1.f, BLACK);
    //DrawModel(raymodel->);
};

void beginMode3() {
    EndMode3D();
};

#endif /* !RAYWINDOW_HPP_ */