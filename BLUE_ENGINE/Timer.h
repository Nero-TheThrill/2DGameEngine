/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/03
*  BLUE ENGINE
*/
#pragma once
#include <chrono>
class Timer
{

public:

    //"Timer::GetInstance(). to use functions of Timer Class.
    //////////////////////////////
    static Timer& GetInstance()
    {
        static Timer timer;
        return timer;
    }
    //////////////////////////////


    void Init();
    float GetDT();
    float GetTime();
private:

    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

};
