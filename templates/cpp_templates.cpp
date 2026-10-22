#include <iostream>
#include <string>

// Templates let you write a function or class that works with different data types

// Function templates

template <typename T>
T add(T a, T b){
    return a + b;
}




// Class templates

template <typename T>
class Box {
    public:
        T value;
        Box (T v) {
            value = v;
        }
        void show(){
            std::cout << "Value: " << value << "\n";
        }
};

int main() {
    std::cout<< add<int>(5, 3) << std::endl;
    std::cout << add<double>(2.5, 1.5) << std::endl;

    Box<int> intBox(50);
    Box<std::string> strBox("Hello");

    intBox.show();
    strBox.show();
    return 0;
}