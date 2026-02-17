#include "../include/partida/CardComparator.h"
#include "../include/side/Side.h"
#include "../include/card/Card.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/action/Numero.h"
#include "../include/action/Color.h"
#include "../include/action/robo/RoboMulticolor.h"
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

/**
 *
 * metodo que compara la carta actual con la carta que elige el jugador
 * >se evalua:
 *      color
 *      accion
 *      color temporal (si es multicolor)
 *      numero
 */
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
        if (isColorAction(sideCurrent, sideCardPlayer))
        {
            return true;
        }

        // hay excepcion si la carta actual es de roobo multicolor
        if (isDrawAction(sideCurrent, sideCardPlayer))
        {
            return true;
        }

        // Coincide color o es comodin multicolor
        if (sideCardPlayer->getColor() == sideCurrent->getColor() ||
            sideCardPlayer->getColor() == MULTICOLOR)
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

    // se verifica cuando la carta en juego actual es multicolor con un color definido
    if (isColorAction(currentSide, playerSide))
    {
        return true;
    }
    //se verifica si es carta robo multicolor, si lo es, se compara con su color temporal
    if (isDrawAction(currentSide, playerSide))
    {
        return true;
    }

    // lo demas se compara que sea color o multicolor
    if (currentSide->getColor() == playerSide->getColor() || playerSide->getColor() == MULTICOLOR)
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

bool CardComparator::isColorAction(Side *sideCurrent, Side *sideCardPlayer)
{
    // verificar si la carta actual es accion Color
    Color *actionColor = dynamic_cast<Color *>(sideCurrent->getAction());
    if (actionColor == nullptr)
    {
        return false;
    }
    // si coincide el color temporal elegido
    if (sideCurrent->getTemporalColor() == sideCardPlayer->getColor())
    {
        return true;
    }

    // si la carta del jugador es multicolor (comodin)
    if (sideCardPlayer->getColor() == MULTICOLOR)
    {
        return true;
    }

    return false;
}

bool CardComparator::isDrawAction(Side *currentSide, Side *playerSide)
{
    RoboMulticolor *currentDraw = dynamic_cast<RoboMulticolor *>(currentSide->getAction());

    // si la carta actual no es robo, no aplica
    if (currentDraw == nullptr)
    {
        return false;
    }

    // si coincide el color temporal elegido
    if (currentSide->getTemporalColor() == playerSide->getColor())
    {
        return true;
    }

    // si la carta del jugador es multicolor (comodin)
    if (playerSide->getColor() == MULTICOLOR)
    {
        return true;
    }

    return false;
}