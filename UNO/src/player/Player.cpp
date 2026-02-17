#include "../include/player/Player.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/card/Card.h"
#include "../include/player/PlayerView.h"
#include "../include/stack/Stack.h"
#include "../include/partida/CardComparator.h"
#include "../include/partida/CardsManager.h"
#include "../include/configuracion-partida/Configuration.h"
#include "string"
#include "../include/action/robo/Robo.h"
#include "../include/circular-list/CircularList.h"
#include <iostream>
using namespace std;

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
                       bool isRobberyMode, CardsManager *manager, Stack *stak, CircularList *players, int *direction, int *turnCount)
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
            playValidCard(isLightSide, discards, stack, players, direction, turnCount);
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
                playValidCard(isLightSide, discards, stack, players, direction, turnCount);
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

void Player::playValidCard(bool isLightSide, Stack *discards, Stack *stak, CircularList *players, int *direction, int *turnCount)
{
    CardsManager* manager = new CardsManager();
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

    Robo *robo;
    string nameAction;
    if (isLightSide)
    {
        robo = dynamic_cast<Robo *>(card->getSideLight()->getAction());
    }
    else
    {
        robo = dynamic_cast<Robo *>(card->getSideDark()->getAction());
    }

    // carta robo tiene una aplicacion de efecto diferente
    if (robo != nullptr)
    {

        nameAction = robo->getNombre();
        
        card->applyEffect(isLightSide);

        int currentAcumulation = robo->getCantidadRobo();
        bool canStack = true;
        while (canStack)
        {
            Player *nextPlayer = defineNextPlayer(players, *direction, turnCount);
            manager->viewCurrentCard(discards->getTopElement(), isLightSide);
            canStack = nextPlayer->accumulate(currentAcumulation, isLightSide, stak, nameAction, discards);
            if (canStack)
            {
                currentAcumulation += robo->getCantidadRobo();
                Card* stackedCard=discards->getTopElement();
                
                stackedCard->applyEffect(isLightSide);
            }
            else
            {
                view->acumulationEnd(nextPlayer, currentAcumulation);
            }
        }
    }
    // se aplica el efecto que tiene la carta directamente solo si no es carta robo
    else
    {
        card->applyEffect(isLightSide);
    }
    delete manager;
}

/**
 * true = continua la acumulacion
 * false = se detiene la acumulacion
 */
bool Player::accumulate(int numberCards, bool isLightSide, Stack *stack, string nameAction, Stack *discards)
{
    cout << "\033[96m" << "Acumulacion total: " << numberCards << "\033[0m" << endl;

    if (config->isAccumulation())
    {
        LinkedList *list = getCardsAcumulation(isLightSide, nameAction, numberCards);

        if (!list->isEmpty())
        {
            view->printList(list, isLightSide);
            int option = view->accumulationMenu(list->isEmpty(), numberCards);

            if (option == PLAY_CARD)
            {
                int cardIndex = view->selectCardAcumulation(list);

                // se obtiene la carta y se elimina de la lista
                Card *card = list->getElement(cardIndex);
                deleteCard(card, list);

                // se pone en la pila de descartes
                discards->push(card);

                delete list;
                return true;
            }
            else
            {
                // El Jugador roba
                drawCards(numberCards, stack);
                delete list;
                return false;
            }
        }
        else
        {
            drawCards(numberCards, stack);
            delete list;
            return false;
        }
    }
    else
    {
        drawCards(numberCards, stack);
        return false;
    }
}

void Player::drawCards(int counterCards, Stack *stack)
{
    for (int i = 0; i < counterCards; i++)
    {
        Card *card = stack->pop();
        addCard(card);
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

/*metodo que se encarga de obtener y listar las cartas con las que el jugador puede seguir la acumulacion */
LinkedList *Player::getCardsAcumulation(bool isLightSide, std::string nombre, int numberCardAcumulation)
{
    LinkedList *listAcumulation = new LinkedList();
    for (int i = 0; i < cardsList->getSize(); i++)
    {
        Card *card;
        string accion;
        card = cardsList->getElement(i);

        if (isLightSide)
        {
            accion = card->getSideLight()->getAction()->getNombre();
            if (accion == nombre)
            {
                card->setIndexTemp(i);
                listAcumulation->insertElement(card);
            }
        }
        else
        {
            accion = card->getSideDark()->getAction()->getNombre();
            if (accion == nombre)
            {
                card->setIndexTemp(i);
                listAcumulation->insertElement(card);
            }
        }
    }

    return listAcumulation;
}

// falta el grito de uno!!!
bool Player ::isWinner()
{
    if (this->cardsList->isEmpty())
    {
        view->winner();
    }
    return this->cardsList->isEmpty();
}

Player *Player::defineNextPlayer(CircularList *players, int direction, int *turnCount)
{
    if (direction == 0)
    {
        (*turnCount)++;
        if (*turnCount >= players->getSize())
        {
            *turnCount = 0;
        }
    }
    else
    {
        (*turnCount)--;
        if (*turnCount < 0)
        {
            *turnCount = players->getSize() - 1;
        }
    }

    return players->getElement(*turnCount);
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

Configuration * ::Player::getConfiguration()
{
    return this->config;
}

void Player::setConfig(Configuration *config)
{
    this->config = config;
}

void Player::deleteCard(Card *card, LinkedList *acumulationList)
{
    for (int i = 0; i < acumulationList->getSize(); i++)
    {
        if (card == acumulationList->getElement(i))
        {
            acumulationList->deleteElement(i);
            break;
        }
    }

    for (int i = 0; i < cardsList->getSize(); i++)
    {
        if (card == cardsList->getElement(i))
        {
            cardsList->deleteElement(i);
            return;
        }
    }
}