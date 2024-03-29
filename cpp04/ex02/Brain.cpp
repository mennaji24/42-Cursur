

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "BRAIN default constructor has been called" << std::endl;
};

Brain::Brain(const Brain &to_copy)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = to_copy.ideas[i];
    }
    std::cout << "BRAIN copy constructor has been called" << std::endl;
}

Brain& Brain::operator=(const Brain &to_copy)
{
    if (this != &to_copy)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = to_copy.ideas[i];
        }
        std::cout << "BRAIN assignment operator has been called" << std::endl;
    }
    return *this;
}

Brain::~Brain(void) {
	std::cout << "BRAIN default destructor has been called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
	else
        return "Invalid Index";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}
