#ifndef Storage_HPP
#define Storage_HPP

#include "GameObject.hpp"

class Storage
{
    private:
        std::map<std::string, GameObject*> gameObjects;
        
    public:
        GameObject* getObject(std::string key);

        void addObject(std::string key);
    
        void removeObject(std::string key);
};

#endif
