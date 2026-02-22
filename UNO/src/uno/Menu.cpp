#include "../include/uno/Menu.h"
#include "../include/configuracion-partida/Configuration.h"
#include "../include/circular-list/CircularList.h"
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

void Menu ::mostarConfiguracion(CircularList *list, Configuration *config, int numberDecks, int numberCards)
{
    string acumulacion = "NO";
    string retoMasCuatro = "NO";
    string modoRobo = "NO";
    string gritoUno = "NO";
    string ganarConNegra = "NO";
    string expansionFlip = "NO";
    if (config->isAccumulation())
    {
        acumulacion = "SI";
    }
    if (config->isChallenge())
    {
        retoMasCuatro = "SI";
    }
    if (config->isScreamOne())
    {
        gritoUno = "SI";
    }
    if (config->isWinBlack())
    {
        ganarConNegra = "SI";
    }
    if (config->isFlip())
    {
        expansionFlip = "SI";
    }
    cout << "\033[1;40;31m";
    cout << "   |----------------------------|" << endl;
    cout << "   |  RESUMEN DE CONFIGURACION  |" << endl;
    cout << "   |----------------------------|" << endl;
    cout << "\033[0m";
    cout << endl;
    cout << endl;
    cout << "       ACUMULACION: " << acumulacion << endl;
    cout << "       RETO DE +4: " << retoMasCuatro << endl;
    cout << "       MODO ROBO: " << modoRobo << endl;
    cout << "       GRITO DE !UNO¡: " << gritoUno << endl;
    cout << "       GANAR CON NEGRA: " << ganarConNegra << endl;
    cout << "       EXPANSION DE FLIP: " << expansionFlip << endl;
    cout << "       NUMERO DE DECKS: " << numberDecks << " decks." << endl;
    cout << "       NUMERO DE CARTAS: " << numberCards + 1 << " cartas." << endl;
    cout << endl;
    cout << endl;
    cout << "       |-----JUGADORES---|" << endl;
    cout << endl;
    for (int i = 0; i < list->getSize(); i++)
    {
        cout << "       " << (i + 1) << ". " << list->getElement(i)->getName() << endl;
    }

    cout << "       Presiona ENTER para iniciar partida...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string temp;
    getline(cin, temp);
}