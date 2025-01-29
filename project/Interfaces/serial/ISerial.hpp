/**
 * @file ISerial.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup serial
 * @{
 */

#ifndef ISERIAL_HPP
#define ISERIAL_HPP

#include <variant>
#include <vector>
#include <map>

namespace serial {

    /**
     * @brief easy to Manage YAML, JSON, XAML and data serialization formats in C++.
     */
    class Node {
        public:
            using node_type = std::variant<bool, int, double, std::string, std::vector<Node>, std::map<std::string, Node>, void *>;
            
            Node() = default;
            Node(node_type node): value(node) {};
            ~Node() = default;

            bool isScalar() {
                return std::holds_alternative<bool>(value) || std::holds_alternative<int>(value) || std::holds_alternative<double>(value) || std::holds_alternative<std::string>(value) ;
            }

            bool isSequence() {
                return std::holds_alternative<std::vector<Node>>(value);
            }

            bool isMap() {
                return std::holds_alternative<std::map<std::string, Node>>(value);
            }

            //scalar types
            bool isBool() {
                return std::holds_alternative<bool>(value);
            }

            bool isInt() {
                return std::holds_alternative<int>(value);
            }

            bool isDouble() {
                return std::holds_alternative<double>(value);
            }

            bool isString() {
                return std::holds_alternative<std::string>(value);
            }
            
            bool isNull() {
                return std::holds_alternative<void *>(value);
            }

            Node operator[](const std::string& key) {
                if (std::holds_alternative<std::map<std::string, Node>>(value)) {
                    return std::get<std::map<std::string, Node>>(value)[key];
                } else {
                    throw std::runtime_error("Node is not a map");
                }
            }

            Node operator[](const int& index) {
                if (isSequence()) {
                    return std::get<std::vector<Node>>(value)[index];
                } else {
                    throw std::runtime_error("Node is not a sequence");
                }
            }

            template <typename T>
            T as() {
                return std::get<T>(value);
            } 

        public:
            node_type value;
    };

    /**
     * @brief Interface for Serial
     * @interface ISerial
     * 
     */
    class ISerial {
        public:

            /**
             * @brief Destroy the ISerial object
             * 
             * @param path 
             */
            virtual ~ISerial() = default;
            
            /**
             * @brief virtual method to load a file
             * 
             * @param path 
             */
            virtual void load(const std::string& path) = 0;

            /**
             * @brief virtual method to know if the file is loaded
             * 
             * @param path 
             */
            virtual bool isLoaded() = 0;

            /**
             * @brief virtual method to close a file
             * 
             * @param path 
             */
            virtual void close() = 0;

            /**
             * @brief virtual method to get the root node
             * 
             * @param path 
             */
            virtual Node getRoot() = 0;
        
        private:
    };

} // namespace serial

#endif // ISERIAL_HPP