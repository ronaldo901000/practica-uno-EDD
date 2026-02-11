#include "../include/deck/GeneratorAction.h"

GeneratorAction::GeneratorAction() {}
GeneratorAction::~GeneratorAction() {}

Numero *GeneratorAction ::generateNumeric(int number)
{
    Numero *numero = new Numero(number);
    return numero;
}
