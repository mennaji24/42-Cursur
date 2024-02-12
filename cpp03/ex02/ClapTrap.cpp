#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name) , hitPoints(10), energyPoints(10), attackDamage(0)
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
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack because it has no hit points or energy points left!" << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " has no hit points left and cannot take further damage!" << std::endl;
        return;
    }

    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired because it has no hit points or energy points left!" << std::endl;
        return;
    }

    energyPoints--; // Simulate the energy consumption required for the repair
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
}
