#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern() = default;
    ~Intern() = default;

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target);
    
    AForm* createShrubberyCreationForm(const std::string& target);
    AForm* createRobotomyRequestForm(const std::string& target);
    AForm* createPresidentialPardonForm(const std::string& target);
};

#endif // INTERN_HPP
