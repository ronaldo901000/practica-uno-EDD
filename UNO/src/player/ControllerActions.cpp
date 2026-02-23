#include "../include/player/ControllerActions.h"
#include "../include/action/robo/Robo.h"
#include "../include/action/robo/RoboAleatorio.h"
#include "../include/card/Card.h"
#include "../include/partida/CardsManager.h"
#include "../include/player/PlayerView.h"
#include "../include/stack/Stack.h"

ControllerActions ::ControllerActions() {}

ControllerActions ::~ControllerActions() {}

void ControllerActions ::handleCardEffect(
    bool isLightSide, Card *card, CardsManager *manager, Stack *stak,
    PlayerView *view, Stack *discards, CircularList *players, int *direction,
    int *turnCount, Player *currentPlayer)
{

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
    if (robo != nullptr && dynamic_cast<RoboAleatorio *>(robo) == nullptr)
    {

        nameAction = robo->getNombre();

        card->applyEffect(isLightSide);

        int currentAcumulation = robo->getCantidadRobo();
        bool canStack = true;
        while (canStack)
        {
            Player *nextPlayer = currentPlayer->defineNextPlayer(players, *direction, turnCount);
            manager->viewCurrentCard(discards->getTopElement(), isLightSide);
            canStack = nextPlayer->accumulate(currentAcumulation, isLightSide, stak, nameAction, discards);
            if (canStack)
            {
                currentAcumulation += robo->getCantidadRobo();
                Card *stackedCard = discards->getTopElement();

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
        RoboAleatorio *roboAleatorio;
        if (isLightSide)
        {
            roboAleatorio = dynamic_cast<RoboAleatorio *>(card->getSideLight()->getAction());
        }
        else
        {
            roboAleatorio = dynamic_cast<RoboAleatorio *>(card->getSideDark()->getAction());
        }
        if (roboAleatorio != nullptr)
        {
            roboAleatorio->setStack(stak);
            roboAleatorio->setPlayers(players);
        }

        card->applyEffect(isLightSide);
    }
}