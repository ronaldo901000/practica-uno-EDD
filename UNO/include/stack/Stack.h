#ifndef STACK_H
#define STACK_H
#include "../include/linked-list/LinkedList.h"
#include "../include/card/Card.h"
class Stack
{
private:
    LinkedList *container;
    int indexTop;

public:
    Stack();
    ~Stack();
    void push(Card *card);
    Card *pop();
    Card* getTopElement();
    bool isEmpty();
    int getTop();
};
#endif