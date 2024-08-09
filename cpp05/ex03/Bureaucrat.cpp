#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    checkGrade();
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
const std::string &Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Increment grade
void Bureaucrat::incrementGrade() {
    --grade;
    checkGrade();
}

// Decrement grade
void Bureaucrat::decrementGrade() {
    ++grade;
    checkGrade();
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Check grade validity
void Bureaucrat::checkGrade() const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Output operator overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

// Sign form
void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn’t sign " << form << " because " << e.what() << std::endl;
    }
}

// Execute form
void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn’t execute " << form << " because " << e.what() << std::endl;
    }
}
