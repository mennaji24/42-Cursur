#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp" // Base class for forms

class Intern {
public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string &formName, const std::string &target) const;

private:
    AForm* createShrubberyCreationForm(const std::string &target) const;
    AForm* createRobotomyRequestForm(const std::string &target) const;
    AForm* createPresidentialPardonForm(const std::string &target) const;
    typedef AForm* (Intern::*FormCreator)(const std::string &) const;

    // Map form names to creator functions
    static const std::pair<std::string, FormCreator> formCreators[];
};

#endif // INTERN_HPP
