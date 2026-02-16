#include "../include/action/Reverse.h"

Reverse::Reverse(int* direccionActual){
    this->nombre="REVERSE";
    this->direccionActual=direccionActual;
}
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
