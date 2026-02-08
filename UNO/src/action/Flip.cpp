#include "../include/action/Flip.h"

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