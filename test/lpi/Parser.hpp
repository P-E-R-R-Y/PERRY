#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <typeindex>

#include "Lexer.hpp"

namespace AST {
  struct Node {
      virtual ~Node() = default;

      virtual void print(int = 0) = 0;
  };

  struct ListNode : public Node {
      ListNode() = default;
      ~ListNode() = default;

      void AddNode(const std::shared_ptr<Node>& node) {
        nodes.push_back(node);
      }

      void print(int i) override {
        for (auto& node: nodes) {
          if (node != nullptr) {
            node->print(i + 1);
          }
        }
      }
      std::vector<std::shared_ptr<Node>> nodes;
  };

  struct ImportNode : public Node {
      ImportNode() = default;
      ~ImportNode() = default;

      void print(int i) override {
        std::cout << std::string(i, '\t') << "import " << path << std::endl;
      }

      std::string path;
  };

  struct VariableNode : public Node {
      VariableNode(std::string name, std::shared_ptr<Node> value) : name(name), value(value) {}
      ~VariableNode() = default;

      void print(int i) override {
        std::cout << std::string(i, '\t') << name << std::endl;
        if (value != nullptr)
          value->print(i + 1);
      }

      std::string name;
      std::shared_ptr<Node> value;
  };

  struct Literals: public AST::Node {
    Literals(bool value) : value(value) {}
    Literals(int value) : value(value) {}
    Literals(double value) : value(value) {}
    Literals(std::string value) : value(value) {}
    ~Literals() = default;

    void print(int i) override {
      if (std::holds_alternative<bool>(value)) {
        std::cout << std::string(i, '\t') << std::get<bool>(value) << std::endl;
      } else if (std::holds_alternative<int>(value)) {
        std::cout << std::string(i, '\t') << std::get<int>(value) << std::endl;
      } else if (std::holds_alternative<double>(value)) {
        std::cout << std::string(i, '\t') << std::get<double>(value) << std::endl;
      } else if (std::holds_alternative<std::string>(value)) {
        std::cout << std::string(i, '\t') << std::get<std::string>(value) << std::endl;
      }
    }
    std::variant<bool, int, double, std::string> value;
  };

  struct LockType: public Node {
    LockType(std::string type) : type(type) {}
    ~LockType() = default;

    void print(int i) override {
      std::cout << std::string(i, '\t') << type << std::endl;
    }
    std::string type;
  };

  struct FunctionNode : public Node {
      FunctionNode(std::string name, std::vector<std::shared_ptr<Node>> args, std::shared_ptr<LockType> ret, std::shared_ptr<Node> body) : name(name), args(args), ret(ret), body(body) {}
      ~FunctionNode() = default;

      void print(int i) override {
        std::cout << std::string(i, '\t') << "func " << name << std::endl;
        for (auto& arg: args) {
          arg->print(i + 1);
        }
        if (ret != nullptr)
          ret->print(i + 1);
      }

      std::string name;
      std::vector<std::shared_ptr<Node>> args;
      std::shared_ptr<LockType> ret;
      std::shared_ptr<Node> body;
  };

}

class Parser {
  public:
    using ASTFunction = std::function<std::shared_ptr<AST::Node>(std::vector<Token>&, size_t&)>;

    Parser() = default;
    ~Parser() = default;

    void addASTFunc(uint16_t value, ASTFunction handler) {
      std::cout << "Adding AST Function for " << value << std::endl;
      astFuncs[value] = handler;
      std::cout << "Added AST Function for " << value << std::endl;
    }

    std::shared_ptr<AST::Node> parse(std::vector<Token>& tokens) {
      std::shared_ptr<AST::ListNode> root = std::make_shared<AST::ListNode>();

      for (size_t pos = 0; pos < tokens.size(); ++pos) {
        if (astFuncs.find(tokens[pos].type) != astFuncs.end()) {
          root->AddNode(astFuncs[tokens[pos].type](tokens, pos));
        }
      }
      return root;
    }

  private:
    std::unordered_map<uint16_t, ASTFunction> astFuncs;
};

#endif // PARSER_HPP