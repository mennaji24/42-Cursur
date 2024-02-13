#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal() //inheritance
{
	std::cout << "DOG default constructor has been called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	*this = to_copy;
	std::cout << "DOG copy constructor has been called " << std::endl;
}

Dog& Dog::operator=(const Dog &to_copy)
{
    this->type = to_copy.type;
	std::cout << "DOG assignment operator has been called " << std::endl;
    return *this;
}

Dog::~Dog(void)
{
	std::cout << "DOG default destructor has been called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "\"Arf!\"" << std::endl;
}
