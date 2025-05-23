#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class SBlock : public Block
{
public:
    
    SBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~SBlock();
};

#endif
