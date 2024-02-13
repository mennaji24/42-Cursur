#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WRONG ANIMAL default constructor has been called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
{
	*this = to_copy;
	std::cout << "WRONG ANIMAL copy constructor has been called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &to_copy)
{
	this->type = to_copy.type;
	std::cout << "WRONG ANIMAL assignment operator has been called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WRONG ANIMAL default destructor has been called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WRONG ANIMAL makeSound() has been called" << std::endl;
}
