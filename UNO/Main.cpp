#include <iostream>
#include "string"
#include "../include/uno/Uno.h"

int main()
{
    while (true)
    {
        Uno *uno = new Uno();
        uno->start();
        delete uno;
    }
    return 0;
}