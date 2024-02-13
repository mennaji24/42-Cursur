
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal  //Base class
{
	protected:
		std::string type;
		Brain* brain;
		
	public:
		Animal(void);
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal(void); 

		virtual std::string getType(void) const;
		virtual void setType(std::string type);
		virtual Brain* get_brain(void) const;

		virtual void makeSound(void) const;
};

#endif
