#include "Intern.hpp"

// Method to create a ShrubberyCreationForm
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

// Method to create a RobotomyRequestForm
AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

// Method to create a PresidentialPardonForm
AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Method to create a form based on the given name and target
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator formCreators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (size_t i = 0; i < sizeof(formNames) / sizeof(std::string); ++i) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cout << "Error: Form name " << formName << " does not exist" << std::endl;
    return nullptr;
}
