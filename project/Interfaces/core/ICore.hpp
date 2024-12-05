#ifndef ICORE_HPP
#define ICORE_HPP

class ICore {
  public:
    ~ICore() = default;

    virtual int start() = 0;    
};

template <class ... T>
class CustomisableEngine: public ICore, public T... {
    public:
        CustomisableEngine(typename T::Params... args): T(args)... {};
        ~CustomisableEngine() = default;

    protected:
        virtual void initHandler() = 0;
        virtual void destroyHandler() = 0;

        virtual void eventHandler() = 0;
        virtual void updateHandler() = 0;
        virtual void displayHandler() = 0;
};

#endif // ICORE_HPP