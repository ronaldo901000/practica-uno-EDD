#ifndef FLIP_H
#define FLIP_H
#include "Action.h"

class Flip : public Action
{
private:
    bool *esLadoClaro;
    const int LADO_CLARO = 1;
    const int LADO_OSCURO = 0;

public:
    Flip(bool *esLadoClaro);
    void realizarAccion() override;
};
#endif