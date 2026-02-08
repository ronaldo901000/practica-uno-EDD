#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H
#include "Node.h"
class CircularList
{
private:
    int size;
    Node*initialNode;
    Node*endNode;
    

public:
    //constructor y destructor
    CircularList();
    ~CircularList();

    //getters, setters, etc
    bool isEmpty();

    int getSize();

    void insertElement(Player* element);
    Player* getElement(int index);
    void deleteElement(int index);
    Node* getNodeByIndex(int index);
    
};
#endif