#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"

class Level1 : public Level
{
    int level = 1;
    int seed;
    char randomCharGenerator();
    

public:
    Level1();
    void setSeed(int seed);
    std::unique_ptr<Block> generateBlock() override;
};

#endif
