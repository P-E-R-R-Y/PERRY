#ifndef DWINDOW_HPP_
#define DWINDOW_HPP_

#include "IWindow.hpp"

#include "EWindow.hpp"

#include "DModel.hpp"

class DWindow: public IWindow {
    public:
        DWindow() {
            ;
        }

        ~DWindow() = default;

        void draw(IModel *model) override {
            DModel *castModel = static_cast<DModel *>(model);
            _window.draw(castModel->_model);
        }

    private:
        EWindow _window;
};

#endif /* !DWINDOW_HPP_ */