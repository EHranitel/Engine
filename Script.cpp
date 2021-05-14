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