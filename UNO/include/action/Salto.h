#ifndef SALTO_H
#define SALTO_H
#include "Action.h"

class Salto : public Action
{
private:
    bool esLadoClaro;
public:
    ~Salto();
    Salto(bool esLadoClaro);
    void realizarAccion() override;
};
#endif