#include <fstream>
#include <iostream>
#include "level4.h"

Level4::Level4(): nonrandom{false}, index{0}, indexCount{0} {}

void Level4::setSeed(int seed)
{
    this->seed = seed;
}

std::unique_ptr<Block> Level4::generateBlock() {
    char blockType;
    if (nonrandom) {
        blockType = sequence[index];
        index = (index + 1) % sequence.size();
    } else {
        blockType = randomCharGenerator();
    }
    return std::move(giveMeABlock(blockType, level));    
}

char Level4::randomCharGenerator() {
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

void Level4::setGenerationNotRandom(std::string file) {
    nonrandom = true;
    try {
        std::ifstream fileStream{file};
        char c;
        while (fileStream >> c) {
            sequence.push_back(c);
        }
    } catch(...) {
        std::cerr << "File not found" << std::endl;
        return;
    }
    
}

void Level4::setGenerationRandom() {
    nonrandom = false;
}
