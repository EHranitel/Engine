#include "Renderer.hpp"
#include "GameObject.hpp"

Renderer::Renderer()
{
    Sprite* newSprite = new Sprite;
    sprite = newSprite; 

    Text* newText = new Text;
    text = newText;
}

void Renderer::rotate(float degeree)
{
    sprite->sprite.rotate(degeree);
}

void Renderer::flipVertically()
{
    sprite->sprite.scale(sf::Vector2f(1, -1));
}

void Renderer::flipHorizontally()
{
    sprite->sprite.scale(sf::Vector2f(-1, 1));
}

sf::Vector2i Renderer::getSize()
{
    return sprite->size;
}

void Renderer::changeFont(std::string fontName, sf::Color color)
{
    text->font.loadFromFile(fontName);
    text->text.setFont(text->font);

    text->text.setFillColor(color);
}

void Renderer::changeText(sf::String message, int characterSize)
{
    text->text.setString(message);
    text->text.setCharacterSize(characterSize);
}

void Renderer::changeImage(std::string imageName)
{
    sprite->image.loadFromFile(imageName);

    sf::Vector2f center = sf::Vector2f
    (
        sprite->image.getSize().x / 2, 
        sprite->image.getSize().y / 2
    );

    sprite->size.x = sprite->image.getSize().x;
    sprite->size.y = sprite->image.getSize().y;

    sprite->sprite.setOrigin(center); 
    sprite->sprite.setPosition(parent->x, parent->y);

    sprite->texture.loadFromImage(sprite->image);
    sprite->sprite.setTexture(sprite->texture);
}

void Renderer::changeSprite(Sprite* sprite)
{
    if (!isAnimated)
    {
        delete this->sprite;
    }

    this->sprite = sprite;
}

void Renderer::update(sf::RenderWindow* window)
{          
    if (!isAnimated)
    {
        sprite->sprite.setPosition(sf::Vector2f(parent->x, parent->y));
    }

    window->draw(sprite->sprite);

    text->text.setPosition(sf::Vector2f(parent->x, parent->y));
    window->draw(text->text);
}

Renderer::~Renderer()
{
    delete sprite;
    delete text;
}

RenderManager::RenderManager()
{
    sf::RenderWindow* newWindow = new sf::RenderWindow(sf::VideoMode(1000, 800), "SFML window");

    window = newWindow;
}

void RenderManager::setWindowSize(int x, int y)
{
    window->setSize(sf::Vector2u(x, y));
}

void RenderManager::update()
{
    window->clear();

    for (std::list<GameObject*>::iterator it = rendererStorage.begin(); it != rendererStorage.end(); ++ it)
    {        
        ((*it)->getComponent<Renderer>())->update(window);
    }

    window->display();
}

void RenderManager::addRenderer(GameObject* rendererParent)
{
    rendererStorage.push_front(rendererParent);
}

void RenderManager::removeRenderer(GameObject* rendererParent)
{
    rendererStorage.remove(rendererParent);
}

RenderManager::~RenderManager()
{
    delete window;
}