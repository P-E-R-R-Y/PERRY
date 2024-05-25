/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-04-14 13:23:25
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-05-25 19:10:56
 * @ Description: Interface for Model
 */




#ifndef IMODEL_HPP_
    #define IMODEL_HPP_
    #include "../../system/Type.hpp"
    #include "../window/IWindow.hpp"

    //class IWindow;
namespace graphic {

    class IModel {

        public:
            //constructor
            virtual ~IModel() = default;
            //p
            virtual __v3f_t getPosition() const = 0;
            virtual void setPosition(__v3f_t position) = 0;

        private:
            //your variables here
    };

} // namespace graphic3

#endif /* !IMODEL_HPP_ */