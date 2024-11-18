/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-10 19:59:08
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-12 00:10:32
 * @ Description: Sfml Encapsulation for IMouse
 */

#ifndef SFMLKEYBOARD_HPP_
#define SFMLKEYBOARD_HPP_

//Interface
#include "../../../../interfaces/graphic/event/IKeyboard.hpp"

//Sfml
#include <SFML/Window/Keyboard.hpp>


//More
#include <vector>
#include <unordered_map>

class SfmlKeyboard : public graphic::IKeyboard {

    public:
        SfmlKeyboard(graphic::IEvent *event) {
        }

        ~SfmlKeyboard() {
        }

        std::vector<Keys> whichKey() const override {
            std::vector<Keys> keys;
            
            return keys;
        }

        bool isKeyPressed(Keys key) const override {
            return (sf::Keyboard::isKeyPressed(_keys.at(key)));
        }

        bool isKeyDown(Keys key) const override {
            return (sf::Keyboard::isKeyPressed(_keys.at(key)));
        }

        bool isKeyReleased(Keys key) const override {
            return (sf::Keyboard::isKeyPressed(_keys.at(key)));
        }

        bool isKeyUp(Keys key) const override {
            return !(sf::Keyboard::isKeyPressed(_keys.at(key)));
        }

        void update() override {};

    private:
        //SfmlEvent *_event;
        const std::unordered_map<IKeyboard::Keys, sf::Keyboard::Key> _keys = {
            //line 0
            {IKeyboard::Keys::KEY_ESCAPE, sf::Keyboard::Key::Escape},
            {IKeyboard::Keys::KEY_F1, sf::Keyboard::Key::F1},
            {IKeyboard::Keys::KEY_F2, sf::Keyboard::Key::F2},
            {IKeyboard::Keys::KEY_F3, sf::Keyboard::Key::F3},
            {IKeyboard::Keys::KEY_F4, sf::Keyboard::Key::F4},
            {IKeyboard::Keys::KEY_F5, sf::Keyboard::Key::F5},
            {IKeyboard::Keys::KEY_F6, sf::Keyboard::Key::F6},
            {IKeyboard::Keys::KEY_F7, sf::Keyboard::Key::F7},
            {IKeyboard::Keys::KEY_F8, sf::Keyboard::Key::F8},
            {IKeyboard::Keys::KEY_F9, sf::Keyboard::Key::F9},
            {IKeyboard::Keys::KEY_F10, sf::Keyboard::Key::F10},
            {IKeyboard::Keys::KEY_F11, sf::Keyboard::Key::F11},
            {IKeyboard::Keys::KEY_F12, sf::Keyboard::Key::F12},

            //line 1
            {IKeyboard::Keys::KEY_1, sf::Keyboard::Key::Num1},
            {IKeyboard::Keys::KEY_2, sf::Keyboard::Key::Num2},
            {IKeyboard::Keys::KEY_3, sf::Keyboard::Key::Num3},
            {IKeyboard::Keys::KEY_4, sf::Keyboard::Key::Num4},
            {IKeyboard::Keys::KEY_5, sf::Keyboard::Key::Num5},
            {IKeyboard::Keys::KEY_6, sf::Keyboard::Key::Num6},
            {IKeyboard::Keys::KEY_7, sf::Keyboard::Key::Num7},
            {IKeyboard::Keys::KEY_8, sf::Keyboard::Key::Num8},
            {IKeyboard::Keys::KEY_9, sf::Keyboard::Key::Num9},
            {IKeyboard::Keys::KEY_0, sf::Keyboard::Key::Num0},
            {IKeyboard::Keys::KEY_MINUS, sf::Keyboard::Key::Subtract},
            {IKeyboard::Keys::KEY_EQUAL, sf::Keyboard::Key::Equal},
            {IKeyboard::Keys::KEY_BACKSPACE, sf::Keyboard::Key::BackSpace},

            //line 2
            {IKeyboard::Keys::KEY_TAB, sf::Keyboard::Key::Tab},
            {IKeyboard::Keys::KEY_Q, sf::Keyboard::Key::Q},
            {IKeyboard::Keys::KEY_W, sf::Keyboard::Key::W},
            {IKeyboard::Keys::KEY_E, sf::Keyboard::Key::E},
            {IKeyboard::Keys::KEY_R, sf::Keyboard::Key::R},
            {IKeyboard::Keys::KEY_T, sf::Keyboard::Key::T},
            {IKeyboard::Keys::KEY_Y, sf::Keyboard::Key::Y},
            {IKeyboard::Keys::KEY_U, sf::Keyboard::Key::U},
            {IKeyboard::Keys::KEY_I, sf::Keyboard::Key::I},
            {IKeyboard::Keys::KEY_O, sf::Keyboard::Key::O},
            {IKeyboard::Keys::KEY_P, sf::Keyboard::Key::P},
            {IKeyboard::Keys::KEY_LEFT_BRACKET, sf::Keyboard::Key::LBracket},
            {IKeyboard::Keys::KEY_RIGHT_BRACKET, sf::Keyboard::Key::RBracket},

            //line 3
            {IKeyboard::Keys::KEY_CAPS_LOCK, sf::Keyboard::Key::Unknown},
            {IKeyboard::Keys::KEY_LEFT_CONTROL, sf::Keyboard::Key::LControl},
            {IKeyboard::Keys::KEY_A, sf::Keyboard::Key::A},
            {IKeyboard::Keys::KEY_S, sf::Keyboard::Key::S},
            {IKeyboard::Keys::KEY_D, sf::Keyboard::Key::D},
            {IKeyboard::Keys::KEY_F, sf::Keyboard::Key::F},
            {IKeyboard::Keys::KEY_G, sf::Keyboard::Key::G},
            {IKeyboard::Keys::KEY_H, sf::Keyboard::Key::H},
            {IKeyboard::Keys::KEY_J, sf::Keyboard::Key::J},
            {IKeyboard::Keys::KEY_K, sf::Keyboard::Key::K},
            {IKeyboard::Keys::KEY_L, sf::Keyboard::Key::L},
            {IKeyboard::Keys::KEY_SEMICOLON, sf::Keyboard::Key::SemiColon},
            {IKeyboard::Keys::KEY_APOSTROPHE, sf::Keyboard::Key::Quote},
            {IKeyboard::Keys::BACK_TICK, sf::Keyboard::Key::LSystem},
            {IKeyboard::Keys::KEY_ENTER, sf::Keyboard::Key::Enter},
            
            //line 4
            {IKeyboard::Keys::KEY_LEFT_SHIFT, sf::Keyboard::Key::LShift},
            {IKeyboard::Keys::KEY_BACKSLASH, sf::Keyboard::Key::BackSlash},
            {IKeyboard::Keys::KEY_Z, sf::Keyboard::Key::Z},
            {IKeyboard::Keys::KEY_X, sf::Keyboard::Key::X},
            {IKeyboard::Keys::KEY_C, sf::Keyboard::Key::C},
            {IKeyboard::Keys::KEY_V, sf::Keyboard::Key::V},
            {IKeyboard::Keys::KEY_B, sf::Keyboard::Key::B},
            {IKeyboard::Keys::KEY_N, sf::Keyboard::Key::N},
            {IKeyboard::Keys::KEY_M, sf::Keyboard::Key::M},
            {IKeyboard::Keys::KEY_COMMA, sf::Keyboard::Key::Comma},
            {IKeyboard::Keys::KEY_DOT, sf::Keyboard::Key::Period},
            {IKeyboard::Keys::KEY_RIGHT_SHIFT, sf::Keyboard::Key::RShift},

            /// Line 5
            {IKeyboard::Keys::KEY_LEFT_ALT, sf::Keyboard::Key::LAlt},
            {IKeyboard::Keys::KEY_SPACE, sf::Keyboard::Key::Space},
            {IKeyboard::Keys::KEY_RIGHT_ALT, sf::Keyboard::Key::RAlt},
            {IKeyboard::Keys::KEY_RIGHT_CONTROL, sf::Keyboard::Key::RControl},
    
            /// KEYPAD
            {IKeyboard::Keys::KEY_PAD_0, sf::Keyboard::Key::Numpad0},
            {IKeyboard::Keys::KEY_PAD_1, sf::Keyboard::Key::Numpad1},
            {IKeyboard::Keys::KEY_PAD_2, sf::Keyboard::Key::Numpad2},
            {IKeyboard::Keys::KEY_PAD_3, sf::Keyboard::Key::Numpad3},
            {IKeyboard::Keys::KEY_PAD_4, sf::Keyboard::Key::Numpad4},
            {IKeyboard::Keys::KEY_PAD_5, sf::Keyboard::Key::Numpad5},
            {IKeyboard::Keys::KEY_PAD_6, sf::Keyboard::Key::Numpad6},
            {IKeyboard::Keys::KEY_PAD_7, sf::Keyboard::Key::Numpad7},
            {IKeyboard::Keys::KEY_PAD_8, sf::Keyboard::Key::Numpad8},
            {IKeyboard::Keys::KEY_PAD_9, sf::Keyboard::Key::Numpad9},
            {IKeyboard::Keys::KEY_PAD_MINUS, sf::Keyboard::Key::Subtract},
            {IKeyboard::Keys::KEY_PAD_PLUS, sf::Keyboard::Key::Add},
            {IKeyboard::Keys::KEY_PAD_DOT, sf::Keyboard::Key::Period},
            {IKeyboard::Keys::KEY_PAD_ENTER, sf::Keyboard::Key::Enter},

            //Arrow
            {IKeyboard::Keys::KEY_UP, sf::Keyboard::Key::Up},
            {IKeyboard::Keys::KEY_DOWN, sf::Keyboard::Key::Down},
            {IKeyboard::Keys::KEY_LEFT, sf::Keyboard::Key::Left},
            {IKeyboard::Keys::KEY_RIGHT, sf::Keyboard::Key::Right},
        };
};

#endif /* !SFMLKEYBOARD_HPP_ */