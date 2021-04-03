#ifndef Renderer_HPP
#define Renderer_HPP

#include <list>
#include "Component.hpp"
#include <SFML/Graphics.hpp>

class Renderer : public Component
{
    private:
        std::list<sf::Sprite*> sprites;
        std::list<sf::Sprite*>::iterator currentSprite;

        int tickTime = 50;
        int time = 0;

    public:
        int x;
        int y;

        void setPosition(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        void addSprite(std::string imageName)
        {
            sf::Image* image = new sf::Image;
            image->loadFromFile(imageName);

            sf::Texture* texture = new sf::Texture;
            texture->loadFromImage(*image);

            sf::Sprite* sprite = new sf::Sprite;
            sprite->setPosition(x, y);
        
            sprite->setTexture(*texture);

            sprites.push_front(sprite);

            currentSprite = sprites.begin();
        }

        void update(sf::RenderWindow* window)
        {
            time++;
            
            if(time == 50)
            {
                time = 0;

                std::list<sf::Sprite*>::iterator endSprite;
                endSprite = sprites.end();
                endSprite--;

                if(currentSprite == endSprite)
                {
                    currentSprite = sprites.begin();
                }

                else
                {
                    currentSprite++;
                }
            }
            
            window->draw(**currentSprite);
        }

        ~Renderer()
        {
            for (auto it = sprites.begin(); it != sprites.end(); ++it) 
            {
                delete *it;
            }
        }
};

class RenderManager
{
    private:
        

    public:
        std::list<Renderer*> rendererStorage;
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