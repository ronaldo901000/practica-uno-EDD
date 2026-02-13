#include "../include/partida/CardsManager.h"
#include "../include/stack/Stack.h"
#include "../include/circular-list/CircularList.h"
#include "../include/player/Player.h"
#include "../include/card/Card.h"
#include <iostream>
#include <iomanip>
#include "../include/action/Numero.h"

using namespace std;
CardsManager::CardsManager() {}

CardsManager::~CardsManager() {}

void CardsManager::dealCards(Stack *stack, CircularList *players)
{
    // se reparten 7 veces 1 carta a cada jugador
    for (int i = 0; i < NUMBER_CARDS; i++)
    {
        for (int j = 0; j < players->getSize(); j++)
        {
            Player *player = players->getElement(j);
            Card *card = stack->pop();
            player->addCard(card);
        }
    }
    std::cout << "Reparticion completada" << std::endl;
}

void CardsManager ::drawInitialCard(Stack *stack, Stack *discards)
{
    Card *initialCard = stack->pop();
    discards->push(initialCard);
}

void CardsManager::viewCurrentCard(Card *card, bool isLightSide)
{
    string printColor;
    string RESET = "\033[0m";
    if (isLightSide)
    {
        printColor = "\033[30;47m";
    }
    else
    {
        printColor = "\033[37;40m";
    }

    string accion = card->getSideLight()->getAction()->getNombre();
    string color = card->getSideLight()->getColor();
    string valorNumerico = "";

    Numero *numero = dynamic_cast<Numero *>(card->getSideLight()->getAction());
    if (numero != nullptr)
    {
        valorNumerico = std::to_string(numero->getNumero());
    }

    cout << endl;
    cout << "     " << printColor << "┌───────────────────┐" << RESET << endl;
    cout << "     " << printColor << "│   CARTA ACTUAL    │" << RESET << endl;
    cout << "     " << printColor << "├───────────────────┤" << RESET << endl;
    cout << "     " << printColor << "│                   │" << RESET << endl;

    if (!valorNumerico.empty())
    {
        cout << "     " << printColor
             << "│        " << setw(3) << left << valorNumerico << "        │"
             << RESET << endl;
    }
    else
    {
        cout << "     " << printColor
             << "│     " << setw(10) << left << accion << "  │"
             << RESET << endl;
    }

    cout << "     " << printColor << "│                   │" << RESET << endl;

    cout << "     " << printColor
         << "│      " << setw(13) << left << color << "│"
         << RESET << endl;

    cout << "     " << printColor << "│                   │" << RESET << endl;
    cout << "     " << printColor << "└───────────────────┘" << RESET << endl;
    cout << endl;
}
