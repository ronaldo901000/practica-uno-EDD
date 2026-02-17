#ifndef SALTO_H
#define SALTO_H
#include "Action.h"

class Salto : public Action
{
private:
    bool esLadoClaro;
    int* turnoActual;
    int* direccionJuego;
    const int DERECHA=0;
    const int IZQUIERDA=1;
    int numeroJugadores;
public:
    ~Salto();
    Salto(bool esLadoClaro, int* turnoActual, int* direccionJuego);
    void realizarAccion() override;
    void setNumeroJugadores(int numeroJugadores);
};
#endif