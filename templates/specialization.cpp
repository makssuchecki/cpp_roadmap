#include <iostream>
#include <string>

// full specialization

template <typename T>
struct Printer{
    static void print(const ^& v) { std::cout << "generic: "<< v << "\n"; }
};

template <>
struct Printer<bool> {
    static void print(bool v) { std::cout << (v ? "true" : "false") << "\n"; }
};

// partial specialization
template <typename T>
struct Printer<T*>{
    static void print(T* p) {
        std::cout << "pointer: " << (p ? *p : T{}) << "\n";
    }
};

template <typename T, typename U>
struct Pair {};

template <typename T>
struct Pair<T, T> {};

int main(){
    return 0;
}