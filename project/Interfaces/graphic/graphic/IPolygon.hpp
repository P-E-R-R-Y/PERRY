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


#ifndef IPOLYGON_HPP_
    #define IPOLYGON_HPP_
    #include "../../../libraries/system/type.hpp"
    #include "../../../libraries/maths/geometry.hpp"
    #include "../window/IWindow.hpp"

namespace graphic {
    
    typedef struct triangle_s {
        __v2f_t A;
        __v2f_t B;
        __v2f_t C;
    } triangle_t;

    class IPolygon {

        public:
            //constructor
            virtual ~IPolygon() = default;
            //c
            virtual __color_t getColor() const = 0;
            virtual void setColor(__color_t position) = 0;
            //is
            virtual bool isReady() const = 0;
            //p
            virtual __v2f_t getPosition() const = 0;
            virtual void setPosition(__v2f_t position) = 0;
            //v
            virtual std::vector<__v2f_t> getPoints() const = 0;

        private:
            //your variables here
    };

} // namespace graphic3


#endif /* !IPOLYGON_HPP_ */