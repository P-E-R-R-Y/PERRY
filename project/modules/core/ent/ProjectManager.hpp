/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** ProjectManager
*/

#ifndef PROJECT_MANAGER_HPP_
    #define PROJECT_MANAGER_HPP_

    #include <type_traits>

    // ProjectManager
    #include "ProjectComponentManager.hpp"
    #include "Ecs.hpp"

/**
 * @namespace Project
 *
 * @author perry.chouteau@epitech.eu
 */
namespace Project {

    /**
     * @brief ProjectManager
     *
     * @author perry.chouteau@epitech.eu
     */
    class ProjectManager {
        public:

            ProjectManager()
            {
                config_extractor<projectConfig::componentsList>::function(_ecs);
            };

            ~ProjectManager() = default;

            /**
             * @brief Client
             *
             * @param ip
             * @param port
             * @return int
             */
            virtual int Start() = 0;

////////////////////////////////////////////////////////////////////////////////////////////////

        protected:

            /**
             * @brief Config Extractor (default will make the compilation failed) [Dark C++]
             * @def the config extractor is used to extract all component need at the start of the program
             *
             * @tparam T
             */
            template <class T>
            struct config_extractor {
                static_assert(std::is_same_v<T, std::tuple<>>, "component_list in ComponentManager.hpp should be a tuple of Components");
            };

            /**
             * @brief Config Extractor (specification won't make the compilation failed) [Dark C++]
             * @def the config extractor is used to extract all component need at the start of the program
             *
             * @tparam Components
             */
            template <class ... Components>
            struct config_extractor<std::tuple<Components...>> {
                /**
                 * @brief this function will extract all component need at the start of the program and register them in the ECS
                 *
                 * @param r
                 */
                static void function(registry &r) {
                    (r.registerComponent<Components>(), ...);
                }
            };

        protected:
            registry _ecs;
    };

};

#endif /* !PROJECT_MANAGER_HPP_ */