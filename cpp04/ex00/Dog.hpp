#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
#include <iostream>

class Dog : public Animal //Derived class
{
	public:
		Dog(void);
		Dog(const Dog &original);
		Dog &operator=(const Dog &to_copy);
		~Dog(void);

		void makeSound(void) const; //Attribute: polymorphic behavior
};

#endif
