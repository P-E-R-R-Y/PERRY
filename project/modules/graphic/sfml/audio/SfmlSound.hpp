/**
 * @file SfmlSound.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-04
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef SFMLSOUND_HPP_
    #define SFMLSOUND_HPP_

    #include "ISound.hpp"

class SfmlSound: public graphic::ISound {

    public:

        SfmlSound(std::string path) {
        }

        ~SfmlSound() override {
        }

        bool isReady() const override { return true; } //sfml sound is always ready

        /**
         * @brief play the sound
         */
        void play() override {
        }

        /**
         * @brief pause the sound
         * 
         */
        void pause() override {
        }

        /**
         * @brief stop the sound and reset it to the beginning
         * 
         */
        void stop() override {
        }

        /**
         * @brief set the volume of the sound
         * 
         * @param volume 
         */
        void setVolume(float volume) override {
        }

        /**
         * @brief get the volume of the sound
         * 
         * @return float 
         */
        float getVolume() const override {
            return 0;
        }

    private:

};

#endif /* !SFMLSOUND_HPP_ */