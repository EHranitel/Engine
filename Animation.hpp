#ifndef Animation_HPP
#define Animation_HPP

#include <map>
#include <list>
#include "Renderer.hpp"

class Animation : public Component
{
    private:
        std::map<std::string, Sprite*> sprites;
        Sprite* currentSprite;
        std::string currentSpriteName;
        
    public:
        std::string currentSpritePack;

        void addSpriteFromImage(std::string imageName, float frameTime, int numberOfParts, int firstPart = 0, int lastPart = 0);

        void removeSprite(std::string imageName);

        void changeRendererSprite(std::string imageName);

        void update();

        ~Animation();
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