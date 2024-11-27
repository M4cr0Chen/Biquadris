#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"

class Level4 : public Level
{
    bool nonrandom;
    int level = 1;
    int index;
    int indexCount;
    std::vector<char> sequence;
    int seed;
    char randomCharGenerator();
    

public:
    Level4();
    void setSeed(int seed) override;
    std::unique_ptr<Block> generateBlock() override;
    void setGenerationNotRandom(std::string file);
    void setGenerationRandom();
};

#endif
