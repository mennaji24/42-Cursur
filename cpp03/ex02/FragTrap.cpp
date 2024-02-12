#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
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