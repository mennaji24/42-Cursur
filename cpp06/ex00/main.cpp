#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    } else {
        std::cerr << "Usage: ./convert <literal>\n";
    }
    return 0;
}
