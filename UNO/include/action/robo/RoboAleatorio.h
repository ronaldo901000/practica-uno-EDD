#ifndef ROBO_ALEATORIO_H
#define ROBO_ALEATORIO_H
#include "../include/action/robo/Robo.h"
class CircularList;
class Stack;

class RoboAleatorio : public Robo
{
private:
    CircularList *players;

public:
    RoboAleatorio();
    ~RoboAleatorio();
    void realizarAccion() override;
    void setStack(Stack *stack);
    void setPlayers(CircularList* players);
};
#endif