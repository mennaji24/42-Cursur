#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 3);
        Bureaucrat jane("Jane Smith", 25);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("John Doe");
        PresidentialPardonForm pardon("Jane Smith");

        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        jane.signForm(robotomy);
        jane.executeForm(robotomy);

        john.signForm(pardon);
        john.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
