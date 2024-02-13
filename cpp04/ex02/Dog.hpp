

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal //Derived class
{
	private:
		Brain* brain;
		std::string type;
		
	public:
		Dog(void);
		Dog(const Dog &original);
		Dog &operator=(const Dog &to_copy);
		~Dog(void);

		void makeSound(void) const; //Polymorphic behavior
		Brain* getBrain(void) const;
};

#endif
