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
#include "lvl4block.h"

class Level
{
public:
    virtual std::unique_ptr<Block> generateBlock() = 0;
    virtual void setGenerationNotRandom(std::string file);
    virtual void setGenerationRandom();
    virtual void setSeed(int seed) = 0;
    std::unique_ptr<Block> giveMeABlock(char blockType, int level);
    virtual ~Level() = default;
};

#endif
