#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../include/linked-list/Node.h"
#include "../include/cards/Card.h"
class LinkedList
{
private:
    int size;
    Node *initialNode;
    Node *endNode;

public:
    // constructor y destructor
    LinkedList();
    ~LinkedList();

    // getters, setters, etc
    bool isEmpty();

    int getSize();

    void insertElement(Card *element);
    Card *getElement(int index);
    void deleteElement(int index);
    Node *getNodeByIndex(int index);
};
#endif