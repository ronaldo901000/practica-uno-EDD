#ifndef CREATOR_PLAYERS_H
#define CREATOR_PLAYERS_H
#include "../include/circular-list/CircularList.h"
class CreatorPlayers
{
private:
    int numberPlayers;
    void getNamePlayer(Player *player, int i);

public:
    CreatorPlayers(int numberPlayers);
    ~CreatorPlayers();
    
    CircularList* createPlayers();
};
#endif