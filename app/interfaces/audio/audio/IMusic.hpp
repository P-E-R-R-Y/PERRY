#ifndef IMUSIC_HPP
#define IMUSIC_HPP

#include "IAudio.hpp"

class IMusic : IAudio{
public:
  virtual ~IMusic() = default;
};

#endif // IMUSIC_HPP