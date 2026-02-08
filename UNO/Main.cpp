#include<iostream>
#include "string"
#include "../include/player/Player.h"
#include "../include/circular-list/CircularList.h"

int main (){
    Player* p1 = new Player("Ronaldo",0);
    Player* p2 = new Player("Juan",1);
    Player* p3 = new Player("Dilan",2);
    Player* p4 = new Player("Josue",3);
    
    CircularList* cl= new CircularList();
    cl->insertElement(p1);
    cl->insertElement(p2);
    cl->insertElement(p3);
    cl->insertElement(p4);

    for (int i = 0; i < cl->getSize(); i++)
    {
        std::cout<<"Nombre: "<<cl->getElement(i)->getName()<<std::endl;
    }
    std::cout<<"Nombre: "<<cl->getNodeByIndex(3)->getNextNode()->getElement()->getName()<<std::endl;
    std::cout<<"Nombre: "<<cl->getNodeByIndex(3)->getNextNode()->getNextNode()->getElement()->getName()<<std::endl;
    return 0;
}