#include <iostream>
// The rule of Five is a modern extension of the Rule of Three, which includes
// the move constructor and move assignment operator.
// This rule is relevant when dealing with move semantics introduced in C++11

// The Rule of Five states that if you define any of the following:
// Copy constructor, Copy assignment, Destructor, Move constructor, Move assignment
// You should fedine all of them

#include <iostream>
#include <cstring>

class student
{
public:
    int age;
    char* name;

    student(int age_, const char* name_)
        : age(age_), name(new char[strlen(name_) + 1])
    {
        strcpy(name, name_);
    }

    student(const student& other)
        : age(other.age), name(new char[strlen(other.name) + 1])
    {
        strcpy(name, other.name);
    }

    student& operator=(const student& other)
    {
        if (this != &other)
        {
            char* new_name = new char[strlen(other.name) + 1]; // najpierw alokuj
            strcpy(new_name, other.name);
            delete[] name;        // dopiero potem zwolnij stare
            name = new_name;
            age = other.age;
        }
        return *this;
    }

    student (student&& other)
    {
        name = other.name;
        age = other.age;
        other.name = NULL;
    }
    student& operator=(student&& other)
    {
        if (this != &other)
        {
            if (name)
            {
                delete name;
            }
            age = other.age;
            name = other.name;
            other.name = NULL;
        }
        return *this;
    }
    ~student()
    {
        delete[] name;
    }
};

int main(){
    student s1(20, "Jan");
    student s2 = s1;
}