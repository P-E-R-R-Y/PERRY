/**
 *
 * File: raylib.cpp (header.v2)
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

#ifndef SDLLIB_CPP_
#define SDLLIB_CPP_

//Sdl2
#include "window/SdlWindow.hpp"
#include "graphic/SdlPolygon.hpp"
#include "graphic/SdlModel.hpp"
#include "window/SdlCamera.hpp"

//Windowing
extern "C" graphic3::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new SdlWindow(screenWidth, screenHeight, std::string("Raylib " + title));
}

extern "C" void deleteWindow(graphic3::IWindow *window) {
    delete window;
}

extern "C" graphic3::ICamera *createCamera(__v3f_t position) {
    return new SdlCamera();
}

extern "C" void deleteCamera(graphic3::ICamera *camera) {
    delete camera;
}

//Graphics
extern "C" graphic3::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new SdlPolygon(points);
}

extern "C" void deletePolygon(graphic3::IPolygon *polygon) {
    delete polygon;
}

extern "C" graphic3::ISprite *createSprite(std::string sprite) {
    return new SdlSprite(sprite);
}

extern "C" void deleteSprite(graphic3::ISprite *sprite) {
    delete sprite;
}

extern "C" graphic3::IModel *createModel() {
    return new SdlModel();
}

extern "C" void deleteModel(graphic3::IModel *model) {
    delete model;
}

#endif /* !SDLLIB_CPP_ */