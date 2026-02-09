#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H
#include "CircularNode.h"
class CircularList
{
private:
    int size;
    CircularNode*initialNode;
    CircularNode*endNode;
    

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
    CircularNode* getNodeByIndex(int index);
    
};
#endif