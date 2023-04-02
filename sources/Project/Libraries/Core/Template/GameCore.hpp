/**
 *
 * File: SwitchLibCore.hpp (header.v2)
 * Created Date: Sun 02/04/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sun 02/04/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include "EngineCore.hpp"
#include <type_traits>

template<typename T, typename = std::enable_if_t<std::is_base_of<EngineCore, T>::value>>
class GameCore: public T {
};