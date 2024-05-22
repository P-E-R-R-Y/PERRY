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
//window
#include "window/SfmlWindow.hpp"
#include "window/SfmlCamera.hpp"
//event
#include "event/SfmlEvent.hpp"
#include "event/SfmlKeyboard.hpp"
#include "event/SfmlMouse.hpp"
//graphic
#include "graphic/SfmlSprite.hpp"
#include "graphic/SfmlModel.hpp"

/**
 * @brief Window
 * 
 */
extern "C" graphic3::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    std::cout << "creatingWindow" << std::endl;
    return new SfmlWindow(screenWidth, screenHeight, "Sfml " + title);
}

extern "C" void deleteWindow(graphic3::IWindow *window) {
    delete window;
}

extern "C" graphic3::ICamera *createCamera(__v3f_t position) {
    return new SfmlCamera();
}

extern "C" void deleteCamera(graphic3::ICamera *camera) {
    delete camera;
}

/**
 * @brief Event
 * 
 */
extern "C" graphic3::IEvent *createEvent() {
    return new SfmlEvent();
}

extern "C" void deleteEvent(graphic3::IEvent *event) {
    delete event;
}

extern "C" graphic3::IKeyboard *createKeyboard(graphic3::IEvent *event) {
    return new SfmlKeyboard(event);
}

extern "C" void deleteKeyboard(graphic3::IKeyboard *keyboard) {
    delete keyboard;
}

extern "C" graphic3::IMouse *createMouse(graphic3::IEvent *event) {
    return new SfmlMouse(event);
}

extern "C" void deleteMouse(graphic3::IMouse *mouse) {
    delete mouse;
}

/**
 * @brief Graphic
 * 
 */
extern "C" graphic3::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new SfmlPolygon(points);
}

extern "C" void deletePolygon(graphic3::IPolygon *polygon) {
    delete polygon;
}

extern "C" graphic3::ISprite *createSprite(std::string sprite) {
    return new SfmlSprite(sprite);
}

extern "C" void deleteSprite(graphic3::ISprite *sprite) {
    delete sprite;
}

extern "C" graphic3::IModel *createModel() {
    return new SfmlModel();
}

extern "C" void deleteModel(graphic3::IModel *model) {
    delete model;
}

#endif /* !SFML_CPP_ */
