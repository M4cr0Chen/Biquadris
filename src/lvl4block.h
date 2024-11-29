#ifndef LVL4BLOCK_H
#define LVL4BLOCK_H

#include "block.h"

class LVL4Block : public Block
{
public:
    LVL4Block(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~LVL4Block() override;
};

#endif
