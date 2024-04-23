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

#ifndef SDLWINDOW_HPP_
#define SDLWINDOW_HPP_
//Sdl
#include <SDL2/SDL.h>

//Interface
#include "../../../Interfaces/graphic3/window/IWindow.hpp"
#include "../../../Interfaces/system/math.hpp"
//encapsulation
#include "../graphic/SdlPolygon.hpp"
#include "../graphic/SdlSprite.hpp"
#include "../graphic/SdlModel.hpp"
#include "SdlCamera.hpp"


#include <iostream>

class SdlWindow : public graphic3::IWindow {

    public:
        SdlWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
            std::cout << "SdlWindow not implemented" << std::endl;
            //InitWindow(screenWidth, screenHeight, title.c_str());
        };

        ~SdlWindow() = default;

        //GLOBAL
        bool isOpen() override {
            std::cout << "SdlWindow::isOpen not implemented" << std::endl;
            return true;
            //return !WindowShouldClose();
        };

        void close() override {
            std::cout << "SdlWindow::close not implemented" << std::endl;
            //CloseWindow();
        };

        //DRAW
        void beginDraw() override {
            std::cout << "SdlWindow::beginDraw not implemented" << std::endl;
            //BeginDrawing();
            //ClearBackground(BLACK);
        };

        virtual void drawPoly(graphic3::IPolygon *polygon) override;
        virtual void drawSprite(graphic3::ISprite *sprite) override;

        void endDraw() override {
            std::cout << "SdlWindow::endDraw not implemented" << std::endl;
            //EndDrawing();
        };

        //Draw3 (Carve)
        void beginMode3(graphic3::ICamera *camera) override;
        
        virtual void drawModel(graphic3::IModel *model) override;

        void endMode3() override {
            std::cout << "SdlWindow::endMode3 not implemented" << std::endl;
            //EndMode3D();
        };

        //EVENT
        bool isPoll() override {
            return true;
        }

        bool pollEvent() override {
            return SDL_PollEvent(&event);
        }

        void eventClose() override {
            std::cout << "SdlWindow::eventClose not implemented" << std::endl;
            SDL_Quit();
            //CloseWindow();
        };

    private:
        SDL_Event event;
};

void SdlWindow::drawPoly(graphic3::IPolygon *polygon) {
    std::cout << "SdlWindow::drawPoly not implemented" << std::endl;
//    SdlPolygon *rayPolygon = static_cast<SdlPolygon *>(polygon);
//    std::vector<graphic3::triangle_t> triangles = rayPolygon->_triangles;
//
//    std::cout << "StartDraw" << std::endl;
//    for (int i = 0; i < triangles.size(); i++) {
//        //raylib ask for counter clockwise it's why I reverse the order
//        DrawTriangle({static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)},
//                    {static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)},
//                    {static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)},
//                    Color{static_cast<unsigned char>(rand()%255), 0, 0, 255});
//    }
//    std::cout << "EndDraw" << std::endl;
};

void SdlWindow::drawSprite(graphic3::ISprite *sprite) {
    std::cout << "SdlWindow::drawSprite not implemented" << std::endl;
//    RaySprite *raysprite = static_cast<RaySprite *>(sprite);
//    Rectangle posSize = {float(raysprite->getPosition().x), float(raysprite->getPosition().y),
//                        float(raysprite->getSize().x), float(raysprite->getSize().y) };
//
//    DrawTexturePro(raysprite->_texture, raysprite->_crop, posSize, {0,0}, 0, WHITE);
};

void SdlWindow::beginMode3(graphic3::ICamera *camera) {
    std::cout << "SdlWindow::beginMode3 not implemented" << std::endl;
//    RayCamera *raycamera = static_cast<RayCamera *>(camera);
//
//    BeginMode3D(raycamera->_camera);
};

void SdlWindow::drawModel(graphic3::IModel *model) {
    std::cout << "SdlWindow::drawModel not implemented" << std::endl;
//    RayModel *raymodel = static_cast<RayModel *>(model);
//
//    DrawCubeV(raymodel->_position, raymodel->_scale, RED);
//    DrawCubeWiresV(raymodel->_position, raymodel->_scale, BLACK);
//    //DrawModel(raymodel->);
};

#endif /* !SDLWINDOW_HPP_ */