#include <iostream>
#include <memory>
// idioms are common patterns and practices used by programmers to solve specific problems
// or to make the code more expressive, efficient, or safer

// RAII (Resource Acquisition Is Initialization)
// Ensures that resources are properly released when they are no longer needed
class FileHandle{
public:
    FileHandle(const char* filename) : file(fopen(filename, "r")) {}
    ~FileHandle() {
        if (file) {
            fclose(file);
        }
    }
    private:
    FILE* file;
};

// Pimpl (Pointer to Implementation)
// hides implementation details to reduce compile-time dependencies and improve encapsulation
class Widget {
public:
    Widget();
    ~Widget();
    void doSomething();
private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

// Copy-and-Swap Idiom
// provies a strong exception guarantee for assignment operators by implementing
// the copy constructor, the destructor, and the copy assignment operator
class MyClass{
public:
    MyClass(const MyClass& other) : data(new int(*other.data)) {}
    MyClass& operator=(MyClass other){
        swap(*this, other);
        return *this;
    }
    friend void swap(MyClass& first, MyClass& second) {
        using std::swap;
        swap(first.data, second.data);
    }
private:
    int* data;
};

// CRTP (Curiously Recurring Template Pattern)
// allows static polymorphism by using templates and inheritance

template <typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};
class Derived : public Base<Derived>{
public:
    void implementation(){
        // Implementation details;
    }
};

// Named Constructor Idiom
// avoids the need for multiple constructors by using static methods to construct the object

class MyClass2{
public:
    static MyClass2 createWithDefault(){
        return MyClass2(0);
    }
    static MyClass2 createWithCustomValue(int value){
        return MyClass2(value);
    }
private:
    MyClass2(int value) : value(value) {}
    int value;
};

// SFINAE (Substitution Failure is Not An Error)
// allows template metaprogramming by making certain template instantiations fail gracefully
template <typename T>
class HasType {
private:
    template <typename U> static char test(typename U::type*);
    template <typename U> static long test(...);
public:
    static const bool value = sizeof(test<T>(0)) == sizeof(char);
};


// Type Erasure
// allows storing and manipulating types without knowing their types at compile time.

class Any {
public:
    template<typename T>
    Any(T value) : ptr(new ConcreteHolder<T>(value)) {}

    ~Any() { delete ptr; }
    
    template <typename T>
    T get() const {
        return static_cast<ConcreteHolder<T>*>(ptr)->value;
    }
private:
    struct Holder{
        virtual ~Holder() = default;
    };
    template<typename T>
    struct ConcreteHolder : Holder {
        ConcreteHolder(T value) : value(value) {}
        T value;
    };
    Holder* ptr;
};