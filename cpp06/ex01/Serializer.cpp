#include "Serializer.hpp"

/*serialize: We use reinterpret_cast to convert the Data* pointer to a uintptr_t.
 This cast doesn't change the bits of the pointer, 
 it only reinterprets the memory address as an integer*/
my_uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<my_uintptr_t>(ptr);
}

Data* Serializer::deserialize(my_uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}



