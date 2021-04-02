#include "Storage.hpp"
#include <iostream>
#include <array>
#include <list>
#include <string>

int main()
{
    Storage storage;
    ManagerController controller;
    
    GameObject obj1;
    GameObject obj2;
 
    //Component comp;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    controller.renderManager.window = &window;

    Renderer rend1;
    //rend1.updateSprite("images/Eye.png");
    //Renderer rend2;
    //rend2.updateSprite("images/Eye.png");

    obj1.addComponent(rend1);
    obj1.controller = controller;

    storage.addObject(obj1, std::to_string(1));

    GameObject* obj = storage.getObject(std::to_string(1));

    Renderer* rend = obj->getComponent(rend1);
    //rend->updateSprite("images/Eye.png");
    rend->setPosition(100, 100);

    //obj1.removeComponent(typeid(Renderer).name());

    //controller.renderManager.addRenderer(&rend1);
    //controller.renderManager.addRenderer(&rend2);


    while (window.isOpen())	
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		controller.renderManager.update();
	}
    std::cout << std::to_string(1) << std::endl;

    return 0;
}