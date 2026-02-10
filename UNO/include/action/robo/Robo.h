#ifndef ROBO_H
#define ROBO_H
#include "Action.h"

class Robo : public Action
{
protected:
int cantidadRobo;
public:
    void realizarAccion() override;
};
#endif