#ifndef GENERATOR_aCTION_H
#define GENERATOR_aCTION_H
#include "../include/action/Numero.h"

class GeneratorAction{
    private:

    public:
    GeneratorAction();
    ~GeneratorAction();
    Numero* generateNumeric(int number);
};

#endif