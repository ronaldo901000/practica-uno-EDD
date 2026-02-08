#include "../include/action/Reverse.h"

//metodo que se encarga de cambiar la direccion o sentido de la partida
void Reverse::realizarAccion()
{
    if (*direccionActual == DERECHA)
    {
        *direccionActual = IZQUIERZA;
    }
    else
    {
        *direccionActual = DERECHA;
    }
}

void Reverse::setDireccionActual(int *direccionActual)
{
    this->direccionActual = direccionActual;
}