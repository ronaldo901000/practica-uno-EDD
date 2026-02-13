#include "../include/uno/Uno.h"
#include <iostream>
#include <limits>
#include <stdlib.h>
#include "../include/circular-list/CircularList.h"
#include "../include/deck/GeneratorCards.h"
using namespace std;

Uno::~Uno() {}
void Uno::start()
{
    // muestra el logo de UNO
    Menu menu = Menu();
    menu.getLogoUno();

    // se crea la configuracion de juego
    Configuration *config = createConfig();

    // se crean los jugadores
    CreatorPlayers *creator = new CreatorPlayers(config->getNumberPlayers());
    CircularList *list = creator->createPlayers();

    system("clear");
    cout << "¡Jugadores registrados exitosamente!" << endl;

    // se crean los mazos necesario para la partida
    GeneratorStack *generator = new GeneratorStack(config, list->getSize());
    Stack *stack = generator->generate();

    // inicia la partida
    Partida *partida = new Partida(list, stack, config);
    partida->start();
}

Configuration *Uno::createConfig()
{
    bool accumulation = false;
    bool challenge = false;
    bool robberyMode = false;
    bool screamOne = false;
    bool winBlack = false;
    bool flip = false;
    int numberPlayers;
    cout << "Configuración de partida" << endl;
    cout << endl;

    cout << "Acumulacion (Stacking) ?" << endl;
    getResponse(&accumulation);
    cout << endl;

    cout << "Reto del +4 ?" << endl;
    getResponse(&challenge);
    cout << endl;

    cout << "Modo Robo ?" << endl;
    getResponse(&robberyMode);
    cout << endl;

    cout << "Grito de ¡UNO! ?" << endl;
    getResponse(&screamOne);
    cout << endl;

    cout << "Ganar con Negra ?" << endl;
    getResponse(&winBlack);
    cout << endl;

    cout << "Jugar Con expansion de FLIP??" << endl;
    getResponse(&flip);
    cout << endl;

    cout << "Numero de jugadores (Minimo 2): " << endl;
    getNumerPlayers(&numberPlayers);

    Configuration *config = new Configuration(
        accumulation,
        challenge,
        robberyMode,
        screamOne,
        winBlack,
        flip,
        numberPlayers);
    system("clear");
    cout << "Configuracion creada exitosamente" << endl;
    return config;
}

void Uno::getResponse(bool *response)
{
    int value;
    cout << "1)SI      2)NO" << endl;
    do
    {
        cout << "-->";
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingresa un numero" << endl;
            continue;
        }
        if (value != SI && value != NO)
        {
            cout << "Por favor Selecciona  1)SI      2)NO" << endl;
        }
    } while (value != SI && value != NO);
    if (value == SI)
    {
        *response = true;
    }
}
void Uno::getNumerPlayers(int *numberPlayers)
{
    do
    {
        cout << "-->";
        cin >> *numberPlayers;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingresa un numero" << endl;
            continue;
        }
        if (*numberPlayers < MIN_PLAYERS)
        {
            cout << "El Minimo permitido son 2 jugadores, vuelve a intentarlo: " << endl;
        }
    } while (*numberPlayers < MIN_PLAYERS);
}
