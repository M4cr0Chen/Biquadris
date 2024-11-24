#include "level0.h"

Level0::Level0(bool isPlayerOne, std::string s1, std::string s2)
{
    if (isPlayerOne)
    {
        index = 0;
        for (char c : s1)
        {
            sequence.push_back(c);
        }
    }
    else
    {
        index = 0;
        for (char c : s2)
        {
            sequence.push_back(c);
        }
    }
}

std::unique_ptr<Block> Level0::generateBlock()
{
    std::unique_ptr<Block> block = std::move(giveMeABlock(sequence[index], level));

    index = (index + 1) % sequence.size();

    return std::move(block);
}
