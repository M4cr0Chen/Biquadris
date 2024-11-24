#include "tblock.h"

TBlock::TBlock(int level)
{
    setBottomLeftCell(nullptr);
    setLevel(level);
    setBlockType('S');
    setRotationIndex(0);
    setWidth(3);
}

void TBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    // Board *board = getBoard();
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back((*gridRef)[2][0].get());
    cells.emplace_back((*gridRef)[2][1].get());
    cells.emplace_back((*gridRef)[2][2].get());
    cells.emplace_back((*gridRef)[3][1].get());
    (*gridRef)[2][0]->setCellType(getBlockType());
    (*gridRef)[2][1]->setCellType(getBlockType());
    (*gridRef)[2][2]->setCellType(getBlockType());
    (*gridRef)[3][1]->setCellType(getBlockType());
}

bool TBlock::moveLeft()
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

bool TBlock::moveRight()
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

bool TBlock::moveDown()
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

void TBlock::drop()
{
    while (moveDown())
    {
        continue;
    }
}

bool TBlock::isValidMove(std::vector<Cell *> newCells)
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

bool TBlock::rotateClockwise()
{
    std::vector<Cell *> tempCells;
    rotationIndex = getRotationIndex();

    if (rotationIndex == 0)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        // if (y > 3)
        //     return false;

        tempCells.push_back((*gridRef)[x - 1][y].get());     // Top
        tempCells.push_back((*gridRef)[x][y + 1].get());     // Bottom
        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Second from bottom
        tempCells.push_back((*gridRef)[x - 2][y + 1].get()); // Second from top

        if (isValidMove(tempCells))
        {
            setWidth(2);
            rotationIndex = (rotationIndex + 1) % 2;
        }
    }
    else if (rotationIndex == 1)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (y > 8)
            return false;

        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Left
        tempCells.push_back((*gridRef)[x][y].get());         // Second from left
        tempCells.push_back((*gridRef)[x][y + 1].get());     // Second from right
        tempCells.push_back((*gridRef)[x][y + 2].get());     // Right

        if (isValidMove(tempCells))
        {
            width = 3;
            rotationIndex = (rotationIndex + 1) % 2;
        }
    }
    else if (rotationIndex == 2)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        // if (y > 3)
        //     return false;

        tempCells.push_back((*gridRef)[x][y].get());         // Top
        tempCells.push_back((*gridRef)[x - 1][y].get());     // Bottom
        tempCells.push_back((*gridRef)[x - 2][y].get());     // Second from bottom
        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Second from top

        if (isValidMove(tempCells))
        {
            setWidth(2);
            rotationIndex = (rotationIndex + 1) % 2;
        }
    }
    else if (rotationIndex == 3)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (y > 8)
            return false;

        tempCells.push_back((*gridRef)[x][y + 1].get());     // Left
        tempCells.push_back((*gridRef)[x - 1][y].get());     // Second from left
        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Second from right
        tempCells.push_back((*gridRef)[x - 1][y + 2].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 3;
            rotationIndex = (rotationIndex + 1) % 2;
        }
    }

    if (isValidMove(tempCells))
    {
        for (Cell *cell : tempCells)
        {
            cell->setCellType(getBlockType());
        }
        // bottomLeftCell = tempCells[0];
        cells = tempCells;
        return true;
    }
    return false;
}

bool TBlock::rotateCounterClockwise()
{
    // Three clockwise rotations = one counterclockwise rotation
    bool success = true;
    for (int i = 0; i < 3 && success; i++)
    {
        success = rotateClockwise();
    }
    return success;
}
