#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

class Bureaucrat {
public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

private:
    const std::string name;
    int grade;

    void checkGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_H
