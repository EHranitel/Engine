#ifndef Storage_HPP
#define Storage_HPP

#include "GameObject.hpp"

class Storage
{
    private:
        std::map<std::string, GameObject*> gameObjects;
 
    public:

        GameObject* getObject(std::string key)
        {  
            return gameObjects[key];
        };

        void addObject(GameObject gameObject, std::string key)
        {
            //GameObject* newObject = new GameObject;

            gameObjects[key] = &gameObject;
        }
    
        void removeObject(std::string key)
        {
            delete gameObjects[key];
            gameObjects.erase(key);
        }
};

#endif