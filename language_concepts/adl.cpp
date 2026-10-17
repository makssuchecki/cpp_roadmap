#include <iostream>

// Argument Dependent Lookup extends the function lookup process by allowing 
// the compiler to search for functions in the namespaces of the function arguments' types

namespace geo{
    struct Point { int x, y; };     
    void print(const Point& p) {std::cout << p.x << " " <<p.y <<std::endl;}; 
}

int main(){
    geo::Point p{1, 2};
    print(p);
}