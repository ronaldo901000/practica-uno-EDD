#ifndef CARD_H
#define CARD_H
#include "../include/side/Side.h"
#include "../include/side/SideDark.h"
class Card
{
private:
    Side *sideLight;
    Side *sideDark;

public:
    Card(Side *sideLight);
    Card(Side *sideLight, Side *sideDark);
    ~Card();
    Side *getSideLight();
    Side *getSideDark();
    void setSideDark(SideDark* sideDark);
};
#endif