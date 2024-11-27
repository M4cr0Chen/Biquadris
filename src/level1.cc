#include "level1.h"

Level1::Level1() = default;

void Level1::setSeed(int seed)
{
    this->seed = seed;
}

std::unique_ptr<Block> Level1::generateBlock() {
    char blockType = randomCharGenerator();
    return std::move(giveMeABlock(blockType, level));
}

char Level1::randomCharGenerator() {
    int n = rand() % 12;
    if (n < 1) {
        return 'S';
    } else if (n < 2) {
        return 'Z';
    } else if (n < 4) {
        return 'I';
    } else if (n < 6) {
        return 'J';
    } else if (n < 8) {
        return 'T';
    } else if (n < 10) {
        return 'L';
    } else {
        return 'O';
    }
}
