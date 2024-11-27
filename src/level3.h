#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"

class Level3 : public Level
{
    bool nonrandom;
    int level = 1;
    int index;
    std::vector<char> sequence;
    int seed;
    char randomCharGenerator();
    

public:
    Level3();
    void setSeed(int seed);
    std::unique_ptr<Block> generateBlock() override;
    void setGenerationNotRandom(std::string file) override;
    void setGenerationRandom() override;
};

#endif
