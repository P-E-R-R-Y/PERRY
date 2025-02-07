/**
 * @file Text.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-07
 */

#ifndef SDLTEXT_HPP_
    #define SDLTEXT_HPP_

    #include <string>
    #include <SDL.h>
    #include <SDL_ttf.h>

    #include "IText.hpp"

class SdlText: public graphic::IText {

    public:

        SdlText(std::string text, std::string path) {
            font = TTF_OpenFont(path.c_str(), 24);
            if (!font) {
                std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
                _isReady = false;
                return;
            }
            // Create text surface and texture
            SDL_Color color = {255, 255, 255};
            textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
            if (!textSurface) {
                std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
                _isReady = false;
                return;
            }
            _isReady = true;
        }

        ~SdlText() override { 
                SDL_FreeSurface(textSurface);
                TTF_CloseFont(font);
                SDL_DestroyTexture(textTexture);

        };

        bool isReady() const override {
            return _isReady;
        }

        friend class SdlWindow;

    private:

        bool _isReady;
        TTF_Font* font;
        SDL_Surface* textSurface;
        SDL_Texture* textTexture;

};

#endif /* !SDLTEXT_HPP_ */