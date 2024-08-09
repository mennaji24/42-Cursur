#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration

class Form {
public:
    Form(const std::string &name, int signGrade, int execGrade);
    ~Form();

    const std::string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

private:
    const std::string name;
    bool signedStatus;
    const int signGrade;
    const int execGrade;

    void checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // FORM_H
