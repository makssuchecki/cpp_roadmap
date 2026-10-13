#include <iostream>
// The Rule of Zero is a guideline suggesting that if your class does not manage
// resource (such as dynamic memory, file handles, etc), you should not explicitly 
// define the constructor, destructor, or copy/move operations.

class student
{
    public:
    int age;
    std::string name;
};

int main()
{
    student a;
    a.name = "Henry";
    a.age = 22;

    student b(a);
    b.name = "James";

    student c;

    c = b;

    std::cout << a.name << '\n';
    std::cout << b.name << '\n';
    std::cout << c.name << '\n';
}