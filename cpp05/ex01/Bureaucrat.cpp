#include "Bureaucrat.hpp"

// Implementation of GradeTooHighException
const char* Bureaucrat::GradeTooHighExpception::what() const noexcept{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
    return "Grade is too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade){
    if (grade < 1){
        throw GradeTooHighExpception()
    }
    if (grade > 150){
        throw GradeTooLowException()
    }
}

//implementation of getName
const std::string& getName() const{
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade(){
    if(grade - 1 < 1){
        throw GradeTooHighExpception();
    }
    --grade;
}

std::ostream& operato<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Existing operator<< implementation
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}