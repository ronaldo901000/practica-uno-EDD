#ifndef ROBO_MULTICOLOR_H
#define ROBO_MULTICOLOR_H
#include "Robo.h"
class Side;

class RoboMulticolor : public Robo
{
private:
    std::string colorsDarkSide[4];
    std::string colorsLightSide[4];
    Side* side;

public:
    RoboMulticolor();
    void realizarAccion() override;
    void setSide(Side* side);
};

#endif