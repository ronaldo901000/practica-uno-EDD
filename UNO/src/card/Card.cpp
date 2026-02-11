#include "../include/card/Card.h"

Card ::Card(Side *sideLight)
{
    this->sideLight = sideLight;
    this->sideDark=nullptr;
}

Card ::Card(Side *sideLight, Side *sideDark)
{
    this->sideLight = sideDark;
    this->sideDark = sideDark;
}

Side *Card::getSideLight()
{
    return this->sideLight;
}
Side *Card::getSideDark()
{
    return this->sideDark;
}