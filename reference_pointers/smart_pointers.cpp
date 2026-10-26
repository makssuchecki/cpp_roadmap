#include <iostream>
#include <memory>

// Smart pointers are classes that behave like regular pointers
// but provide automatic memory management

// weak_ptr holds non-owning reference to an object managed by a shared_ptr 

// shared_ptr enables multiple pointers to safely own and share the same object 

// unique_ptr provides exclusive ownership of a dynamically allocated object

class Entity
{
public:
    Entity() 
    {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
    void Print(){}
};

int main(){
    {
        std::shared_ptr<Entity> e0;
        {
            std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // unique pointer
            
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // shared pointer

            std::weak_ptr<Entity> weakEntity = sharedEntity; // weak pointer

            e0 = sharedEntity;
            
            entity->Print();
        }

    }   

    
}