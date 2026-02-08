#ifndef PLAYER_H
#define PLAYER_H
#include "string"
class Player
{
private:
    std::string name;
    int id;

public:
    Player (std::string name, int id);
    ~Player();
    std::string getName();
    void setName(std::string name);

    int getId();
    void setId(int id);
};
#endif