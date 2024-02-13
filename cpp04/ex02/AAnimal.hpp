

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string type;
		
	public:
		AAnimal(void);
		AAnimal(const AAnimal &to_copy);
		AAnimal &operator=(const AAnimal &to_copy);
		virtual ~AAnimal(void);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;
		//Pure virtual function: Any class deriving from AAnimal 
		// must provide its own implementation of makeSound()
};

#endif