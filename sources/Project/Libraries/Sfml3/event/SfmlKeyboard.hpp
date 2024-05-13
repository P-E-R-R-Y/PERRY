/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-10 19:59:08
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-13 15:00:46
 * @ Description: Raylib Encapsulation for IMouse
 */

#ifndef SFMLKEYBOARD_HPP_
#define SFMLKEYBOARD_HPP_

//Interface
#include "../../../Interfaces/graphic3/event/IKeyboard.hpp"

//Sfml
#include <SFML/Window/Keyboard.hpp>

//More
#include <vector>

class SfmlKeyboard : public graphic3::IKeyboard {

    public:
        SfmlKeyboard(graphic3::IEvent *event) {
            _event = event;
        }

        ~SfmlKeyboard() {
        }

        std::vector<Keys> whichKey() const override {
            std::vector<Keys> keys;

            return keys;
        }

        bool isKeyPressed(Keys key) const override {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                return true;
            }
            return false;
        }

        bool isKeyDown(Keys key) const override {
            return false;
        }

        bool isKeyReleased(Keys key) const override {
            return false;
        }

        bool isKeyUp(Keys key) const override {
            return false;
        }

        void update() override {};

    private:
        graphic3::IEvent *_event;
};

#endif /* !SFMLKEYBOARD_HPP_ */