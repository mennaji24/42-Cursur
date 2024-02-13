#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat &operator=(const Cat &to_copy);
		~Cat(void);

		void makeSound(void) const; //Attribute: polymorphic behavior
};

#endif
