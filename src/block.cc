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

void Block::setBlockEmpty()
{
    for (Cell *cell : cells)
    {
        cell->setCellType(' ');
    }
}

void Block::setBlockCellType(char blockType)
{
    for (Cell *cell : cells)
    {
        cell->setCellType(blockType);
    }
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

void Block::setRotationIndex(int index)
{
    rotationIndex = index;
}

int Block::getRotationIndex()
{
    return rotationIndex;
}

void Block::setWidth(int width)
{
    this->width = width;
}

int Block::getWidth()
{
    return width;
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
