#include "../include/partida/Partida.h"

Partida::Partida()
{
    // 1 representa direccion en contra de las manecillas del reloj
    // 0 representa direccion a favor de las manecillas del reloj
    *this->direccion = 1;
}

int *Partida::getDireccion()
{
    return this->direccion;
}

void Partida::setDireccion(int *direccion)
{
    this->direccion = direccion;
}

int *Partida::getLadoEnJuego()
{
    return this->ladoEnJuego;
}