#include "Storage.hpp"
#include <iostream>
#include <array>
#include <list>
#include <string>

int main()
{
    Storage storage;
    ManagerController controller;

    Renderer rend0;

    int time = 0;
    int deleteThis = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML window");
    controller.renderManager.window = &window;

    for(int i = 0; i < 10; i++)
    {
        storage.addObject(std::to_string(i));

        GameObject* obj = storage.getObject(std::to_string(i)); 
        obj->controller = &controller;

        obj->addComponent(rend0);

        Renderer* rend = obj->getComponent(rend0);

        rend->setPosition(20 + rand()%(980-20+1), 20 + rand()%(780-20+1));

        rend->addSprite("images/Eye1.png");
        rend->addSprite("images/Eye2.png");
        rend->addSprite("images/Eye3.png");
        rend->addSprite("images/Eye4.png");
    }

    while (window.isOpen())	
	{
        time++;

        if(time == 100)
        {
            if(deleteThis == 10)
            {
                deleteThis = 0;
            }

            storage.removeObject(std::to_string(deleteThis));

            storage.addObject(std::to_string(deleteThis));

            GameObject* obj = storage.getObject(std::to_string(deleteThis)); 
            obj->controller = &controller;

            obj->addComponent(rend0);

            Renderer* rend = obj->getComponent(rend0);

            rend->setPosition(20 + rand()%(980-20+1), 20 + rand()%(780-20+1));

            rend->addSprite("images/Eye1.png");
            rend->addSprite("images/Eye2.png");
            rend->addSprite("images/Eye3.png");
            rend->addSprite("images/Eye4.png");

            time = 0;
            deleteThis++;
        }

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		controller.renderManager.update();
	}

    //std::cout << std::to_string(1) << std::endl;

    return 0;
}