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

    char nextBlockType;

    std::vector<Cell *> getMoveProjectedCells(const Block *block, char dir) const;
    std::vector<Cell *> getRotateProjectedCells(const Block *block, char dir) const;

public:
    Board();
    Cell *getCellAt(int x, int y);
    char getNextBlockType();
    void addBlock(std::unique_ptr<Block> block);
    void changeBlock(Block *block);
};

#endif
