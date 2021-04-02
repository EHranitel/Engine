#ifndef Managers_HPP
#define Managers_HPP

#include "Renderer.hpp"
#include "Script.hpp"

class ManagerController
{
    private:

    public:
        RenderManager renderManager;

        void update()
        {
            renderManager.update();
        }
};

#endif