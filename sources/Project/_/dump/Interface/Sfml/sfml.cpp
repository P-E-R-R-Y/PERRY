/**
 *
 * File: sfml.cpp
 * Created Date: Su Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun Mar 12 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/


#include "Window/SFMLWindow.hpp"
#include "Window/SFMLCamera2.hpp"
#include "Window/SFMLCamera3.hpp"
#include "Graphics/SFMLModel2.hpp"
#include "Graphics/SFMLModel3.hpp"

extern "C" IWindow *createWindow() {
    return new SFMLWindow;
}

extern "C" void deleteWindow(IWindow *window) {
    delete window;
}

extern "C" ICamera2 *createCamera2() {
    return new SFMLCamera2;
}

extern "C" void deleteCamera2(ICamera2 *camera2) {
    delete camera2;
}

extern "C" ICamera3 *createCamera3() {
    return new SFMLCamera3;
}

extern "C" void deleteCamera3(ICamera3 *camera3) {
    delete camera3;
}

extern "C" IModel2 *createModel2() {
    return new SFMLModel2;
}

extern "C" void deleteModel2(IModel2 *model2) {
    delete SFMLModel2;
}

extern "C" IModel3 *createModel3() {
    return new SFMLModel3;
}

extern "C" void createModel3(IModel3 *model3) {
    delete model3;
}
