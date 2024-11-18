#ifndef IAUDIO_HPP
#define IAUDIO_HPP

#include "../system/Type.hpp"

class IAudio {
protected:
  virtual ~IAudio() = default;

  virtual void play(const std::string& soundFile) = 0;
  virtual void stop() = 0;

  virtual void setVolume(int volume) = 0;
  virtual int getVolume() const = 0;

  virtual void setOffset(float offset) = 0;
  virtual float getOffset() const = 0;

  virtual void setLoop(bool loop) = 0;
  virtual bool isLoop() const = 0;

  virtual void setPosition(double x, double y, double z) = 0;
  virtual __v3f_t getPosition() const = 0;
};

#endif // IAUDIO_HPP