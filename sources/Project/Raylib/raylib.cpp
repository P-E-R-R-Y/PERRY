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
#include "Window/RayWindow.hpp"
#include "Graphics/RayModel2.hpp"
#include "Graphics/RayModel3.hpp"
#include "Graphics/RayCamera.hpp"

extern "C" IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new RayWindow(screenWidth, screenHeight, std::string("Raylib " + title));
}

extern "C" void deleteWindow(IWindow *window) {
    delete window;
}

extern "C" IModel2 *createModel2(std::string path) {
    return new RayModel2(path);
}

extern "C" void deleteModel2(IModel2 *model2) {
    delete model2;
}

extern "C" ICamera *createCamera() {
    return new RayCamera();
}

extern "C" void deleteCamera(ICamera *camera) {
    delete camera;
}

extern "C" IModel3 *createModel3() {
    return new RayModel3();
}

extern "C" void deleteModel3(IModel3 *model3) {
    delete model3;
}

#endif /* !RAYLIB_CPP_ */