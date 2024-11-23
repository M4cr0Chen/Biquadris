#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "board.h"
#include "cell.h"

class Board;

class Block
{
protected:
    std::vector<Cell *> cells;
    Cell *bottomLeftCell;
    Board *board;
    char blockType;
    int level;
    int rotationIndex;
    int width;

public:
    virtual ~Block() = default;
    virtual bool moveLeft() = 0;
    virtual bool moveRight() = 0;
    virtual bool moveDown() = 0;
    virtual void drop() = 0;
    virtual bool rotateClockwise() = 0;
    virtual bool rotateCounterClockwise() = 0;
    virtual bool isValidMove(std::vector<Cell *> newCells);
    std::vector<Cell *> getCells() const;
    void setBlockEmpty();
    void setBlockCellType(char type);
    Board *getBoard() const;
    // std::vector<Cell *> getProjectedCells(char dir) const;
    char getBlockType() const;
    void setBlockType(char type);
    int getLevel();
    void setLevel(int level);
    void setRotationIndex(int index);
    int getRotationIndex();
    void setWidth(int width);
    int getWidth();
    bool isAtBottom() const;
    void takeoverCells(std::vector<Cell *> &newCells);
    Cell *getBottomLeftCell();
    int updateBlock();
};

#endif
