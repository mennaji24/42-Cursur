#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
public:
    //nested exeption class
    class GradeTooHighExpception; public std::exception {
        const char* what() const noexcept override;
    };
    
    class GradeTooLowException : public std::exception {
        const char * what() const noexcept ovveride;
    };

    //declare a constructor for initialize name & grade 
    Bureaucrat(const std::string& name, int grade);

    //Getters
    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    //Operator overload
    //Operator Overload: Declares an overload of the insertion (<<) operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
    
private:
    const std::string name;
    int grade;
}
#endif 