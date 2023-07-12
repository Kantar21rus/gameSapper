#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <vector>

#include "menuitem.h"

class MainMenu
{
public:
    MainMenu();

    void showMainMenu();
    void addItem(const std::string& itemsName, int itemType = MenuItemTypes::Base);

    MenuItem* findItem(const std::string& fName);
    MenuItem* findItem(int fNumber);

private:
    std::vector<MenuItem> items;
};

#endif // MAINMENU_H
