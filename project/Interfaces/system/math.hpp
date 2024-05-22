#ifndef MATH_HPP_
    #define MATH_HPP_

  #include<iostream>
  #include"Type.hpp" 

double cross_product(__v2f_t a, __v2f_t b) {
    //cross product formula
    return a.x * b.y - a.y * b.x;
}

bool is_inside_triangle(__v2f_t P, __v2f_t A, __v2f_t B, __v2f_t C) {
    //To calculate the area of a triangle given three points (x, y), you can use the formula for the area of a triangle formed by three vertices (x1, y1), (x2, y2), and (x3, y3):
    //Area = 0.5 * |(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))|

    double abc = 0.5 * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    double abp = 0.5 * abs(A.x * (B.y - P.y) + B.x * (P.y - A.y) + P.x * (A.y - B.y));
    double bcp = 0.5 * abs(B.x * (C.y - P.y) + C.x * (P.y - B.y) + P.x * (B.y - C.y));
    double cap = 0.5 * abs(C.x * (A.y - P.y) + A.x * (P.y - C.y) + P.x * (C.y - A.y));

    //if sum of abp, bcp, cap is equal to abc, then the point is inside the triangle, otherwise it's outside.
    return abc == abp + bcp + cap;
}

bool is_convex(__v2f_t A, __v2f_t B, __v2f_t C, bool clockwise = true) {
    //calculate the vector from B to A and B to C
    __v2f_t BA = {A.x - B.x, A.y - B.y};
    __v2f_t BC = {C.x - B.x, C.y - B.y};
    //calculate the cross product of BA and BC
    double cross = BA.x * BC.y - BA.y * BC.x;
        
    // 1. if it's a clockwise direction, then the cross product should be negative to be a convex angle
    // 2. if it's a counter clockwise direction, then the cross product should be positive to be a convex angle
    // 180 degree in this case is an exception, it's neither convex nor concave, but we can consider it as concave.
    if (clockwise) {
        return cross < 0;
    } else {
        return cross > 0;
    }
}

bool is_concave(__v2f_t A, __v2f_t B, __v2f_t C, bool clockwise = true) {
    //if it's not convex, then it's concave
    //prefere to inverse clockwise rather than inverse the result of is_convex to handle the 180 degree case
    return is_convex(A, B, C, !clockwise);
}

#endif /* !MATH_HPP_ */
