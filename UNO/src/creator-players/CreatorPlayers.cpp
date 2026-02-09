#include "../include/creator-players/CreatorPlayers.h"
#include <iostream>
using namespace std;

CreatorPlayers ::CreatorPlayers(int numberPlayers)
{
    this->numberPlayers = numberPlayers;
}

CreatorPlayers::~CreatorPlayers() {}

/*
        metodo que se encarga de crear la
        lista doblemente enlazada circular
        que almacena jugadores
*/
CircularList* CreatorPlayers ::createPlayers()
{
    // se crea la lista circular
    CircularList *list = new CircularList();
    for (int i = 0; i < this->numberPlayers; i++)
    {
        // se crea el jugador
        Player *player = new Player();
        // se obtiene el nombre y se le asigna un ID
        getNamePlayer(player, i);
        // se inserta a la lista
        list->insertElement(player);
    }
    return list;
}

// metodo que se encarga de pedir el nombre al jugador
void CreatorPlayers::getNamePlayer(Player *player, int i)
{
    string name;

    cout << "Jugador " << (i + 1) << ", ingresa tu nombre: ";
    cin >> name;

    player->setName(name);
    player->setId(i);
}
