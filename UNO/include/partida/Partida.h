#ifndef PARTIDA_H
#define PARTIDA_H
#include "../include/circular-list/CircularList.h"

class Partida
{
private:
    CircularList *listaJugadores;
    int* direccion;
    int* ladoEnJuego;

public:
    Partida();
    //falta el contructor para cuando este todo listo para inciar una partida(Jugadores, COnfig etc)
    int* getDireccion();
    void setDireccion(int* direccion);

    int* getLadoEnJuego();
};


#endif