#include <map>
#include <iostream>

class Component 
{
    private:

    public:
    
};
 
class Collider : public Component 
{
    private:

    public:
        
};
 
class Renderer : public Component 
{
    private:

    public:
    
};
 
class GameObject 
{
    private:
        std::map<std::string, Component*> components;

    public:

        template <class T>
        T* GetComponent(std::string key)
        {
            T* component = static_cast<T*> (components[key]);
    
            return component;
        };

        template <typename T>
        void AddComponent(T component, std::string key)
        {
            components[key] = &component;
        }
    
        void RemoveComponent(std::string key)
        {
            components.erase(key);
        }
};
 