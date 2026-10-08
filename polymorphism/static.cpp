#include <iostream>
#include <string>

// static - compile time
 
template <typename T>
T maxOf(T a, T b){ return a > b ? a : b; }

int main(){
    std::cout << maxOf(4, 6) << std::endl;
    std::cout << maxOf(4.9, 5.1) << std::endl;
    std::cout << maxOf(std::string("a"), std::string("z")) << std::endl;
}

template <typename Derived>
struct Shape {
    double area() const {
        return static_cast<const Derived*>(this)->areaImpl();
    }
};

struct Square : Shape<Square> {
    double side = 2;
    double areaImpl() const { return side * side; }
};