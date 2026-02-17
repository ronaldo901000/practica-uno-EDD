#ifndef ROBO_H
#define ROBO_H
#include "../include/action/Action.h"
class Stack;
class Robo : public Action
{
protected:
    int cantidadRobo;
    bool esAcumulacion;
    Stack *stack;
    int contadorDeAcumulacion;

public:
    Robo();
    ~Robo();
    virtual void realizarAccion() = 0;
    int getCantidadRobo();
    void setEsAcumulacion(bool esAcumulacion);
    void setContadorAcumulacion(int acumulacionActual);
};
#endif