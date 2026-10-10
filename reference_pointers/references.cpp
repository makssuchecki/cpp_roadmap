#include <iostream>

void IncrementPtr(int* value)
{
    ++*value;
}


void IncrementRef(int& value)
{
    ++value;
}

int main()
{
    int a = 5;
    IncrementPtr(&a);
    IncrementRef(a);

    int* b = &a;
    int& ref = a;

    std::cout << a << std::endl;
}