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


#ifndef IMODEL2_HPP_
    #define IMODEL2_HPP_
    #include "../../Systems/Type.hpp"
    #include "../Window/IWindow.hpp"

    //class IWindow;

    class IModel2 {

        public:
            //constructor
            virtual ~IModel2() = default;
            //is
            virtual bool isReady() const = 0;
            //b
            virtual __v4f_t getBounds() const = 0;
            //c
            virtual void setCrop(__v4f_t rect) = 0;
            //p
            virtual __v2f_t getPosition() const = 0;
            virtual void setPosition(__v2f_t position) = 0;
            //s
            virtual __v2f_t getSize() const = 0;
            virtual void setSize(__v2f_t size) = 0;

        private:
            //your variables here
    };

#endif /* !IMODEL2_HPP_ */