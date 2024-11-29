#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class OBlock : public Block
{
public:
    
    OBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~OBlock() override;
};

#endif
