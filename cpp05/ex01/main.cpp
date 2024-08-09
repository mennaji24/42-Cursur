#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 50);
        Form formA("Form A", 45, 70);

        std::cout << formA << std::endl;
        john.signForm(formA);  // Should succeed

        Bureaucrat jane("Jane Doe", 80);
        Form formB("Form B", 30, 60);

        std::cout << formB << std::endl;
        jane.signForm(formB);  // Should fail
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
