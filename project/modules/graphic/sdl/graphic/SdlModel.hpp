/**
 * @file SdlModel.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup SDL
 * @{
 */

#ifndef SDLMODEL_HPP_
#define SDLMODEL_HPP_

//Interface
#include "../../../../interfaces/graphic/graphic/IModel.hpp"

//Sdl
#include <SDL2/SDL.h>

/**
 * @brief handle 3d model
 */
class SdlModel : public graphic::IModel {

    public:
        SdlModel() {
            std::cout << "SdlModel::SdlModel not implemented" << std::endl;
            //_position = {-1, -1, -1};
            //_scale = {1, 1, 1};
        }

        ~SdlModel() {
        }

        __v3f_t getPosition() const override {
            std::cout << "SdlModel::getPosition not implemented" << std::endl;
            return {0, 0, 0};
            //return {_position.x, _position.y, _position.z};
        }
        void setPosition(__v3f_t position) override {
            std::cout << "SdlModel::setPosition not implemented" << std::endl;
            //_position = {float(position.x), float(position.y), float(position.z)};
        }

        friend class SdlWindow;

    private:
        //Vector3 _position;
        //Vector3 _scale;
        //your variables here
};

#endif /* !SDLMODEL_HPP_ */