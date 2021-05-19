#include "GameObject.hpp"

void Physics::update()
{
    vX += aX;
    vY += aY;

    parent->x += vX;
    parent->y += vY;
}

void PhysicsManager::update()
{
    for (std::list<GameObject*>::iterator it = physicsStorage.begin(); it != physicsStorage.end(); ++ it)
    {        
        ((*it)->getComponent<Physics>())->update();
    }
}

void PhysicsManager::addPhisics(GameObject* physicsParent)
{
    physicsStorage.push_front(physicsParent);
}

void PhysicsManager::removePhysics(GameObject* physicsParent)
{
    physicsStorage.remove(physicsParent);
}