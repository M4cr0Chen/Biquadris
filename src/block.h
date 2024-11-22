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
    virtual bool moveLeft();
    virtual bool moveRight();
    virtual bool moveDown();
    virtual void drop();
    virtual bool rotateClockwise();
    virtual bool rotateCounterClockwise();
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
