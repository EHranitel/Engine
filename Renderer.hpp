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

        sf::Vector2i position = sf::Vector2i(0, 0);
        sf::Vector2i size;
        sf::IntRect rectangle;

        int numberOfParts = 1;

        int frameTime = 1000;

        int firstPart = 0;
        int lastPart = numberOfParts;
};

class Text
{
    public:
        sf::Font font;
        sf::Text text;
};

class Renderer : public Component
{
    private:

    public:
        bool isAnimated = false;

        Sprite* sprite;
        Text* text;

        Renderer();

        void rotate(float degree);
        void flipVertically();
        void flipHorizontally();

        sf::Vector2i getSize();

        void changeFont(std::string fontName, sf::Color color = sf::Color::Red);

        void changeText(sf::String message, int characterSize = 25);

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

        RenderManager();

        void setWindowSize(int x, int y);

        void update();

        void addRenderer(GameObject* rendererParent);

        void removeRenderer(GameObject* rendererParent);

        ~RenderManager();
};

#endif