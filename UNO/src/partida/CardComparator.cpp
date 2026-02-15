#include "../include/partida/CardComparator.h"
#include "../include/side/Side.h"
#include "../include/card/Card.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/action/Numero.h"
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