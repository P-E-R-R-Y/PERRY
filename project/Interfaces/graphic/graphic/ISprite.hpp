/**
 *
 * File: IWindow.hpp
 * Created Date: Fr Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Fri Mar 10 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/


#ifndef ISPRITE_HPP_
    #define ISPRITE_HPP_
    #include "../../../libraries/system/type.hpp"
    #include "../window/IWindow.hpp"

namespace graphic {

    /**
     * @brief Sprite interface
     * @interface ISprite 
     */
    class ISprite {

        public:

            /**
             * @brief Destroy the ISprite object
             */
            virtual ~ISprite() = default;
            
            /**
             * @brief notice if the sprite is ready
             * 
             * @return bool
             */
            virtual bool isReady() const = 0;
            
            /**
             * @brief give the bounds of the sprite
             * 
             * @return __v4f_t
             */
            virtual __v4f_t getBounds() const = 0;
            
            /**
             * @brief Crop the sprite with a rectangle
             * 
             * @param rect
             */
            virtual void setCrop(__v4f_t rect) = 0;
            
            /**
             * @brief Get the Position object
             * 
             * @return __v2f_t
             */
            virtual __v2f_t getPosition() const = 0;

            /**
             * @brief Set the Position object
             * 
             * @param position
             */
            virtual void setPosition(__v2f_t position) = 0;
            
            /**
             * @brief Get the Rotation object
             * 
             * @return float
             */
            virtual float getRotation() const = 0;
            
            /**
             * @brief Set the Rotation object
             * 
             * @param angle
             * @param isRad
             */
            virtual void setRotation(float angle, bool isRad = false) = 0;
            
            /**
             * @brief Get the Sprite size
             * 
             * @return __v2f_t
             */
            virtual __v2f_t getSize() const = 0;

            /**
             * @brief Set the Sprite size
             * 
             * @param size
             */
            virtual void setSize(__v2f_t size) = 0;

    };

} // namespace graphic3

#endif /* !ISPRITE_HPP_ */