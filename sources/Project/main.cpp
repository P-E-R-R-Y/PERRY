#include <iostream>
#include <vector>
//#include <raylib.h>

struct __v2f_t {
    float x;
    float y;
};

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

int main() {
  __v2f_t P = {101, 101};
  __v2f_t A = {100, 100};
  __v2f_t B = {150, 149};
  __v2f_t C = {200, 200};

  std::cout << (is_inside_triangle(P, A, B, C)? "true": "false") << std::endl;

  std::cout << (is_convex(A, B, C)? "true": "false") << std::endl;

}

/*main() {
    std::vector<int> triangles; 

    std::vector<__v2f_t> points = {{100, 100}, {200, 100}, {200, 200}, {300, 200}, {300, 300}, {100, 300}};//{50, 300

    std::cout << "all points" << std::endl;
    for (int i = 0; i < points.size(); i++) {
        std::cout << points[i].x << " " << points[i].y << std::endl;
    }

    //DrawTriangle
    for (int i = 0; points.size() >= 3; i++) {
        std::cout << "i: " << i << std::endl;
        //calcul angle
        __v2f_t pointA = points[i % points.size()];
        __v2f_t pointB = points[(i+1) % points.size()];
        __v2f_t pointC = points[(i+2) % points.size()];
        std::cout << "\tpointA" << pointA.x << " " << pointA.y << std::endl;
        std::cout << "\tpointB" << pointB.x << " " << pointB.y << std::endl;
        std::cout << "\tpointC" << pointC.x << " " << pointC.y << std::endl;

        //cross product bToA x bToC
        __v2f_t BA = {pointA.x - pointB.x, pointA.y - pointB.y};
        __v2f_t BC = {pointC.x - pointB.x, pointC.y - pointB.y};
        double cross = BA.x * BC.y - BA.y * BC.x;
        //if cross product is negative, then it's a concave angle
        //if it's positive, it's a convex angle
        std::cout << pointA.x << " " << pointA.y << std::endl;
        std::cout << pointB.x << " " << pointB.y << std::endl;
        std::cout << pointC.x << " " << pointC.y << std::endl;

        if (cross > 0) {
            std::cout << "concave" << std::endl;
            continue;
        } else {
            std::cout << "convex" << std::endl;
            triangles.push_back(i);
            triangles.push_back((i+1) % points.size());
            triangles.push_back((i+2) % points.size());
        }

        bool is_ear = true;
        //check collision
        for (int j = 0; j < points.size(); j++) {
            if (j == i%points.size() || j == ((i+1)%points.size()) || j == ((i+2)% points.size())) {
                continue;
            }
            if (is_inside_triangle(points[j], pointA, pointB, pointC)) {
                std::cout << "collision" << std::endl;
                is_ear = false;
                break;
            }
        } 
        if (is_ear) {
            //draw triangle
            DrawTriangle({static_cast<float>(pointA.x), static_cast<float>(pointA.y)},
                        {static_cast<float>(pointB.x), static_cast<float>(pointB.y)},
                        {static_cast<float>(pointC.x), static_cast<float>(pointC.y)},
                        {static_cast<unsigned char>(rand()%255), 0, 0, 255});
            //remove point
            points.erase(points.begin() + (i+1) % points.size());
        }
    }
}*/