#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Deafult FragTrap constructor " << name << " created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destuctor" << name << " is destroyed!" << std::endl;
}


void FragTrap::highFivesGuys() 
{
    std::cout << "Hey guys! Give me some high fives!" << std::endl;
}