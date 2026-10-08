#include <iostream>
#include <string>

// Function overloading means defining several functions with the same name 
// but different parameter lists in the same scope
// The compiler picks the right one at compile time based on the arguments

int add(int a, int b){ return a+b; }
double add(double a, double b) { return a+b; }
std::string add(const std::string& a, const std::string &b) { return a + b; }

int main() {
    std::cout << add(1, 5) << "\n";
    std::cout << add(0.4, 2.9) << "\n";
    std::cout << add(std::string("aaa"), std::string("bbb")) << "\n";
}
