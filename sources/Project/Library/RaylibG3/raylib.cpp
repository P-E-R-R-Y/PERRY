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

#ifndef RAYLIB_CPP_
#define RAYLIB_CPP_

//Raylib
#include "window/RayWindow.hpp"
#include "graphic/RayModel2.hpp"
#include "graphic/RayModel3.hpp"
#include "window/RayCamera.hpp"

//Windowing
extern "C" graphic3::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new RayWindow(screenWidth, screenHeight, std::string("Raylib " + title));
}

extern "C" void deleteWindow(graphic3::IWindow *window) {
    delete window;
}

extern "C" graphic3::ICamera *createCamera(__v3f_t position) {
    return new RayCamera();
}

extern "C" void deleteCamera(graphic3::ICamera *camera) {
    delete camera;
}

//Graphics
extern "C" graphic3::IModel2 *createModel2(std::string path) {
    return new RayModel2(path);
}

extern "C" void deleteModel2(graphic3::IModel2 *model2) {
    delete model2;
}

extern "C" graphic3::IModel3 *createModel3() {
    return new RayModel3();
}

extern "C" void deleteModel3(graphic3::IModel3 *model3) {
    delete model3;
}

#endif /* !RAYLIB_CPP_ */