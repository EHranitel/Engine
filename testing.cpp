#include "Storage.hpp"

class Test1 : public Script
{
    public:
        void run()
        {
            if (parent->x <= 100)
            {
                parent->getComponent<Renderer>()->flipHorizontally();
                parent->getComponent<Renderer>()->changeText("DOG");

                parent->getComponent<Physics>()->vX = 0.05;
            }
        }
};

class Test2 : public Script
{
    public:
        void run()
        {
            if (parent->x >= 500)
            {
                parent->getComponent<Renderer>()->flipHorizontally();
                parent->getComponent<Renderer>()->changeText("DOGGE");

                parent->getComponent<Physics>()->vX = -0.05;
            }
        }
};

class Test3 : public Script
{
    public:
        void run()
        {
            if(parent->controller->timeManager.getTime() == 300)
            {
                parent->removeComponent<Animation>();
                parent->removeComponent<Renderer>();
                parent->removeComponent<Physics>();

                parent->removeComponent<Test1>();
                parent->removeComponent<Test2>();               
            }

            if(parent->controller->timeManager.getTime() == 600)
            {
                parent->addComponent<Animation>();
                parent->addComponent<Renderer>();

                Animation* anim = parent->getComponent<Animation>();
                anim->addSpriteFromImage("images/Dog_Husky.png", 100, 28, 0, 7);
                anim->changeRendererSprite("images/Dog_Husky.png");

                Renderer* rend = parent->getComponent<Renderer>();
                rend->isAnimated = true;
                rend->changeFont("fonts/times.ttf");
            }
        }
};

class Rotation : public Script
{
    public:
        void run()
        {
            parent->getComponent<Renderer>()->rotate(5);
        }
};

int main()
{
    Storage storage;
    ManagerController controller;

    controller.renderManager.setWindowSize(1000, 1000);

    for(int i = 0; i < 3; i++)
    {
        storage.addObject(std::to_string(i));

        GameObject* obj = storage.getObject(std::to_string(i)); 
        obj->controller = &controller;
        obj->storage = &storage;

        obj->addComponent<Renderer>();
        Renderer* rend = obj->getComponent<Renderer>();
        rend->isAnimated = true;
        rend->changeFont("fonts/times.ttf");
        rend->changeText("DOG");

        obj->addComponent<Animation>();
        Animation* anim = obj->getComponent<Animation>();
        anim->addSpriteFromImage("images/Dog_Husky.png", 100, 28, 9, 17);
        anim->changeRendererSprite("images/Dog_Husky.png");

        rend->flipHorizontally();

        obj->addComponent<Physics>();
        Physics* phys = obj->getComponent<Physics>();
        phys->vX = 0.1;

        obj->addComponent<Test1>();
        obj->addComponent<Test2>();

        obj->x = 0 + rand()%(400-20+1);
        obj->y = 20 + rand()%(780-20+1);
    }

    storage.getObject(std::to_string(0))->addComponent<Test3>();

    storage.addObject("Cobblesone");

    GameObject* obj = storage.getObject("Cobblesone"); 
    obj->controller = &controller;
    obj->storage = &storage;

    obj->addComponent<Renderer>();
    obj->addComponent<Rotation>();
    obj->getComponent<Renderer>()->changeImage("images/Cobblestone.png");


    obj->x = 800;
    obj->y = 300;

    controller.update();

    return 0;
}