#include "Storage.hpp"
#include <array>

class Test : public Script
{
    public:
        void run()
        {
            if (parent->x < 1000)
            {
                //std::cout << "SCRIPT" << std::endl;

                parent->x += 5;
            }
        }
};

int main()
{
    Storage storage;
    ManagerController controller;

    Renderer rend0;

    int time = 0;
    int deleteThis = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML window");
    controller.renderManager.window = &window;

    for(int i = 0; i < 1; i++)
    {
        storage.addObject(std::to_string(i));

        GameObject* obj = storage.getObject(std::to_string(i)); 
        obj->controller = &controller;

        obj->addComponent<Renderer>();
        obj->addComponent<Animation>();
        obj->addComponent<Test>();

        Renderer* rend = obj->getComponent<Renderer>();

        obj->x = 50;
        //0 + rand()%(980-20+1);
        obj->y = 50;
        //20 + rand()%(780-20+1);

        std::cout << "ASD" << std::endl;

        rend->changeImage("images/Eye1.png");

        std::cout << "ZXC" << std::endl;
    }

    while (window.isOpen())	
	{
        time++;

        if(time % 101 == 100)
        {
            GameObject* obj1 = storage.getObject(std::to_string(0)); 
            std::cout << "1234" << std::endl;
            Renderer* rend1 = obj1->getComponent<Renderer>();
            std::cout << "12345" << std::endl;
            rend1->flipHorizontally();
            std::cout << "123456" << std::endl;

            /*GameObject* obj2 = storage.getObject(std::to_string(1)); 
            std::cout << "1234" << std::endl;
            Renderer* rend2 = obj2->getComponent<Renderer>();
            std::cout << "12345" << std::endl;
            //rend2->flipVertically();/*
            
            std::cout << "123456" << std::endl;*/

            /*if(deleteThis == 1)
            {
                deleteThis = 0;
            }

            storage.removeObject(std::to_string(deleteThis));

            storage.addObject(std::to_string(deleteThis));

            GameObject* obj = storage.getObject(std::to_string(deleteThis)); 
            obj->controller = &controller;

            obj->addComponent<Renderer>();

            Renderer* rend = obj->getComponent<Renderer>();

            rend->setPosition(20 + rand()%(980-20+1), 20 + rand()%(780-20+1));

            rend->addImage("images/Eye1.png");

            time = 0;
            deleteThis++;*/
        }

        if (time % 200 == 150)
        {
            GameObject* obj = storage.getObject(std::to_string(0)); 

            obj->removeComponent<Renderer>();
            std::cout << "1" << std::endl;
            obj->removeComponent<Animation>();
            std::cout << "12" << std::endl;
            obj->removeComponent<Test>();
            std::cout << "123" << std::endl;
        }

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		controller.update();
	}

    //std::cout << std::to_string(1) << std::endl;

    return 0;
}