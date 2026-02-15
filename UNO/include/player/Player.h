#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class LinkedList;
class Card;
class PlayerView;
class Stack;
class CardComparator;
class CardsManager;

class Player
{
private:
    std::string name;
    int id;
    CardComparator* comparator;
    LinkedList* cardsList;
    PlayerView* view;
    const int PLAY_CARD=1;
    const int DRAW_CARD=2;
    //contador de robos sucesivos
    int numberDraw;
    

public:
    Player(std::string name, int id);
    Player();
    ~Player();
    std::string getName();
    void setName(std::string name);
    int getId();
    void setId(int id);
    LinkedList* getCardsList();

    void playCard(bool isLightSide, Stack* stack, Stack* discards, bool isRobberyMode, CardsManager* manager);
    void addCard(Card *card);
    void sortCards();
    bool isWinner();
    void playValidCard(bool isLightSide, Stack *discards);
};
#endif