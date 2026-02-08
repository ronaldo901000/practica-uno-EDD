#ifndef NODE_H
#define NODE_H
#include "../include/cards/Card.h"

class Node
{
private:
    Node *nextNode;
    Card *element;

public:
    // Constructores y destructor
    Node();
    Node(Card *element);
    ~Node();

    // Getters y setters
    Card *getElement();
    void setElement(Card *element);

    Node *getNextNode();
    void setNextNode(Node *nextNode);
};

#endif
