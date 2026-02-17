#include "../include/action/robo/RoboMulticolor.h"
#include "limits"
#include "../include/side/Side.h"

RoboMulticolor::RoboMulticolor()
{

    colorsLightSide[0] = "Rojo";
    colorsLightSide[1] = "Azul";
    colorsLightSide[2] = "Verde";
    colorsLightSide[3] = "Amarillo";

    colorsDarkSide[0] = "Rosa";
    colorsDarkSide[1] = "Turquesa";
    colorsDarkSide[2] = "Naranja";
    colorsDarkSide[3] = "Violeta";
}

void RoboMulticolor ::realizarAccion()
{
    cout << "Elige un color para esta carta: " << endl;
    if (esLadoClaro)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << (i + 1) << ". " << colorsLightSide[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            cout << (i + 1) << ". " << colorsDarkSide[i] << endl;
        }
    }
    int opcion;
    while (true)
    {
        if (!(cin >> opcion))
        {
            // Si escriben algo diferente de numeros
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida, Solo numeros\n\n";
            continue;
        }

        if (opcion < 1 || opcion > 4)
        {
            cout << "Opcion fuera de rango. Intenta de nuevo.\n\n";
            continue;
        }

        break;
    }
    std::string selectedColor;
    if (this->esLadoClaro)
    {
        selectedColor = colorsLightSide[opcion - 1];
    }
    else
    {
        selectedColor = colorsDarkSide[opcion - 1];
    }
    this->side->setTemporalColor(selectedColor);
}

void RoboMulticolor::setSide(Side* side){
    this->side=side;
}