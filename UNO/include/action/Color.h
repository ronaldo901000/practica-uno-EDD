#ifndef COMODIN_COLOR_H
#define COMODIN_COLOR_H
#include "Action.h"

class Color : public Action
{
private:
    bool esLadoClaro;

public:
    Color(bool esLadoClaro);
    ~Color();
    void realizarAccion() override;
};
#endif