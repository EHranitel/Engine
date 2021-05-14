#include "Storage.hpp"

GameObject* Storage::getObject(std::string key)
{  
    if (!gameObjects.count(key))
    {
        std::cout << "GAME OBJECT NOT FOUND" << std::endl;

        return nullptr;
    }

    return gameObjects[key];
}

void Storage::addObject(std::string key)
{
    GameObject* newObject = new GameObject;

    gameObjects[key] = newObject;
}

void Storage::removeObject(std::string key)
{
    if (!gameObjects.count(key))
    {
        std::cout << "GAME OBJECT NOT FOUND" << std::endl;

        return;
    }

    delete gameObjects[key];
    gameObjects.erase(key);
}