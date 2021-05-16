#include "Script.hpp"
#include <iostream>

void ScriptManager::update()
{
    for (auto it = scriptStorage.begin(); it != scriptStorage.end(); ++it)
    {        
        static_cast<Script*>((*it))->run();
    }
}

void ScriptManager::addScript(Component* script)
{
    scriptStorage.push_front(script);
}

void ScriptManager::removeScript(Component* script)
{
    scriptStorage.remove(script);
}

void ScriptManager::removeAllScriptsFromOneGameObject(GameObject* object)
{
    int len = scriptStorage.size();

    std::list<Component*>::iterator it = scriptStorage.begin();

    for (int i = 0; i < len; i++) 
    {
        if ((*it)->parent == object)
        {
            scriptStorage.erase(it++);

            continue;
        }

        it++;
    }
}