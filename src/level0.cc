#include "level0.h"

std::unique_ptr<Block> Level0::generateBlock(char blockType, int level)
{
    switch (blockType)
    {
    case 'I':
        return std::make_unique<IBlock>(level);
    }
}
