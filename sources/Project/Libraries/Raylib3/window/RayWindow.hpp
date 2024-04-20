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
#include "../../../Interfaces/graphic3/window/IWindow.hpp"
#include "../../../Interfaces/system/math.hpp"
//encapsulation
#include "../graphic/RayPolygon.hpp"
#include "../graphic/RaySprite.hpp"
#include "../graphic/RayModel.hpp"
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

        virtual void drawPoly(graphic3::IPolygon *polygon) override;
        virtual void drawSprite(graphic3::ISprite *sprite) override;

        void endDraw() override {
            EndDrawing();
        };

        //Draw3 (Carve)
        void beginMode3(graphic3::ICamera *camera) override;
        
        virtual void draw3(graphic3::IModel *model) override;

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

void RayWindow::drawPoly(graphic3::IPolygon *polygon) {
    RayPolygon *rayPolygon = static_cast<RayPolygon *>(polygon);
    std::vector<triangle_t> triangles = rayPolygon->_triangles;

    std::cout << "StartDraw" << std::endl;
    for (int i = 0; i < triangles.size(); i++) {
        //raylib ask for counter clockwise it's why I reverse the order
        DrawTriangle({static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)},
                    {static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)},
                    {static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)},
                    Color{static_cast<unsigned char>(rand()%255), 0, 0, 255});
    }
    std::cout << "EndDraw" << std::endl;
};

void RayWindow::drawSprite(graphic3::ISprite *sprite) {
    RaySprite *raysprite = static_cast<RaySprite *>(sprite);
    Rectangle posSize = {float(raysprite->getPosition().x), float(raysprite->getPosition().y),
                        float(raysprite->getSize().x), float(raysprite->getSize().y) };

    DrawTexturePro(raysprite->_texture, raysprite->_crop, posSize, {0,0}, 0, WHITE);
};

void RayWindow::beginMode3(graphic3::ICamera *camera) {
    RayCamera *raycamera = static_cast<RayCamera *>(camera);

    BeginMode3D(raycamera->_camera);
};

void RayWindow::draw3(graphic3::IModel *model) {
    RayModel *raymodel = static_cast<RayModel *>(model);

    DrawCubeV(raymodel->_position, raymodel->_scale, RED);
    DrawCubeWiresV(raymodel->_position, raymodel->_scale, BLACK);
    //DrawModel(raymodel->);
};

void beginMode3() {
    EndMode3D();
};

#endif /* !RAYWINDOW_HPP_ */