#include "../include/side/Side.h"

Side ::Side(Action *action, ColorEnum color)
{
    this->action = action;
    this->color = color;
}
Side ::~Side() {};

Action *Side::getAction()
{
    return this->action;
}

std::string Side::getColor()
{
    if (this->color == ColorEnum::Rojo)
    {
        return "Rojo";
    }
    else if (this->color == ColorEnum::Azul)
    {
        return "Azul";
    }
    else if (this->color == ColorEnum::Verde)
    {
        return "Verde";
    }
    else if (this->color == ColorEnum::Amarillo)
    {
        return "Amarillo";
    }
    else if (this->color == ColorEnum::Negro)
    {
        return "Negro";
    }
    else if (this->color == ColorEnum::Rosa)
    {
        return "Rosa";
    }
    else if (this->color == ColorEnum::Turquesa)
    {
        return "Turquesa";
    }
    else if (this->color == ColorEnum::Naranja)
    {
        return "Naranja";
    }
    else if (this->color == ColorEnum::Violeta)
    {
        return "Violeta";
    }
    else if (this->color == ColorEnum::Multicolor)
    {
        return "Multicolor";
    }

    return "Desconocido";
    
}