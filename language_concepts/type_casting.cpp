#include <iostream>



int main()
{
    double value = 5.25;
    double a = (int)value + 5.3;

    double s = static_cast<int>(value) + 5.3;
    std::cout << a << std::endl;
    return 0;
}