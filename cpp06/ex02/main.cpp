#include "Base.hpp"
#include <iostream>

int main() {
    Base* base = generate();
    std::cout << "Identify using pointer: ";
    identify(base);
    std::cout << "Identify using reference: ";
    identify(*base);

    delete base; // Don't forget to free the memory!
    return 0;
}
