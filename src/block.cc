#include "block.h"
#include <cmath>
#include <iostream>

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

void Block::setBoard(Board *board)
{
    this->board = board;
}

std::vector<Cell *> Block::getCells()
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

void Block::setBottomLeftCell(Cell *cell)
{
    bottomLeftCell = cell;
}

void Block::takeoverCells(std::vector<Cell *> &newCells)
{
    cells = newCells;
}

int Block::getLevel()
{
    return level;
}

bool Block::playerLose()
{
    for (int i = 0; i < 11; i++)
    {
        if ((*gridRef)[3][i]->getCellType() != ' ')
        {
            return true;
        }
    }

    return false;
}

bool Block::moveLeft()
{
    int x = getBottomLeftCell()->getX();
    int y = getBottomLeftCell()->getY();

    if (y == 0)
    {
        return false;
    }

    std::vector<Cell *> newCells;
    for (Cell *cell : cells)
    {
        int row = cell->getX();
        int col = cell->getY();
        newCells.emplace_back((*gridRef)[row][col - 1].get());
    }

    if (isValidMove(newCells))
    {
        for (Cell *cell : newCells)
        {
            cell->setCellType(getBlockType());
        }
        bottomLeftCell = (*gridRef)[x][y - 1].get();
        cells = newCells;
        return true;
    }

    return false;
}

bool Block::moveRight()
{
    int x = getBottomLeftCell()->getX();
    int y = getBottomLeftCell()->getY();

    if (y + width > 10)
    {
        return false;
    }

    std::vector<Cell *> newCells;
    for (Cell *cell : cells)
    {
        int row = cell->getX();
        int col = cell->getY();
        newCells.emplace_back((*gridRef)[row][col + 1].get());
    }

    if (isValidMove(newCells))
    {
        for (Cell *cell : newCells)
        {
            cell->setCellType(getBlockType());
        }
        bottomLeftCell = (*gridRef)[x][y + 1].get();
        cells = newCells;
        return true;
    }

    return false;
}

bool Block::moveDown()
{
    int x = getBottomLeftCell()->getX();
    int y = getBottomLeftCell()->getY();

    if (x == 17)
    {
        return false;
    }

    std::vector<Cell *> newCells;
    for (Cell *cell : cells)
    {
        int row = cell->getX();
        int col = cell->getY();
        newCells.emplace_back((*gridRef)[row + 1][col].get());
    }

    if (isValidMove(newCells))
    {
        for (Cell *cell : newCells)
        {
            cell->setCellType(getBlockType());
        }
        bottomLeftCell = (*gridRef)[x + 1][y].get();
        cells = newCells;
        return true;
    }

    return false;
}

void Block::drop()
{
    while (moveDown())
    {
        continue;
    }
}

bool Block::isValidMove(std::vector<Cell *> newCells)
{
    setBlockEmpty();

    for (Cell *cell : newCells)
    {
        if (!cell || cell->getCellType() != ' ')
        {
            setBlockCellType(getBlockType());
            return false;
        }
    }

    return true;
}
