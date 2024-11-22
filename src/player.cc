#include "player.h"
#include "level.h"
#include "level0.h"

//Player::Player() : level{new Level0{}}, levelNum{0} {}
Player::Player() : levelNum{0} {}

void Player::setLevel(int levelNum)
{
    levelNum = levelNum;
}

int Player::getLevel()
{
    return levelNum;
}

Score &Player::getScore()
{
    return score;
}

Board &Player::getBoard()
{
    return board;
}
