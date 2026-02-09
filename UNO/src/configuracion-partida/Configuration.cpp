#include "../include/configuracion-partida/Configuration.h"

Configuration::Configuration(bool accumulation, bool challenge,
                             bool robberyMode, bool screamOne, bool winBlack,
                             bool isFlip, int numberPlayers)
{
    this->accumulation = accumulation;
    this->challenge = challenge;
    this->robberyMode = robberyMode;
    this->screamOne = screamOne;
    this->winBlack = winBlack;
    this->flip = isFlip;
    this->numberPlayers = numberPlayers;
}

Configuration::~Configuration() {}

bool Configuration ::isAccumulation()
{
    return this->accumulation;
}

bool Configuration ::isChallenge()
{
    return this->challenge;
}
bool Configuration ::isRObberyMode()
{
    return this->robberyMode;
}
bool Configuration ::isScreamOne()
{
    return this->screamOne;
}
bool Configuration ::isWinBlack()
{
    return this->winBlack;
}
bool Configuration ::isFlip()
{
    return this->flip;
}

int Configuration::getNumberPlayers()
{
    return this->numberPlayers;
}