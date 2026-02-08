#include "../include/stack/Stack.h"
#include "stdexcept"

Stack::Stack()
{
    this->container = new LinkedList();
    this->indexTop = -1;
}

Stack::~Stack() {}

//metodo que apila las cartas
void Stack ::push(Card *card)
{
    indexTop++;
    container->insertElement(card);
}

// metodo que devuele el elemento que esta en el tope de la pila
Card *Stack::pop()
{
    // se avisa que hay una excepcion si esta vacia la pila
    if (isEmpty())
    {
        throw std::runtime_error("Pila vacia: ya no hay mas cartas");
    }
    Card *card = this->container->getElement(indexTop);
    indexTop--;
    return card;
}

bool Stack::isEmpty()
{
    return indexTop == -1;
}

int Stack::getTop()
{
    return this->indexTop;
}
