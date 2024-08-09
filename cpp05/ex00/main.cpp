#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("John Doe", 50);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.decrementGrade();
        b1.decrementGrade();
        std::cout << b1 << std::endl;

        // This will throw an exception
        Bureaucrat b2("Jane Doe", 151);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
