#include <iostream>
#include <cstdlib>

int divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        std::cerr << "Error: division by zero" << std::endl;
        exit(1);
    }
    return numerator / denominator;
}

int main()
{
    int result = divide(10, 0);
    std::cout << "Result: " << result << std::endl;
    return 0;
}