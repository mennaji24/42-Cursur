
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal //Derived class
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
		void getIdea(void)const;
		Brain* getBrain(void) const;
};

#endif
