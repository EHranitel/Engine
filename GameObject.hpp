#ifndef GameObject_HPP
#define GameObject_HPP

#include <map>
#include <iostream>
#include "Managers.hpp"

class GameObject 
{
    private:
        std::map<std::string, Component*> components;
        
    public:
        std::string name;
        ManagerController* controller;
        
        float x;
        float y;

        template <typename T>
        T* getComponent();    

        template <typename T>
        void addComponent();

        template <typename T>
        void removeComponent();
        
        ~GameObject();
};

template <typename T>
T* GameObject::getComponent()
{
    if (!components.count(typeid(T).name()))
    {
        std::cout << "COMPONENT NOT FOUND" << std::endl;

        return nullptr;
    }

    T* newComponent = static_cast<T*> (components[typeid(T).name()]);

    return newComponent;
}

template <typename T>
void GameObject::addComponent()
{
    T* newComponent = new T;
    newComponent->gameObjectName = name;
    newComponent->parent = this;

    if(typeid(T).name() == typeid(Renderer).name())
    {
        controller->renderManager.addRenderer(this);
    }

    if(typeid(T).name() == typeid(Animation).name())
    {
        controller->animationManager.addAnimation(this);
    }

    if(std::is_base_of<Script, T>::value)
    {
        controller->scriptManager.addScript(newComponent);
    }
    
    components[typeid(T).name()] = newComponent;
}

template <typename T>
void GameObject::removeComponent()
{ 
    if (!components.count(typeid(T).name()))
    {
        std::cout << "COMPONENT NOT FOUND" << std::endl;

        return;
    }

    if (typeid(T).name() == typeid(Renderer).name())
    {
        delete components[typeid(T).name()];

        controller->renderManager.removeRenderer(this);
    }

    if (typeid(T).name() == typeid(Animation).name())
    {
        delete components[typeid(T).name()];

        controller->animationManager.removeAnimation(this);
    }

    if(std::is_base_of<Script, T>::value)
    {
        controller->scriptManager.removeScript(components[typeid(T).name()]);
    }

    components.erase(typeid(T).name());
}

#endif