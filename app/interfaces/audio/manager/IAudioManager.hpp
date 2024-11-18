#ifndef IAUDIOMANAGER_HPP
#define IAUDIOMANAGER_HPP

#include <string>

class IAudioManager {
public:
  virtual ~IAudioManager() = default;

  virtual void setVolume(float volume) = 0;
  virtual float getVolume() const = 0;  
};

#endif // IAUDIOMANAGER_HPP