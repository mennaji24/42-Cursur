

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal //Derived class
{
	private:
		Brain* brain;
		std::string type;
		
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat &operator=(const Cat &to_copy);
		~Cat(void);

		void makeSound(void) const; //Polymorphic behavior
		Brain* getBrain(void) const;
};

#endif
