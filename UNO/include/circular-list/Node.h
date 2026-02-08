#ifndef NODE_H
#define NODE_H
#include "../include/player/Player.h"

class Node
{
private:
    Node *previousNode;
    Node *nextNode;
    Player *element;

public:
    // Constructores y destructor
    Node();
    Node(Player *element);
    ~Node();

    // Getters y setters
    Player* getElement();
    void setElement(Player *element);

    Node* getPreviousNode();
    void setPreviousNode(Node* previousNode);

    Node *getNextNode();
    void setNextNode(Node *nextNode);
};

#endif
