/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-22 20:46:28
 * @ Description:
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
