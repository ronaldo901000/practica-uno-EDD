#include "../include/partida/CardsManager.h"
#include "../include/stack/Stack.h"
#include "../include/circular-list/CircularList.h"
#include "../include/player/Player.h"
#include "../include/card/Card.h"
#include <iostream>
#include <iomanip>
#include "../include/action/Numero.h"
#include "../include/partida/CardComparator.h"
#include "../include/action/Color.h"
#include "../include/action/robo/RoboMulticolor.h"
#include <random>

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
}

void CardsManager ::drawInitialCard(Stack *stack, Stack *discards)
{
    Card *initialCard = stack->pop();
    discards->push(initialCard);
}

/*metodo que verifica que la pila de cartas tenga al menos 24*/
void CardsManager::checkDrawPile(Stack *stack, Stack *discards)
{
    // mini 24 cartas en la pila de robo
    if (stack->getTop() < 24)
    {
        // saca la primera carta de descartes para jugar
        Card *playCard = discards->pop();

        int size = discards->getTop() + 1;
        if (size > 0)
        {
            Card **arrayCards = new Card *[size];

            for (int i = 0; i < size; i++)
            {
                arrayCards[i] = discards->pop();
            }

            shuffleCards(arrayCards, size);

            for (int i = 0; i < size; i++)
            {
                stack->push(arrayCards[i]);
            }

            delete[] arrayCards; 
        }

        discards->push(playCard);

        cout << "\033[33mBarajeando cartas\033[0m" << endl;
    }
}

void CardsManager ::shuffleCards(Card **cards, int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < size - 1; i++)
    {
        std::uniform_int_distribution<> dis(i, size - 1);
        int randomIndex = dis(gen);

        Card *temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

void CardsManager::viewCurrentCard(Card *card, bool isLightSide)
{
    string printColor;
    string RESET = "\033[0m";
    Side *side;
    if (isLightSide)
    {
        printColor = "\033[30;47m";
        side = card->getSideLight();
    }
    else
    {
        printColor = "\033[37;40m";
        side = card->getSideDark();
    }

    string accion = side->getAction()->getNombre();
    string color = "";
    string valorNumerico = "";

    // se define que color se muestra en un multicolor
    Color *actionColor = dynamic_cast<Color *>(side->getAction());
    RoboMulticolor *actionRobo = dynamic_cast<RoboMulticolor *>(side->getAction());
    if (actionColor != nullptr || actionRobo != nullptr)
    {
        color = side->getTemporalColor();
    }
    else
    {
        color = side->getColor();
    }

    Numero *numero = dynamic_cast<Numero *>(side->getAction());
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
