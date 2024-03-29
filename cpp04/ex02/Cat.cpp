
#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	this->setType("Cat");
	this->brain = new Brain();
	brain->setIdea(0, "Original Cat Idea");
	std::cout << "CAT default constructor has been called" << std::endl;
}

Cat::Cat(const Cat &to_copy) : AAnimal(to_copy)
{
    this->brain = new Brain();
	*this = to_copy;
    std::cout << "CAT copy constructor has been called " << std::endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	this->type = to_copy.type;
	*(this->brain) = *(to_copy.brain);
    std::cout << "CAT assignment operator has been called " << std::endl;
    return *this;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "CAT default destructor has been called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "\"Meow...\"" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return (this->brain);
}
