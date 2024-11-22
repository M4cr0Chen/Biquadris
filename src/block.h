#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "board.h"
#include "cell.h"

class Board;

class Block
{
private:
    std::vector<Cell *> cells;
    Cell *bottomLeftCell;
    Board *board;
    char blockType;
    int level;

public:
    virtual ~Block() = default;
    virtual bool moveLeft() = 0;
    virtual bool moveRight() = 0;
    virtual bool moveDown() = 0;
    virtual void drop() = 0;
    virtual bool rotateClockwise() = 0;
    virtual bool rotateCounterClockwise() = 0;
    std::vector<Cell *> getCells() const;
    Board *getBoard() const;
    // std::vector<Cell *> getProjectedCells(char dir) const;
    char getBlockType() const;
    void setBlockType(char type);
    int getLevel();
    void setLevel(int level);
    bool isAtBottom() const;
    void takeoverCells(std::vector<Cell *> &newCells);
    Cell *getBottomLeftCell();
    int updateBlock();
};

#endif
