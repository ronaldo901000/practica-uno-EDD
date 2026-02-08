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
    Node *newNode = new Node(element);

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
        newNode->setPreviousNode(endNode);
        this->endNode = newNode;
        this->endNode->setNextNode(this->initialNode);
    }
    this->size++;
}

// metodo que se encarga de obtener jugadores segun el indice
Player *CircularList::getElement(int index)
{
    return getNodeByIndex(index)->getElement();
}

Node *CircularList::getNodeByIndex(int index)
{
    if (isEmpty())
    {
        return nullptr;
    }
    if (index < 0 || index >= size)
    {
        return nullptr;
    }
    Node *current = initialNode;

    for (int i = 0; i < index; i++)
    {
        Node *next = current->getNextNode();
        current = next;
    }
    return current;
}

//metodo que se encarga de eliminar nodos, en base a su indice
void CircularList ::deleteElement(int index)
{
    Node *node =getNodeByIndex(index);

    Node* previus= node->getPreviousNode();
    Node* next = node->getNextNode();
    //los nodos anterior y siguiente del nodo a eliminar se conectan
    previus->setNextNode(next);
    next->setPreviousNode(previus);
    //se destruye el nodo
    node->~Node();
}