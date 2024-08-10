#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

// Define uintptr_t as an unsigned long for C++98 compatibility
typedef unsigned long my_uintptr_t;

class Serializer {
public:
    static my_uintptr_t serialize(Data* ptr);
    static Data* deserialize(my_uintptr_t raw);
};

#endif
