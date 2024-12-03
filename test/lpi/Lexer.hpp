#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include <cctype>
#include <regex>

// Token structure
class Token {
    public:
        uint16_t type;
        std::string value;
    
    public:
    Token(uint16_t type, const std::string& value) : type(type), value(value) {}
};

class Lexer {
public:
    using RuleFunction = std::function<Token(const std::smatch&)>;

    Lexer() {
        addType("unknown", static_cast<uint16_t>(-1));
    };

    void addType(std::string name, uint16_t type) {
        types[name] = type;
        inversedTypes[type] = name;
    }

    void addRule(const std::string& pattern, RuleFunction handler) {
        rules.emplace_back(std::regex(pattern), handler);
    }

    std::vector<Token> tokenize(const std::string& path) {
        std::ifstream file(path);
        //isOpen
        if (!file.is_open()) { return {}; }

        std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        std::string input = data;
        size_t pos = 0;

        std::vector<Token> tokens;

        while (pos < input.size()) {
            // Skip whitespace
            if (std::isspace(input[pos])) {
                ++pos;
                continue;
            }

            bool matched = false;

            for (const auto& [pattern, handler] : rules) {
                std::smatch match;
                std::string remaining = input.substr(pos);

                if (std::regex_search(remaining, match, pattern) && match.position(0) == 0) {
                    tokens.push_back(handler(match));
                    pos += match.length(0);
                    matched = true;
                    break;
                }
            }
            
            if (!matched) {
                tokens.emplace_back(this->at("unknown"), std::string(1, input[pos]));
                ++pos;
            }
        }
        return tokens;
    }
public:
    uint16_t at(const std::string& name) {
        return types.at(name);
    }
    
    std::string at(uint16_t type) {
        return inversedTypes.at(type);
    }

private:
    std::unordered_map<std::string, uint16_t> types;
    std::unordered_map<uint16_t, std::string> inversedTypes;
    std::vector<std::pair<std::regex, RuleFunction>> rules;
};

/*// Lexer class
class Lexer {
public:
    explicit Lexer() : pos(0) {}

    // Load method to process input string
    std::vector<Token> load(const std::string& data) {
        this->input = data;
        pos = 0;
        tokens.clear();
 
        while (pos < input.size()) {
            while (input[pos] != input.size() && std::isspace(input[pos])) {
                pos++;
            }
            for (const auto& [is, get] : tokenParsers) {
                if (is()) { // If a parser matches, exit loop
                    tokens.push_back(get());
                    break;
                }
            }
        }
        // Add EndOfFile token
        tokens.emplace_back(Token::Type::EndOfFile, "");
        return tokens;
    }

private:
    std::string input;
    size_t pos; // Current position in the input string
    std::vector<Token> tokens;

    std::vector<std::string> keywords = {"var", "func", "if", "else", "while", "return"};
    std::vector<std::string> type = {"int", "float", "double", "char", "void"};
    std::string operators = "+*-/=!.";
    std::string separators = "(){}[],;:";
    // Token parsers stored in an unordered_map
    std::vector<std::pair<std::function<bool()>, std::function<Token()>>> tokenParsers = {
        // Number
        {[this]() -> bool {
            return std::isdigit(input[pos]);
        }, [this]() -> Token {
            std::string value;
            while (std::isdigit(input[pos])) {
                value += input[pos++];
            }
            return Token(Token::Type::Number, value);
        }},
        // Keywords & Identifiers
        {[this]() -> bool {
            return std::isalpha(input[pos]);
        }, [this]() -> Token {
            std::string value;
            while (std::isalnum(input[pos])) {
                value += input[pos++];
            }
            for (const auto& keyword : keywords) {
                if (value == keyword) {
                    return Token(Token::Type::Keyword, value);
                }
            }
            return Token(Token::Type::Identifier, value);
        }},
        //Operator
        {[this]() -> bool {
            return operators.find(input[pos]) != std::string::npos;
        }, [this]() -> Token {
            std::string value(1, input[pos++]);
            return Token(Token::Type::Operator, value);
        }},
        //Separator
        {[this]() -> bool {
            return separators.find(input[pos]) != std::string::npos;
        }, [this]() -> Token {
            std::string value(1, input[pos++]);
            return Token(Token::Type::Operator, value);
        }},

        //unknown
        {[]() -> bool {
            return true;
        }, [this]() -> Token {
            return Token(Token::Type::Unknown, std::string(1, input[pos++]));
        }},
    };
};*/

#endif // LEXER_HPP