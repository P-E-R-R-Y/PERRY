//Std
#include <tuple>
#include <type_traits> //std::is_same_v
#include <iostream>

class ComponentExtractor {
    public:
        ~ComponentExtractor() = default;

    protected:

        /**
         * @brief Config Extractor (default will make the compilation failed) [Dark C++]
         * @def the config extractor is used to extract all component need at the start of the program
         *
         * @tparam T
         */
        template <class T>
        struct config_extractor { // ne devrait jamais être instancié sauf erreur => gestion d'erreur
            static_assert(std::is_same_v<T, std::tuple<>>, "component_list in ComponentManager.hpp should be a tuple of Components"); // empeche la compilation si T n'est pas std::tuple<int> (ce qui ne peux jamais arriver)
        };

        /**
         * @brief Config Extractor (specification won't make the compilation failed) [Dark C++]
         * @def the config extractor is used to extract all component need at the start of the program
         *
         * @tparam Components
         */
        template <class ... Components>
        struct config_extractor<std::tuple<Components...>> { // overload si T est un tuple de choses. Ne clash pas avec la def précédentes
            /**
             * @brief this function will extract all component need at the start of the program and register them in the ECS
             * 
             * @param registry
            */
            static void function(registry &r) {
                (r.register_component<Components>(), ...);
            }
        };
};