#ifndef ISOUNDMANAGER_HPP
#define ISOUNDMANAGER_HPP

#include "IAudioManager.hpp"

class ISoundManager: public IAudioManager {
public:
  virtual ~ISoundManager() = default;
};

#endif // ISOUNDMANAGER_HPP