#include "GameObject.hpp"

void Physics::update()
{
    vX += aX;
    vY += aY;

    parent->x += vX;
    parent->y += vY;
}

bool Collider::isCollide(sf::ConvexShape collisionModel1, sf::ConvexShape collisionModel2)
{
    for (int i = 0; i < collisionModel1.getPointCount(); i++)
    {
        for (int j = 0; j < collisionModel2.getPointCount(); j++)
        {
            if ((collisionModel1.getPoint(i).x <= collisionModel2.getPoint(j).x <= collisionModel1.getPoint(i + 1).x) or (collisionModel1.getPoint(i).x <= collisionModel2.getPoint(j + 1).x <= collisionModel1.getPoint(i + 1).x))
            {
                if ((collisionModel1.getPoint(i).y <= collisionModel2.getPoint(j).y <= collisionModel1.getPoint(i + 1).y) or (collisionModel1.getPoint(i).y <= collisionModel2.getPoint(j + 1).y <= collisionModel1.getPoint(i + 1).y))
                {
                    return true;
                }
            }
                
        }
    }
    return false;
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