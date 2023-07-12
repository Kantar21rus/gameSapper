#include "mainmenu.h"

MainMenu::MainMenu()
{

}

void MainMenu::showMainMenu()
{
//    for (int number = 0; number < items.size(); ++number)
//    {
//        std::cout << number + 1 << "\t" << items[number].getName() << std::endl;
//    }

    for (auto item : items)
    {
        std::cout << item.getNumber() << "\t" << item.getName() << std::endl;
    }
}

void MainMenu::addItem(const std::string &itemsName, int itemType)
{
    switch (itemType) {
    case MenuItemTypes::Base:
    {
        items.push_back(MenuItem(itemsName, items.size() + 1));
        break;
    }
    }
}

MenuItem* MainMenu::findItem(const std::string &fName)
{
    void* ptr1;
    void* ptr2;
    for (auto item : items)
    {
        if (item.getName() == fName)
        {
 //           return &item;
            ptr1 = &item;
        }
    }


    for (int pos = 0; pos < items.size(); ++pos)
    {
        if (items[pos].getName() == fName)
        {
 //           return &items[pos];
            ptr2 = &items[pos];
        }
    }

    return nullptr;
}

MenuItem* MainMenu::findItem(int fNumber)
{
//    for (auto item : items)
//    {
//        if (item.getNumber() == fNumber)
//        {
//            return &item;
//        }
//    }

    for (int pos = 0; pos < items.size(); ++pos)
    {
        if (items[pos].getNumber() == fNumber)
        {
            return &items[pos];
        }
    }

    return nullptr;
}
