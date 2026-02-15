#include "../include/partida/Partida.h"

Partida::Partida(
    CircularList *playerList,
    Stack *stack,
    Configuration *config)
{
    this->playerList = playerList;
    this->numberPlayers = playerList->getSize();
    this->stack = stack;
    this->discards = new Stack();
    this->config = config;
    // 1 representa direccion en contra de las manecillas del reloj o derecha
    // 0 representa direccion a favor de las manecillas del reloj o izquierda
    this->direction = RIGHT;
    // 1 representa lado claro (normal)
    // 0 representa lado oscuro|
    this->sidePlay = LIGHT_SIDE;
}

void Partida::start()
{
    // se reparte 7 cartas a cada jugador

    CardsManager *manager = new CardsManager();
    manager->dealCards(this->stack, this->playerList);

    // inician las rondas de juego
    startRounds(manager);
    delete manager;
}

void Partida::startRounds(CardsManager *manager)
{
    /*
        la primera ronda inicia con el repartidor sacando la primera carta de la pila
        poniendola en la pila de descartes
    */
    manager->drawInitialCard(this->stack, this->discards);
    while (!hasWinner)
    {
        for (int i = 0; i < numberPlayers; i++)
        {
            // el jugador en turno juega sus cartas
            Player *player = playerList->getElement(i);
            player->playCard(this->sidePlay, stack, discards, config->isRObberyMode(), manager);

            if (player->isWinner())
            {
                hasWinner = true;
            }
        }
    }
}

int Partida::getDireccion()
{
    return this->direction;
}

void Partida::setDireccion(int direccion)
{
    this->direction = direccion;
}

int Partida::getSidePlay()
{
    return this->direction;
}