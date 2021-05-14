#ifndef Renderer_HPP
#define Renderer_HPP

#include <list>
#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Sprite
{
    public:
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        float frameTime = 1000;
};

class Renderer : public Component
{
    private:

    public:

        bool needAnimationRightNow = false;

        Sprite* sprite;

        Renderer();

        void rotate(float degree);
        void flipVertically();
        void flipHorizontally();

        void changeImage(std::string imageName);

        void changeSprite(Sprite* sprite);

        void update(sf::RenderWindow* window);
        
        ~Renderer();
};

class RenderManager
{
    private:
        std::list<GameObject*> rendererStorage;

    public:
        sf::RenderWindow* window;

        void update();

        void addRenderer(GameObject* rendererParent);

        void removeRenderer(GameObject* rendererParent);
};

#endif