#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(const std::string &name, int signGrade, int execGrade)
    : name(name), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {
    checkGrade(signGrade);
    checkGrade(execGrade);
}

// Destructor
Form::~Form() {}

// Getters
const std::string &Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecGrade() const {
    return execGrade;
}

// Signing function
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Exception messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Check grade validity
void Form::checkGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Output operator overload
std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << form.getName() << ", form status: " << (form.isSigned() ? "signed" : "not signed")
       << ", sign grade required: " << form.getSignGrade()
       << ", execution grade required: " << form.getExecGrade();
    return os;
}
