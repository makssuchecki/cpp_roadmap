#include <iostream>


class Foo{
public:
    Foo(int a, int b){
        std::cout << "Konstruktor Foo" << std::endl;
    }
    ~Foo(){
        std::cout << "Destruktor Foo" << std::endl;
    }

};

int main(){
    int* p = new int(42);
    delete p;
    p = nullptr;

    Foo* f = new Foo(1, 2);
    delete f;
}
