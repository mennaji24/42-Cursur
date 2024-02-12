#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name) , hitPoints(10), energyPoints(10), attackDamage(10)
{
    std::cout << "ClapTrap" << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    name = copy.name;
    hitPoints = copy.hitPoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    std::cout << "Copy constructor was called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
    if(this != &original){
        this->name = original.name;
        this->hitPoints = original.hitPoints;
        this->energyPoints = original.energyPoints;
        this->attackDamage = original.attackDamage;
    }
    std::cout << "Copy assignment constuctor was called!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if(energyPoints < 1)
    {
        std::cout << "ClapTrap " << name << " doesn't have enough energy attack! " << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
    if(hitPoints == 0){
        std::cout << "ClapTrap " << name << " doesn't have enough energy to be repaired!" << std::endl;
        return;
    }
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
 }
 //amount of damage  function 
 void ClapTrap::beRepaired(unsigned int amount)
 {
    if(energyPoints < 1){
        std::cout << "ClapTrap " << name << " doesn't have enough energy to be repaired!" << std::endl;
        return;
    }
    energyPoints--; //simulate the energy consumation  required for the repair
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
}
