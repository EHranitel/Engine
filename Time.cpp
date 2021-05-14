#include "Time.hpp"

int TimeManager::getTime()
{
    return time;
}

void TimeManager::update()
{
    time++;
}