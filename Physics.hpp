#include "Component.hpp"
#include <list>

class Physics : public Component
{
    private:

    public:
        float vX = 0;
        float vY = 0;

        float aX = 0;
        float aY = 0;

        void update();
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

