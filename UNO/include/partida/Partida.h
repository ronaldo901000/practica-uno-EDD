#ifndef PARTIDA_H
#define PARTIDA_H
#include "../include/circular-list/CircularList.h"
#include "../include/stack/Stack.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/configuracion-partida/Configuration.h"
#include "../include/player/Player.h"
#include "../include/partida/CardsManager.h"
class Partida
{
private:
    CircularList *playerList;
    int *direction;
    bool *sidePlay;
    Stack *stack;
    Stack *discards;
    Configuration *config;
    Player playerTurn;
    bool hasWinner;
    int numberPlayers;
    int *turnCount;

    const int DARK_SIDE = 0;
    const int LIGHT_SIDE = 1;

    const int RIGHT = 0;
    const int LEFT = 1;

    void startRounds(CardsManager *manager);

public:
    Partida(
        CircularList *playerList,
        Stack *stack,
        Configuration *config,
        int *playDirection,
        int *turnCount,
        bool *sidePlay);

    ~Partida();

    void start();

    int *getDireccion();

    void setDireccion(int *direccion);

    bool getSidePlay();
};

#endif