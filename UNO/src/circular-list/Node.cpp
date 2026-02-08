#include "../include/circular-list/Node.h"

Node::Node() {}

Node::Node(Player *element)
{
    this->element = element;
}

Node::~Node() {}


Player *Node::getElement()
{
    return this->element;
}
void Node::setElement(Player *element)
{
    this->element = element;
}


Node *Node::getPreviousNode()
{
    return this->previousNode;
}
void Node::setPreviousNode(Node *previusNode)
{
    this->previousNode = previousNode;
}


Node *Node::getNextNode()
{
    return this->nextNode;
}
void Node::setNextNode(Node *nextNode)
{
    this->nextNode = nextNode;
}