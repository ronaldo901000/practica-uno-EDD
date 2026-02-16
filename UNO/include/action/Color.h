#ifndef COMODIN_COLOR_H
#define COMODIN_COLOR_H
#include "Action.h"
class Side;

class Color : public Action
{
private:
    bool esLadoClaro;
    std:: string currentColor; 
    std::string colorsDarkSide[4];
    std::string colorsLightSide[4];
    Side* side;

public:
    Color(bool esLadoClaro);
    ~Color();
    void realizarAccion() override;
    std::string getCurrentColor();
    void setCurrentColor();
    void setSide(Side* side);

};
#endif