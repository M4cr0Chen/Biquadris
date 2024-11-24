#include "player.h"
#include "level.h"
#include "level0.h"

// Player::Player() : levelNum{0} {}
Player::Player(bool isPlayerOne, std::string s1, std::string s2) : level{new Level0{isPlayerOne, s1, s2}}, levelNum{0}, s1{s1}, s2{s2} {}

void Player::createBlock()
{
    std::unique_ptr<Block> block = level->generateBlock();
    board.addBlock(std::move(block));
}

int Player::dropBlock()
{
    int numLine, score;
    score = board.dropBlock(&numLine);
}

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
