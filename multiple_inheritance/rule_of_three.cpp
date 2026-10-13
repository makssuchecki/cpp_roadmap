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

    ~student()
    {
        delete[] name;
    }
};

int main(){
    student s1(20, "Jan");
    student s2 = s1;
}