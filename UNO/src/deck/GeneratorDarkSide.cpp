#include "../include/deck/GeneratorDarkSide.h"

GeneratorDarkSide::GeneratorDarkSide(
    Card **cards, 
    int numberCards, 
    int* playDirection, 
    int* turnCount,
    bool* isLightSide,
    int numberPlayers)
{
    this->cards = cards;
    this->numberCards = numberCards;
    this->playDirection=playDirection;
    this->turnCount=turnCount;
    this->isLightSide=isLightSide;
    this->numberPlayers=numberPlayers;
}

GeneratorDarkSide::~GeneratorDarkSide()
{
}

Card **GeneratorDarkSide::getCards()
{
    return this->cards;
}

// metodo general, se encarga de pedir a los metodos auxiliares que generen las cartas
void GeneratorDarkSide ::createDarkSide()
{
    generateAllCardsWithColor();
    createWildCards();
}

void GeneratorDarkSide ::generateAllCardsWithColor()
{
    for (int i = 0; i < CANTIDAD_COLORES_POR_LADO; i++)
    {
        if (i == ROSA)
        {
            generateCardNumeric(ColorEnum::Rosa);
            generateSpecialCards(ColorEnum::Rosa, false);
            generateFlipCards(ColorEnum::Rosa);
        }

        else if (i == TURQUEZA)
        {
            generateCardNumeric(ColorEnum::Turquesa);
            generateSpecialCards(ColorEnum::Turquesa, false);
            generateFlipCards(ColorEnum::Turquesa);
        }
        else if (i == NARANJA)
        {
            generateCardNumeric(ColorEnum::Naranja);
            generateSpecialCards(ColorEnum::Naranja, false);
            generateFlipCards(ColorEnum::Naranja);
        }
        else if (i == VIOLETA)
        {
            generateCardNumeric(ColorEnum::Violeta);
            generateSpecialCards(ColorEnum::Violeta, false);
            generateFlipCards(ColorEnum::Violeta);
        }
    }
}

void GeneratorDarkSide::generateCardNumeric(ColorEnum color)
{
    // Carta 0 (solo una)
    Numero *action = generateNumeric(0);
    SideDark *side = new SideDark(action, color);
    int randomIndex = generateIndexRandom(this->numberCards);
    cards[randomIndex]->setSideDark(side);

    // Cartas 1 a 9 (dos de cada una)
    for (int num = 1; num <= 9; num++)
    {
        for (int k = 0; k < CANT_MISMO_NUMERO_POR_COLOR; k++)
        {
            Numero *action = generateNumeric(num);
            SideDark *side = new SideDark(action, color);
            int randomIndex = generateIndexRandom(this->numberCards);
            cards[randomIndex]->setSideDark(side);
        }
    }
}

void GeneratorDarkSide ::generateFlipCards(ColorEnum color)
{
    for (int i = 0; i < CANT_MISMA_CARTA_ESPECIAL_POR_COLOR; i++)
    {
        int randomIndex = generateIndexRandom(this->numberCards);
        Flip *action = new Flip(isLightSide);
        SideDark *side = new SideDark(action, color);
        cards[randomIndex]->setSideDark(side);
    }
}
void GeneratorDarkSide ::generateSpecialCards(ColorEnum color, bool esClaro)
{
    for (int i = 0; i < CANT_CARTAS_ESPECIALES; i++)
    {
        for (int j = 0; j < CANT_MISMA_CARTA_ESPECIAL_POR_COLOR; j++)
        {
            int randomIndex = generateIndexRandom(this->numberCards);
            if (i == 0)
            {
                Salto *action = new Salto(esClaro, turnCount, playDirection);
                action->setNumeroJugadores(this->numberPlayers);
                SideDark *side = new SideDark(action, color);
                cards[randomIndex]->setSideDark(side);
            }
            else if (i == 1)
            {
                Reverse *action = new Reverse(playDirection);
                SideDark *side = new SideDark(action, color);
                cards[randomIndex]->setSideDark(side);
            }
            else if (i == 2)
            {
                RoboMasTresFlip *action = new RoboMasTresFlip();
                SideDark *side = new SideDark(action, color);
                cards[randomIndex]->setSideDark(side);
            }
        }
    }
}

void GeneratorDarkSide::createWildCards()
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
        {
            int randomIndex = generateIndexRandom(this->numberCards);

            if (i == 0)
            {
                Color *action = new Color(false);
                SideDark *side = new SideDark(action, ColorEnum::Multicolor);
                cards[randomIndex]->setSideDark(side);
                action->setSide(side);
            }
            else if (i == 1)
            {

                RoboMasSeisFlip *action = new RoboMasSeisFlip();
                SideDark *side = new SideDark(action, ColorEnum::Multicolor);
                action->setSide(side);
                action->setEsLadoClaro(isLightSide);
                cards[randomIndex]->setSideDark(side);
            }
        }
}

Numero *GeneratorDarkSide ::generateNumeric(int number)
{
    Numero *numero = new Numero(number);
    return numero;
}

int GeneratorDarkSide::generateIndexRandom(int maxIndex)
{
    bool correct = false;
    int index = 0;
    while (!correct)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, maxIndex - 1);
        index = dis(gen);
        if (cards[index]->getSideDark() == nullptr)
        {
            correct = true;
        }
    }
    return index;
}