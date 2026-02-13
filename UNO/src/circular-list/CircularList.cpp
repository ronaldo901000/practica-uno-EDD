#include "../include/circular-list/CircularList.h"

CircularList::CircularList() {}
CircularList::~CircularList() {}

bool CircularList::isEmpty()
{
    return size == 0;
}

int CircularList::getSize()
{
    return this->size;
}

// metodo que se encarga de crear nodos a partir de un elemento
void CircularList::insertElement(Player *element)
{
    // se crea un nuevo nodo
    CircularNode *newNode = new CircularNode(element);

    // el nodo es el primero y ultimo
    if (isEmpty())
    {
        this->initialNode = newNode;
        this->endNode = newNode;

        this->initialNode->setPreviousNode(this->initialNode);
        this->initialNode->setNextNode(this->initialNode);
    }
    else
    {
        this->endNode->setNextNode(newNode);

        newNode->setPreviousNode(this->endNode);
        newNode->setNextNode(this->initialNode);

        this->initialNode->setPreviousNode(newNode);
        
        this->endNode = newNode;
    }
    this->size++;
}

// metodo que se encarga de obtener jugadores segun el indice
Player *CircularList::getElement(int index)
{
    return getNodeByIndex(index)->getElement();
}

CircularNode *CircularList::getNodeByIndex(int index)
{
    if (isEmpty())
    {
        return nullptr;
    }
    if (index < 0 || index >= size)
    {
        return nullptr;
    }
    CircularNode *current = initialNode;

    for (int i = 0; i < index; i++)
    {
        CircularNode *next = current->getNextNode();
        current = next;
    }
    return current;
}

//metodo que se encarga de eliminar nodos, en base a su indice
void CircularList ::deleteElement(int index)
{
    CircularNode *node =getNodeByIndex(index);

    CircularNode* previus= node->getPreviousNode();
    CircularNode* next = node->getNextNode();
    //los nodos anterior y siguiente del nodo a eliminar se conectan
    previus->setNextNode(next);
    next->setPreviousNode(previus);
    //se destruye el nodo
    node->~CircularNode();
}