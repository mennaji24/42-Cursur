#include "AForm.hpp"

// Constructor to initialize the form
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Getters for the form attributes
const std::string& AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

// Method to sign the form if the bureaucrat's grade is high enough
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Overload the << operator to print form details
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign()
       << " to sign, grade " << form.getGradeToExecute() << " to execute. "
       << (form.isSigned() ? "Form is signed." : "Form is not signed.");
    return os;
}
