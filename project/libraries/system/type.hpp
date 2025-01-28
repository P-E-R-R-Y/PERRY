/**
 *
 * File: Type.hpp
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

#ifndef TYPE_HPP_
    #define TYPE_HPP_

    #ifdef _WIN32
        #define OS "Windows"
    #elif __APPLE__
        #define OS "macOS"
        #include <sys/types.h>
        #include <string>
        #include <iostream>
        //use __int32_t
        //use float
    #else //if __linux__
        #define OS "Linux"
        #include <sys/types.h>
        #include <string>
        #include <iostream>
    #endif

    #include <vector>

namespace type {

    #define __v1i_t __int32_t
    #define __v1f_t float

    //int32
    typedef struct __v2u_s {
        __uint32_t x;
        __uint32_t y;
    } __v2u_t;

    typedef struct __v3u_s {
        __uint32_t x;
        __uint32_t y;
        __uint32_t z;
    } __v3u_t;

    typedef struct __v4u_s {
        __uint32_t x;
        __uint32_t y;
        __uint32_t w;
        __uint32_t h;
    } __v4u_t;

    typedef struct __v2i_s {
        __int32_t x;
        __int32_t y;
    } __v2i_t;

    typedef struct __v3i_s {
        __int32_t x;
        __int32_t y;
        __int32_t z;
    } __v3i_t;

    typedef struct __v4i_s {
        __int32_t x;
        __int32_t y;
        __int32_t w;
        __int32_t h;
    } __v4i_t;

    //double
    typedef struct __v2f_s {
        double x;
        double y;
    } __v2f_t;

    typedef struct __v3f_s {
        double x;
        double y;
        double z;
    } __v3f_t;

    typedef struct __v4f_s {
        double x;
        double y;
        double w;
        double h;
    } __v4f_t;

    typedef struct __color_s {
        double r;
        double g;
        double b;
        double a;
    } __color_t;

    typedef struct __zone_s {
        double top;
        double left;
        double front;
        double bottom;
        double right;
        double back;
    } __zone_t;

    typedef struct _quaternion_s {
        double x;
        double y;
        double z;
        double w;
    } _quaternion_t;

} // namespace type

#endif /* !TYPE_HPP_ */