#include <fstream>
#include "level3.h"

Level3::Level3() = default;

void Level3::setSeed(int seed)
{
    this->seed = seed;
}

std::unique_ptr<Block> Level3::generateBlock() {
    char blockType;
    if (nonrandom) {
        blockType = sequence[index];
        index = (index + 1) % sequence.size();
    } else {
        blockType = randomCharGenerator();
    }
    return std::move(giveMeABlock(blockType, level));    
}

char Level3::randomCharGenerator() {
    int n = rand() % 9;
    if (n < 1) {
        return 'O';
    } else if (n < 2) {
        return 'L';
    } else if (n < 3) {
        return 'I';
    } else if (n < 4) {
        return 'J';
    } else if (n < 5) {
        return 'T';
    } else if (n < 7) {
        return 'S';
    } else {
        return 'Z';
    }
}

void Level3::setGenerationNotRandom(std::string file) {
    nonrandom = true;
    std::ifstream fileStream{file};
    char c;
    while (fileStream >> c) {
        sequence.push_back(c);
    }
}

void Level3::setGenerationRandom() {
    nonrandom = false;
}
