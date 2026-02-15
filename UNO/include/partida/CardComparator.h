#ifndef CARD_COMPARATOR_H
#define CARD_COMPARATOR_H
class LinkedList;
class Card;
class Side;
class SideLigth;
class SideDark;

class CardComparator
{
private:
    bool canPlayCard(Side* sideCurrent, LinkedList* cardsList, bool isLightSide);
public:
    CardComparator();
    ~CardComparator();
    bool alertCards(LinkedList *cardsList, Card *currentCard, bool isLightSide);
    bool isValidCard(Card* playerCard, Card* currentCard, bool isLightSide);
};
#endif
