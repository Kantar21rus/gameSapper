#include "gamecontrol.h"

//GameControl &GameControl::getInstance() {
//    static GameControl instance;
//    return instance;
//}

GameControl *GameControl::getPtrInstance() {
    static GameControl instance;
    return &instance;
}

GameControl::~GameControl()
{
#ifdef _DEBUG
    std::cout << "default destrutor GameControl" << std::endl;
#endif
}

void GameControl::initializeGameMenu()
{
    getMainMenu()->addItem("start");
    getMainMenu()->addItem("option");
    getMainMenu()->addItem("exit");
}

void GameControl::runMainLoop()
{
    getMainMenu()->showMainMenu();
    int i = 0;
    while(!gameClose)
    {
        ++i;
        inputCommand();
        if (i > 3)
            gameClose = true;
    }
}

GameControl::GameControl()
{
#ifdef _DEBUG
    std::cout << "default construtor GameControl" << std::endl;
#endif
}

int GameControl::inputCommand()
{
    std::string cmd;
    int commandInt = 0;

    std::getline(std::cin, cmd);

    int spacePos = cmd.find(' ');
    std::cout << "space pos: " << spacePos << std::endl;

    if (spacePos != std::string::npos)
    {
#ifdef _DEBUG
        std::cout << "2 or more words" << std::endl;
#endif
        std::string firstArg = cmd.substr(0, spacePos);
        std::string secondArg = cmd.substr(spacePos + 1);

#ifdef _DEBUG
        std::cout << secondArg << std::endl;
#endif
        try
        {
            commandInt = std::stoi(firstArg);
        }
        catch (std::invalid_argument const& ex)
        {
#ifdef _DEBUG
            std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
#endif
        }
    }
    else
    {
        std::cout << "1 word" << std::endl;
        try
        {
            commandInt = std::stoi(cmd);
        }
        catch (std::invalid_argument const& ex)
        {
#ifdef _DEBUG
            std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
#endif
        }
    }

    //mainMenu.findItem(commandInt);
    mainMenu.findItem(cmd);

#ifdef _DEBUG
    std::cout << cmd << std::endl;
#endif
    return 0;
}

