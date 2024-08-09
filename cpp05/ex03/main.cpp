#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 50);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("home");
        PresidentialPardonForm pardon("home");

        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        john.signForm(robotomy);
        john.executeForm(robotomy);

        john.signForm(pardon);
        john.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

