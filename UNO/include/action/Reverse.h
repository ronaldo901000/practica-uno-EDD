#ifndef REVERSE_H
#define REVERSE_H
#include "Action.h"

class Reverse : public Action
{
private:
    int* direccionActual;
    const int DERECHA=1;
    const int IZQUIERZA=0;

public:
    Reverse();
    void realizarAccion() override;
    //metodo que sirve para saber cual es la direccion antes del cambio
    void setDireccionActual(int* direccionActual);
};
#endif