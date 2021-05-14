#ifndef Storage_HPP
#define Storage_HPP

#include "GameObject.hpp"

class Storage
{
    private:
        
 
    public:
        std::map<std::string, GameObject*> gameObjects;

        GameObject* getObject(std::string key)
        {  
            return gameObjects[key];
        };

        void addObject(std::string key)
        {
            GameObject* newObject = new GameObject;

            gameObjects[key] = newObject;
        }
    
        void removeObject(std::string key)
        {
            if (!gameObjects.count(key))
            {
                std::cout << "NOT FOUND" << std::endl;

                return;
            }

            delete gameObjects[key];
            gameObjects.erase(key);
        }
};

#endif
