#include "oblock.h"

OBlock::OBlock(int level)
{
    setBottomLeftCell(nullptr);
    setLevel(level);
    setBlockType('S');
    setRotationIndex(0);
    setWidth(3);
}

void OBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    // Board *board = getBoard();
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back((*gridRef)[2][0].get());
    cells.emplace_back((*gridRef)[2][1].get());
    cells.emplace_back((*gridRef)[3][0].get());
    cells.emplace_back((*gridRef)[3][1].get());
    (*gridRef)[2][0]->setCellType(getBlockType());
    (*gridRef)[2][1]->setCellType(getBlockType());
    (*gridRef)[3][0]->setCellType(getBlockType());
    (*gridRef)[3][1]->setCellType(getBlockType());
}

bool OBlock::moveLeft()
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

bool OBlock::moveRight()
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

bool OBlock::moveDown()
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

void OBlock::drop()
{
    while (moveDown())
    {
        continue;
    }
}

bool OBlock::isValidMove(std::vector<Cell *> newCells)
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

bool OBlock::rotateClockwise()
{
    return true;
}

bool OBlock::rotateCounterClockwise()
{
    return true;
}
