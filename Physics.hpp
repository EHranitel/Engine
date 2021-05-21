#include "Component.hpp"
#include <list>

class Physics : public Component
{
    private:

    public:
        float m = 0;
        
        float vX = 0;
        float vY = 0;

        float aX = 0;
        float aY = 0;

        void update();
};

class Collider :public Component 
{
    private:
        std::list<sf::ConvexShape> collisionModel;

    public:
        bool isCollide(sf::ConvexShape, sf::ConvexShape);
};

class PhysicsManager
{
    private:
        std::list<GameObject*> physicsStorage;

    public:
        void update();

        void addPhisics(GameObject* physicsParent);

        void removePhysics(GameObject* physicsParent);
};

