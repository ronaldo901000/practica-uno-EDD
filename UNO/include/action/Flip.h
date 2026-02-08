#ifndef FLIP_H
#define FLIP_H
#include "Action.h"

class Flip : public Action
{
private:
    int *ladoEnJuego;
    const int LADO_CLARO = 1;
    const int LADO_OSCURO = 0;

public:
    Flip();
    void realizarAccion() override;
    void setLadoEnJuego(int *ladoEnJuego);
};
#endif