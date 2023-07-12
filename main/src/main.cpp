#include <iostream>

#include "gamecontrol.h"

int main()
{
    GameControl* ptrGC = GameControl::getPtrInstance();

    ptrGC->initializeGameMenu();
    ptrGC->runMainLoop();

    return 0;
}
