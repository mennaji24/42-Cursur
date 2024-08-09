#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    // Convert std::string to const char* using c_str()
    std::ofstream file((target + "_shrubbery").c_str()); 
    if (file.is_open()) {
        file << "ASCII Trees\n"; // Simplified example
        file.close();
    } else {
        std::cerr << "Failed to create file." << std::endl;
    }
}
