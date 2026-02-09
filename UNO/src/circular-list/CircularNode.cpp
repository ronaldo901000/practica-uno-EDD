#include "../include/circular-list/CircularNode.h"

CircularNode::CircularNode() {}

CircularNode::CircularNode(Player *element)
{
    this->element = element;
}

CircularNode::~CircularNode() {}


Player *CircularNode::getElement()
{
    return this->element;
}
void CircularNode::setElement(Player *element)
{
    this->element = element;
}


CircularNode *CircularNode::getPreviousNode()
{
    return this->previousNode;
}
void CircularNode::setPreviousNode(CircularNode *previusNode)
{
    this->previousNode = previousNode;
}


CircularNode *CircularNode::getNextNode()
{
    return this->nextNode;
}
void CircularNode::setNextNode(CircularNode *nextNode)
{
    this->nextNode = nextNode;
}