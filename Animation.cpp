#include "Animation.hpp"
#include "GameObject.hpp"

void Animation::addSpriteFromImage(std::string imageName, float frameTime, int numberOfParts)
{
    Sprite* sprite = new Sprite;

    sprite->image.loadFromFile(imageName);

    sf::Vector2f center = sf::Vector2f
    (
        sprite->image.getSize().x / 2, 
        sprite->image.getSize().y / 2
    );

    sprite->sprite.setOrigin(center); 
    sprite->sprite.setPosition(parent->x, 
    parent->y - sprite->image.getSize().y * (1 - 1 / numberOfParts) / 2);

    std::cout << parent->y + sprite->image.getSize().y * (1 - 1 / numberOfParts) / 2 << std::endl;

    sprite->texture.loadFromImage(sprite->image);
    sprite->sprite.setTexture(sprite->texture);

    sprite->frameTime = frameTime;

    sprite->numberOfParts = numberOfParts;

    sprite->size = sf::Vector2i(sprite->image.getSize().x, sprite->image.getSize().y / numberOfParts);
    sprite->rectangle = sf::IntRect(sprite->position, sprite->size);

    sprites[imageName] = sprite;

    if (currentSprite == nullptr)
    {
        currentSprite = sprite;
        currentSpriteName = imageName;
    }
}

void Animation::changeRendererSprite(std::string imageName)
{
    if (currentSpriteName != imageName)
    {
        currentSprite = sprites[imageName];
        currentSpriteName = imageName;

        currentSprite->position = sf::Vector2i(0, 0);
    }

    parent->getComponent<Renderer>()->changeSprite(currentSprite);
}

void Animation::update()
{
    if (!parent->getComponent<Renderer>()->isAnimated)
    {
        return;
    }

    if (parent->controller->timeManager.getTime() % currentSprite->frameTime == 0)
    {

        if (currentSprite->position.y >= currentSprite->image.getSize().y * (currentSprite->numberOfParts - 1) / currentSprite->numberOfParts)
        {
            currentSprite->position.y = 0;

            currentSprite->sprite.setPosition(parent->x, 
            parent->y - currentSprite->image.getSize().y / currentSprite->numberOfParts * (currentSprite->numberOfParts - 1) / 2);
        }

        else
        {
            currentSprite->position.y += currentSprite->image.getSize().y / currentSprite->numberOfParts;

            currentSprite->sprite.setPosition(parent->x, 
            parent->y - currentSprite->image.getSize().y / currentSprite->numberOfParts * ((currentSprite->numberOfParts - 1) / 2 - 1));

            std::cout << parent->y - (currentSprite->image.getSize().y / currentSprite->numberOfParts) * ((currentSprite->numberOfParts - 1) / 2 - 1) << std::endl;
        }

        currentSprite->rectangle = sf::IntRect(currentSprite->position, currentSprite->size);
        currentSprite->sprite.setTextureRect(currentSprite->rectangle);
    }
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