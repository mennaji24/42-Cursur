#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class AForm; // Forward declaration

class Bureaucrat {
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

    Bureaucrat(const std::string& name, int grade);
    
    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& form) const;
    void executeForm(AForm const & form) const;

    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

private:
    const std::string name;
    int grade;
};

#endif // BUREAUCRAT_HPP
