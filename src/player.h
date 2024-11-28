#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "score.h"
#include "level.h"
#include <string>

class Level;

class Player
{
private:
    std::unique_ptr<Level> level;
    std::string s1;
    std::string s2;
    Board board;
    int levelNum;
    Score score;
    bool isPlayerOne;
    int seed;

    int startLevel;

public:
    Player(bool isPlayerOne, std::string s1, std::string s2, int seed, int startLevel);
    void createBlock();
    int dropBlock();
    void setLevel(int levelNum);
    int getIntLevel();
    int getSeed();
    void setSeed(int seed);
    Level *getPtrLevel();
    Score &getScore();
    Board &getBoard();
    void replaceUndroppedBlock(char blockType);
    void insertStarBlock();
    void restartPlayer();
    bool shouldDroplvl4Block();

    void decideSwitchSpecialAction();
};

#endif
