#ifndef SIDE_LIGHT_H
#define SIDE_LIGHT_H
#include "Side.h"
class SideLight : public Side
{
private:
public:
    SideLight(Action *action, ColorEnum color);
    ~SideLight() override;
};
#endif