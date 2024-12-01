#ifndef ICORE_HPP
#define ICORE_HPP

class ICore {
  public:
    ~ICore() = default;

    virtual int start() = 0;    
};

#endif // ICORE_HPP