#include "../include/player/CardSorter.h"
#include "../include/card/Card.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/action/Numero.h"
CardSorter ::CardSorter() {}
CardSorter ::~CardSorter() {}

LinkedList *CardSorter::sortCards(LinkedList *listCards, bool isLightSide)
{
    int size = listCards->getSize();
    Card **cards = new Card *[size];

    for (int i = 0; i < size; i++)
    {
        cards[i] = listCards->getElement(i);
    }

    quickSortColor(cards, 0, size - 1, isLightSide);

    int i = 0;
    while (i < size)
    {
        char colorActual = cards[i]->getColorChar(isLightSide);
        int inicio = i;

        while (i < size && cards[i]->getColorChar(isLightSide) == colorActual)
        {
            i++;
        }

        quickSortNumber(cards, inicio, i - 1, isLightSide);
    }

    LinkedList *nuevaLista = new LinkedList();
    for (int k = 0; k < size; k++)
    {
        nuevaLista->insertElement(cards[k]);
    }

    delete[] cards;
    return nuevaLista;
}

void CardSorter::quickSortColor(Card **cards, int first, int last, bool isLightSide)
{
    int i = first;
    int j = last;
    int central = (first + last) / 2;
    char pivot = cards[central]->getColorChar(isLightSide);

    do
    {
        while (cards[i]->getColorChar(isLightSide) < pivot)
        {
            i++;
        }
        while (cards[j]->getColorChar(isLightSide) > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(cards[i], cards[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (first < j)
    {
        quickSortColor(cards, first, j, isLightSide);
    }
    if (i < last)
    {
        quickSortColor(cards, i, last, isLightSide);
    }
}

void CardSorter::quickSortNumber(Card **cards, int first, int last, bool isLightSide)
{
    int i = first;
    int j = last;
    int central = (first + last) / 2;
    int pivot = getCardNumber(cards[central], isLightSide);

    do
    {
        while (getCardNumber(cards[i], isLightSide) < pivot)
            i++;
        while (getCardNumber(cards[j], isLightSide) > pivot)
            j--;

        if (i <= j)
        {
            swap(cards[i], cards[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (first < j)
        quickSortNumber(cards, first, j, isLightSide);
    if (i < last)
        quickSortNumber(cards, i, last, isLightSide);
}

int CardSorter::getCardNumber(Card *card, bool isLightSide)
{
    Action *action;
    if (isLightSide)
    {
        action = card->getSideLight()->getAction();
    }
    else
    {
        action = card->getSideDark()->getAction();
    }
    Numero *numero = dynamic_cast<Numero *>(action);
    if (numero != nullptr)
    {
        return numero->getNumero();
    }
    return -1;
}