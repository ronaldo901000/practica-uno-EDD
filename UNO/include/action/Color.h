#ifndef COLOR_H
#define COLOR_H
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