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

#ifndef SFML_CPP_
#define SFML_CPP_

//SFML
#include "Window/SfmlWindow.hpp"
#include "Graphics/SfmlModel2.hpp"

extern "C" IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    std::cout << "creatingWindow" << std::endl;
    return new SfmlWindow(screenWidth, screenHeight, "Sfml " + title);
}

extern "C" void deleteWindow(IWindow *window) {
    delete window;
}

extern "C" IModel2 *createModel2(std::string path) {
    return new SfmlModel2(path);
}

extern "C" void deleteModel2(IModel2 *model) {
    delete model;
}

#endif /* !SFML_CPP_ */
