#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN(const std::string &expr) : expression(expr) {}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char op, int a, int b) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) handleError("Division by zero");
        return a / b;
    default: handleError("Unknown operator");
    }
    return 0;
}

void RPN::handleError(const std::string &message) {
    std::cerr << "Error: " << message << std::endl;
    std::exit(EXIT_FAILURE);
}

int RPN::evaluate() {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (std::isdigit(token[0])) {
            stack.push(token[0] - '0');
        } else if (isOperator(token[0])) {
            if (stack.size() < 2) handleError("Insufficient operands");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = performOperation(token[0], a, b);
            stack.push(result);
        } else {
            handleError("Invalid token");
        }
    }
    if (stack.size() != 1) handleError("Invalid expression");
    return stack.top();
}
