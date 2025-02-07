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

    };

}

#endif /* !ITEXT_HPP_ */