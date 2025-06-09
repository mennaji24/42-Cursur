#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc("data.csv");

    std::string line;
    std::getline(input, line); // skip header

    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, sep);
        valueStr = line.substr(sep + 3);

        if (!BitcoinExchange::isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!BitcoinExchange::isValidValue(valueStr)) {
            double val = std::atof(valueStr.c_str());
            if (val < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double value = std::atof(valueStr.c_str());
        float rate = btc.getExchangeRate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }

    return 0;
}
