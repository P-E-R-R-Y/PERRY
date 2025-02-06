/**
 * @file SdlMusic.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-03
 * 
 * @addtogroup SDL
 * @{
 */

#ifndef SDLMUSIC_HPP_
    #define SDLMUSIC_HPP_

    //Interface
    #include "IMusic.hpp"

    //Sdl
    #include <SDL.h>
    #include <SDL_mixer.h>

class SdlMusic: public graphic::IMusic {

    public:

        /**
         * @brief Construct a new Ray Music
         * 
         * @param path 
         */
        SdlMusic(std::string path) {
            _music = Mix_LoadMUS(path.c_str());
            _loop = false;
            _pause = false;
        }
         
        /**
         * @brief Destroy the Ray Music
         * 
         */
        ~SdlMusic() override {
            if (_music != NULL) {
                Mix_FreeMusic(_music);
            }
        }

        bool isReady() const override {
            return false; //_music == NULL;
        }

        /**
         * @brief play or resume the music
         */
        void play() override {
            if (_pause) {
                Mix_ResumeMusic();
                _pause = false;
            } else {
                Mix_PlayMusic(_music, _loop ? -1 : 1);
            }
        }

        /**
         * @brief pause the music
         * 
         */
        void pause() override {
            Mix_PauseMusic();
            _pause = true;
        }

        /**
         * @brief stop the music and reset it to the beginning
         * 
         */
        void stop() override {
            std::cout << "stop not implemented" << std::endl;
        }

        void update() override {
            std::cout << "update not implemented" << std::endl;
        }

        /**
         * @brief set the volume of the music
         * 
         * @param volume 
         */
        void setVolume(float volume) override {
            _volume = volume;
        }

        /**
         * @brief get the volume of the music or if not set the master volume
         * 
         * @return float 
         */
        float getVolume() const override {
            return _volume;
        }

        /**
         * @brief set the music to loop or not
         * 
         * @param loop 
         */
        void setLoop(bool loop) override {
            _loop = loop;
        }

        /**
         * @brief get if the music is looping or not
         * 
         * @return true 
         * @return false 
         */
        bool getLoop() const override {
            return _loop;
        }

        /**
         * @brief Set the time of the music in seconds
         * 
         * @param position 
         */
        void setTime(float position) override {
            Mix_SetMusicPosition(static_cast<double>(position));
        }

        /**
         * @brief Get the current time of the music in seconds
         * 
         * @return float 
         */
        float getTime() const override {
            return static_cast<float>(Mix_GetMusicPosition(_music));
        }

        /**
         * @brief Get the Length of the music
         * 
         * @return float 
         */
        float getLength() const override {
            return static_cast<float>(Mix_GetMusicLoopLengthTime(_music));
        }

    private:

        Mix_Music *_music;
        bool _loop;
        bool _pause;
        float _volume;
};

#endif /* !SDLMUSIC_HPP_ */