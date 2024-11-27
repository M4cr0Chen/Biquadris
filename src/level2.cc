#include "level2.h"

Level2::Level2() = default;

void Level2::setSeed(int seed)
{
    this->seed = seed;
}

std::unique_ptr<Block> Level2::generateBlock() {
    char blockType = randomCharGenerator();
    return std::move(giveMeABlock(blockType, level));
}

char Level2::randomCharGenerator() {
    std::vector<char> blocks = {'S', 'Z', 'I', 'J', 'T', 'L', 'O'};
    int n = rand() % 7;
    return blocks[n];
}
