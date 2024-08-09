#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
public:
    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override {
            return "Grade is too low!";
        }
    };

    class FormNotSignedException : public std::exception {
        const char* what() const noexcept override {
            return "Form is not signed!";
        }
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    virtual ~AForm() = default;

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const AForm& form);

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

#endif // AFORM_HPP
