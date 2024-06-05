#include <string>
#include <iostream>
#include <vector>
#include "../../Interfaces/system/Type.hpp"

//position
typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    int x;
    int y;
    int z;
} Velocity;

typedef struct {
    int x;
    int y;
    int z;
} Acceleration;

//rotation

typedef struct {
    int x;
    int y;
    int z;
} Rotation;

typedef struct {
    int x;
    int y;
    int z;
} AngularVelocity;

typedef struct {
    int x;
    int y;
    int z;
} AngularAcceleration;

//physics
typedef struct {
    int mass;
} Mass;

typedef struct {
    int mollar_mass;
} MollarMass;

typedef struct {
    __v3f_t position;
    __v3f_t size;
} Boxes;

typedef struct {
    Boxes *boxes;
} RigidBody;