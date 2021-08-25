#include "Engine.h"
int main()
{
   // dosomething();
    BLUE::Engine* ENGINE = new BLUE::Engine();

    ENGINE->Init();
    ENGINE->GameLoop();
    delete ENGINE;


    return 0;
}