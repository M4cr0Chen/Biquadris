#include "iblock.h"

IBlock::IBlock(int level)
{
    setLevel(level);
    setBlockType('I');
    setRotationIndex(0);
    setWidth(4);
}

void IBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    //Board *board = getBoard();
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back((*gridRef)[3][0].get());
    cells.emplace_back((*gridRef)[3][1].get());
    cells.emplace_back((*gridRef)[3][2].get());
    cells.emplace_back((*gridRef)[3][3].get());
    (*gridRef)[3][0]->setCellType('I');
    (*gridRef)[3][1]->setCellType('I');
    (*gridRef)[3][2]->setCellType('I');
    (*gridRef)[3][3]->setCellType('I');
}

bool IBlock::moveLeft()
{
    int x = getBottomLeftCell()->getX();
    int y = getBottomLeftCell()->getY();

    if (x == 0)
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
        bottomLeftCell = newCells[0];
        cells = newCells;
        return true;
    }

    return false;
}

bool IBlock::moveRight()
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
        bottomLeftCell = newCells[0];
        cells = newCells;
        return true;
    }

    return false;
}

bool IBlock::moveDown()
{
    int x = getBottomLeftCell()->getX();
    int y = getBottomLeftCell()->getY();

    if (y == 17)
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
        bottomLeftCell = newCells[0];
        cells = newCells;
        return true;
    }

    return false;
}

void IBlock::drop()
{
    while (moveDown())
    {
        continue;
    }
}

bool IBlock::isValidMove(std::vector<Cell *> newCells)
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

bool IBlock::rotateClockwise()
{
    std::vector<Cell *> tempCells;
    rotationIndex = getRotationIndex();

    // Horizontal to Vertical (0->1, 2->3)
    if (rotationIndex == 0 || rotationIndex == 2)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (x < 3)
            return false;

        tempCells.push_back((*gridRef)[x][y].get());     // Bottom
        tempCells.push_back((*gridRef)[x - 1][y].get()); // Second from bottom
        tempCells.push_back((*gridRef)[x - 2][y].get()); // Second from top
        tempCells.push_back((*gridRef)[x - 3][y].get()); // Top

        if (isValidMove(tempCells))
        {
            setWidth(1);
            rotationIndex++;
        }
    }
    // Vertical to Horizontal (1->2, 3->0)
    else
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (y > 7)
            return false;

        tempCells.push_back((*gridRef)[x][y].get());     // Left
        tempCells.push_back((*gridRef)[x][y + 1].get()); // Second from left
        tempCells.push_back((*gridRef)[x][y + 2].get()); // Second from right
        tempCells.push_back((*gridRef)[x][y + 3].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 4;
            rotationIndex = (rotationIndex + 1) % 4;
        }
    }

    if (isValidMove(tempCells))
    {
        for (Cell *cell : tempCells)
        {
            cell->setCellType(getBlockType());
        }
        bottomLeftCell = tempCells[0];
        cells = tempCells;
    }
    return false;
}

bool IBlock::rotateCounterClockwise()
{
    rotateClockwise();
}
