#ifndef LEVEL0_H
#define LEVEL0_H

#include "level.h"
#include <string>

class Level0 : public Level
{
    int level = 0;
    int index;
    std::vector<char> sequence;

public:
    Level0(bool isPlayerOne, std::string s1, std::string s2);
    std::unique_ptr<Block> generateBlock() override;
};

#endif
