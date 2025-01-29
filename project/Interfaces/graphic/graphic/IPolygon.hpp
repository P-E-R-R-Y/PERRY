/**
 * @file IPolygon.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */


#ifndef IPOLYGON_HPP_
    #define IPOLYGON_HPP_
    #include "../../../libraries/system/type.hpp"
    #include "../../../libraries/maths/geometry.hpp"
    #include "../window/IWindow.hpp"

using namespace type;

namespace graphic {
    
    /**
     * @brief Triangle structure
     */
    typedef struct triangle_s {
        __v2f_t A;
        __v2f_t B;
        __v2f_t C;
    } triangle_t;

    /**
     * @brief Polygon interface
     * @interface IPolygon 
     */
    class IPolygon {

        public:
            
            /**
             * @brief Destroy the IPolygon object
             */
            virtual ~IPolygon() = default;
            
            /**
             * @brief Get the Color object
             * 
             * @return __color_t 
             */
            virtual __color_t getColor() const = 0;

            /**
             * @brief Set the Color object
             * 
             * @param position 
             */
            virtual void setColor(__color_t position) = 0;
            
            /**
             * @brief Get the Position object
             * 
             * @return __v2f_t 
             */
            virtual bool isReady() const = 0;
            
            /**
             * @brief Get the Position object
             * 
             * @return __v2f_t 
             */
            virtual __v2f_t getPosition() const = 0;
            
            /**
             * @brief Set the Position object
             * 
             * @param position 
             */
            virtual void setPosition(__v2f_t position) = 0;
            
            /**
             * @brief Get the Points object
             * 
             * @return std::vector<__v2f_t> 
             */
            virtual std::vector<__v2f_t> getPoints() const = 0;
    };

} // namespace graphic

#endif /* !IPOLYGON_HPP_ */