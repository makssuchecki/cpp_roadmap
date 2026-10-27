#include <iostream>
#include <string>

// allows writing templates with any number of arguments 
template <typename... Ts>
void f(Ts... args){
    std::cout<< sizeof...(Ts) << ' ' << sizeof...(args) << '\n';
}
int main(){
    f();
    f(1, 2.0, "x");
    return 0;
}
