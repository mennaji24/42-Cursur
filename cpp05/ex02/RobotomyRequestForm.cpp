#include "RobotomyRequestForm.hpp"
#include <iostream>

// Constructor to initialize the form with target
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {
    std::srand(std::time(nullptr));
}

// Execute method to simulate robotomy
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy failed for " << target << "." << std::endl;
    }
}
