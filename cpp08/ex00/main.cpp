#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    // Initialize the vector in C++98 compatible way
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
