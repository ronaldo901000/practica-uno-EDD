#ifndef ROBO_H
#define ROBO_H
#include "../include/action/Action.h"

class Robo : public Action
{
protected:
int cantidadRobo;
public:
    Robo ();
    ~Robo ();
    void realizarAccion() override;
};
#endif