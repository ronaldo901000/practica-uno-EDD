#include "../include/linked-list/LinkedList.h"

LinkedList::LinkedList() {}
LinkedList::~LinkedList() {}

bool LinkedList::isEmpty()
{
    return size == 0;
}

int LinkedList::getSize()
{
    return this->size;
}

// metodo que se encarga de crear nodos a partir de un elemento
void LinkedList::insertElement(Card *element)
{
    // se crea un nuevo nodo
    Node *newNode = new Node(element);

    // el nodo es el primero y ultimo
    if (isEmpty())
    {
        this->initialNode = newNode;
        this->endNode = newNode;
    }
    else
    {
        this->endNode->setNextNode(newNode);
        this->endNode = newNode;
    }
    this->size++;
}

// metodo que se encarga de obtener cartas segun el indice
Card *LinkedList::getElement(int index)
{
    return getNodeByIndex(index)->getElement();
}

Node *LinkedList::getNodeByIndex(int index)
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

// metodo que se encarga de eliminar nodos, en base a su indice
void LinkedList ::deleteElement(int index)
{
    Node *node = getNodeByIndex(index);

    Node *previus = getNodeByIndex(index - 1);
    Node *next = node->getNextNode();
    // los nodos anterior y siguiente del nodo a eliminar se conectan
    previus->setNextNode(next);
    // se destruye el nodo
    node->~Node();
    size--;
}