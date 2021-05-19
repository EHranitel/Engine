#include "Managers.hpp"

void ManagerController::update()
{
    while (renderManager.window->isOpen())	 
	{
		sf::Event event;
		while (renderManager.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			    renderManager.window->close();
		}

        timeManager.update();
        physicsManager.update();
        scriptManager.update();
        animationManager.update();
        renderManager.update();
	}
}