/**
 * @file sfml.cpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief shared graphic/sfml library symbols 
 * @version 0.1
 * @date 2025-01-27
 * 
 * @addtogroup graphic
 * @{
 * @addtogroup SFML
 * @{
 */

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
#include <string>

/**
 * @brief create Sfml window
 * 
 */
extern "C" graphic::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    std::cout << "creatingWindow" << std::endl;
    return new SfmlWindow(screenWidth, screenHeight, "Sfml " + title);
}

/**
 * @brief destroy Sfml window
 */

extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

/**
 * @brief create Sfml camera
 * 
 */
extern "C" graphic::ICamera *createCamera(__v3f_t position) {
    return new SfmlCamera({4, 4, 4}, {0, 0, 0}, 60);
}

/**
 * @brief destroy Sfml camera
 */
extern "C" void deleteCamera(graphic::ICamera *camera) {
    delete camera;
}

/**
 * @brief create Sfml event
 */
extern "C" graphic::IEvent *createEvent() {
    return new SfmlEvent();
}

/**
 * @brief destroy Sfml event
 */
extern "C" void deleteEvent(graphic::IEvent *event) {
    delete event;
}

/**
 * @brief create Sfml keyboard
 */
extern "C" graphic::IKeyboard *createKeyboard(graphic::IEvent *event) {
    return new SfmlKeyboard(event);
}

/**
 * @brief destroy Sfml keyboard
 */
extern "C" void deleteKeyboard(graphic::IKeyboard *keyboard) {
    delete keyboard;
}

/**
 * @brief create Sfml mouse
 */
extern "C" graphic::IMouse *createMouse(graphic::IEvent *event) {
    return new SfmlMouse(event);
}

/**
 * @brief destroy Sfml mouse
 */
extern "C" void deleteMouse(graphic::IMouse *mouse) {
    delete mouse;
}

/**
 * @brief create Sfml polygon
 */
extern "C" graphic::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new SfmlPolygon(points);
}

/**
 * @brief destroy Sfml polygon
 */
extern "C" void deletePolygon(graphic::IPolygon *polygon) {
    delete polygon;
}

/**
 * @brief create Sfml sprite
 */
extern "C" graphic::ISprite *createSprite(std::string sprite) {
    return new SfmlSprite(sprite);
}

/**
 * @brief destroy Sfml sprite
 */
extern "C" void deleteSprite(graphic::ISprite *sprite) {
    delete sprite;
}

/**
 * @brief create Sfml model
 */
extern "C" graphic::IModel *createModel() {
    return new SfmlModel();
}

/**
 * @brief destroy Sfml model
 */
extern "C" void deleteModel(graphic::IModel *model) {
    delete model;
}

/**
 * @brief get the name of the library
 */
extern "C" const char *getName() {
    return "sfml\0";
}

/**
 * @brief get the type of the library
 */
extern "C" const char *getType() {
    return "graphic\0";
}

#endif /* !SFML_CPP_ */
