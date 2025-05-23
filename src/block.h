#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <stdexcept>

#include "board.h"
#include "cell.h"

class Board;

class Block
{
protected:
    std::vector<std::vector<std::unique_ptr<Cell>>> *gridRef;
    std::vector<Cell *> cells;
    Cell *bottomLeftCell;
    Board *board;
    char blockType;
    int level;
    int rotationIndex;
    int width;

public:
    Block() : bottomLeftCell{nullptr}, board{nullptr}, blockType{' '}, level{0} {}

    virtual void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) = 0;
    virtual ~Block() = default;
    bool moveLeft();
    bool moveRight();
    bool moveDown();
    void drop();
    bool isValidMove(std::vector<Cell *> newCells);
    virtual bool rotateClockwise() = 0;
    virtual bool rotateCounterClockwise() = 0;
    std::vector<Cell *> getCells();
    void setBlockEmpty();
    void setBlockCellType(char type);
    Board *getBoard() const;
    void setBoard(Board *board);
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
    void setBottomLeftCell(Cell *cell);
    int updateBlock();
    bool playerLose();
};

#endif
