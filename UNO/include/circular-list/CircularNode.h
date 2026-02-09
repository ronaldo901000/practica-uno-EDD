#ifndef NODE_CIRCULAR_H
#define NODE_CIRCULAR_H
#include "../include/player/Player.h"

class CircularNode
{
private:
    CircularNode *previousNode;
    CircularNode *nextNode;
    Player *element;

public:
    // Constructores y destructor
    CircularNode();
    CircularNode(Player *element);
    ~CircularNode();

    // Getters y setters
    Player* getElement();
    void setElement(Player *element);

    CircularNode* getPreviousNode();
    void setPreviousNode(CircularNode* previousNode);

    CircularNode *getNextNode();
    void setNextNode(CircularNode *nextNode);
};

#endif
