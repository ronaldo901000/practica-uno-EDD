#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H
#include "string"
class Player;
class LinkedList;


class PlayerView
{
private:
    Player* player;
    
public:
    PlayerView(Player* player);
    ~PlayerView();
    void viewCards(bool isFlip);
    int actionsMenu(bool hasValidCards);
    int selectCard();
    bool askContinueDraw();
    void alert();
    int accumulationMenu(bool isEmpty, int totalAcumulacion);
    void viewCardsAcumulation(bool isLightSide, std::string nombre, Player* player);
    void printList(LinkedList* list, bool isLightSize);
    int selectCardAcumulation(LinkedList* listCardsAcumulation);
    void winner();
    void acumulationEnd(Player* nextPlayer, int currentAcumulation);
};

#endif