/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/03
*  BLUE ENGINE
*/
#include"Timer.h"

void Timer::Init()
{
    startTime = previousTime = std::chrono::high_resolution_clock::now();
    currentTime = previousTime;
}

float Timer::GetDT()
{
    currentTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> dt(currentTime - previousTime);

    previousTime = std::chrono::high_resolution_clock::now();

    return dt.count();
}

float Timer::GetTime()
{
    currentTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> dt(currentTime - startTime);

    return dt.count();
}
