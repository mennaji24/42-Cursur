#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    loadData(filename);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string &filename) {
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {
            float value = std::atof(valueStr.c_str());
            _data[date] = value;
        }
    }
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it != _data.begin() && (it == _data.end() || it->first != date))
        --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    if (date.length() != 10 ||
        date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    return (y >= 2009 && m >= 1 && m <= 12 && d >= 1 && d <= 31);
}

bool BitcoinExchange::isValidValue(const std::string &valueStr) {
    double value = std::atof(valueStr.c_str());
    return value >= 0.0 && value <= 1000.0;
}
