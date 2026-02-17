#include "../include/action/Action.h"
class Player;

void Action::setPlayer(Player *player)
{
    this->player = player;
}

std::string Action::getNombre(){
    return this->nombre;
}

void Action::setEsLadoClaro(bool esLadoClaro){
    this->esLadoClaro=esLadoClaro;
}