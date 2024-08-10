#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal)) {
        char c = literal[0];
        printConversions(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
    } else if (isInt(literal)) {
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || l < INT_MIN || l > INT_MAX) {
            handleException();
        } else {
            int i = static_cast<int>(l);
            printConversions(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
        }
    } else if (isFloat(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        if (errno == ERANGE) {
            handleException();
        } else {
            printConversions(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
        }
    } else if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE) {
            handleException();
        } else {
            printConversions(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
        }
    } else {
        handleException();
    }
}

bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal) {
    char *endptr;
    errno = 0;
    long l = std::strtol(literal.c_str(), &endptr, 10);
    return *endptr == '\0' && errno == 0;
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    char *endptr;
    errno = 0;
    float f = std::strtof(literal.c_str(), &endptr);
    return *endptr == 'f' && *(endptr + 1) == '\0' && errno == 0;
}

bool ScalarConverter::isDouble(const std::string &literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    char *endptr;
    errno = 0;
    double d = std::strtod(literal.c_str(), &endptr);
    return *endptr == '\0' && errno == 0;
}

void ScalarConverter::printConversions(char c, int i, float f, double d) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << i << '\n';
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << '\n';
}

void ScalarConverter::handleException() {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
