#include "Storage.hpp"

GameObject* Storage::getObject(std::string key)
{  
    if (!gameObjects.count(key))
    {
        return nullptr;
    }

    return gameObjects[key];
}

void Storage::addObject(std::string key)
{
    GameObject* newObject = new GameObject;
    newObject->name = key;

    gameObjects[key] = newObject;
}

void Storage::removeObject(std::string key)
{
    if (!gameObjects.count(key))
    {
        return;
    }

    delete gameObjects[key];
    gameObjects.erase(key);
}