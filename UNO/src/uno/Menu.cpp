#include "../include/uno/Menu.h"
using namespace std;
Menu::Menu() {}

Menu::~Menu() {}

void Menu::getLogoUno()
{
    // fondo negro + letras rojas
    cout << "\033[1;40;31m";

    cout << endl;
    cout << "|--------------------------|" << endl;
    cout << "|        BIENVENIDO        |" << endl;
    cout << "|--------------------------|" << endl;
    cout << endl;
    cout << "|--------------------------|" << endl;
    cout << "|                          |" << endl;
    cout << "|                          |" << endl;
    cout << "|                          |" << endl;
    cout << "|    U   U  N   N   OOO    |" << endl;
    cout << "|    U   U  NN  N  O   O   |" << endl;
    cout << "|    U   U  N N N  O   O   |" << endl;
    cout << "|    U   U  N  NN  O   O   |" << endl;
    cout << "|     UUU   N   N   OOO    |" << endl;
    cout << "|                          |" << endl;
    cout << "|                          |" << endl;
    cout << "|                          |" << endl;
    cout << "|--------------------------|" << endl;

    // reset colores ANTES del texto normal
    cout << "\033[0m";

    cout << "A continuacion la configuracion de la partida" << endl;
    cout << "Presiona ENTER para continuar...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}