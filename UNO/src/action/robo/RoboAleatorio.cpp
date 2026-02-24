#include "../include/action/robo/RoboAleatorio.h"
#include "../include/circular-list/CircularList.h"
#include "../include/stack/Stack.h"
#include <iostream>
#include <random>
#include <stdlib.h>

using namespace std;

RoboAleatorio ::RoboAleatorio()
{
    this->nombre = "Robo Aleatorio";
    this->cantidadRobo = 5;
}
RoboAleatorio ::~RoboAleatorio() {}

void RoboAleatorio::realizarAccion()
{
    random_device rd;
    mt19937 gen(rd());

    int min = 0;
    int max = this->players->getSize() - 1;

    uniform_int_distribution<> distr(min, max);

    int numeroAleatorio = distr(gen);

    // se selecciona a un jugador de maner aleatoria
    Player *player = players->getElement(numeroAleatorio);

    // el jugador roba 5 cartas del stack
    for (int i = 0; i < cantidadRobo; i++)
    {
        Card *card = stack->pop();
        player->addCard(card);
    }
    cout << endl;
    cout << "\033[93m" << "Gira la ruleta, '" << player->getName() << "' roba " << cantidadRobo << " cartas." << "\033[0m" << endl;
}

void RoboAleatorio ::setStack(Stack *stack)
{
    this->stack = stack;
}

void RoboAleatorio ::setPlayers(CircularList *players)
{
    this->players = players;
}