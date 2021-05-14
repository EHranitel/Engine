#include "Managers.hpp"

void ManagerController::update()
{
    scriptManager.update();
    timeManager.update();
    animationManager.update();
    renderManager.update();
}