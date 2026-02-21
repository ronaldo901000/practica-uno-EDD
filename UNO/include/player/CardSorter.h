#ifndef CARD_SORTER_H
#define CARD_SORTER_H
class LinkedList;
class Card;

class CardSorter{
    private:
    void quickSortNumber(Card** cards, int first, int left, bool isLigtSide);
    void quickSortColor(Card** cards, int first, int left, bool isLigtSide);
    int getCardNumber(Card* card, bool isLightSide);
    public:
    CardSorter();
    ~CardSorter();
    LinkedList* sortCards(LinkedList* cards, bool isLightSide);

};
#endif