#include <iostream>

void somefun() {}
void print(int val) { std::cout << val << std::endl; }
void print(double val) {std::cout << val << std::endl; }

int main()
{
    print(10);
    print(10.1);
    return 0;
}