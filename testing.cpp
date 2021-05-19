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

    controller.update();

    return 0;
}