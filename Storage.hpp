#include "GameObject.hpp"

class Storage
{
    private:
        std::map<std::string, GameObject*> gameObjects;
 
    public:

        template <class T>
        T* GetObject(std::string key)
        {
            T* gameObject = static_cast<T*> (gameObjects[key]);
    
            return gameObject;
        };

        template <typename T>
        void AddComponent(T component, std::string key)
        {
            gameObjects[key] = &component;
        }
    
        void RemoveComponent(std::string key)
        {
            gameObjects.erase(key);
        }
};