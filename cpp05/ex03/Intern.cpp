#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <utility> // For std::pair

// Initialize the formCreators array
const std::pair<std::string, Intern::FormCreator> Intern::formCreators[] = {
    std::pair<std::string, Intern::FormCreator>("shrubbery creation", &Intern::createShrubberyCreationForm),
    std::pair<std::string, Intern::FormCreator>("robotomy request", &Intern::createRobotomyRequestForm),
    std::pair<std::string, Intern::FormCreator>("presidential pardon", &Intern::createPresidentialPardonForm)
};

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    for (size_t i = 0; i < sizeof(formCreators) / sizeof(formCreators[0]); ++i) {
        if (formCreators[i].first == formName) {
            AForm* form = (this->*formCreators[i].second)(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cerr << "Intern could not create form: " << formName << std::endl;
    return NULL;
}
