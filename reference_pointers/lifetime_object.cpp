#include <iostream>

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
};

int main()
{
    {
        Entity* e = new Entity();
    }    
}