#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat; // Forward declaration

class AForm {
public:
    AForm(const std::string &name, int signGrade, int execGrade);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        virtual const char* what() const throw();
    };

protected:
    void checkGrade(int grade) const;

private:
    const std::string name;
    bool signedStatus;
    const int signGrade;
    const int execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // AFORM_HPP
