#include "../include/action/Color.h"
using namespace std;
#include <iostream>

Color::Color(bool esLadoClaro)
{
    this->nombre = "COMODIN COLOR";
    this->esLadoClaro = esLadoClaro;
}
void Color::realizarAccion()
{
    cout << this->player->getName() << " Lanza una carta de color" << endl;
}