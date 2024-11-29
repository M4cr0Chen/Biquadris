#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class ZBlock : public Block
{
public:
    ZBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~ZBlock() override;
};

#endif
