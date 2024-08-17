#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// Template function 'iter' to iterate over an array
template <typename T, typename F>
void iter(T* array, size_t length, F function) {
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

#endif
