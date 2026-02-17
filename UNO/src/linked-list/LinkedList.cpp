#include "../include/linked-list/LinkedList.h"

LinkedList::LinkedList()
{
    this->initialNode = nullptr;
    this->endNode = nullptr;
    this->size = 0;
}

LinkedList::~LinkedList()
{
    // Liberar todos los nodos
    Node *current = initialNode;
    while (current != nullptr)
    {
        Node *next = current->getNextNode();
        delete current;
        current = next;
    }
}

bool LinkedList::isEmpty()
{
    return size == 0;
}

int LinkedList::getSize()
{
    return this->size;
}

void LinkedList::insertElement(Card *element)
{
    Node *newNode = new Node(element);

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

Card *LinkedList::getElement(int index)
{
    Node *node = getNodeByIndex(index);
    return (node != nullptr) ? node->getElement() : nullptr;
}

Node *LinkedList::getNodeByIndex(int index)
{
    if (isEmpty() || index < 0 || index >= size)
    {
        return nullptr;
    }

    Node *current = initialNode;
    for (int i = 0; i < index; i++)
    {
        current = current->getNextNode();
    }
    return current;
}

void LinkedList::deleteElement(int index)
{
    if (isEmpty() || index < 0 || index >= size)
    {
        cout << "El indice: '" << index << "' esta fuera de rango para eliminar" << endl;
        return;
    }

    // Solo hay un nodo
    if (size == 1)
    {
        delete initialNode;
        initialNode = nullptr;
        endNode = nullptr;
        size = 0;
        return;
    }

    // Se elimina el primer nodo
    if (index == 0)
    {
        Node *temp = initialNode;
        initialNode = initialNode->getNextNode();
        delete temp;
        size--;
        return;
    }

    // Se elimina un nodo de en medio o el ultimo
    Node *previous = getNodeByIndex(index - 1);
    Node *current = previous->getNextNode();

    previous->setNextNode(current->getNextNode());

    if (current == endNode)
    {
        endNode = previous;
    }

    delete current;
    size--;
}