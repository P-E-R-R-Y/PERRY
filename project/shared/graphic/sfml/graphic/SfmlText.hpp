/**
 * @file RayText.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-03
 * 
 * @addtogroup Raylib
 */

#ifndef SFMLTEXT_HPP_
    #define SFMLTEXT_HPP_

    //standard
    #include <string>

    //Interface
    #include "IText.hpp"

    //Sfml
    #include <SFML/System.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

class SfmlText: public graphic::IText {

    public:
        SfmlText(std::string text, std::string font) {
            _isLoadedSuccessfully = _font.loadFromFile(font.c_str());
            _text.setFont(_font);
            _text.setString(text);
            _text.setFillColor(sf::Color::White);
            _text.setCharacterSize(20);
            _text.setPosition(sf::Vector2f{0, 0});
        }

        ~SfmlText() override { }

        bool isReady() const override {
            return _isLoadedSuccessfully;
        }

        void setText(const std::string text) override {
            _text.setString(text);
        }

        std::string getText() const override {
            return _text.getString().toAnsiString();
        } 

        void setFont(std::string font) override {
            _isLoadedSuccessfully = _font.loadFromFile(font.c_str());
        }

        void setFontSize(unsigned int size)  override {
            _text.setCharacterSize(size);
        }
        unsigned int getFontSize() const override {
            return _text.getCharacterSize();
        }

        void setTextColor(__color_t color) override {
            _text.setFillColor(sf::Color{
                static_cast<unsigned char>(color.r), 
                static_cast<unsigned char>(color.g), 
                static_cast<unsigned char>(color.b),
                static_cast<unsigned char>(color.a)});
        }

        __color_t getTextColor() const override {
            sf::Color c = _text.getFillColor();

            return __color_t{static_cast<double>(c.r), static_cast<double>(c.g), static_cast<double>(c.b), static_cast<double>(c.a)};
        } 

        void setPosition(__v2f_t position) override {
            _text.setPosition(sf::Vector2f{static_cast<float>(position.x), static_cast<float>(position.y)});
        }
        
        __v2f_t getPosition() const override {
            sf::Vector2f pos = _text.getPosition();

            return __v2f_t{static_cast<double>(pos.x), static_cast<double>(pos.y)};
        }

        void setRotation(float angle) override {
            _text.setRotation(angle);
        }

        float getRotation() const override {
            return _text.getRotation();
        }

        friend class SfmlWindow;

    private:

        sf::Font _font;
        sf::Text _text;
        bool _isLoadedSuccessfully;

};

#endif /* !SFMLTEXT_HPP_ */