#include "Bucreaut.hpp"

int main(){
    try{
        Bureaucrat john("John Doe", 2);
        std::cout << john << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << john << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jane("Jane Smith", 151);  // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jane("Jane Smith", 150);
        std::cout << jane << std::endl;

        jane.decrementGrade();
        std::cout << jane << std::endl;

        jane.decrementGrade();  // This will throw an exception
        std::cout << jane << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;

}