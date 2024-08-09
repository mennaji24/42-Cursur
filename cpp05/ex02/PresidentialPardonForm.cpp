#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor to initialize the form with target
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {}

// Execute method to pardon the target
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
