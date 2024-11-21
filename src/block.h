#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "cell.h"

class Block
{
private:
    std::vector<Cell *> cells;

    char blockType;

public:
    Block(char blockType);
    char getBlockType();
};

#endif
