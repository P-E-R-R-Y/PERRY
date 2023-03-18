/**
 *
 * File: sfml.cpp (header.v2)
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

#include "Window/SfmlWindow.hpp"

extern "C" IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new SfmlWindow(screenWidth, screenHeight, "Sfml " + title);
}

extern "C" void deleteWindow(IWindow *window) {
    delete window;
}