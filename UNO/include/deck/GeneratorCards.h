#ifndef GENERATOR_CARDS_H
#define GENERATOR_CARDS_H
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
#include "../include/action/Flip.h"
#include "../include/enum/ColorEnum.h"
#include "GeneratorAction.h"
#include "../include/side/SideLight.h"
#include "../include/side/SideDark.h"
class GeneratorCards
{
private:
    Card **cards;
    Configuration *config;
    GeneratorAction *generator;
    int cantidadCartas;
    int ultimaPosicionOcupada;

    const int CANTIDAD_FLIP = 116;
    const int CANTIDAD_NORMAL = 108;
    const int CANTIDAD_COLORES_POR_LADO = 4;
    const int AMARILLO = 0;
    const int ROJO = 1;
    const int AZUL = 2;
    const int VERDE = 3;
    const int CANT_MISMO_NUMERO_POR_COLOR = 2;
    const int CANT_CARTAS_ESPECIALES = 3;
    const int CANT_MISMA_CARTA_ESPECIAL_POR_COLOR = 2;

    void calculateNumberCards();
    void generateLightSideCard();
    void generateCardNumeric(ColorEnum color);

    void generateAllCardsWithColor();

    void generateSpecialCards(ColorEnum color, bool esClaro);
    void createWildCards(bool esClaro);
    void generateFlipCards(ColorEnum color);

public:
    GeneratorCards(Configuration* config);
    ~GeneratorCards();
    void generateCards();
    Card **getCards();
    int getNumberCards();
};
#endif