#include <iostream>

// RTTI - Runtime Type Identification

class Animal {virtual void dummy(){} };

class Lion : public Animal {};

class StrayCat : public Animal
{
    public:
        void meow(){std::cout<<"meoww"<<std::endl;}
};

void speak(Animal* animalPtr)
{
    // StrayCat* catPtr = (StrayCat*)animalPtr;
    StrayCat* catPtr = dynamic_cast<StrayCat*>(animalPtr);
    if (catPtr) catPtr->meow();
    else{std::cout << "Related instance has no meow" << std::endl;}
}

int main(){
    Animal* animalPtr = new Animal;
    Lion* lionPtr = new Lion;
    StrayCat* catPtr = new StrayCat;
    
    std::cout << "for animal ptr"<<std::endl;
    speak(animalPtr);
    std::cout << "for straycat ptr" <<std::endl;
    speak(catPtr);
    std::cout << "for lion ptr"<< std::endl;
    speak(lionPtr);
    return 0;
}