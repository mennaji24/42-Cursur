#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& n) : name(n) , hitPoints(100), energyPoints(50), attackDamage(20)
{
    std::cout << "ScavTrap" << name << " created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
 {
    if(energyPoints < 1){
        std::cout << "ScavTrap " << name << " doesn't have enough energy attack! " << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void  ScavTrap::takeDamage(unsigned int amount)
{
    if(hitPoints == 0){
        std::cout << "ScavTrap " << name << " doesn't have enough energy to be repaired!" << std::endl;
        return;
    }
    hitPoints -= amount;
    std::cout << "ScavTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
 {
    if(energyPoints < 1){
        std::cout << "ScavTrap " << name << " doesn't have enough energy to be repaired!" << std::endl;
        return;
    }
    energyPoints--; //simulate the energy consumation  required for the repair
    hitPoints += amount;
    std::cout << "ScavTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap" << name << " is now in Gate keeper mode." << std::endl;
}