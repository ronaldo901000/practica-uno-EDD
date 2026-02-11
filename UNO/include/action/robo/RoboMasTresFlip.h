#ifndef ROBO_MAS_TRES_FLIP_H
#define ROBO_MAS_TRES_FLIP_H
#include "../include/action/robo/Robo.h"

class RoboMasTresFlip : public Robo
{
private:
public:
    RoboMasTresFlip();
    void realizarAccion() override;
};

#endif