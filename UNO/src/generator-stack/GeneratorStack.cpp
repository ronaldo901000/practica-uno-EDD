#include "../include/generator-stack/GeneratorStack.h"

GeneratorStack::GeneratorStack(Configuration *config, int numberPlayers)
{
    this->config = config;
    this->numberPlayers = numberPlayers;
}

GeneratorStack::~GeneratorStack() {}

/*
metodo que se encarga de generar la pila de cartas
para iniciar una partida
*/
Stack *GeneratorStack ::generate()
{
    generateDecks();
    shuffleCards();
    Stack *stack = new Stack();
    for (int i = 0; i < totalNumberCards; i++)
    {
        Card *card = allCards[i];
        stack->push(card);
    }

    return stack;
}

void GeneratorStack::generateDecks()
{
    int numberDecks = (numberPlayers - 1) / 6 + 1;
    this->decks = new Deck *[numberDecks];

    for (int i = 0; i < numberDecks; i++)
    {
        GeneratorCards *generator = new GeneratorCards(this->config);
        Card **cards = generator->generateCards();
        Deck *deck = new Deck(cards, generator->getNumberCards());
        decks[i] = deck;
        // Guardar info del primer generador para usar despues
        if (i == 0)
        {
            totalNumberCards = numberDecks * generator->getNumberCards();
            allCards = new Card *[totalNumberCards];
            numberCardsDeck = generator->getNumberCards();
        }
        delete generator;
    }

    int initialIndex = 0;
    for (int i = 0; i < numberDecks; i++)
    {
        Deck *deck = decks[i];
        gatherDecks(initialIndex, deck, numberCardsDeck, allCards);
        initialIndex += numberCardsDeck;
    }
}

// metodo que junta las cartas de un mazo en un solo arreglo
void GeneratorStack::gatherDecks(int initialIndex, Deck *deck, int numberCards, Card **allCards)
{
    for (int i = 0; i < numberCards; i++)
    {
        allCards[initialIndex + i] = deck->getCardIndex(i);
    }
}

int GeneratorStack ::calculateNumberDecks()
{
    return (numberPlayers - 1) / 6 + 1;
}

/*
metodo que se encarga de barajear las cartas de la pila
*/
void GeneratorStack::shuffleCards()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < totalNumberCards - 1; i++)
    {
        std::uniform_int_distribution<> dis(i, totalNumberCards - 1);
        int randomIndex = dis(gen);

        Card *temp = allCards[i];
        allCards[i] = allCards[randomIndex];
        allCards[randomIndex] = temp;
    }
}

int GeneratorStack::generateIndexRandom(int maxIndex)
{
    int index = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, maxIndex - 1);
    index = dis(gen);

    return index;
}
