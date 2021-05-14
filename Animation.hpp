#ifndef Animation_HPP
#define Animation_HPP

#include <list>
#include "Component.hpp"
#include "Renderer.hpp"

class Animation : public Component
{
    private:
        std::list<Sprite*> sprites;
        std::list<Sprite*>::iterator currentSprite;

    public:


        void update();
};

class AnimationManager
{
    private:
        std::list<GameObject*> animationStorage;

    public:

        void update();

        void addAnimation(GameObject* animationParent);

        void removeAnimation(GameObject* animationParent);
};

#endif