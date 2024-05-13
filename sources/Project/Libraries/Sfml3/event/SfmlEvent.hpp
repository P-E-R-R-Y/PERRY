/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 11:09:33
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-13 15:12:06
 * @ Description:
 */

#ifndef SFMLEVENT_HPP
#define SFMLEVENT_HPP

//Interface
#include "../../../Interfaces/graphic3/event/IEvent.hpp"

//Sfml
#include <SFML/Window.hpp>

class SfmlEvent : public graphic3::IEvent {
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
