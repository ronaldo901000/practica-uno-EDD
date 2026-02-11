#include "../include/side/SideDark.h"

SideDark::SideDark(Action *action, ColorEnum color)
    : Side(action, color)
{
    this->name = "LADO OSCURO";
}

SideDark::~SideDark() {}
