#ifndef Renderer_HPP
#define Renderer_HPP

#include <list>
#include "Component.hpp"
#include <SFML/Graphics.hpp>

class Renderer : public Component
{
    private:
        sf::Sprite sprite;
        sf::Image image;
        sf::Texture texture;

    public:
        int x;
        int y;

        void setPosition(int x, int y)
        {
            sprite.setPosition(x, y);
        }

        void updateSprite(std::string imageName)
        {
            image.loadFromFile(imageName);
        
            texture.loadFromImage(image);
        
            sprite.setTexture(texture);
        }

        void update(sf::RenderWindow* window)
        {
            window->draw(sprite);
        }
};

class RenderManager
{
    private:
        std::list<Renderer*> rendererStorage;

    public:
        sf::RenderWindow* window;

        void update()
        {
            window->clear();

            for (std::list<Renderer*>::iterator it = rendererStorage.begin(); it != rendererStorage.end(); ++ it)
            {        
                (*it)->update(window);
            }

            window->display();
        }

        void addRenderer(Renderer* renderer)
        {
            rendererStorage.push_front(renderer);
        }

        void removeRenderer(Renderer* renderer)
        {
            rendererStorage.remove(renderer);
        }
};

#endif