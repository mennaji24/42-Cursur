// Array.hpp
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // For std::exception and std::out_of_range

template <typename T>
class Array {
private:
    T* _data;          // Pointer to the array
    unsigned int _size; // Number of elements in the array

public:
    // Default constructor: creates an empty array
    Array() : _data(NULL), _size(0) {}

    // Constructor with size parameter: creates an array of n elements
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor: creates a deep copy of the array
    Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    // Assignment operator: creates a deep copy of the array
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Destructor: releases allocated memory
    ~Array() {
        delete[] _data;
    }

    // Subscript operator: access elements with bounds checking
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Const version of subscript operator
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Size function: returns the number of elements in the array
    unsigned int size() const {
        return _size;
    }
};

#endif
