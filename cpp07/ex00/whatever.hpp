#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/* template takes two arguments 
by reference, swaps their values using a temporary variable*/
template <typename T> //tamplate allow to create a single function  that can work with different data types
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

// Template to find the minimum of two values
template <typename T>
T const &min(T const &a, T const &b) {
    return (a < b) ? a : b;
}

// Template to find the maximum of two values
template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b) ? a : b;
}

#endif