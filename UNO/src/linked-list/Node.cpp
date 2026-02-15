#include "../include/linked-list/Node.h"

Node::Node() 
{
    this->element = nullptr;
    this->nextNode = nullptr;
}

Node::Node(Card *element)
{
    this->element = element;
    this->nextNode = nullptr;
}

Node::~Node() {}

Card *Node::getElement()
{
    return this->element;
}

void Node::setElement(Card *element)
{
    this->element = element;
}

Node *Node::getNextNode()
{
    return this->nextNode;
}

void Node::setNextNode(Node *nextNode)
{
    this->nextNode = nextNode;
}