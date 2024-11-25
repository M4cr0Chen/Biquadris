#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock : public Block
{
public:
    //std::vector<std::vector<std::unique_ptr<Cell>>> *gridRef;
    JBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
};

#endif
