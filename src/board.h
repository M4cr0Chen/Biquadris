#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

#include "block.h"

class Board
{
private:
    std::vector<std::vector<std::unique_ptr<Cell>>> grid;
    std::vector<std::unique_ptr<Block>> activeBlocks;

public:
};

#endif
