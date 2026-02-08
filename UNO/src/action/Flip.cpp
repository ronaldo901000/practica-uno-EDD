#include "../include/action/Flip.h"

Flip::Flip()
{
    this->nombre = "FLIP";
}
void Flip::realizarAccion()
{
    if (*ladoEnJuego == LADO_CLARO)
    {
        *ladoEnJuego = LADO_OSCURO;
    }
    else
    {
        *ladoEnJuego = LADO_CLARO;
    }
}

void Flip::setLadoEnJuego(int *ladoEnJuego)
{
    this->ladoEnJuego = ladoEnJuego;
}