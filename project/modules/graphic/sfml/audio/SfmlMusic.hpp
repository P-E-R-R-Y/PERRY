/**
 * @file SfmlMusic.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-04
 */

#ifndef SFMLMUSIC_HPP_
    #define SFMLMUSIC_HPP_

    //Interface
    #include "IMusic.hpp"

    //Sfml
    #include <SFML/Audio.hpp>

class SfmlMusic: public graphic::IMusic {

    public:

        /**
         * @brief Construct a new Ray Music
         * 
         * @param path 
         */
        SfmlMusic(std::string path) {
        }
        
        /**
         * @brief Destroy the Ray Music
         * 
         */
        ~SfmlMusic() override {
        }

        /**
         * @brief check if the music is ready
         * 
         * @return true 
         * @return false 
         */
        bool isReady() const override { return true; } //sfml music is always ready

        /**
         * @brief play the music
         */
        void play() override {
        }

        /**
         * @brief pause the music
         * 
         */
        void pause() override {
        }

        /**
         * @brief stop the music and reset it to the beginning
         * 
         */
        void stop() override {
        }

        void update() override {
        }

        /**
         * @brief set the volume of the music
         * 
         * @param volume 
         */
        void setVolume(float volume) override {
        }

        /**
         * @brief get the volume of the music or if not set the master volume
         * 
         * @return float 
         */
        float getVolume() const override {
            return 0;
        }

        /**
         * @brief set the music to loop or not
         * 
         * @param loop 
         */
        void setLoop(bool loop) override {
        }

        /**
         * @brief get if the music is looping or not
         * 
         * @return true 
         * @return false 
         */
        bool getLoop() const override {
            return false;
        }

        /**
         * @brief Set the time of the music in seconds
         * 
         * @param position 
         */
        void setTime(float position) override {
        }

        /**
         * @brief Get the current time of the music in seconds
         * 
         * @return float 
         */
        float getTime() const override {
            return 0;
        }

        /**
         * @brief Get the Length of the music
         * 
         * @return float 
         */
        float getLength() const override {
            return 0;
        }

    private:

};

#endif /* !SFMLMUSIC_HPP_ */