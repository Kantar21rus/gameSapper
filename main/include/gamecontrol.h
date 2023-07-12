#ifndef GAMECONTROL_H
#define GAMECONTROL_H


#include <iostream>


#include "gamefield.h"
#include "mainmenu.h"

//!
//! \brief The GameControl class - singletone class, the main class that controls the program
//!
class GameControl {
public:

    //!
    //! \brief getPtrInstance   - gives access to an object of the class
    //! \return                 - pointer to GameControl's object
    //!
    static GameControl* getPtrInstance();
    ~GameControl();

    //!
    //! \brief getMainMenu      - gives access to mainMenu
    //! \return                 - pointer to MainMenu's object
    //!
    MainMenu* getMainMenu() {return &mainMenu;}

    //!
    //! \brief initializeGameMenu   - initializes the main menu, adds the necessary items to it
    //!
    void initializeGameMenu();

    //!
    //! \brief runMainLoop      - starts the main loop and transfers control to the user
    //!
    void runMainLoop();

private:
    //!
    //! \brief GameControl      - private constructor to implement singleton
    //!
    GameControl();

    GameControl(GameControl const&) = delete;
    void operator=(GameControl const&) = delete;

    MainMenu mainMenu;

    //!
    //! \brief inputCommand     - function for receiving and parsing user input
    //! \return                 - return code, 0 - all ok, 1 and higher error
    //!
    int inputCommand();

    bool gameClose = false;

};


#endif // GAMECONTROL_H
