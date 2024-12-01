#ifndef ISERIAL_HPP
#define ISERIAL_HPP

#include <variant>
#include <vector>
#include <map>

/**
 * @brief easy to Manage YAML, JSON, XAML and data serialization formats in C++
 * 
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

class ISerial {
    public:
        virtual ~ISerial() = default;
        
        virtual void load(const std::string& path) = 0;
        virtual bool isLoaded() = 0;
        virtual void close() = 0;
        virtual Node getRoot() = 0;
    
    private:
};

#endif // ISERIAL_HPP