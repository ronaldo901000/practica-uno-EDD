#ifndef UNO_H
#define UNO_H
#include "../include/configuracion-partida/Configuration.h"
#include "../include/creator-players/CreatorPlayers.h"
#include "../include/deck/Deck.h"
#include "../include/generator-stack/GeneratorStack.h"
#include "../include/uno/Menu.h"
#include "../include/partida/Partida.h"
class Uno
{
private:
    const int SI = 1;
    const int NO = 2;
    const int MIN_PLAYERS = 2;
    Configuration *createConfig();
    void getResponse(bool *response);
    void getNumerPlayers(int *numberPlayers);

public:
    ~Uno();
    void start();
};
#endif