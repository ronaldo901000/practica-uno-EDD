#ifndef GENERATOR_STACK_H
#define GENERATOR_STACK_H
#include "../include/stack/Stack.h"
#include "../include/deck/Deck.h"
#include "../include/configuracion-partida/Configuration.h"
#include "../include/deck/GeneratorCards.h"
#include "../include/card/Card.h"
#include <random>

class GeneratorStack
{
private:
    int numberPlayers;
    Deck **decks;
    Configuration *config;
    Card **allCards;
    int totalNumberCards;
    int numberCardsDeck;
    // metodos
    int calculateNumberDecks();
    void generateDecks();
    void gatherDecks(int initialIndex, Deck *deck, int numberCards, Card **allCards);
    int generateIndexRandom(int totalNumberCards);
    void shuffleCards();

public:
    // constructor y destructor
    GeneratorStack(Configuration *config, int numberPlayers);

    ~GeneratorStack();

    Stack *generate();
};
#endif