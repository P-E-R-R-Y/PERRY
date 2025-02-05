/**
 * @file IText.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * @addtogroup graphic
 */


#ifndef ITEXT_HPP_
    #define ITEXT_HPP_

    #include "../../../libraries/system/type.hpp"
    #include <string>

namespace graphic {

    /**
     * @brief Text interface
     * 
     * @interface IText
     */
    class IText {

        public:

            /**
             * @brief Destroy the IText object
             * 
             */
            virtual ~IText() = default;

            virtual bool isReady() const = 0;

            /**
             * @brief Set the Text value
             * 
             * @param text 
             */
            virtual void setText(const std::string text) = 0;

            /**
             * @brief Get the Text value
             * 
             * @return std::string 
             */
            virtual std::string getText() const = 0;

            /**
             * @brief Set the Font value
             * 
             * @param font 
             */
            virtual void setFont(std::string path) = 0;

            /**
             * @brief Set the Font Size text
             * 
             * @param size 
             */
            virtual void setFontSize(unsigned int size) = 0;

            /**
             * @brief Get the Font Size text
             * 
             * @return unsigned int 
             */
            virtual unsigned int getFontSize() const = 0;

            /**
             * @brief Set the Text Color text
             * 
             * @param color 
             */
            virtual void setTextColor(__color_t color) = 0;

            /**
             * @brief Get the Text Color text
             * 
             * @return __v4f_t 
             */
            virtual __color_t getTextColor() const = 0;

            /**
             * @brief Set the Position text
             * 
             * @param position 
             */
            virtual void setPosition(__v2f_t position) = 0;

            /**
             * @brief Get the Position text
             * 
             * @return __v2f_t 
             */
            virtual __v2f_t getPosition() const = 0;

            /**
             * @brief Set the Rotation object
             * 
             * @param angle 
             */
            virtual void setRotation(float angle) = 0;

            /**
             * @brief Get the Rotation object
             * 
             * @return float 
             */
            virtual float getRotation() const = 0;

    };

}

#endif /* !ITEXT_HPP_ */