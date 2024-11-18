/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 00:01:34
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2024-11-11 23:29:28
 * @ Description:
 */

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <type_traits>
#include <typeindex>

#ifndef IEVENT_HPP
#define IEVENT_HPP

namespace graphic {

/**
 * @brief Event interface
 * 
 * This class is used to create a map of functions that can be invoked by name and return type.
 * 
 * @tparam T The return type of the functions that will be stored in the map
 * 
 * @note This class is not thread-safe
 * 
 * @example
 * 
 * ```cpp
 * IEvent event;
 * 
 * // Add a functiont(): that returns a bool and invoke it
 * event.add<bool>("isTrueTrue", []() { return true; });
 * event.invoke<bool>("isTrueTrue");
 * // Add a functiont(): that returns a double and invoke it
 * event.add<double>("getPotentiometreValue", []() { return 0.5; });
 * event.invoke<double>("getPotentiometreValue");
 * // Add a functiont(): that returns a std::string and invoke it
 * event.add<std::string>("getInputString", []() { return "Hello there!"; });
 * event.invoke<std::string>("getInputString");
 * ```
 */
class IEvent {

    public:
        // Add a function of type T to the map
        template <typename T>
        void add(std::string name ,std::function<T()> func) {
            // Add the function to the correct list for its return type
            auto& funcList = functionMaps[typeid(T)];
            funcList[name] = func;
        }

        // Invoke all functions of a specific type T
        template <typename T>
        T invoke(std::string name) {
            auto it = functionMaps.find(typeid(T));
            if (it != functionMaps.end()) {
                auto function = it->second;
                if function.find(name) != function.end() {
                    return function[name](); // Invoke the function
                } else {
                    std::cout << "No functions found for name: " << name << std::endl;
                }
                functionMaps[typeid(T)][name](); // Invoke the function
            } else {
                std::cout << "No functions found for type: " << typeid(T).name() << std::endl;
                return T();
            }
        }

    private:
        // A map where the key is the type of return value, and the value is a list of functions returning that type
        std::map<std::type_index, std::map<std::string, std::function<void()>>> functionMaps;

};

}

#endif // IEVENT_HPP
