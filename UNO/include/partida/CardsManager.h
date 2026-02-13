#ifndef CARDS_MANAGER_H
#define CARDS_MANAGER_H
class Stack;
class CircularList;
class Card;

class CardsManager
{
private:
    const int NUMBER_CARDS = 7;

public:
    CardsManager();
    ~CardsManager();
    void dealCards(Stack *stack, CircularList *players);
    void drawInitialCard(Stack* stack, Stack* discards);
    void viewCurrentCard(Card* card, bool isLightSide);
};
#endif