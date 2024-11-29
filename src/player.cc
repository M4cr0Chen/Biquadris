#include "player.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <iostream>


Player::Player(bool isPlayerOne, std::string s1, std::string s2, int seed, int startLevel) : 
    seed{seed}, 
    level{nullptr}, 
    levelNum{0}, 
    s1{s1}, s2{s2}, 
    isPlayerOne{isPlayerOne},
    startLevel{startLevel}
    {}

void Player::createBlock()
{
    std::cout << "levelnum: " << levelNum << std::endl;
    std::unique_ptr<Block> block = level->generateBlock();
    board.addBlock(std::move(block));
}

int Player::dropBlock()
{
    int numLine = 0;
    int dropScore = 0;
    int lineScore = 0;
    std::cout << "current block is null: " << (getBoard().getCurrentBlock() == nullptr) << std::endl;
    if (getBoard().getCurrentBlock() != nullptr)
    {
        board.dropBlock(&numLine, &dropScore);

        if (numLine > 0)
        {
            lineScore = std::pow(numLine + levelNum, 2);
        }

        score.addToCurrentScore(dropScore);
        std::cout << "dropscore: " << dropScore << ", " << "linescore: " << lineScore << std::endl;
        score.addToCurrentScore(lineScore);

        // numLine = 0;
        dropScore = 0;
        lineScore = 0;
    }

// check star block

    if (getBoard().getTempBlock() != nullptr) {
        board.dropStarBlock(&numLine, &dropScore);
        if (numLine > 0)
        {
            lineScore = std::pow(numLine + levelNum, 2);
        }

        score.addToCurrentScore(dropScore);
        std::cout << "dropSTARscore: " << dropScore << ", " << "linescore: " << lineScore << std::endl;
        score.addToCurrentScore(lineScore);
    }


    return numLine;
}

void Player::setLevel(int levelNum)
{
    this->levelNum = levelNum;
    switch (levelNum)
    {
    case 0:
        level = std::make_unique<Level0>(isPlayerOne, s1, s2);
        board.setLevel(0);
        break;
    case 1:
        level = std::make_unique<Level1>();
        level->setSeed(seed);
        board.setLevel(1);
        break;
    case 2:
        level = std::make_unique<Level2>();
        level->setSeed(seed);
        board.setLevel(2);
        break;
    case 3:
        level = std::make_unique<Level3>();
        level->setSeed(seed);
        board.setLevel(3);
        break;
    case 4:
        level = std::make_unique<Level4>();
        level->setSeed(seed);
        board.setLevel(4);
        break;
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

int Player::getSeed()
{
    return seed;
}

void Player::setSeed(int seed)
{
    this->seed = seed;
}

Score &Player::getScore()
{
    return score;
}

Board &Player::getBoard()
{
    return board;
}

void Player::replaceUndroppedBlock(char blockType)
{
    std::cout << "levelnum: " << levelNum << std::endl;
    std::unique_ptr<Block> block = level->giveMeABlock(blockType, levelNum);
    board.changeBlock(std::move(block));
}

void Player::insertStarBlock() {
    std::unique_ptr<Block> block = level->giveMeABlock('*', levelNum);
    board.insertBlock(std::move(block));
}

void Player::restartPlayer()
{
    levelNum = startLevel;
    board = Board();
    score.resetCurrentScore();
    level = std::make_unique<Level0>(isPlayerOne, s1, s2);
}

bool Player::shouldDroplvl4Block()
{
    return levelNum == 4 && (board.getCount() % 5 == 0 && board.getCount() != 0);
}

void Player::decideSwitchSpecialAction()
{
    if (board.getIsBlind()) {
        board.setBoardBlind();
    }
    if (board.getIsHeavy()) {
        board.setBoardHeavy();
    }
}
