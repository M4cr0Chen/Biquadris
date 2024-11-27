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
    void setSeed(int seed) override;
    std::unique_ptr<Block> generateBlock() override;
    void setGenerationNotRandom(std::string file);
    void setGenerationRandom();
};

#endif
