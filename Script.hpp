#ifndef Script_HPP
#define Script_HPP

#include "Component.hpp"
#include <list>

class Script : public Component
{
    private:

    public:
        virtual void run(){};
};

class ScriptManager
{
    private:
        std::list<Component*> scriptStorage;

    public:
        void update();

        void addScript(Component* script);

        void removeScript(Component* script);
};

#endif