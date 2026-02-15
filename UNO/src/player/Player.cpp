#include "../include/player/Player.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/card/Card.h"
#include "../include/player/PlayerView.h"
#include "../include/stack/Stack.h"
#include "../include/partida/CardComparator.h"

Player::Player(std::string name, int id)
{
    this->name = name;
    this->id = id;
    this->cardsList = new LinkedList();
    this->view = new PlayerView(this);
}
Player ::Player()
{
    this->cardsList = new LinkedList();
    this->view = new PlayerView(this);
}
Player::~Player() {}

// metodo que sirve para que el jugador juegue sus cartas
void Player ::playCard(bool isLightSide, Stack *stack, Stack *discards, bool isRobberyMode)
{
    view->viewCards(isLightSide);
    this->comparator = new CardComparator();

    bool hasValidCards = comparator->alertCards(cardsList, stack->getTopElement(), isLightSide);

    int action = view->actionsMenu(hasValidCards);

    if (action == PLAY_CARD)
    {
        int selectedCardIndex = view->selectCard();

        Card *card = cardsList->getElement(selectedCardIndex);

        cardsList->deleteElement(selectedCardIndex);
        discards->push(card);
    }
    else
    {
        bool continueDrawing = false;
        do
        {
            Card *card = stack->pop();
            cardsList->insertElement(card);
            // si esta en modo robo solo deja de robar si puede jugar

        } while (isRobberyMode && continueDrawing);
    }
}

// metodo que se encarga de agregar una carta a la mano del jugador
void Player::addCard(Card *card)
{
    this->cardsList->insertElement(card);
}
// metodo que ordena las cartas del jugador
void Player::sortCards()
{
}

std::string Player::getName()
{
    return this->name;
}
void Player::setName(std::string name)
{
    this->name = name;
}

int Player::getId()
{
    return this->id;
}
void Player::setId(int id)
{
    this->id = id;
}

LinkedList *Player::getCardsList()
{
    return cardsList;
}