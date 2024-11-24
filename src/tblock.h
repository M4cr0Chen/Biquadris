#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class TBlock : public Block
{
public:
    std::vector<std::vector<std::unique_ptr<Cell>>> *gridRef;
    TBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool moveLeft() override;
    bool moveRight() override;
    bool moveDown() override;
    void drop() override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    bool isValidMove(std::vector<Cell *> newCells) override;
};

#endif
