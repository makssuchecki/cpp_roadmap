#include <iostream>

int* create_array(int size)
{
    int array[10];
    for (int i = 0; i < size; i++)
        array[i] = i * i;
    
    return array;
}

int main()
{
    int* pointer = create_array(10);
    std::cout << pointer[3] << std::endl;
    delete pointer;
}