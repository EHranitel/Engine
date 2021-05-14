#ifndef Component_HPP
#define Component_HPP

#include <string>

class GameObject;

class Component 
{
    private:

    public:
        GameObject* parent;
        std::string gameObjectName;
};

#endif
