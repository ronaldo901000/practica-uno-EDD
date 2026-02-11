#ifndef SIDE_H
#define SIDE_H
#include "../include/action/Action.h"
#include "../include/enum/ColorEnum.h"
#include <string>
class Side
{
protected:
    Action *action;
    ColorEnum color;
    std::string name;

public:
    Side(Action *action, ColorEnum color);
    virtual ~Side();
    Action *getAction();
    std::string getColor();
};
#endif
