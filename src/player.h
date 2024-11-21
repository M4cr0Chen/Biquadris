#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Level;

class Player
{
private:
    std::unique_ptr<Level> level;
    Board board;

public:
};

#endif
