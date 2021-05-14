#include "Animation.hpp"
#include "GameObject.hpp"

void Animation::update()
{

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