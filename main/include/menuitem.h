#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>




enum MenuItemTypes {
    Base = 0
};


//!
//! \brief The MenuItem class - Parents class for all items in Main Menu
//!
class MenuItem
{
public:

    //!
    //! \brief MenuItem - Main constructor, immediately sets the name
    //! \param iName   - name which set
    //!
    MenuItem(const std::string& iName, int iNumber);

    //!
    //! \brief getName      - get name of this item
    //! \return             - return name
    //!
    const std::string& getName() {return name;}

    //!
    //! \brief getNumber    - get number of this item
    //! \return             - return number
    //!
    int getNumber() {return number;}

    //!
    //! \brief doIt         - virtual method doIt for different inheritor
    //!
    virtual void doIt() {};

protected:
    //!
    //! \brief MenuItem - Base constructor, protected so as not to be created without a name
    //!
    MenuItem();

    std::string name;
    int number;

};

#endif // MENUITEM_H
