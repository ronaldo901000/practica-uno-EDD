#include "../include/deck/GeneratorCards.h"
#include "string"
#include <iostream>

GeneratorCards ::GeneratorCards(Configuration *config)
{
    this->config = config;
    this->ultimaPosicionOcupada = 0;
    this->cantidadCartas = 0;
    this->generator = new GeneratorAction();
}

GeneratorCards::~GeneratorCards() {}

Card **GeneratorCards ::getCards()
{
    return this->cards;
}

// metodo que se encarga de la creacion de todas las cartas del mazo
void GeneratorCards ::generateCards()
{

    calculateNumberCards();
    // se generan el lado claro de las cartas

    generateLightSideCard();

    // si es flip se genera el lado oscuro
    if (config->isFlip())
    {
    }
}

// metodo que calcula el total de cartas que tendrá el mazo
void GeneratorCards ::calculateNumberCards()
{
    cantidadCartas = CANTIDAD_NORMAL;
    if (this->config->isFlip())
    {
        cantidadCartas = CANTIDAD_FLIP;
    }
    // se define el tamaño del arreglo de cartas
    cards = new Card *[cantidadCartas];
}

// metodo que se encarga de generar el lado claro de una carta
void GeneratorCards::generateLightSideCard()
{
    generateAllCardsWithColor();
    createWildCards(true);
    // si es una partida flip, se agregan 8 cartas mas,
    if (config->isFlip())
    {
    }
}

// metod que genera todas las cartas numericas y cartas especiales que tiene un color especifico
void GeneratorCards ::generateAllCardsWithColor()
{
    for (int i = 0; i < CANTIDAD_COLORES_POR_LADO; i++)
    {
        if (i == AMARILLO)
        {
            generateCardNumeric(ColorEnum::Amarillo);
            generateSpecialCards(ColorEnum::Amarillo, true);
            if (config->isFlip())
            {
                generateFlipCards(ColorEnum::Amarillo);
            }
        }

        else if (i == ROJO)
        {
            generateCardNumeric(ColorEnum::Rojo);
            generateSpecialCards(ColorEnum::Rojo, true);
            if (config->isFlip())
            {
                generateFlipCards(ColorEnum::Rojo);
            }
        }
        else if (i == AZUL)
        {
            generateCardNumeric(ColorEnum::Azul);
            generateSpecialCards(ColorEnum::Azul, true);
            if (config->isFlip())
            {
                generateFlipCards(ColorEnum::Azul);
            }
        }
        else if (i == VERDE)
        {
            generateCardNumeric(ColorEnum::Verde);
            generateSpecialCards(ColorEnum::Verde, true);
            if (config->isFlip())
            {
                generateFlipCards(ColorEnum::Verde);
            }
        }
    }
}

/*
Metodo que se encarga de construir las cartas numericas
    1. Se genera una accion
    2. Se genera un lado
    3. Se construye la carta
    */
void GeneratorCards::generateCardNumeric(ColorEnum color)
{
    // Carta 0 (solo una)
    Numero *action = generator->generateNumeric(0);
    SideLight *side = new SideLight(action, color);
    cards[this->ultimaPosicionOcupada] = new Card(side);

    // se genera su lado oscuro si es flip
    if (config->isFlip())
    {
        // pendiente de implementacion
    }
    ultimaPosicionOcupada++;

    // Cartas 1 a 9 (dos de cada una)
    for (int num = 1; num <= 9; num++)
    {
        for (int k = 0; k < CANT_MISMO_NUMERO_POR_COLOR; k++)
        {
            Numero *action = generator->generateNumeric(num);
            SideLight *side = new SideLight(action, color);
            cards[ultimaPosicionOcupada] = new Card(side);
            if (config->isFlip())
            {
                // pendiente de implementacion
            }
            (ultimaPosicionOcupada)++;
        }
    }
}

void GeneratorCards ::generateSpecialCards(ColorEnum color, bool esClaro)
{
    for (int i = 0; i < CANT_CARTAS_ESPECIALES; i++)
    {
        for (int j = 0; j < CANT_MISMA_CARTA_ESPECIAL_POR_COLOR; j++)
        {
            if (i == 0)
            {
                Salto *action = new Salto(esClaro);
                SideLight *side = new SideLight(action, color);
                cards[ultimaPosicionOcupada] = new Card(side);
                (ultimaPosicionOcupada)++;
            }
            else if (i == 1)
            {
                Reverse *action = new Reverse();
                SideLight *side = new SideLight(action, color);
                cards[ultimaPosicionOcupada] = new Card(side);
                (ultimaPosicionOcupada)++;
            }
            else if (i == 2)
            {

                if (!config->isFlip())
                {
                    RoboMasDos *action = new RoboMasDos();
                    SideLight *side = new SideLight(action, color);
                    cards[ultimaPosicionOcupada] = new Card(side);
                }
                else
                {
                    RoboMasUnoFlip *action = new RoboMasUnoFlip();
                    SideLight *side = new SideLight(action, color);
                    cards[ultimaPosicionOcupada] = new Card(side);
                }
                (ultimaPosicionOcupada)++;
            }
        }
    }
}

void GeneratorCards::createWildCards(bool isLight)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
            {
                Color *action = new Color(isLight);
                SideLight *side = new SideLight(action, ColorEnum::Multicolor);
                cards[ultimaPosicionOcupada] = new Card(side);
            }
            else if (i == 1)
            {
                if (!config->isFlip())
                {
                    RoboMasCuatro *action = new RoboMasCuatro();
                    SideLight *side = new SideLight(action, ColorEnum::Multicolor);
                    cards[ultimaPosicionOcupada] = new Card(side);
                }
                else
                {
                    RoboMasDosFlip *action = new RoboMasDosFlip();
                    SideLight *side = new SideLight(action, ColorEnum::Multicolor);
                    cards[ultimaPosicionOcupada] = new Card(side);
                }
            }
            ultimaPosicionOcupada++;
        }
}

void GeneratorCards ::generateFlipCards(ColorEnum color)
{
    for (int i = 0; i < CANT_MISMA_CARTA_ESPECIAL_POR_COLOR; i++)
    {
        Flip *action = new Flip();
        SideLight *side = new SideLight(action, color);
        cards[ultimaPosicionOcupada] = new Card(side);
        ultimaPosicionOcupada++;
    }
}

int GeneratorCards::getNumberCards()
{
    return this->cantidadCartas;
}