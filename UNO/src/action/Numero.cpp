#include "../include/action/Numero.h"

Numero ::Numero(int numero)
{
    this->nombre = "NUMERICA";
    this->numero = numero;
}

Numero ::~Numero() {}

// pendiente de implementacion
void Numero ::realizarAccion()
{
}

int Numero::getNumero(){
    return this->numero;
}