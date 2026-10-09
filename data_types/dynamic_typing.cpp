#include <iostream>
#include <type_traits>

void autoType() {
    int a = 42;
    
    auto b = 42;

    std::cout << "Value of b: " << b << std::endl;
}

void declType(){
    int x = 5;
    double y = 10.5;

    decltype(x + y) result = x + y; // deduce the type of an expression
    std::cout << "Result: " << result << std::endl;
}

void checkSame(){
    bool result1 = std::is_same<int, int>::value;
    bool result2 = std::is_same<int, double>::value;

    std::cout << std::boolalpha;
    std::cout << "int and int are the same: " << result1 << std::endl;
    std::cout << "int and double are the same: " << result2 << std::endl;
}
void safeCheck(){
    int x = 5;
    double y = 10.5;

    decltype(x + y) result = x + y;

    std::cout << "Type of result: " << (std::is_same<decltype(result), double>::value ? "double" : "unknown") << std::endl;
}

template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b){
    return a + b;
}

void autoAdding(){
    int x = 5;
    double y = 10.5;

    auto result = add(x, y);

    std::cout << "Result: "<< result << std::endl;

    std::string s1 = "Hello, ", s2 = "world!";
    auto result2 = add(s1, s2);

    std::cout << "Result: " << result2 << std::endl;
}

int main(){
    autoType();
    declType();
    checkSame();
    safeCheck();
    autoAdding();
    return 0;
}