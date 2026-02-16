#include "../include/partida/CardComparator.h"
#include "../include/side/Side.h"
#include "../include/card/Card.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/action/Numero.h"
#include "../include/action/Color.h"
#include <iostream>
using namespace std;

CardComparator::CardComparator() {}

CardComparator::~CardComparator() {}

bool CardComparator::alertCards(LinkedList *cardsList, Card *currentCard, bool isLightSide)
{
    Side *side;
    if (isLightSide)
    {
        side = currentCard->getSideLight();
    }
    else
    {
        side = currentCard->getSideDark();
    }
    return canPlayCard(side, cardsList, isLightSide);
}

bool CardComparator::canPlayCard(Side *sideCurrent, LinkedList *cardsList, bool isLightSide)
{
    for (int i = 0; i < cardsList->getSize(); i++)
    {
        Side *sideCardPlayer;

        if (isLightSide)
        {
            sideCardPlayer = cardsList->getElement(i)->getSideLight();
        }
        else
        {
            sideCardPlayer = cardsList->getElement(i)->getSideDark();
        }


        // hay una excepcion en cartas multicolor, se compara con el color temporal
        Color *actionColor;
        if (isLightSide)
        {
            actionColor = dynamic_cast<Color *>(sideCurrent->getAction());
        }
        else
        {
            actionColor = dynamic_cast<Color *>(sideCurrent->getAction());
        }

        // se define que color se muestra en un multicolor
        if (actionColor != nullptr)
        {
            if (sideCurrent->getTemporalColor() == sideCardPlayer->getColor() || sideCardPlayer->getColor() == "Multicolor")
            {
                return true;
            }
        }

        // Coincide color o es comodin multicolor
        if (sideCardPlayer->getColor() == sideCurrent->getColor() ||
            sideCardPlayer->getColor() == "Multicolor")
        {
            return true;
        }

        // Coincide accion
        if (sideCardPlayer->getAction()->getNombre() ==
            sideCurrent->getAction()->getNombre())
        {
            Numero *numberCurrent = dynamic_cast<Numero *>(sideCurrent->getAction());
            Numero *numberPlayer = dynamic_cast<Numero *>(sideCardPlayer->getAction());

            // Si ambas son cartas numericas
            if (numberCurrent != nullptr && numberPlayer != nullptr)
            {
                if (numberCurrent->getNumero() == numberPlayer->getNumero())
                {
                    return true;
                }
                // No coincide el numero, continuar con la siguiente carta
                continue;
            }
            // cualquier otra carta igual es verdadera
            return true;
        }
    }

    return false;
}

bool CardComparator::isValidCard(Card *playerCard, Card *currentCard, bool isLightSide)
{
    Side *currentSide;
    Side *playerSide;
    if (isLightSide)
    {
        currentSide = currentCard->getSideLight();
        playerSide = playerCard->getSideLight();
    }
    else
    {
        currentSide = currentCard->getSideDark();
        playerSide = playerCard->getSideDark();
    }

    // comparaciones

    Color *actionColor;
    if (isLightSide)
    {
        actionColor = dynamic_cast<Color *>(currentCard->getSideLight()->getAction());
    }
    else
    {
        actionColor = dynamic_cast<Color *>(currentCard->getSideDark()->getAction());
    }

    // se define que color se muestra en un multicolor
    if (actionColor != nullptr)
    {
        if (currentSide->getTemporalColor() == playerSide->getColor() || playerSide->getColor() == "Multicolor")
        {
            return true;
        }
    }

    if (currentSide->getColor() == playerSide->getColor() || playerSide->getColor() == "Multicolor")
    {
        return true;
    }
    // Coincide accion
    if (currentSide->getAction()->getNombre() ==
        playerSide->getAction()->getNombre())
    {
        Numero *numberCurrent = dynamic_cast<Numero *>(currentSide->getAction());
        Numero *numberPlayer = dynamic_cast<Numero *>(playerSide->getAction());

        // Si ambas son cartas numericas y con el mismo valor
        if (numberCurrent != nullptr && numberPlayer != nullptr)
        {
            if (numberCurrent->getNumero() == numberPlayer->getNumero())
            {
                return true;
            }
            // si son cartas numericas con diferente valor
            else
            {
                return false;
            }
        }

        return true;
    }
    return false;
}