#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class LBlock : public Block
{
public:
    LBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~LBlock() override;
};

#endif
