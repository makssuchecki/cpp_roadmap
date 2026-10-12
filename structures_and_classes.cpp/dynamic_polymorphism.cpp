#include <iostream>
#include <iterator>

class Student
{
public:
    std::string name;
    Student(std::string name) : name(name) {}
    virtual void print() { std::cout << name << std::endl; }
};

class MedicalStudent : public Student
{
public:
    std::string speciality;

    MedicalStudent(std::string name, std::string speciality) : Student(name), speciality(speciality){};

    void print() { std::cout << name << ": " << speciality << std::endl; }
};

int main(){
    Student *students[] =
    {
        new Student("Kevin"),
        new Student("Mary"),
        new Student("Kulvinder"),
        new MedicalStudent("Ali", "Family Medicine"),
        new MedicalStudent("Harry", "Cardiology"),
        new MedicalStudent("Lisa", "Radiology")
    };
    for (int i = 0; i < std::size(students) ; i++)
        students[i]->print();
    
    for (int i = 0; i < std::size(students); i++)
        delete students[i];
}