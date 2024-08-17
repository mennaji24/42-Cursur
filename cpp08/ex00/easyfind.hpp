#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // For std::find
#include <iterator>   // For std::distance
#include <exception>  // For std::exception

//template fuction easyfind
template <typename T>

typename T::iterator easyfind(T& container, int value){
    //use std::find to search  for the value
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    //check if the elemnt was found 
    if(it == container.end()){
        throw std::runtime_error("Element not found in container");
    }
    return it;
}


#endif
