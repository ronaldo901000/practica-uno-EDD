#ifndef ROBO_MAS_TRES_FLIP_H
#define ROBO_MAS_TRES_FLIP_H
#include "Robo.h"

class RoboMasTresFlip : public Robo
{
private:
public:
    RoboMasTresFlip();
    ~RoboMasTresFlip();
    void realizarAccion() override;
};

#endif