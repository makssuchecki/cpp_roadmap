#include <iostream>


// Local Scope
// A variable created inside a function belongs to the local scope of that function
void myFunction(){
    int x = 5;
    std::cout << x << std::endl;
}

// Global Scope 
// A variable created outside of function is called a global variable and belongs to the global scope
int y = 10;


int main(){
    myFunction();

    std::cout << y <<std::endl;
    return 0;
}