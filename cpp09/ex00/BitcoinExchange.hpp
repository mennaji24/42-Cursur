#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string &filename);
    ~BitcoinExchange();

    float getExchangeRate(const std::string &date) const;
    static bool isValidDate(const std::string &date);
    static bool isValidValue(const std::string &value);
    
private:
    std::map<std::string, float> _data;
    void loadData(const std::string &filename);
};

#endif
