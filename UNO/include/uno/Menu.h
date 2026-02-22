#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <limits>
#include <stdlib.h>
class Configuration;
class Player;
class CircularList;

class Menu
{
private:
public:
    Menu();
    ~Menu();
    void getLogoUno();
    void mostarConfiguracion(CircularList* list, Configuration* config,  int numberDecks, int numberCards);
};
#endif