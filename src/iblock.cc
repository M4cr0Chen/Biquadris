#include "iblock.h"

IBlock::IBlock(int level)
{
    setLevel(level);
    setBlockType('I');
}

void IBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    setRotationIndex(0);
    std::vector<Cell *> cells = getCells();
    //Board *board = getBoard();
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back(grid[3][0].get());
    cells.emplace_back(grid[3][1].get());
    cells.emplace_back(grid[3][2].get());
    cells.emplace_back(grid[3][3].get());
    grid[3][0]->setCellType('I');
    grid[3][1]->setCellType('I');
    grid[3][2]->setCellType('I');
    grid[3][3]->setCellType('I');
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
        newCells.emplace_back(board->getCellAt(x, y - 1));
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
        newCells.emplace_back(board->getCellAt(x, y + 1));
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
        newCells.emplace_back(board->getCellAt(x + 1, y));
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
    int rotationIndex = getRotationIndex();

    // Horizontal to Vertical (0->1, 2->3)
    if (rotationIndex == 0 || rotationIndex == 2)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (x < 3)
            return false;

        tempCells.push_back(board->getCellAt(x, y));     // Bottom
        tempCells.push_back(board->getCellAt(x - 1, y)); // Second from bottom
        tempCells.push_back(board->getCellAt(x - 2, y)); // Second from top
        tempCells.push_back(board->getCellAt(x - 3, y)); // Top

        if (isValidMove(tempCells))
        {
            setWidth(1);
            setRotationIndex(getRotationIndex() + 1);
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

        tempCells.push_back(board->getCellAt(x, y));     // Left
        tempCells.push_back(board->getCellAt(x, y + 1)); // Second from left
        tempCells.push_back(board->getCellAt(x, y + 2)); // Second from right
        tempCells.push_back(board->getCellAt(x, y + 3)); // Right

        if (isValidMove(tempCells))
        {
            width = 4;
            rotationIndex = (rotationIndex + 1) % 4;
        }
    }
}

bool IBlock::rotateCounterClockwise()
{
    rotateClockwise();
}
