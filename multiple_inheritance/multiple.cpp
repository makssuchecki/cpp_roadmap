#include <iostream>

class CommonBaseClass
{
public:
    int common_value;

    CommonBaseClass() : common_value(-99) {}
    CommonBaseClass(int common_value) : common_value(common_value) {} 
};
class BaseClass1 : virtual public CommonBaseClass
{
public:
    int value;

    BaseClass1() : CommonBaseClass(100) {}

    void function1()
    {
        std::cout << "Function1 BaseClass1" << std::endl;
    }
    void ambi_function()
    {
        std::cout << "Ambiguous BaseClass1" << std::endl;
    }
};


class BaseClass2 : virtual public CommonBaseClass
{
public:
    int value;
    
    BaseClass2() : CommonBaseClass(200) {}

    void function2()
    {
        std::cout << "Function2 BaseClass2" << std::endl;
    }
    void ambi_function()
    {
        std::cout << "Ambiguous BaseClass2" << std::endl;
    }
};

class DerivedClass: public BaseClass1, public BaseClass2
{
public:
    DerivedClass() : CommonBaseClass(999) {}
    void function3()
    {
        std::cout << "Function3 DerivedClass" << std::endl;
    }
    void ambi_function()
    {
        BaseClass1::ambi_function();
    }
};

int main()
{
    DerivedClass derived;
    
    derived.function1();
    derived.function2();
    derived.function3();
    derived.BaseClass1::ambi_function();

    derived.ambi_function();

    std::cout << "Common value: " << derived.common_value << std::endl;

    derived.BaseClass1::value = 20;
    return 0;
}