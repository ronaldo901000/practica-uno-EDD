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
#include "../include/player/CardSorter.h"
#include "../include/action/robo/RoboAleatorio.h"
#include "ControllerActions.h"

using namespace std;

Player::Player(std::string name, int id)
{
    this->name = name;
    this->id = id;
    this->cardsList = new LinkedList();
    this->view = new PlayerView(this);
    this->numberDraw = 0;
    this->sorter = new CardSorter();
    this->controllerActions = new ControllerActions();
}
Player ::Player()
{
    this->cardsList = new LinkedList();
    this->view = new PlayerView(this);
    this->numberDraw = 0;
    this->controllerActions = new ControllerActions();
}
Player::~Player()
{
    delete cardsList;
    delete view;
    delete controllerActions;
}

// metodo que sirve para que el jugador juegue sus cartas
void Player ::playCard(bool isLightSide, Stack *stack, Stack *discards,
                       bool isRobberyMode, CardsManager *manager, CircularList *players, int *direction, int *turnCount)
{
    // se ordenan las cartas
    sortCards(isLightSide);
    // se revuelven cartas si ya no hay cartas en la pila
    manager->checkDrawPile(stack, discards);

    this->comparator = new CardComparator();

    // verifica que el usuario tenga al menos 1 carta jugable para su turno
    bool hasValidCards = comparator->alertCards(cardsList, discards->getTopElement(), isLightSide);

    if (!isRobberyMode)
    {
        // se muestra la carta actual en juego
        manager->viewCurrentCard(discards->getTopElement(), isLightSide);

        view->viewCards(isLightSide);
        int action = view->actionsMenu(hasValidCards, config->isScreamOne());

        if (action == PLAY_CARD)
        {
            playValidCard(isLightSide, discards, stack, players, direction, turnCount);
        }
        else if(action ==DRAW_CARD)
        {
            Card *card = stack->pop();
            cardsList->insertElement(card);
        }
        //apartado para reportar a alguien que no aviso ¡UNO!
        else{
            view->reportUno(this, players, stack);
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
            int action = view->actionsMenu(comparator->alertCards(cardsList, discards->getTopElement(), isLightSide), config->isScreamOne());
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
    CardsManager *manager = new CardsManager();
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

    // realiza las acciones segun el tipo de carta
    controllerActions->handleCardEffect(isLightSide, card, manager, stak, view, discards, players, direction, turnCount, this);

    // si esta activa la configuracion de gito UNO y ya solo le queda una carta al jugador
    if (config->isScreamOne() && cardsList->getSize() == 1)
    {
        view->declareUno(this->saidUno);
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
    this->saidUno=false;
}

// metodo que se encarga de agregar una carta a la mano del jugador
void Player::addCard(Card *card)
{
    this->cardsList->insertElement(card);
}

// metodo que ordena las cartas del jugador
void Player::sortCards(bool isLightSide)
{
    LinkedList *listaVieja = this->cardsList;
    this->cardsList = sorter->sortCards(this->cardsList, isLightSide);
    delete listaVieja;
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

PlayerView *Player ::getView()
{
    return this->view;
}

bool Player :: getSaidUno(){
    return this->saidUno;
}