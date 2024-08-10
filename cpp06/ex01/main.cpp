#include "Serializer.hpp"
#include <iostream>

int main(){
    Data originalData;
    originalData.id = 1;
    originalData.name = "Test Data";

    my_uintptr_t raw = Serializer::serialize(&originalData);

    Data* deserilizedData = Serializer::deserialize(raw);
    if (deserilizedData == &originalData){
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Original Data ID: " << deserilizedData->id << ", Name: " << deserilizedData->name << std::endl;
    }else{
        std::cout << "Serialization and deserialization failed!\n";
  
    }
    return 0;
}