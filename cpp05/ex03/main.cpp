#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 3);
        Bureaucrat jane("Jane Smith", 25);

        Intern someRandomIntern;

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "John Doe");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Jane Smith");
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Nowhere");

        if (shrubbery) {
            john.signForm(*shrubbery);
            john.executeForm(*shrubbery);
            delete shrubbery;
        }

        if (robotomy) {
            jane.signForm(*robotomy);
            jane.executeForm(*robotomy);
            delete robotomy;
        }

        if (pardon) {
            john.signForm(*pardon);
            john.executeForm(*pardon);
            delete pardon;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
