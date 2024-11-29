#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class IBlock : public Block
{
public:
    IBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~IBlock() override;
};

#endif
