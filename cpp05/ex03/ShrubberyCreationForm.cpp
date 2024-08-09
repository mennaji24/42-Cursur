#include "ShrubberyCreationForm.hpp"

// Constructor to initialize the form with target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

// Execute method to write ASCII trees to a file
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outfile(target + "_shrubbery");
    if (!outfile) {
        throw std::runtime_error("Could not open file");
    }

    outfile << "      /\\\n";
    outfile << "     /\\*\\\n";
    outfile << "    /\\O\\*\\\n";
    outfile << "   /*/\\/\\/\\\n";
    outfile << "  /\\O\\/\\*\\/\\\n";
    outfile << " /\\*\\/\\*\\/\\/\\\n";
    outfile << "/\\O\\/\\/*/\\/O/\\\n";
    outfile.close();
}
