#ifndef ROBO_MAS_SEIS_FLIP_H
#define ROBO_MAS_SEIS_FLIP_H
#include "Robo.h"

class RoboMasSeisFlip : public Robo
{
private:
public:
    RoboMasSeisFlip();
    void realizarAccion() override;
};

#endif