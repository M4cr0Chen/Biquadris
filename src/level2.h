#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"

class Level2 : public Level
{
    int level = 1;
    int seed;
    char randomCharGenerator();
    

public:
    Level2();
    void setSeed(int seed);
    std::unique_ptr<Block> generateBlock() override;
};

#endif
