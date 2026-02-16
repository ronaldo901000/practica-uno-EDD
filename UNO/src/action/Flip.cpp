#include "../include/action/Flip.h"
#include <iostream>
Flip::Flip(bool *esLadoClaro)
{
    this->nombre = "FLIP";
    this->esLadoClaro = esLadoClaro;
}
void Flip::realizarAccion()
{
    if (*esLadoClaro)
    {
        *esLadoClaro = false;
        std::cout << "\033[33m" << "Es FLIP, cambiando al lado oscuro" << "\033[0m" << std::endl;
    }
    else
    {
        *esLadoClaro = true;
        std::cout << "\033[33m" << "Es FLIP, cambiando al lado claro" << "\033[0m" << std::endl;
    }
}
