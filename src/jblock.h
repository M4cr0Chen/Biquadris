#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock : public Block
{
public:
    JBlock(int level);
    void init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid) override;
    bool rotateClockwise() override;
    bool rotateCounterClockwise() override;
    ~JBlock() override;
};

#endif
