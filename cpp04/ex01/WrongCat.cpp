

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WRONG CAT default constructor has been called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy)
{
	this->type = to_copy.type;
	std::cout << "WRONG CAT copy constructor has been called " << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	std::cout << "WRONG CAT assignment operator has been called " << std::endl;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WRONG CAT default destructor has been called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "\"Wrong Meow...\"" << std::endl;
}
