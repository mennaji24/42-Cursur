
#include <iostream>
#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "ANIMAL default constructor has been called" << std::endl;
};

Animal::Animal(const Animal &to_copy)
{
	*this = to_copy;
	std::cout << "ANIMAL copy constructor has been called" << std::endl;
}

Animal& Animal::operator=(const Animal &to_copy)
{
	this->type = to_copy.type;
	std::cout << "ANIMAL assignment operator has been called" << std::endl;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "ANIMAL default destructor has been called" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::setType(std::string type)
{
	this->type = type;
}

Brain *Animal::get_brain(void) const
{
	return (NULL);
}

void Animal::makeSound(void) const
{
	std::cout << "ANIMAL makeSound() has been called" << std::endl;
}
