#include "FragTrap.hpp"

int main() 
{
    const std::string name = " ScavTrap1";
    FragTrap FragTrap(name);
    FragTrap.attack("Target1");
    FragTrap.takeDamage(3);
    FragTrap.beRepaired(2);
    FragTrap.highFivesGuys();
    return 0;
}
