#ifndef ROBO_MAS_UNO_FLIP_H
#define ROBO_MAS_UNO_FLIP_H
#include "Robo.h"

class RoboMasUnoFlip : public Robo
{
private:
public:
    RoboMasUnoFlip();
    ~RoboMasUnoFlip();
    void realizarAccion() override;
};

#endif