#include "Time.hpp"

int TimeManager::getTime()
{
    return time;
}

void TimeManager::update()
{
    time = (time + 1) % (2 ^ 64 - 1);
}