#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "score.h"
#include "level.h"

class Level;

class Player
{
private:
    std::unique_ptr<Level> level;
    Board board;
    int levelNum;
    Score score;

public:
    Player();
    void setLevel(int levelNum);
    //int getLevel();
    Level *getLevel();
    Score &getScore();
    Board &getBoard();
};

#endif
