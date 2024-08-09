#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm() = default;

    void execute(Bureaucrat const & executor) const override;

private:
    std::string target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
