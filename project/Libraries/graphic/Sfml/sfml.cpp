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
extern "C" graphic::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    std::cout << "creatingWindow" << std::endl;
    return new SfmlWindow(screenWidth, screenHeight, "Sfml " + title);
}

extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

extern "C" graphic::ICamera *createCamera(__v3f_t position) {
    return new SfmlCamera();
}

extern "C" void deleteCamera(graphic::ICamera *camera) {
    delete camera;
}

/**
 * @brief Event
 * 
 */
extern "C" graphic::IEvent *createEvent() {
    return new SfmlEvent();
}

extern "C" void deleteEvent(graphic::IEvent *event) {
    delete event;
}

extern "C" graphic::IKeyboard *createKeyboard(graphic::IEvent *event) {
    return new SfmlKeyboard(event);
}

extern "C" void deleteKeyboard(graphic::IKeyboard *keyboard) {
    delete keyboard;
}

extern "C" graphic::IMouse *createMouse(graphic::IEvent *event) {
    return new SfmlMouse(event);
}

extern "C" void deleteMouse(graphic::IMouse *mouse) {
    delete mouse;
}

/**
 * @brief Graphic
 * 
 */
extern "C" graphic::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new SfmlPolygon(points);
}

extern "C" void deletePolygon(graphic::IPolygon *polygon) {
    delete polygon;
}

extern "C" graphic::ISprite *createSprite(std::string sprite) {
    return new SfmlSprite(sprite);
}

extern "C" void deleteSprite(graphic::ISprite *sprite) {
    delete sprite;
}

extern "C" graphic::IModel *createModel() {
    return new SfmlModel();
}

extern "C" void deleteModel(graphic::IModel *model) {
    delete model;
}

#endif /* !SFML_CPP_ */
