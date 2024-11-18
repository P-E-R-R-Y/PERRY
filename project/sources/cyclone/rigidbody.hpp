/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-06-07 16:56:06
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-06-08 00:35:55
 * @ Description:
 */

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "types.hpp"

namespace physics
{
  class Rigidbody {
    public :

      Rigidbody() = default;
      ~Rigidbody() = default;

      double _mass;
      double _drag;
      double _angularDrag;
      double _gravityScale;
      bool _useGravity;
      bool _isKinematic;
      bool _freezeRotation;
      bool _freezePosition;
      Vector3 _position;
      Vector3 _velocity;
      Vector3 _acceleration;
      Quaternion _rotation;
      Vector3 _angularVelocity;
      Vector3 _angularAcceleration;
  };

} // namespace physics

#endif //RIGIDBODY_HPP
