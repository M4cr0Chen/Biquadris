#include "block.h"
#include <cmath>

int Block::updateBlock()
{
    for (int i = cells.size() - 1; i >= 0; i--)
    {
        if (cells[i]->getCellType() == ' ')
        {
            cells.erase(cells.begin() + i);
        }
    }

    if (cells.empty())
    {
        return std::pow(level + 1, 2);
    }

    return 0;
}

Board *Block::getBoard() const
{
    return board;
}

std::vector<Cell *> Block::getCells() const
{
    return cells;
}

char Block::getBlockType() const
{
    return blockType;
}

void Block::setBlockType(char blockType)
{
    this->blockType = blockType;
}

void Block::setLevel(int level)
{
    this->level = level;
}

bool Block::isAtBottom() const
{
    return bottomLeftCell->getY() == 1;
}

Cell *Block::getBottomLeftCell()
{
    return bottomLeftCell;
}

void Block::takeoverCells(std::vector<Cell *> &newCells)
{
    cells = newCells;
}

int Block::getLevel()
{
    return level;
}
