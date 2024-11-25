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

public:
    Player(bool isPlayerOne, std::string s1, std::string s2);
    void createBlock();
    int dropBlock();
    void setLevel(int levelNum);
    int getIntLevel();
    Level *getPtrLevel();
    Score &getScore();
    Board &getBoard();
};

#endif
