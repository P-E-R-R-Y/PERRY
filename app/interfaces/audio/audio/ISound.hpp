#ifndef ISOUND_HPP
#define ISOUND_HPP

#include "IAudio.hpp"

class ISound : IAudio{
public:
  virtual ~ISound() = default;
};

#endif // ISOUND_HPP