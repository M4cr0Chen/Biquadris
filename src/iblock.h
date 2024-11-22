#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class IBlock : public Block
{
public:
    IBlock(int level);
    bool moveLeft();
    bool moveRight();
    bool moveDown();
    void drop();
    bool rotateClockwise();
    bool rotateCounterClockwise();
};

#endif
