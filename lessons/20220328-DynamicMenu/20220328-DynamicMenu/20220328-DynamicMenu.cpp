#include <iostream>
#include <vector>
#include <string>
#include "20220328-DynamicMenu.h"

using namespace std;

typedef void (*MenuHandler)(void*);

struct MenuItem
{
    char key;
    string text;
    MenuHandler handler;
};

void MenuOption1(void* params)
{
    cout << "MenuOption1 handler: " << (char*)params << endl;
}

void MenuOption2(void* params)
{
    cout << "MenuOption2 handler" << endl;
}

void MenuOption3(void* params)
{
    cout << "MenuOption3 handler" << endl;
}

void displayMenu(std::vector<MenuItem>& menuItems)
{
    for (auto item : menuItems)
    {
        cout << item.key << ". " << item.text << endl;
    }

    cout << "Choose an option: ";
}

void handleMenu(std::vector<MenuItem>& menuItems)
{
    char choice;

    char name[] = { "Ivan" };

    while (true)
    {
        displayMenu(menuItems);

        cin >> choice;

        auto it = find_if(menuItems.begin(), menuItems.end(),
            [&choice](const MenuItem& item)
            {
                return item.key == choice;
            });

        if (it != menuItems.end())
        {
            auto handler = (*it).handler;
            if (handler != NULL)
            {
                handler(name);
            }
            else
            {
                break;
            }
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }
}

int main()
{
    vector<MenuItem> menuItems =
    {
        { '1' , "Start", MenuOption1 },
        { '2' , "Help", MenuOption2 },
        { '9' , "Exit", NULL },
    };

    handleMenu(menuItems);

}


