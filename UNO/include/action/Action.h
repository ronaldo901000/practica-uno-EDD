#ifndef ACTION_H
#define ACTION_H
#include "../include/player/Player.h"
#include "string"
class Action
{
protected:
    Player* player;
    std::string nombre;
public:
    virtual ~Action() {}
    virtual void realizarAccion() = 0;
    void setPlayer(Player* player);

    std::string getNombre();
};
#endif