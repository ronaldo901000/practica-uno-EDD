#include "../include/action/Salto.h"
#include <iostream>
Salto ::Salto(bool esLadoClaro, int *turnoActual, int *direccionJuego)
{
    this->esLadoClaro = esLadoClaro;
    this->turnoActual = turnoActual;
    this->direccionJuego = direccionJuego;
    this->nombre = "SALTO";
}
Salto ::~Salto() {}

// pendiente de implementacion
void Salto ::realizarAccion()
{
    if (esLadoClaro)
    {
        if (*direccionJuego == DERECHA)
        {
            (*turnoActual)++;
        }
        else
        {
            (*turnoActual)--;
        }
        std::cout << "\033[32m" << "El siguiente jugador pierde su turno" << "\033[0m" << std::endl;
    }
    // si es lado oscuro
    else
    {
        if (*direccionJuego == DERECHA)
        {
            (*turnoActual)--;
        }
        else
        {
            (*turnoActual)++;
        }
        std::cout << "\033[32m" << "Todos pierden su turno, juegas de nuevo" << "\033[0m" << std::endl;
    }
}