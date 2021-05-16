#include "Managers.hpp"

void ManagerController::update()
{
    timeManager.update();
    scriptManager.update();
    animationManager.update();
    renderManager.update();
}