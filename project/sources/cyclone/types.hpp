/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-06-07 16:58:28
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-11 12:50:14
 * @ Description:
 */


#ifndef TYPES_HPP
#define TYPES_HPP

#include "../../interfaces/system/Type.hpp"
 
namespace physics {

  class Vector3 {
    public :

      Vector3() = default;
      Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
      ~Vector3() = default;

      double x;
      double y;
      double z;
  };
 
  class Quaternion {
    public :

      Quaternion() = default;
      Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
      ~Quaternion() = default;

      double x;
      double y;
      double z;
      double w;
  };

  class Zone {
    public :

      Zone() = default;
      Zone(float top, float left, float front, float bottom, float right, float back) : top(top), left(left), front(front), bottom(bottom), right(right), back(back) {}
      Zone(Vector3 tlf, Vector3 brb) : top(tlf.x), left(tlf.y), front(tlf.z), bottom(brb.x), right(brb.y), back(brb.z) {}
      Zone(Zone& zone) : top(zone.top), left(zone.left), front(zone.front), bottom(zone.bottom), right(zone.right), back(zone.back) {}
      Zone(Zone&& zone) : top(zone.top), left(zone.left), front(zone.front), bottom(zone.bottom), right(zone.right), back(zone.back) {}
      ~Zone() = default;

      double top;
      double left;
      double front;

      double bottom;
      double right;
      double back;

  };

}

#endif