#ifndef ACTION_H
#define ACTION_H
#include "../include/player/Player.h"
class Action
{
protected:
    Player* player;
public:
    virtual ~Action() {}
    virtual void realizarAccion() = 0;
    void setPlayer(Player* player);
};
#endif