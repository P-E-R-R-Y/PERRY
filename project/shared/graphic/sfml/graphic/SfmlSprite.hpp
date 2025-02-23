/**
 * @file SfmlSprite.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SFML
 * @{
 */


#ifndef SFMLSPRITE_HPP_
#define SFMLSPRITE_HPP_

//Interface
#include "IPolygon.hpp"

//Raylib
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/**
 * @brief Used to handle images
 * 
 */
class SfmlSprite : public graphic::ISprite {

    public:
        /**
         * @brief Construct a new Sfml Sprite object
         * 
         * @param path 
         */
        SfmlSprite(std::string path) {
            std::cout << "SfmlSprite::path-> " << path << std::endl;
            if (_texture.loadFromFile(path)) {
                _sprite.setTexture(_texture);
            }
            _position = {0, 0};
            _scale = {1, 1};
        }

        ~SfmlSprite() = default;

        /**
         * @brief check if the sprite is ready
         * 
         * @return true 
         * @return false 
         */
        bool isReady() const override {
            return (_sprite.getTexture() != nullptr);
        }

        /**
         * @brief Get the Bounds object
         * 
         * @return __v4f_t 
         */
        __v4f_t getBounds() const override {
            sf::FloatRect rect = _sprite.getGlobalBounds();
            return { rect.left, rect.top, rect.width, rect.height};
        }

        /**
         * @brief Set the Crop object
         * 
         * @param rect 
         */
        void setCrop(__v4f_t rect) override {
            _sprite.setTextureRect(sf::IntRect(rect.x, rect.y, rect.w, rect.h));
        }

        /**
         * @brief Get the Position object
         * 
         * @return __v2f_t 
         */
        __v2f_t getPosition() const override {
            return { _sprite.getPosition().x, _sprite.getPosition().y};
        }

        /**
         * @brief Set the Position object
         * 
         * @param position 
         */
        void setPosition(__v2f_t position) override {
            _sprite.setPosition(position.x, position.y);
        }

        /**
         * @brief Get the Rotation object
         * 
         * @return float 
         */
        float getRotation() const override {
            return _sprite.getRotation();
        }

        /**
         * @brief Set the Rotation object
         * 
         * @param angle 
         * @param isRad 
         */
        void setRotation(float angle, bool isRad = false) override {
            if (isRad) {
                _sprite.setRotation(angle * 180.f / M_PI);
            } else {
                _sprite.setRotation(angle);
            }
        }

        /**
         * @brief Get the Size object
         * 
         * @return __v2f_t 
         */
        __v2f_t getSize() const override {
            sf::Vector2u size = _sprite.getTexture()->getSize();
            sf::Vector2f scale = _sprite.getScale();
            return {float(size.x) * scale.x, float(size.y) * scale.y};
        }

        /**
         * @brief Set the Size object
         * 
         * @param size 
         */
        void setSize(__v2f_t size) override {
            auto oldSize = _sprite.getTexture()->getSize();
            _sprite.setScale(size.x/oldSize.x, size.y/oldSize.y);
        }

        friend class SfmlWindow;

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        //your variables here
};

#endif /* !SFMLSPRITE_HPP_ */