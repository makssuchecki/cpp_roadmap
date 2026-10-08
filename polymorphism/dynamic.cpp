#include <iostream>

// dynamic - runtime

struct Shape { virtual double area() const = 0; virtual ~Shape() = default; };
struct Square : Shape { double area() const override { return 4; }};

int main(){
    Shape* s = new Square;
    std::cout << s->area() << "\n";
    return 0;
}
