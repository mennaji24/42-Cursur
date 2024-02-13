
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &to_copy);
		Brain &operator=(const Brain &to_copy);
		~Brain(void);

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea);
		const std::string *getIdeaAddress(size_t i)const;
};

#endif
