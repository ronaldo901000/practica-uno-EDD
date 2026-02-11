#include "../include/side/SideLight.h"

SideLight::SideLight(Action *action, ColorEnum color)
    : Side(action, color)
{
    this->name = "LADO CLARO";
}

SideLight::~SideLight() {}
