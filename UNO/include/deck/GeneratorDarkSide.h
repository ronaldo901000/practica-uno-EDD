#ifndef GENERATOR_DARK_SIDE_H
#define GENERATOR_DARK_SIDE_H
#include "../include/card/Card.h"
#include "../include/enum/ColorEnum.h"
#include "../include/action/Numero.h"
#include "../include/action/Salto.h"
#include "../include/action/Reverse.h"
#include "../include/action/robo/RoboMasDos.h"
#include "../include/action/robo/RoboMasCuatro.h"
#include "../include/action/robo/RoboMasUnoFlip.h"
#include "../include/action/robo/RoboMasCuatro.h"
#include "../include/action/robo/RoboMasDosFlip.h"
#include "../include/action/robo/RoboMasTresFlip.h"
#include "../include/action/robo/RoboMasSeisFlip.h"
#include "../include/action/Color.h"
#include "../include/action/Flip.h"
#include "../include/side/SideDark.h"
#include <random>

class GeneratorDarkSide
{
private:
    Card **cards;
    int numberCards;
    int* playDirection;
    int* turnCount;
     bool* isLightSide;

    const int ROSA = 0;
    const int TURQUEZA = 1;
    const int NARANJA = 2;
    const int VIOLETA = 3;
    const int CANTIDAD_COLORES_POR_LADO = 4;
    const int CANT_MISMO_NUMERO_POR_COLOR = 2;
    const int CANT_CARTAS_ESPECIALES = 3;
    const int CANT_MISMA_CARTA_ESPECIAL_POR_COLOR = 2;
    int numberPlayers;
    Numero *generateNumeric(int number);
    void generateAllCardsWithColor();
    void generateFlipCards(ColorEnum color);
    void createWildCards();
    void generateCardNumeric(ColorEnum color);
    int generateIndexRandom(int maxIndex);
    void generateSpecialCards(ColorEnum color, bool esClaro);

public:
    GeneratorDarkSide(Card **cards, int numberCards, int* playDirection, int* turnCount,  bool *isLightSide, int numberPlayers);
    ~GeneratorDarkSide();
    Card **getCards();
    void createDarkSide();
};
#endif
