#include "iter.hpp"

// Function to be applied to each element: Print the element
template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer array elements:" << std::endl;
    iter(intArray, 5, printElement<int>); // Specify the type explicitly

    // Test with an array of strings
    std::string stringArray[] = {"hello", "world", "iter", "template"};
    std::cout << "String array elements:" << std::endl;
    iter(stringArray, 4, printElement<std::string>); // Specify the type explicitly

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Double array elements:" << std::endl;
    iter(doubleArray, 4, printElement<double>); // Specify the type explicitly

    return 0;
}
