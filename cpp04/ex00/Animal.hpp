#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
#include <iostream>

class Animal  //Base class
{
	protected:
		std::string type;
		
	public:
		Animal(void);
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal(void);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const; //virtual -> Polymorphism
};

#endif
