#ifndef ROBO_MAS_CUATRO_H
#define ROBO_MAS_CUATRO_H
#include "Robo.h"

class RoboMasCuatro : public Robo
{
private:
public:
    RoboMasCuatro();
    ~RoboMasCuatro();
    void realizarAccion() override;
};
#endif