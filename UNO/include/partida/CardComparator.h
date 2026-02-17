#ifndef CARD_COMPARATOR_H
#define CARD_COMPARATOR_H
#include "string"
using namespace std;

class LinkedList;
class Card;
class Side;
class SideLigth;
class SideDark;

class CardComparator
{
private:
    bool canPlayCard(Side* sideCurrent, LinkedList* cardsList, bool isLightSide);
    bool isColorAction(Side *sideCurrent, Side *sideCardPlayer);
    bool isDrawAction(Side* sideCurrent, Side* playerSide);
    const string MULTICOLOR="Multicolor";
    const string ROBO_4 ="ROBO +4";
    const string ROBO_2_FLIP= "ROBO +2";
    const string ROBO_6_FLIP= "ROBO +6";
public:
    CardComparator();
    ~CardComparator();
    bool alertCards(LinkedList *cardsList, Card *currentCard, bool isLightSide);
    bool isValidCard(Card* playerCard, Card* currentCard, bool isLightSide);
};
#endif
