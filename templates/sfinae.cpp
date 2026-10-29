#include <iostream>
#include <type_traits>

// SFINAE = Substitution Failure Is Not An Error
template <typename T>
typename T::value_type first(const T& c){
    return *c.begin();
}