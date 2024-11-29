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

    std::unique_ptr<Block> currentBlock;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Block> tempBlock;

    bool isHeavy;
    bool isBlind;

    int level;
    int count;

public:
    std::vector<std::unique_ptr<Block>> activeBlocks;
    Board();
    Cell *getCellAt(int x, int y);
    char getNextBlockType();
    void addBlock(std::unique_ptr<Block> block);
    void dropBlock(int *numLine, int *score);
    void dropStarBlock(int *numLine, int *score);
    void changeBlock(std::unique_ptr<Block> block);
    void insertBlock(std::unique_ptr<Block> block);
    bool isRowFull(int row);
    void moveRowDown(int row, int destRow);
    int updateActiveBlocks();
    void updateBlocksPosition(int clearedRow);
    void changeCurrentAndNextBlock(std::unique_ptr<Block> newCurrentBlock, std::unique_ptr<Block> newNextBlock);

    void moveCellsDownByOne(std::vector<Cell *> cellsToBeMoved);

    Block *getCurrentBlock();
    Block *getNextBlock();
    Block *getTempBlock();
    int getHeavyInt();
    void setLevel(int level);
    int getCount();
    void setCount(int count);
    void setBoardBlind();
    void setBoardHeavy();
    bool getIsBlind();
    bool getIsHeavy();
    bool isGameOver();
    void setRowEmpty(int row);
};

#endif
