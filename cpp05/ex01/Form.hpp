#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

 class Form {
public:
    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override {
            return "Form grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override {
            return "Form grade is too low!";
        }
    };

    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    friend std::ostream& operator<<(std::ostream& os, const Form& form);

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

#endif 

