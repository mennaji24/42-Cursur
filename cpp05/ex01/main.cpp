#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John Doe", 2);
        Form formA("Form A", 5, 10);

        std::cout << formA << std::endl;

        john.signForm(formA);  // Should print failure message

        Bureaucrat jane("Jane Smith", 6);
        jane.signForm(formA);  // Should print success message

        std::cout << formA << std::endl;

        Form formB("Form B", 1, 10);
        jane.signForm(formB);  // Should print failure message due to high required grade

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
