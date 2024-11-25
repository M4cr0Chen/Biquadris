#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <cmath>

#include "block.h"
#include "cell.h"

class Block;

class Board
{
private:
    std::vector<std::vector<std::unique_ptr<Cell>>> grid;
    // std::vector<std::unique_ptr<Block>> activeBlocks;

    std::unique_ptr<Block> currentBlock;
    std::unique_ptr<Block> nextBlock;

    char nextBlockType;

    std::vector<Cell *> getMoveProjectedCells(const Block *block, char dir) const;
    std::vector<Cell *> getRotateProjectedCells(const Block *block, char dir) const;

    bool isHeavy;
    bool isBlind;

    int level;

public:
    // Testing purpose
    std::vector<std::unique_ptr<Block>> activeBlocks;
    Board();
    Cell *getCellAt(int x, int y);
    char getNextBlockType();
    void addBlock(std::unique_ptr<Block> block);
    void dropBlock(int *numLine, int *score);
    void changeBlock(Block *block);
    bool isRowFull(int row);
    void moveRowDown(int row, int destRow);
    int updateActiveBlocks();
    void updateBlocksPosition(int clearedRow);

    Block *getCurrentBlock();
    Block *getNextBlock();
    int getHeavyInt();
};

#endif
