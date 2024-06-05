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

//window
#include "window/SdlWindow.hpp"
#include "window/SdlCamera.hpp"
//event
#include "event/SdlEvent.hpp"
#include "event/SdlKeyboard.hpp"
#include "event/SdlMouse.hpp"
//graphic
#include "graphic/SdlPolygon.hpp"
#include "graphic/SdlModel.hpp"
#include "graphic/SdlSprite.hpp"

/**
 * @brief Window
 * 
 */
extern "C" graphic::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new SdlWindow(screenWidth, screenHeight, std::string("Sdl " + title));
}

extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

extern "C" graphic::ICamera *createCamera(__v3f_t position) {
    return new SdlCamera();
}

extern "C" void deleteCamera(graphic::ICamera *camera) {
    delete camera;
}

/**
 * @brief Event
 * 
 */

extern "C" graphic::IEvent *createEvent() {
    return new SdlEvent();
}

extern "C" void deleteEvent(graphic::IEvent *event) {
    delete event;
}

extern "C" graphic::IKeyboard *createKeyboard(graphic::IEvent *event) {
    return new SdlKeyboard(event);
}

extern "C" void deleteKeyboard(graphic::IKeyboard *keyboard) {
    delete keyboard;
}

extern "C" graphic::IMouse *createMouse(graphic::IEvent *event) {
    return new SdlMouse(event);
}

extern "C" void deleteMouse(graphic::IMouse *mouse) {
    delete mouse;
}

/**
 * @brief Graphic
 * 
 */
extern "C" graphic::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new SdlPolygon(points);
}

extern "C" void deletePolygon(graphic::IPolygon *polygon) {
    delete polygon;
}

extern "C" graphic::ISprite *createSprite(std::string sprite) {
    return new SdlSprite(sprite);
}

extern "C" void deleteSprite(graphic::ISprite *sprite) {
    delete sprite;
}

extern "C" graphic::IModel *createModel() {
    return new SdlModel();
}

extern "C" void deleteModel(graphic::IModel *model) {
    delete model;
}

#endif /* !SDLLIB_CPP_ */