#ifndef SIDE_DARK_H
#define SIDE_DARK_H
#include "../include/action/Action.h"
#include "../include/enum/ColorEnum.h"
#include "Side.h"
class SideDark :public Side
{
private:
public:
    SideDark(Action *action, ColorEnum color);
    ~SideDark() override;
};
#endif
