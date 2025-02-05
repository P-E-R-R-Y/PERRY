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

#ifndef ISOUND_HPP_
    #define ISOUND_HPP_

    #include "../../../libraries/system/type.hpp"
    #include <string>

namespace graphic {

    class ISound {

        public:

            virtual ~ISound() = default;

            virtual bool isReady() const = 0;

            /**
             * @brief play the sound
             */
            virtual void play() = 0;

            /**
             * @brief pause the sound
             * 
             */
            virtual void pause() = 0;

            /**
             * @brief stop the sound and reset it to the beginning
             * 
             */
            virtual void stop() = 0;

            /**
             * @brief set the volume of the sound
             * 
             * @param volume 
             */
            virtual void setVolume(float volume) = 0;

            /**
             * @brief get the volume of the sound
             * 
             * @return float 
             */
            virtual float getVolume() const = 0;

    };

}

#endif /* !ISOUND_HPP_ */