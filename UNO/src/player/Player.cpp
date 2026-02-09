#include "../include/player/Player.h"

Player::Player(std::string name, int id)
{
    this->name = name;
    this->id = id;
}
Player :: Player(){}
Player::~Player() {}

std::string Player::getName()
{
    return this->name;
}
void Player::setName(std::string name)
{
    this->name = name;
}

int Player::getId()
{
    return this->id;
}
void Player::setId(int id)
{
    this->id = id;
}