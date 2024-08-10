#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cctype>


class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    static void printConversions(char c, int i, float f, double d);
    static void handleException();
};

#endif

