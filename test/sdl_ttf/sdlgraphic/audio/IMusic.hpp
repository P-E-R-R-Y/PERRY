/**
 * @file IAudio.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-02
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef IMUSIC_HPP_
    #define IMUSIC_HPP_

    #include "type.hpp"
    #include <string>

namespace graphic {

    class IMusic {

        public:

            virtual ~IMusic() = default;

            virtual bool isReady() const = 0;

            /**
             * @brief play the music
             */
            virtual void play() = 0;

            /**
             * @brief pause the music
             * 
             */
            virtual void pause() = 0;

            /**
             * @brief stop the music and reset it to the beginning
             * 
             */
            virtual void stop() = 0;

            /**
             * @brief update the music
             * 
             */
            virtual void update() = 0;

            /**
             * @brief set the volume of the music
             * 
             * @param volume 
             */
            virtual void setVolume(float volume) = 0;

            /**
             * @brief get the volume of the music
             * 
             * @return float 
             */
            virtual float getVolume() const = 0;

            /**
             * @brief set the music to loop or not
             * 
             * @param loop 
             */
            virtual void setLoop(bool loop) = 0;

            /**
             * @brief get if the music is looping or not
             * 
             * @return true 
             * @return false 
             */
            virtual bool getLoop() const = 0;

            /**
             * @brief Set the time of the music in seconds
             * 
             * @param position 
             */
            virtual void setTime(float position) = 0;

            /**
             * @brief Get the current time of the music in seconds
             * 
             * @return float 
             */
            virtual float getTime() const = 0;

            /**
             * @brief Get the Length of the music
             * 
             * @return float 
             */
            virtual float getLength() const = 0;
    };

}

#endif /* !IMUSIC_HPP_ */