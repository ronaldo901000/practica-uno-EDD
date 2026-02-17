#ifndef ROBO_MAS_DOS_H
#define ROBO_MAS_DOS_H
#include "Robo.h"

class RoboMasDos : public Robo{
    private:
        int* acumulate;
        int* numberCards;
        
    public:
    RoboMasDos();
    void realizarAccion()override;
};
#endif