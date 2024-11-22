#ifndef LEVEL_H
#define LEVEL_H

#include <memory>
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"


class Level
{
public:
    virtual std::unique_ptr<Block> generateBlock(char blockType, int level) = 0;
    ~Level() = default;
};

#endif
