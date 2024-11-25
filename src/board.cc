#include "board.h"

Board::Board() : nextBlockType{' '}, currentBlock{nullptr}, nextBlock{nullptr}
{
    grid.resize(18);
    for (int i = 0; i < 18; i++)
    {
        grid[i].resize(11);
        for (int j = 0; j < 11; j++)
        {
            grid[i][j] = std::make_unique<Cell>(i, j, ' ');
        }
    }
}

Cell *Board::getCellAt(int x, int y)
{
    return grid[x][y].get();
}

char Board::getNextBlockType()
{
    return nextBlockType;
}

void Board::addBlock(std::unique_ptr<Block> newblock)
{
    // testing purpose
    // activeBlocks.emplace_back(std::move(newblock));

    if (nextBlock == nullptr)
    {
        nextBlock = std::move(newblock);
        return;
    }

    // currentBlock = activeBlocks[activeBlocks.size() - 1].get();
    currentBlock = std::move(nextBlock);
    nextBlock = std::move(newblock);
    currentBlock->init(grid[3][0].get(), grid);
}

int Board::dropBlock(int *numLine)
{
    currentBlock->drop();
    activeBlocks.push_back(std::move(currentBlock));

    // clearline logic

    currentBlock = nullptr;

    return 0;
}

Block *Board::getCurrentBlock()
{
    return currentBlock.get();
}

Block *Board::getNextBlock()
{
    return nextBlock.get();
}

int Board::getHeavyInt()
{
    if (isHeavy)
    {
        return 2;
    }

    return 0;
}
