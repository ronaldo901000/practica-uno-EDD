#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class LinkedList;
class Card;
class PlayerView;
class Stack;
class CardComparator;
class CardsManager;
class Configuration;
class CircularList;

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
    Configuration* config;
    void deleteCard(Card* card, LinkedList *acumulationList);
    

public:
    Player(std::string name, int id);
    Player();
    ~Player();
    std::string getName();
    void setName(std::string name);
    int getId();
    void setId(int id);
    LinkedList* getCardsList();
    void drawCards(int counterCards, Stack *stack);
    void setConfig(Configuration* config);
    Configuration* getConfiguration();

    void playCard(bool isLightSide, Stack* stack, Stack* discards, bool isRobberyMode, CardsManager* manager0, Stack* stak, CircularList *players, int *direction, int *turnCount);
    void addCard(Card *card);
    void sortCards();
    bool isWinner();
    void playValidCard(bool isLightSide, Stack *discards,Stack* stak,  CircularList* players, int* direction, int* turnCount);
    bool accumulate(int numberCards, bool isLightSide, Stack *stack, string nameAction, Stack* discards);

    LinkedList* getCardsAcumulation(bool isLightSide, std::string nombre, int numberCardAcumulation);
    Player* defineNextPlayer(CircularList* players, int direction, int* turnCount);
};
#endif