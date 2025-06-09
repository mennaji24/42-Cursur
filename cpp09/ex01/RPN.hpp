#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
    RPN(const std::string &expression);
    int evaluate();

private:
    std::string expression;
    std::stack<int> stack;

    bool isOperator(char c);
    int performOperation(char op, int a, int b);
    void handleError(const std::string &message);
};

#endif
