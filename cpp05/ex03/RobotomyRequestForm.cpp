#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Failed to robotomize " << target << "!" << std::endl;
    }
}
