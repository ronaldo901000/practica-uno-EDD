#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H
#include "string"
class Player;
class LinkedList;
class CircularList;
class Stack;


class PlayerView
{
private:
    Player* player;
    
public:
    PlayerView(Player* player);
    ~PlayerView();
    void viewCards(bool isFlip);
    int actionsMenu(bool hasValidCards, bool isUno);
    int selectCard();
    bool askContinueDraw();
    void alert();
    int accumulationMenu(bool isEmpty, int totalAcumulacion);
    void printList(LinkedList* list, bool isLightSize);
    int selectCardAcumulation(LinkedList* listCardsAcumulation);
    void winner();
    void acumulationEnd(Player* nextPlayer, int currentAcumulation);
    void declareUno(bool &saidUno);
    void reportUno(Player *player, CircularList *playersList, Stack *stack);
};

#endif