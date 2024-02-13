

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal //Derived class
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
		void getIdea(void)const;
		Brain* getBrain(void) const;
};

#endif
