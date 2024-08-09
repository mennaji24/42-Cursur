#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

// Forward declaration of AForm
class AForm;

class Bureaucrat {
public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form) const; // Update to AForm
    void executeForm(AForm const &form) const; // Update to AForm

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

#endif // BUREAUCRAT_HPP
