/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/28
*  BLUE ENGINE
*/
#include "Engine.h"
#include"StateManager.h"
int main()
{
    //make new Engine
    Engine* ENGINE = new Engine();

    //Initialize Engine
    ENGINE->Init();

    //GameLoop
    ENGINE->GameLoop();
   
    //If the gameloop ends, delete Engine
    delete ENGINE;

    return 0;
}
