#include "../include/card/Card.h"

Card ::Card(Side *sideLight)
{
    this->sideLight = sideLight;
    this->sideDark = nullptr;
}

Card ::Card(Side *sideLight, Side *sideDark)
{
    this->sideLight = sideDark;
    this->sideDark = sideDark;
}

void Card ::applyEffect(bool isLightSide){
    Side* side;
    if(isLightSide){
        side=this->sideLight;
    }
    else{
        side=this->sideDark;
    }
    side->getAction()->realizarAccion();
}
Side *Card::getSideLight()
{
    return this->sideLight;
}
Side *Card::getSideDark()
{
    return this->sideDark;
}

void Card ::setSideDark(SideDark *sideDark)
{
    this->sideDark = sideDark;
}