#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class SBlock : public Block
{
public:
    std::vector<std::vector<std::unique_ptr<Cell>>> *gridRef;
    SBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
};

#endif
