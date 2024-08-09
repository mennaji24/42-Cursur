#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm() = default;

    void execute(Bureaucrat const & executor) const override;

private:
    std::string target;
};

#endif // PRESIDENTIALPARDONFORM_HPP
