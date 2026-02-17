#include "../include/partida/Partida.h"

Partida::Partida(
    CircularList *playerList,
    Stack *stack,
    Configuration *config,
    int *playDirection,
    int *turnCount,
    bool *sidePlay)
{
    this->playerList = playerList;
    this->numberPlayers = playerList->getSize();
    this->stack = stack;
    this->discards = new Stack();
    this->config = config;
    // 1 representa direccion en contra de las manecillas del reloj o derecha
    // 0 representa direccion a favor de las manecillas del reloj o izquierda
    this->direction = playDirection;
    // 1 representa lado claro (normal)
    // 0 representa lado oscuro|
    this->sidePlay = sidePlay;

    this->turnCount = turnCount;
    for (int i = 0; i < playerList->getSize(); i++)
    {
        playerList->getElement(i)->setConfig(this->config);
    }
    
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
        // el jugador en turno juega sus cartas
        Player *player = playerList->getElement(*turnCount);
        player->playCard(*this->sidePlay, stack, discards, config->isRObberyMode(), manager, stack, playerList,direction,turnCount);

        if (player->isWinner())
        {
            hasWinner = true;
        }
        if (*direction == RIGHT)
        {
            (*turnCount)++;
            if (*turnCount == playerList->getSize())
            {
                *turnCount = 0;
            }
        }
        else
        {
            (*turnCount)--;
            if (*turnCount == -1)
            {
                *turnCount = playerList->getSize() - 1;
            }
        }
    }
}

void Partida::definePlayerNext(Player *nextPlayer)
{
    if (*direction == RIGHT)
    {
        int positionNext = (*turnCount)++;
        if (positionNext == playerList->getSize())
        {
            positionNext = 0;
        }
        nextPlayer = playerList->getNodeByIndex(positionNext)->getNextNode()->getElement();
    }
    else if (*direction == LEFT)
    {
        int positionNext = (*turnCount)--;
        if (positionNext == -1)
        {
            positionNext = playerList->getSize() - 1;
        }
        nextPlayer = playerList->getNodeByIndex(positionNext)->getNextNode()->getElement();
    }
}
int *Partida::getDireccion()
{
    return this->direction;
}

void Partida::setDireccion(int *direccion)
{
    this->direction = direccion;
}

bool Partida::getSidePlay()
{
    return this->sidePlay;
}