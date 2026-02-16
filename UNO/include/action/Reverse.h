#ifndef REVERSE_H
#define REVERSE_H
#include "Action.h"

class Reverse : public Action
{
private:
    int* direccionActual;
    const int DERECHA=0;
    const int IZQUIERZA=1;

public:
    Reverse(int* direccionActual);
    void realizarAccion() override;
    //metodo que sirve para saber cual es la direccion antes del cambio
};
#endif