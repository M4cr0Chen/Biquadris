#include "level.h"

std::unique_ptr<Block> Level::giveMeABlock(char blockType, int level) {
    switch (blockType)
    {
    case 'I':
        return std::make_unique<IBlock>(level);
    case 'J':
        return std::make_unique<JBlock>(level);
    case 'L':
        return std::make_unique<LBlock>(level);
    case 'O':
        return std::make_unique<OBlock>(level);
    case 'S':
        return std::make_unique<SBlock>(level);
    case 'Z':
        return std::make_unique<ZBlock>(level);
    case 'T':
        return std::make_unique<TBlock>(level);
    default:
        return nullptr;
    }
}
