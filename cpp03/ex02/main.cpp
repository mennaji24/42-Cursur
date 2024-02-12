#include "FragTrap.hpp"

int main(void)
{
	FragTrap Jim(" Jim");
	FragTrap Bob(" Bob");

	std::cout << std::endl;

	Jim.attack("Bob");
	Bob.takeDamage(5);
	Jim.highFivesGuys();

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
	
	return 0;
}

