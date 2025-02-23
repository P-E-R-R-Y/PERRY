/**
 * @file SfmlEvent.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SFML
 * @{
 */

#ifndef SFMLEVENT_HPP
#define SFMLEVENT_HPP

//Interface
#include "../../../interfaces/graphic/event/IEvent.hpp"

//Sfml
#include <SFML/Window.hpp>

class SfmlEvent : public graphic::IEvent {
  public:
    friend class SfmlWindow;
    friend class SfmlKeyboard;
    friend class SfmlMouse;

    SfmlEvent() {}
    ~SfmlEvent() {}
  private:
    sf::Event _event;
};

#endif // SFMLEVENT_HPP
