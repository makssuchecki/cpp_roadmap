#include <iostream>
// A pointer is an integer which stores a memory address

int main(){
    int var = 8;
    int* ptr = &var;
    *ptr = 9;

    int** dbl = &ptr;
    std::cout << ptr << "\n";
    std::cout << dbl << "\n";
}