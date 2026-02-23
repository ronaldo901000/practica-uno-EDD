#ifndef CONTROLLER_ACTIONS_H
#define CONTROLLER_ACTIONS_H
class Player;
class Card;
class CircularList;
class Stack;
class CardsManager;
class PlayerView;

class ControllerActions{
private:
    
public:
    ControllerActions(/* args */);
    ~ControllerActions();

    void handleCardEffect(bool isLightSide, Card *card, CardsManager *manager, Stack *stak,
    PlayerView *view, Stack *discards, CircularList *players, int *direction,
    int *turnCount, Player *currentPlayer);

};

#endif 