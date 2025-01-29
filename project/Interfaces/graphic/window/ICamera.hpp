/**
 * @file ICamera.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */
    

#ifndef ICAMERA_HPP_
    #define ICAMERA_HPP_
    #include "../../../libraries/system/type.hpp"
    #include "IWindow.hpp"

namespace graphic {

    /**
     * @brief Camera interface
     * @interface ICamera 
     */
    class ICamera {

        public:
            typedef enum{
                PERSPECTIVE,
                ORTHOGRAPHIC
            } Projection;

            typedef enum {
                CUSTOM = 0,              // Custom camera
                FREE,                    // Free camera
                ORBITAL,                 // Orbital camera
                FIRST_PERSON,            // First person camera
                THIRD_PERSON             // Third person camera
            } Mode;

            /**
             * @brief Destroy the ICamera object
             */
            virtual ~ICamera() = default;
            
            /**
             * @brief Get the FOV
             * 
             * @return float
             */
            virtual float getFov() const = 0;
            
            /**
             * @brief Set the FOV
             * 
             * @param fov
             */
            virtual void setFov(float fov) = 0;

            /**
             * @brief Get the mode
             * 
             * @return Mode
             */
            virtual Mode getMode() const = 0;

            /**
             * @brief Set the mode
             * 
             * @param mode
             */
            virtual void setMode(Mode mode) = 0;

            /**
             * @brief Get the position
             * 
             * @return __v3f_t
             */
            virtual __v3f_t getPosition() const = 0;

            /**
             * @brief Set the position
             * 
             * @param position 
             */
            virtual void setPosition(__v3f_t position) = 0;

            /**
             * @brief Get the Projection
             * 
             * @return __v3f_t
             */
            virtual Projection getProjection() const = 0;

            /**
             * @brief Set the Projection
             * 
             * @param projection
             */
            virtual void setProjection(Projection projection) = 0;
            
            /**
             * @brief Get the target
             * 
             * @return __v3f_t
             */
            virtual __v3f_t getTarget() const = 0;

            /**
             * @brief Set the target
             * 
             * @param size
             */
            virtual void setTarget(__v3f_t size) = 0;
            
            /**
             * @brief Get the up vector
             * 
             * @return __v3f_t
             */
            virtual __v3f_t getUp() const = 0;

            /**
             * @brief Set the up vector
             * 
             * @param up
             */
            virtual void setUp(__v3f_t up) = 0;

        private:
            //your variables here
    };

} // namespace graphic3

#endif /* !ICAMERA_HPP */