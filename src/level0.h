#ifndef LEVEL0_H
#define LEVEL0_H

#include "level.h"

class Level0 : public Level
{
    int index;
    std::vector<char> sequence;

public:
    std::unique_ptr<Block> generateBlock(char blockType, int level) override;
};

#endif
