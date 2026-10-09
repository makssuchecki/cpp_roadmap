#include <iostream>


// Implicit Type Conversion
void implicitTypeConversion(){
    int num_int = 9;
    
    double num_double;

    num_double = num_int;
    
    std::cout << "num_int = "<< num_int << std::endl; 
    std::cout << "num_double = " << num_double << std::endl;   
}

void automaticConversion(){
    int num_int;
    
    double num_double = 9.99;

    num_int = num_double;

    std::cout << "num_int = "<< num_int << std::endl;
    std::cout << "num_double = " << num_double << std::endl; 
}

// Explicit Type Conversion (type casting)
void CStyle(){
    int num_int = 26;

    double num_double;

    num_double = (double)num_int;
    std::cout << num_double << std::endl;

}

void functionStyle(){
    int num_int = 26;
    double num_double;

    num_double = double(num_int);
    std::cout << num_double << std::endl;
}

int main(){
    implicitTypeConversion();
    automaticConversion();

    CStyle();
    functionStyle();
    return 0;
}