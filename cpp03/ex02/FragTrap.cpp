#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& n) : name(n) , hitPoints(100), energyPoints(100), attackDamage(30)
{
    std::cout << "FragTrap" << name << " created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string &target)
 {
    if(energyPoints < 1){
        std::cout << "FragTrap " << name << " doesn't have enough energy attack! " << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void  FragTrap::takeDamage(unsigned int amount)
{
    if(hitPoints == 0){
        std::cout << "FragTrap " << name << " doesn't have enough energy to be repaired!" << std::endl;
        return;
    }
    hitPoints -= amount;
    std::cout << "FragTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if(energyPoints < 1)
    {
        std::cout << "FragTrap " << name << " doesn't have enough energy to be repaired!" << std::endl;
        return;
    }
    energyPoints--; //simulate the energy consumation  required for the repair
    hitPoints += amount;
    std::cout << "FragTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
}

void FragTrap::highFivesGuys() 
{
    std::cout << "Hey guys! Give me some high fives!" << std::endl;
}