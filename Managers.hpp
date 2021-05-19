#ifndef Managers_HPP
#define Managers_HPP

#include "Time.hpp"
#include "Script.hpp"
#include "Animation.hpp"
#include "Physics.hpp"

class ManagerController
{
    private:

    public:
        RenderManager renderManager;
        ScriptManager scriptManager;
        AnimationManager animationManager;
        TimeManager timeManager;
        PhysicsManager physicsManager;

        void update();
};

#endif