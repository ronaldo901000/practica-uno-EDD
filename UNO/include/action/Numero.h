#ifndef NUMERO_H
#define NUMERO_H
#include "Action.h"

class Numero : public Action
{
private:
    int numero;

public:
    Numero(int numero);
    ~Numero();
    void realizarAccion() override;
};
#endif