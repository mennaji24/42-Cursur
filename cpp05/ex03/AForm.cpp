#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name(name), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {
    checkGrade(signGrade);
    checkGrade(execGrade);
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string &AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

// Signing function
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Check grade validity
void AForm::checkGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Output operator overload
std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << ", form status: " << (form.isSigned() ? "signed" : "not signed")
       << ", sign grade required: " << form.getSignGrade()
       << ", execution grade required: " << form.getExecGrade();
    return os;
}
