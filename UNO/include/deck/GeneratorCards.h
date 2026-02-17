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
#include "../include/deck/GeneratorDarkSide.h"
class GeneratorCards
{
private:
    Configuration *config;
    GeneratorAction *generator;
    GeneratorDarkSide* generatorDarkSide;
    int cantidadCartas;
    int ultimaPosicionOcupada;
    int* playDirection;
    int* turnCout;
    bool* esLadoClaro;
    int numberPlayers;

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
    void generateLightSideCard(Card** cards);
    void generateCardNumeric(ColorEnum color , Card** cards);

    void generateAllCardsWithColor( Card** cards);

    void generateSpecialCards(ColorEnum color, bool esClaro , Card** cards);
    void createWildCards(bool esClaro , Card** cards);
    void generateFlipCards(ColorEnum color,Card** cards);

public:
    GeneratorCards(Configuration* config,int* playDirection, int* turnCout, bool* esLadoClaro, int numberPlayers);
    ~GeneratorCards();
    Card** generateCards();
    int getNumberCards();
};
#endif