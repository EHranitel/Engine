#ifndef Animation_HPP
#define Animation_HPP

#include <map>
#include <list>
#include "Component.hpp"
#include "Renderer.hpp"

class Animation : public Component
{
    private:
        std::map<std::string, std::list<Sprite*>> sprites;
        std::list<Sprite*>::iterator currentSprite;
        std::string currentSpritePack;

    public:
        void addSpriteFromImage(std::string spritePackName, std::string imageName, float frameTime);

        void changeRendererSprite();

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