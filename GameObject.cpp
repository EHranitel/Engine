#include "GameObject.hpp"

GameObject::~GameObject()
{
    /*for (auto it = components.begin(); it != components.end(); ++it) 
    {
        delete &it;
        components.erase(it);
    }

    std::cout << components.size() << std::endl;*/
}