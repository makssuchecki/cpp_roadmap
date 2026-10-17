#include <iostream>

// static_cast compile-time checked conversions between related types.
// This is the default cast you should reach for

// dynamic_cast runtime-checked downcasts in polymorphic hierarchies.
// The base class need at least one virtual function, because the check relies on RTTI

// const_cast adds or removes const and volatile. It's the only cast that can do this

// reinterpret_cast reinterprets the bit pattern as a different type, with no checks
// and no conversion. It works between unrelated pointer types and between pointers and integers

class Base
{
public:
    Base() {}
    virtual ~Base() = default;  
};

class Derived : public Base
{
public:
    Derived() {}
};

int main()
{
    double d = 3.7;
    int i = static_cast<int>(d);             

    Base* b = new Derived;
    Derived* dp = static_cast<Derived*>(b);   


    
    delete b;                                 
    return 0;
}