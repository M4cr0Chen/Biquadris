#include "player.h"
#include "level.h"
#include "level0.h"

// Player::Player() : levelNum{0} {}
Player::Player() : level{new Level0{}}, levelNum{0} {}

void Player::setLevel(int levelNum)
{
    levelNum = levelNum;
    switch (levelNum)
    {
    case 0:
        level = std::make_unique<Level0>();
        break;
        // case 1:
        //     level = std::make_unique<Level1>();
    }
}

int Player::getIntLevel()
{
    return levelNum;
}

Level *Player::getPtrLevel()
{
    return level.get();
}

Score &Player::getScore()
{
    return score;
}

Board &Player::getBoard()
{
    return board;
}
