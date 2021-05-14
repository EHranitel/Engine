#ifndef Managers_HPP
#define Managers_HPP

#include "Time.hpp"
#include "Script.hpp"
#include "Animation.hpp"

class ManagerController
{
    private:

    public:
        RenderManager renderManager;
        ScriptManager scriptManager;
        AnimationManager animationManager;
        TimeManager timeManager;

        void update();
};

#endif