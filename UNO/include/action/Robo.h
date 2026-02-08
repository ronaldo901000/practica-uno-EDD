#ifndef ROBO_H
#define ROBO_H
#include "Action.h"

class Robo : public Action
{
private:
int cantidadRobo;
public:
    void realizarAccion() override;
};
#endif