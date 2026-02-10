#ifndef GENERATOR_STACK_H
#define GENERATOR_STACK_H
#include "../include/stack/Stack.h"
class GeneratorStack
{
private:
    //atributos
    int numberPlayers;

    //metodos
    int calculateNumberDecks();
    Stack* generateStack();
public:
    //constructor y destructor
    GeneratorStack();
    ~GeneratorStack();

    Stack* generate();
    
    void shuffleCards(Stack* stack);


};
#endif 