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

    #include <SFML/Audio.hpp>

class SfmlSound: public graphic::ISound {

    public:

        SfmlSound(std::string path) {
            _ready = buffer.loadFromFile(path);
            if (_ready) {
                sound.setBuffer(buffer);
            }
        }

        ~SfmlSound() override { }

        bool isReady() const override { return _ready; } //sfml sound is always ready

        /**
         * @brief play the sound
         */
        void play() override {
            sound.play();
        }

        /**
         * @brief pause the sound
         * 
         */
        void pause() override {
            sound.pause();
        }

        /**
         * @brief stop the sound and reset it to the beginning
         * 
         */
        void stop() override {
            sound.stop();
        }

        /**
         * @brief set the volume of the sound
         * 
         * @param volume 
         */
        void setVolume(float volume) override {
            sound.setVolume(volume * 100);
        }

        /**
         * @brief get the volume of the sound
         * 
         * @return float 
         */
        float getVolume() const override {
            return sound.getVolume();
        }

    private:

        sf::SoundBuffer buffer;
        sf::Sound sound;
        bool _ready;

};

#endif /* !SFMLSOUND_HPP_ */