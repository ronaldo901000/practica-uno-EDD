#ifndef ACTION_H
#define ACTION_H
#include "../include/player/Player.h"
#include "string"
class Action
{
protected:
    Player* player;
    std::string nombre;
    bool esLadoClaro;
public:
    virtual ~Action() {}
    virtual void realizarAccion() = 0;
    void setPlayer(Player* player);
    void setEsLadoClaro(bool esLadoClaro);
    std::string getNombre();
};
#endif