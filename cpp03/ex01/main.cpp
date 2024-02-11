#include "ScavTrap.hpp"

int main() 
{
    const std::string name = " ScavTrap1";
    ScavTrap ScavTrap(name);
    ScavTrap.attack("Target1");
    ScavTrap.takeDamage(3);
    ScavTrap.beRepaired(2);
    ScavTrap.guardGate();
    return 0;
}
