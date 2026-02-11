#ifndef DECK_H
#define DECK_H
#include "../include/linked-list/LinkedList.h"
#include "../include/configuracion-partida/Configuration.h"
#include "../include/action/Numero.h"
#include "../include/action/Salto.h"
#include "../include/action/Reverse.h"
#include "../include/action/robo/RoboMasDos.h"
#include "../include/action/robo/RoboMasCuatro.h"
#include "../include/action/robo/RoboMasUnoFlip.h"
#include "../include/action/robo/RoboMasCuatro.h"
#include "../include/action/robo/RoboMasDosFlip.h"
#include "../include/action/Color.h"
#include "../include/enum/ColorEnum.h"
#include "GeneratorAction.h"
#include "../include/side/SideLight.h"
#include "../include/side/SideDark.h"

class Deck
{
private:
    Card **cards;

public:
    Deck(Card **cards);
    ~Deck();
    Card **getCards();
};

#endif