#include "../include/deck/Deck.h"
#include "string"
#include <iostream>

Deck ::Deck(Card **cards)
{
    this->cards = cards;
}
Deck::~Deck() {}

Card **Deck ::getCards()
{
    return this->cards;
}