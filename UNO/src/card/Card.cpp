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

void Card ::applyEffect(bool isLightSide)
{
    Side *side;
    if (isLightSide)
    {
        side = this->sideLight;
    }
    else
    {
        side = this->sideDark;
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

int Card::getIndexTemp()
{
    return this->indexTemp;
}
void Card::setIndexTemp(int indexTemp)
{
    this->indexTemp = indexTemp;
}

char Card ::getColorChar(bool isLightSide){
    char c;
    if(isLightSide){
        if(getSideLight()->getColor()=="Azul"){
            return 'a';
        }
        c = getSideLight()->getColor().at(0);
    }
    else{
        c = getSideDark()->getColor().at(0);
    }
    
    return c;
}