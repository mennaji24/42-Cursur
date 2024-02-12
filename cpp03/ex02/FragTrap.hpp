#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        FragTrap();

    public:
        FragTrap(const std::string& name);
        ~FragTrap();
        void highFivesGuys();
};

#endif