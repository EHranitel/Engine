#include "Animation.hpp"
#include "GameObject.hpp"

void Animation::addSpriteFromImage(std::string spritePackName, std::string imageName, float frameTime)
{
    Sprite* sprite = new Sprite;

    sprite->image.loadFromFile(imageName);

    sf::Vector2f center = sf::Vector2f
    (
        sprite->image.getSize().x / 2, 
        sprite->image.getSize().y / 2
    );

    sprite->sprite.setOrigin(center); 
    sprite->sprite.setPosition(parent->x, parent->y);

    sprite->texture.loadFromImage(sprite->image);
    sprite->sprite.setTexture(sprite->texture);

    sprite->frameTime = frameTime;

    sprites[spritePackName].push_front(sprite);
}

void Animation::changeRendererSprite()
{
    if (currentSprite == sprites.end())
    {
        currentSprite = sprites.begin();
    }

    else
    {
        ++currentSprite;
    }

    parent->getComponent<Renderer>()->changeSprite(currentSprite->second);
}

void Animation::update()
{
    if (!parent->getComponent<Renderer>()->needAnimationRightNow)
    {
        return;
    }

    if (time)
}

void AnimationManager::update()
{
    for (std::list<GameObject*>::iterator it = animationStorage.begin(); it != animationStorage.end(); ++ it)
    {        
        ((*it)->getComponent<Animation>())->update();
    }
}

void AnimationManager::addAnimation(GameObject* animationParent)
{
    animationStorage.push_front(animationParent);
}

void AnimationManager::removeAnimation(GameObject* animationParent)
{
    animationStorage.remove(animationParent);
}