

#pragma once

#include "../system/Type.hpp"


class Quaternion {
  public:
    Quaternion()  : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Quaternion(const Quaternion& copy) : x(copy.x), y(copy.y), z(copy.z), w(copy.w) {}
    Quaternion(const Quaternion&& copy) : x(copy.x), y(copy.y), z(copy.z), w(copy.w) {}
    ~Quaternion() {}

    //setter
    void set(float x, float y, float z, float w) {
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = w; 
    }
    void set(const Quaternion& copy) {
      x = copy.x;
      y = copy.y;
      z = copy.z;
      w = copy.w; 
    }

    void identity() { x = y = z = 0.0f; w = 1.0f; }
    void conjugate() { x = -x; y = -y; z = -z; }
    void normalize() { 
      float len = length();
      if (len != 0.0f) {
        x /= len;
        y /= len;
        z /= len;
        w /= len;
      } 
    }
    void invert() { conjugate(); normalize(); }


    //function
    void lerp(const Quaternion& q, float t) {
      x = x + t * (q.x - x);
      y = y + t * (q.y - y);
      z = z + t * (q.z - z);
      w = w + t * (q.w - w);
    }

    void rotate(const __v3f_t& axis, float angle) {
      Quaternion q;
      q.fromAxis(axis, angle);
      *this *= q;
    }

    void fromAxis(const __v3f_t& axis, float angle) {
      float halfAngle = angle * 0.5f;
      float s = sin(halfAngle);
      x = axis.x * s;
      y = axis.y * s;
      z = axis.z * s;
      w = cos(halfAngle);
    }

    float dot(const Quaternion& q) const {
      return x * q.x + y * q.y + z * q.z + w * q.w;
    }
    float length() const {
      return sqrt(x * x + y * y + z * z + w * w);
    }
    float lengthSquared() const {
      return x * x + y * y + z * z + w * w;
    }
    float angle(const Quaternion& q) const {
      float s = sqrt(lengthSquared() * q.lengthSquared());
      return acos(dot(q) / s);
    }
    float getRoll() const {
      return atan2(2.0f * (x * y + z * w), 1.0f - 2.0f * (y * y + z * z));
    }
    float getPitch() const {
      return asin(2.0f * (x * z - w * y));
    }
    float getYaw() const {
      return atan2(2.0f * (x * w + y * z), 1.0f - 2.0f * (z * z + w * w));
    }

    __v3f_t getAxis() const {
      float s = sqrt(1.0f - w * w);
      return {x / s, y / s, z / s};
    }

    Quaternion operator+(const Quaternion& q) const {
      return Quaternion(x + q.x, y + q.y, z + q.z, w + q.w);
    }
    Quaternion operator-(const Quaternion& q) const {
      return Quaternion(x - q.x, y - q.y, z - q.z, w - q.w);
    }
    Quaternion operator*(const Quaternion& q) const {
      return Quaternion(
        w * q.x + x * q.w + y * q.z - z * q.y,
        w * q.y + y * q.w + z * q.x - x * q.z,
        w * q.z + z * q.w + x * q.y - y * q.x,
        w * q.w - x * q.x - y * q.y - z * q.z
      );
    }
    Quaternion operator*(float scalar) const {
      return Quaternion(x * scalar, y * scalar, z * scalar, w * scalar);
    }
    Quaternion operator/(float scalar) const {
      return Quaternion(x / scalar, y / scalar, z / scalar, w / scalar);
    }
    Quaternion& operator+=(const Quaternion& q) {
      x += q.x;
      y += q.y;
      z += q.z;
      w += q.w;
      return *this;
    }
    Quaternion& operator-=(const Quaternion& q) {
      x -= q.x;
      y -= q.y;
      z -= q.z;
      w -= q.w;
      return *this;
    }
    Quaternion& operator*=(const Quaternion& q) {
      *this = *this * q;
      return *this;
    }

  float x, y, z, w;
};