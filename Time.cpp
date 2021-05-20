#include "Time.hpp"

int TimeManager::getTime()
{
    return time;
}

void TimeManager::update()
{
    time = (time + 1) % (1000000 - 1);
}