#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

Base* generate() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Randomly pick a number between 0 and 2
    int random = std::rand() % 3;

    // Return a new instance based on the random number
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;  // Should never reach here
}
