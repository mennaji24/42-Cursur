#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Jim("Jim");
	ScavTrap Bob("Bob");

	std::cout << std::endl;

	Jim.attack("Bob");
	Bob.takeDamage(5);

    std::cout << std::endl;

	Jim.attack("Bob");
	Bob.takeDamage(1);

	std::cout << std::endl;

	Jim.attack("Bob");
	Bob.takeDamage(1);

	std::cout << std::endl;

	Bob.beRepaired(7);

	std::cout << std::endl;

	Jim.attack("Bob");
	Bob.takeDamage(10);

	std::cout << std::endl;

	Jim.attack("Bob");
	Bob.takeDamage(200);

	std::cout << std::endl;
	
	Bob.attack("Jim");

	std::cout << std::endl;

	Jim.guardGate();

	std::cout << std::endl;
	
	return 0;
}
