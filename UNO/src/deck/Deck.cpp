#include "../include/deck/Deck.h"
#include "string"
#include <iostream>

Deck::Deck(Card **cards, int numberCards)
{
    this->cards = new Card *[numberCards];
    for (int i = 0; i < numberCards; i++)
    {
        this->cards[i] = cards[i]; 
}
}
Deck::~Deck() {}

Card **Deck ::getCards()
{
    return this->cards;
}

Card *Deck::getCardIndex(int index)
{
    return cards[index];
}