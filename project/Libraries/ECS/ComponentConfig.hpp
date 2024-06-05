#include "Component.hpp"
#include <tuple>

/**
 * @brief user config listing all components
 *
 */
struct config {

    using components_list = std::tuple<Position,
                                        Velocity,
                                        Acceleration,

                                        Rotation,
                                        AngularVelocity,
                                        AngularAcceleration,

                                        Mass,
                                        MollarMass,
                                        RigidBody,

                                        int>;

};