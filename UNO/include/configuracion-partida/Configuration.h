#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class Configuration
{
private:
    bool accumulation;
    bool challenge;
    bool robberyMode;
    bool screamOne;
    bool winBlack;
    bool flip;
    int numberPlayers;

public:
    Configuration(bool accumulation, bool challenge,
                  bool robberyMode, bool screamOne, bool winBlack,
                  bool isFlip, int numberPlayers);
    ~Configuration();

    bool isAccumulation();
    bool isChallenge();
    bool isRObberyMode();
    bool isScreamOne();
    bool isWinBlack();
    bool isFlip();
    int getNumberPlayers();

    
};
#endif