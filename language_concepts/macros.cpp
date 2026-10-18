#include <iostream>

// Macro is a label defined in the source code that is replaced
// by its value by the preprocessor before compilation

// Object-Like Macros are replaced by their value in the source code
// before compilation. Primary purpose is to define constants
// to be used in the code

#define PI 3.1416

void area(){
    float radius = 3;
    float area;

    area = PI * radius * radius;

    std::cout << "Area is " << area << std::endl;
}

// Function-Like Macros behave like functions, in that they take
// arguments that are used in the replaced code

#define AREA(r) r * r * PI

int main() {
    float radius = 5;
    float result;

    result = AREA(radius);

    std::cout << "Area is " << result << std::endl;
    return 0;
}

// C++ has predefined macros:
// __DATE__, __TIME__, __FILE__, __LINE__

// Once defined, a macro can be undefined with the #undef command.
#undef PI
