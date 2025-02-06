/**
 * @file SdlSound.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-02
 * 
 * @addtogroup SDL
 * @{
 */

#ifndef SDLSOUND_HPP_
    #define SDLSOUND_HPP_

    //Interface
    #include "ISound.hpp"

    //Sdl
    #include <SDL.h>
    #include <SDL_mixer.h>

class SdlSound: public graphic::ISound {

    public:

        SdlSound(std::string path) {
            sound = Mix_LoadWAV(path.c_str());
            channel = -1;
        }

        ~SdlSound() override {
            if (sound != NULL) {
                Mix_FreeChunk(sound);
            }
        }

        /**
         * @brief check if the sound is ready
         * 
         * @return true 
         * @return false 
         */
        bool isReady() const override {
            return false;//sound != NULL;
        }

        /**
         * @brief play the sound
         */
        void play() override {
            if (channel == -1)
                channel = Mix_PlayChannel(-1, sound, 0);
            else {
                Mix_Resume(channel);
            }
        }

        /**
         * @brief pause the sound
         * 
         */
        void pause() override {
            Mix_Pause(channel);
        }

        /**
         * @brief stop the sound and reset it to the beginning
         * 
         */
        void stop() override {
            if (channel != -1) {
                Mix_HaltChannel(channel);
            }
        }

        /**
         * @brief set the volume of the sound
         * 
         * @param volume 
         */
        void setVolume(float volume) override {
            Mix_VolumeChunk(sound, static_cast<int>(volume * 128));
        }

        /**
         * @brief get the volume of the sound
         * 
         * @return float 
         */
        float getVolume() const override {
            return static_cast<float>(Mix_VolumeChunk(sound, -1)) / 128.f;
        }

    private:
        Mix_Chunk* sound;
        int channel;
};



#endif /* !SDLSOUND_HPP_ */