#include "../include/player/Player.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/card/Card.h"
#include "../include/player/PlayerView.h"
#include "../include/stack/Stack.h"
#include "../include/partida/CardComparator.h"
#include "../include/partida/CardsManager.h"

Player::Player(std::string name, int id)
{
    this->name = name;
    this->id = id;
    this->cardsList = new LinkedList();
    this->view = new PlayerView(this);
    this->numberDraw = 0;
}
Player ::Player()
{
    this->cardsList = new LinkedList();
    this->view = new PlayerView(this);
    this->numberDraw = 0;
}
Player::~Player() {}

// metodo que sirve para que el jugador juegue sus cartas
void Player ::playCard(bool isLightSide, Stack *stack, Stack *discards,
                       bool isRobberyMode, CardsManager *manager)
{

    this->comparator = new CardComparator();

    // verifica que el usuario tenga al menos 1 carta jugable para su turno
    bool hasValidCards = comparator->alertCards(cardsList, discards->getTopElement(), isLightSide);

    if (!isRobberyMode)
    {
        // se muestra la carta actual en juego
        manager->viewCurrentCard(discards->getTopElement(), isLightSide);

        view->viewCards(isLightSide);
        int action = view->actionsMenu(hasValidCards);

        if (action == PLAY_CARD)
        {
            playValidCard(isLightSide, discards);
        }
        else
        {
            Card *card = stack->pop();
            cardsList->insertElement(card);
        }
    }
    else
    {
        bool isTurnValid;
        do
        {
            // se muestra la carta actual en juego
            manager->viewCurrentCard(discards->getTopElement(), isLightSide);

            view->viewCards(isLightSide);
            int action = view->actionsMenu(comparator->alertCards(cardsList, discards->getTopElement(), isLightSide));
            if (action == PLAY_CARD)
            {
                playValidCard(isLightSide, discards);
                isTurnValid = true;
            }
            else
            {
                Card *card = stack->pop();
                cardsList->insertElement(card);
            }
        } while (!isTurnValid);
    }
    delete comparator;
}

void Player::playValidCard(bool isLightSide, Stack *discards)
{
    Card *card;
    int selectedCardIndex;
    bool isValidCard;
    // ciclo se repite si el jugador no selecciona una carta valida para jugar
    do
    {
        selectedCardIndex = view->selectCard();
        card = cardsList->getElement(selectedCardIndex);
        isValidCard = comparator->isValidCard(card, discards->getTopElement(), isLightSide);
        // se le avisa al jugador que su eleccion de carta no es la correcta
        if (!isValidCard)
        {
            view->alert();
        }
    } while (!isValidCard);

    cardsList->deleteElement(selectedCardIndex);
    discards->push(card);
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

// falta el grito de uno!!!
bool Player ::isWinner()
{
    return this->cardsList->getSize() == 0;
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