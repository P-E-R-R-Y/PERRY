#ifndef DMODEL_HPP_
#define DMODEL_HPP_

#include "IWindow.hpp"

#include "DWindow.hpp"
#include "EModel.hpp"

class DModel: public IModel {
    public:
        DModel(std::string str) : _model(str) {
        }

        ~DModel() = default;

        friend class DWindow;

    private:
        EModel _model;
};

#endif /* !DMODEL_HPP_ */