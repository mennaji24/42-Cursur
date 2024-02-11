#include "ClapTrap.hpp"

int main() 
{
    const std::string name = " ClapTrap1";
    ClapTrap claptrap(name);
    claptrap.attack("Target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(2);
    return 0;
}

