#include "../include/player/PlayerView.h"
#include "../include/player/Player.h"
#include "../include/linked-list/LinkedList.h"
#include "../include/card/Card.h"
#include "../include/side/Side.h"
#include "../include/action/Action.h"
#include "../include/action/Numero.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

PlayerView::PlayerView(Player *player)
{
    this->player = player;
}

PlayerView::~PlayerView() {}

void PlayerView::viewCards(bool isLightSide)
{
    cout << "\033[1;31m";
    cout << "Jugador en turno: " << player->getName() << endl;
    if (isLightSide)
    {
        cout << "|-----------------------------------------------------------|" << endl;
        cout << "|            CARTAS EN MANO 'LADO CLARO'                    |" << endl;
        cout << "|-----------------------------------------------------------|" << endl;
        cout << "|  No.    ACCION          COLOR        VALOR(NUMERO)        |" << endl;
        cout << "|-----------------------------------------------------------|" << endl;
    }

    else
    {
        cout << "|-----------------------------------------------------------|" << endl;
        cout << "|            CARTAS EN MANO 'LADO OSCURO'                   |" << endl;
        cout << "|-----------------------------------------------------------|" << endl;
        cout << "|  No.    ACCION          COLOR        VALOR(NUMERO)        |" << endl;
        cout << "|-----------------------------------------------------------|" << endl;
    }

    for (int i = 0; i < player->getCardsList()->getSize(); i++)
    {
        Card *card;
        string accion;
        string color;
        string valorNumerico = "-";
        if (isLightSide)
        {
            card = player->getCardsList()->getElement(i);
            accion = card->getSideLight()->getAction()->getNombre();
            color = card->getSideLight()->getColor();

            Numero *numero = dynamic_cast<Numero *>(card->getSideLight()->getAction());
            if (numero != nullptr)
            {
                valorNumerico = std::to_string(numero->getNumero());
            }
        }
        else
        {
            card = player->getCardsList()->getElement(i);
            accion = card->getSideDark()->getAction()->getNombre();
            color = card->getSideDark()->getColor();

            Numero *numero = dynamic_cast<Numero *>(card->getSideDark()->getAction());
            if (numero != nullptr)
            {
                valorNumerico = std::to_string(numero->getNumero());
            }
        }

        cout << "| "
             << setw(6) << left << (i + 1)
             << "  "
             << setw(15) << left << accion
             << " "
             << setw(17) << left << color
             << " "
             << setw(15) << left << valorNumerico
             << " |"
             << endl;
    }

    cout << "|-----------------------------------------------------------|" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    // fin del color
    cout << "\033[0m";
}

int PlayerView::actionsMenu(bool hasValidCards)
{
    int opcion;

    if (hasValidCards)
    {
        while (true)
        {
            cout << "ACCIONES" << endl;
            cout << "1. Poner Carta" << endl;
            cout << "2. Robar carta" << endl;
            cout << "Seleccione una opcion: ";

            if (!(cin >> opcion))
            {
                // Si escriben algo diferente de numeros
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida, Solo numeros.\n\n";
                continue;
            }

            if (opcion < 1 || opcion > 2)
            {
                cout << "Opcion fuera de rango. Intente de nuevo.\n\n";
                continue;
            }

            break;
        }
    }
    else
    {

        cout << "No tienes cartas Jugables, debes robar 1 carta";
        cout << "Presiona enter para Robar" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        // se agrega automaticamete el numero 2 que significa el robo de una carta de la pila
        opcion = 2;
    }
    return opcion;
}

int PlayerView::selectCard()
{
    int opcion;
    int cantidadCartas = player->getCardsList()->getSize();
    while (true)
    {
        cout << "Elige el No. de la carta (1 - " << cantidadCartas << "): ";

        if (!(cin >> opcion))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Solo numeros" << endl;
            continue;
        }

        if (opcion < 1 || opcion > cantidadCartas)
        {
            cout << "Numero fuera de rango" << endl;
            continue;
        }

        break;
    }

    return opcion - 1;
}

#include <limits>

bool PlayerView::askContinueDraw()
{
    int opcion;

    while (true)
    {
        cout << "\n¿Deseas robar otra carta?\n";
        cout << "1. Si\n";
        cout << "2. No\n";
        cout << "Selecciona una opcion: ";

        if (!(cin >> opcion))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Solo numeros.\n";
            continue;
        }

        if (opcion == 1)
        {
            return true;
        }

        if (opcion == 2)
        {
            return false;
        }

        cout << "Opcion fuera de rango, intenta de nuevo" << endl;
    }
}

void PlayerView::alert()
{
    std::cout << "\033[1;31m"<< "La carta que elegiste no es valida, vuelve a intentarlo" <<"\033[0m"<< endl;
}