#include "../include/action/robo/Robo.h"

Robo ::Robo() {}

Robo ::~Robo() {}

int Robo::getCantidadRobo()
{
    return this->cantidadRobo;
}
void Robo ::setEsAcumulacion(bool esAcumulacion)
{
    this->esAcumulacion = esAcumulacion;
}

void Robo::setContadorAcumulacion(int acumulacionEnCurso)
{
    this->contadorDeAcumulacion += acumulacionEnCurso;
}