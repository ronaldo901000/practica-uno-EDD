#include "../include/generator-stack/GeneratorStack.h"

GeneratorStack::GeneratorStack() {}
GeneratorStack::~GeneratorStack() {}

/*
metodo que se encarga de generar la pila de cartas
para iniciar una partida
*/
Stack *GeneratorStack ::generate()
{
    return nullptr;
}

int GeneratorStack ::calculateNumberDecks()
{
    return (numberPlayers - 1) / 6 + 1;
}
/*
metodo que se encarga de barajear las cartas de la pila
*/
void GeneratorStack ::shuffleCards(Stack *stack)
{
}

//se debe crear la clase mazo
Stack *GeneratorStack ::generateStack()
{
    return nullptr;
}